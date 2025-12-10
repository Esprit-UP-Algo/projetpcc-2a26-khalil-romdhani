#include "moniteur.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>

Moniteur::Moniteur() {}

Moniteur::Moniteur(QString nom_m, QString prenom_m, QString email_m, QString tel_m,
                   QString dispo_m, QString specialite_m, int experience_m, int id_seance,QDate date_inactivite)
{
    this->nom_m = nom_m;
    this->prenom_m = prenom_m;
    this->email_m = email_m;
    this->tel_m = tel_m;
    this->dispo_m = dispo_m;
    this->specialite_m = specialite_m;
    this->experience_m = experience_m;
    this->id_seance = id_seance;
    this->date_inactivite = date_inactivite;

}
Moniteur::Moniteur(QString cin_m, QString nom_m, QString prenom_m, QString email_m, QString tel_m,
                   QString dispo_m, QString specialite_m, int experience_m, int id_seance, QDate date_inactivite)
{
    this->cin_m = cin_m;
    this->nom_m = nom_m;
    this->prenom_m = prenom_m;
    this->email_m = email_m;
    this->tel_m = tel_m;
    this->dispo_m = dispo_m;
    this->specialite_m = specialite_m;
    this->experience_m = experience_m;
    this->id_seance = id_seance;
    this->date_inactivite = date_inactivite;

}
// ✅ Ajouter un moniteur (sans CIN_M, généré automatiquement dans Oracle)
bool Moniteur::ajouter()
{
    QSqlQuery query;

    // ✅ Vérifier si inactif mais date manquante
    if (dispo_m.toLower() == "inactif" && !date_inactivite.isValid()) {
        qDebug() << "❌ Erreur: Moniteur inactif mais date d'inactivité manquante";
        return false;
    }

    // ✅ Si actif, forcer date_inactivite à NULL
    if (dispo_m.toLower() == "actif") {
        date_inactivite = QDate(); // Date invalide = NULL en base
    }

    query.prepare("INSERT INTO MONITEURS (NOM_M, PRENOM_M, SPECIALITE_M, EXPERIENCE_M, DISPO_M, EMAIL_M, TEL_M, ID_SEANCE, DATE_INACTIVITE) "
                  "VALUES (:nom, :prenom, :specialite, :experience, :dispo, :email, :tel, :id_seance, :date_inactivite)");

    query.bindValue(":nom", nom_m);
    query.bindValue(":prenom", prenom_m);
    query.bindValue(":specialite", specialite_m);
    query.bindValue(":experience", experience_m);
    query.bindValue(":dispo", dispo_m);
    query.bindValue(":email", email_m);
    query.bindValue(":tel", tel_m);

    if (id_seance <= 0)
        query.bindValue(":id_seance", QVariant(QVariant::Int));
    else
        query.bindValue(":id_seance", id_seance);

    // ✅ Gestion correcte de date_inactivite
    if (date_inactivite.isValid())
        query.bindValue(":date_inactivite", date_inactivite);
    else
        query.bindValue(":date_inactivite", QVariant(QVariant::Date));

    if (!query.exec()) {
        qDebug() << "❌ Erreur ajout Moniteur:" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        return false;
    }

    return true;
}

// ✅ Afficher les moniteurs dans un tableau Qt
void Moniteur::afficher(QTableWidget* table)
{
    QSqlQuery query("SELECT CIN_M, NOM_M, PRENOM_M, EMAIL_M, TEL_M, SPECIALITE_M, DISPO_M, EXPERIENCE_M, ID_SEANCE, DATE_INACTIVITE FROM MONITEURS ORDER BY CIN_M ASC");

    // ✅ DÉSACTIVER les signaux pendant le chargement
    table->blockSignals(true);

    table->setRowCount(0);
    table->setColumnCount(10);

    QStringList headers = {"id", "Nom", "Prénom", "Email", "Téléphone", "Spécialité", "Disponibilité", "Expérience", "ID Séance", "Date Inactivité"};
    table->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        table->insertRow(row);

        for (int col = 0; col < 10; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem();

            if (col == 9) { // Colonne DATE_INACTIVITE
                QDate dateInactivite = query.value(col).toDate();
                if (dateInactivite.isValid()) {
                    item->setText(dateInactivite.toString("dd/MM/yyyy"));
                } else {
                    item->setText("");
                }
            } else {
                item->setText(query.value(col).toString());
            }

            // ✅ NE PAS définir de couleurs ici - laissé au système de clignotement
            table->setItem(row, col, item);
        }
        row++;
    }

    // ✅ RÉACTIVER les signaux
    table->blockSignals(false);

    qDebug() << "📊 Tableau chargé avec" << row << "lignes";
}
// ✅ Modifier tous les champs d'un moniteur (appel complet depuis GereMoniteur)
bool Moniteur::modifier(QString cin_m, QString nom, QString prenom, QString email, QString tel,
                        QString dispo, QString specialite, int experience, int id_seance, QDate date_inactivite)
{
    // ✅ Vérification cohérence disponibilité/date
    if (dispo.toLower() == "inactif" && !date_inactivite.isValid()) {
        qDebug() << "❌ Date d'inactivité manquante pour un moniteur inactif.";
        return false;
    }

    // ✅ Si actif → on met la date vide/null
    if (dispo.toLower() == "actif") {
        date_inactivite = QDate();   // date vide = NULL dans Oracle
    }

    QSqlQuery query;
    query.prepare("UPDATE MONITEURS SET "
                  "NOM_M = :nom, "
                  "PRENOM_M = :prenom, "
                  "EMAIL_M = :email, "
                  "TEL_M = :tel, "
                  "DISPO_M = :dispo, "
                  "SPECIALITE_M = :specialite, "
                  "EXPERIENCE_M = :experience, "
                  "ID_SEANCE = :id_seance, "
                  "DATE_INACTIVITE = :date_inact "
                  "WHERE CIN_M = :cin");

    query.bindValue(":cin", cin_m);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":tel", tel);
    query.bindValue(":dispo", dispo);
    query.bindValue(":specialite", specialite);
    query.bindValue(":experience", experience);

    if (id_seance <= 0)
        query.bindValue(":id_seance", QVariant(QVariant::Int));
    else
        query.bindValue(":id_seance", id_seance);

    // ✅ Correction du nom du paramètre bindValue
    if (date_inactivite.isValid())
        query.bindValue(":date_inact", date_inactivite); // ✅ ":date_inact" pas ":date_inactivite"
    else
        query.bindValue(":date_inact", QVariant(QVariant::Date));

    if (!query.exec()) {
        qDebug() << "❌ Erreur modification Moniteur:" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        return false;
    }

    return query.numRowsAffected() > 0;
}
// ✅ Modifier un moniteur existant
bool Moniteur::modifier(QString cin_m, QString colonne, QVariant valeur)
{
    // 🚫 Vérifie si le champ est autorisé
    if (colonne == "CIN_M") {
        qDebug() << "⚠️ Tentative de modification du id interdite.";
        return false;
    }

    // ✅ Vérification de la validité des données selon la colonne
    QRegularExpression regex;
    bool valide = true;
    QString erreur;

    if (colonne == "NOM_M" || colonne == "PRENOM_M") {
        regex = QRegularExpression("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]{2,30}$");
        valide = regex.match(valeur.toString()).hasMatch();
        if (!valide) erreur = "Le nom/prénom doit contenir uniquement des lettres (2-30 caractères).";
    }
    else if (colonne == "TEL_M") {
        regex = QRegularExpression("^[0-9]{8}$");
        valide = regex.match(valeur.toString()).hasMatch();
        if (!valide) erreur = "Le téléphone doit contenir exactement 8 chiffres.";
    }
    else if (colonne == "EMAIL_M") {
        regex = QRegularExpression("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        valide = regex.match(valeur.toString()).hasMatch();
        if (!valide) erreur = "L’adresse email est invalide.";
    }
    else if (colonne == "EXPERIENCE_M") {
        bool ok;
        int exp = valeur.toInt(&ok);
        valide = ok && exp >= 0 && exp <= 50;
        if (!valide) erreur = "L’expérience doit être un nombre entre 0 et 50.";
    }

    // 🚫 Si invalide → rejet sans exécuter de requête SQL
    if (!valide) {
        qDebug() << "❌ Donnée refusée pour" << colonne << ":" << erreur;
        return false;
    }

    // ✅ Requête SQL sécurisée
    QSqlQuery query;
    QString sql = QString("UPDATE MONITEURS SET %1 = :valeur WHERE CIN_M = :cin").arg(colonne);
    query.prepare(sql);
    query.bindValue(":valeur", valeur);
    query.bindValue(":cin", cin_m);

    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL (modification):" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "⚠️ Aucun enregistrement mis à jour (CIN introuvable ?)";
        return false;
    }

    qDebug() << "✅ Champ" << colonne << "modifié pour CIN" << cin_m;
    return true;
}

// ✅ Supprimer un moniteur
bool Moniteur::supprimer(QString cin_m)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MONITEURS WHERE CIN_M = :cin");
    query.bindValue(":cin", cin_m);

    if (!query.exec()) {
        qDebug() << "Erreur suppression moniteur:" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}
QVector<int> Moniteur::statistiquesSpecialites()
{
    QVector<int> stats(4, 0);   // 4 spécialités : A, B, C, D

    QSqlQuery query("SELECT SPECIALITE_M, COUNT(*) "
                    "FROM MONITEURS "
                    "GROUP BY SPECIALITE_M");

    while (query.next())
    {
        QString spec = query.value(0).toString();
        int count = query.value(1).toInt();

        if (spec == "A") stats[0] = count;
        else if (spec == "B") stats[1] = count;
        else if (spec == "C") stats[2] = count;
        else if (spec == "D") stats[3] = count;
    }

    return stats;
}
