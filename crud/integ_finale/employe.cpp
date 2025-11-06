#include "employe.h"
#include "connection.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Employe::Employe() {
    id_employe = 0;
    nom = prenom = telephone = poste = "";
    salaire = 0;
    date_embauche = QDate::currentDate();
}

Employe::Employe(int id, QString n, QString p, QString tel, QDate date, QString post, double sal)
    : id_employe(id), nom(n), prenom(p), telephone(tel), date_embauche(date), poste(post), salaire(sal)
{
}

// Vérifier si l'ID existe déjà
bool Employe::idExiste(int id) {
    QSqlDatabase db = Connection::instance()->getDatabase();
    if (!db.isOpen()) {
        qDebug() << "❌ Base non ouverte dans idExiste";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) AS total FROM EMPLOYES WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL dans idExiste pour ID =" << id << ":" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value("total").toInt();
        qDebug() << "✅ Vérification ID =" << id << ", COUNT =" << count;
        return count > 0;
    } else {
        qDebug() << "❌ Aucun résultat retourné pour ID =" << id;
        return false;
    }
}


// Ajouter un employé
bool Employe::ajouter() {
    QSqlDatabase db = Connection::instance()->getDatabase();
    if (!db.isOpen()) {
        qDebug() << "❌ Base de données non ouverte dans ajouter !";
        return false;
    }

    // Vérification des champs obligatoires
    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
        qDebug() << "❌ Champs obligatoires (nom, prénom, poste) manquants";
        return false;
    }

    // Générer automatiquement un ID libre
    QSqlQuery query(db);
    if (!query.exec("SELECT MAX(ID_EMPLOYE) FROM EMPLOYES")) {
        qDebug() << "❌ Erreur SQL lors de la récupération du MAX(ID_EMPLOYE) :" << query.lastError().text();
        return false;
    }

    int newId = 1;
    if (query.next()) {
        newId = query.value(0).toInt() + 1;
    }
    qDebug() << "Prochain ID libre généré :" << newId;
    id_employe = newId; // Met à jour l'ID de l'employé courant

    // Préparer l'insertion
    query.prepare(
        "INSERT INTO EMPLOYES "
        "(ID_EMPLOYE, NOM_EMP, PRENOM_EMP, POSTE_EMP, TEL_EMP, DATE_EMBAUCHE_EMP, SALAIRE_EMP) "
        "VALUES (:id, :nom, :prenom, :poste, :telephone, TO_DATE(:date_embauche, 'YYYY-MM-DD'), :salaire)"
        );

    query.bindValue(":id", id_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":telephone", telephone);
    query.bindValue(":date_embauche", date_embauche.toString("yyyy-MM-dd"));
    query.bindValue(":salaire", salaire);

    if (!query.exec()) {
        qDebug() << "❌ Erreur lors de l'insertion pour ID =" << id_employe << ":" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Employé ajouté avec succès, ID =" << id_employe;
    return true;
}


// Modifier un employé
bool Employe::modifier(int ancienId, int nouveauId, QString nom, QString prenom,
                       QString telephone, QDate date_embauche, QString poste, double salaire)
{
    if (!Connection::instance()->createconnect()) {
        qDebug() << "❌ Échec de la connexion à la base de données dans modifier";
        return false;
    }
    QSqlDatabase db = Connection::instance()->getDatabase();
    if (!db.isOpen()) {
        qDebug() << "❌ Base de données non ouverte dans modifier";
        return false;
    }
    // Vérification des champs obligatoires
    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty()) {
        qDebug() << "❌ Champs obligatoires (nom, prénom, poste) manquants pour modifier ID =" << ancienId;
        return false;
    }
    QSqlQuery query(db);
    query.prepare("UPDATE EMPLOYES SET "
                  "ID_EMPLOYE = :nouveauId, "
                  "NOM_EMP = :nom, "
                  "PRENOM_EMP = :prenom, "
                  "TEL_EMP = :telephone, "
                  "DATE_EMBAUCHE_EMP = TO_DATE(:date, 'YYYY-MM-DD'), "
                  "POSTE_EMP = :poste, "
                  "SALAIRE_EMP = :salaire "
                  "WHERE ID_EMPLOYE = :ancienId");
    query.bindValue(":ancienId", ancienId);
    query.bindValue(":nouveauId", nouveauId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":date", date_embauche.toString("yyyy-MM-dd"));
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL dans modifier pour ID =" << ancienId << ":" << query.lastError().text();
        return false;
    }
    qDebug() << "✅ Employé avec ID =" << ancienId << "modifié avec succès (nouveau ID =" << nouveauId << ")";
    return true;
}

// Supprimer un employé
bool Employe::supprimer(int id) {
    if (!Connection::instance()->createconnect()) {
        qDebug() << "❌ Échec de la connexion à la base de données dans supprimer";
        return false;
    }
    QSqlDatabase db = Connection::instance()->getDatabase();
    if (!db.isOpen()) {
        qDebug() << "❌ Base de données non ouverte dans supprimer";
        return false;
    }
    QSqlQuery query(db);
    query.prepare("DELETE FROM EMPLOYES WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL dans supprimer pour ID =" << id << ":" << query.lastError().text();
        return false;
    }
    qDebug() << "✅ Employé avec ID =" << id << "supprimé avec succès";
    return true;
}

// Afficher les employés dans un QTableWidget
void Employe::afficher(QTableWidget* table) {
    if (!Connection::instance()->createconnect()) {
        qDebug() << "❌ Échec de la connexion à la base de données dans afficher";
        return;
    }
    QSqlDatabase db = Connection::instance()->getDatabase();
    if (!db.isOpen()) {
        qDebug() << "❌ Base de données non ouverte dans afficher";
        return;
    }
    table->setRowCount(0);
    QSqlQuery query(db);
    if (!query.exec("SELECT ID_EMPLOYE, NOM_EMP, PRENOM_EMP, TEL_EMP, DATE_EMBAUCHE_EMP, POSTE_EMP, SALAIRE_EMP FROM EMPLOYES")) {
        qDebug() << "❌ Erreur SQL dans afficher :" << query.lastError().text();
        return;
    }
    int row = 0;
    while (query.next()) {
        table->insertRow(row);
        for (int col = 0; col < 7; ++col) {
            table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
    QStringList headers = {"ID", "Nom", "Prénom", "Téléphone", "Date Embauche", "Poste", "Salaire"};
    table->setHorizontalHeaderLabels(headers);
    qDebug() << "✅ " << row << "employés affichés dans le tableau";
}
