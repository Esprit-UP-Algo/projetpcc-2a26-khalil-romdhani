#include "Candidat.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

Candidat::Candidat()
    : id_candidat(0), id_seance(0)
{
}

Candidat::Candidat(int id_candidat, QString nom_c, QString prenom_c, QDate date_n_c,
                   QString adresse_c, QString telephone_c, QString email,
                   QString nv_permis, QString progression, int id_seance)
    : id_candidat(id_candidat), nom_c(nom_c), prenom_c(prenom_c), date_n_c(date_n_c),
    adresse_c(adresse_c), telephone_c(telephone_c), email(email),
    nv_permis(nv_permis), progression(progression), id_seance(id_seance)
{
}

bool Candidat::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CANDIDATS (ID_CANDIDAT, NOM_C, PRENOM_C, DATE_N_C, ADRESSE_C, TELEPHONE_C, EMAIL, NV_PERMIS, PROGRESSION) "
                  "VALUES (:id_candidat, :nom_c, :prenom_c, :date_n_c, :adresse_c, :telephone_c, :email, :nv_permis, :progression)");
    query.bindValue(":id_candidat", id_candidat);
    query.bindValue(":nom_c", nom_c);
    query.bindValue(":prenom_c", prenom_c);
    query.bindValue(":date_n_c", date_n_c);
    query.bindValue(":adresse_c", adresse_c);
    query.bindValue(":telephone_c", telephone_c);
    query.bindValue(":email", email);
    query.bindValue(":nv_permis", nv_permis);
    query.bindValue(":progression", progression);

    bool success = query.exec();

    if (!success) {
        qDebug() << "SQL Error:" << query.lastError().text();
        qDebug() << "Executed query:" << query.lastQuery();
    }

    return success;
}

void Candidat::afficher(QTableWidget* table)
{
    table->setRowCount(0);

    QSqlQuery query("SELECT ID_CANDIDAT, NOM_C, PRENOM_C, DATE_N_C, ADRESSE_C, TELEPHONE_C, EMAIL, NV_PERMIS, PROGRESSION FROM CANDIDATS");

    int row = 0;
    while (query.next()) {
        table->insertRow(row);

        table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        table->setItem(row, 3, new QTableWidgetItem(query.value(3).toDate().toString("dd/MM/yyyy")));
        table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
        table->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
        table->setItem(row, 8, new QTableWidgetItem(query.value(8).toString()));
        row++;
    }

    QStringList headers;
    headers << "ID" << "Nom" << "Prénom" << "Date Naissance" << "Adresse"
            << "Téléphone" << "Email" << "Niveau Permis" << "Progression";
    table->setHorizontalHeaderLabels(headers);
}

bool Candidat::modifier(int ancienId, int nouveauId, QString nom, QString prenom, QDate date_n,
                        QString adresse, QString telephone, QString email, QString nv_permis,
                        QString progression)
{
    QSqlQuery query;
    if (ancienId != nouveauId)
    {
        QMessageBox::warning(nullptr,"Erreur","ID ne peut pas etre modifiee");
        return false;
    }

    query.prepare("UPDATE CANDIDATS SET ID_CANDIDAT=:nouveauId, NOM_C=:nom, PRENOM_C=:prenom, DATE_N_C=:date_n, "
                  "ADRESSE_C=:adresse, TELEPHONE_C=:telephone, EMAIL=:email, NV_PERMIS=:nv_permis, "
                  "PROGRESSION=:progression "
                  "WHERE ID_CANDIDAT=:ancienId");

    query.bindValue(":ancienId", ancienId);
    query.bindValue(":nouveauId", nouveauId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_n", date_n);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":nv_permis", nv_permis);
    query.bindValue(":progression", progression);

    bool success = query.exec();

    if (!success) {
        qDebug() << "SQL Error:" << query.lastError().text();
        qDebug() << "Executed query:" << query.lastQuery();
    }

    return success;
}

bool Candidat::supprimer(int id_candidat)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CANDIDATS WHERE ID_CANDIDAT = :id_candidat");
    query.bindValue(":id_candidat", id_candidat);

    bool success = query.exec();

    if (!success) {
        qDebug() << "SQL Error during deletion:" << query.lastError().text();
    }

    return success;
}
