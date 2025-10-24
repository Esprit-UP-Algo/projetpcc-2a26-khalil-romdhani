#include "vehicule.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QTableWidgetItem>

Vehicule::Vehicule()
{
}

Vehicule::Vehicule(QString matricule, QString type, QString marque, QString modele,
                   QString annee, QString etat, int kilometrage, QDate date_maintenance)
{
    this->matricule = matricule;
    this->type = type;
    this->marque = marque;
    this->modele = modele;
    this->annee = annee;
    this->etat = etat;
    this->kilometrage = kilometrage;
    this->date_maintenance = date_maintenance;
}

bool Vehicule::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO VEHICULES (MATRICULE, TYPE_V, MARQUE_V, MODELE_V, ANNEE_V, ETAT_V, KILOMETRAGE_V, DATE_MAINT_V) "
                  "VALUES (:matricule, :type, :marque, :modele, :annee, :etat, :kilometrage, :date_maintenance)");

    query.bindValue(":matricule", matricule);
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":modele", modele);
    query.bindValue(":annee", annee);
    query.bindValue(":etat", etat);
    query.bindValue(":kilometrage", kilometrage);
    query.bindValue(":date_maintenance", date_maintenance);

    bool success = query.exec();

    if (!success) {
        qDebug() << "SQL Error:" << query.lastError().text();
        qDebug() << "Executed query:" << query.lastQuery();
        qDebug() << "Values - Matricule:" << matricule << "Type:" << type << "Marque:" << marque;
    }

    return success;
}

void Vehicule::afficher(QTableWidget* table)
{
    table->setRowCount(0);

    QSqlQuery query("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, ANNEE_V, ETAT_V, KILOMETRAGE_V, DATE_MAINT_V FROM VEHICULES");

    int row = 0;
    while (query.next()) {
        table->insertRow(row);

        table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
        table->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));

        row++;
    }

    QStringList headers;
    headers << "Matricule" << "Type" << "Marque" << "Modèle" << "Année" << "État" << "Kilométrage" << "Date Maintenance";
    table->setHorizontalHeaderLabels(headers);
}

bool Vehicule::modifier(QString ancienMatricule, QString nouveauMatricule, QString type, QString marque, QString modele,
                        QString annee, QString etat, int kilometrage, QDate date_maintenance)
{
    QSqlQuery query;

    query.prepare("UPDATE VEHICULES SET MATRICULE=:nouveauMatricule, TYPE_V=:type, MARQUE_V=:marque, MODELE_V=:modele, "
                  "ANNEE_V=:annee, ETAT_V=:etat, KILOMETRAGE_V=:kilometrage, DATE_MAINT_V=:date_maintenance "
                  "WHERE MATRICULE=:ancienMatricule");

    query.bindValue(":ancienMatricule", ancienMatricule);
    query.bindValue(":nouveauMatricule", nouveauMatricule);
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":modele", modele);
    query.bindValue(":annee", annee);
    query.bindValue(":etat", etat);
    query.bindValue(":kilometrage", kilometrage);
    query.bindValue(":date_maintenance", date_maintenance);

    bool success = query.exec();

    if (!success) {
        qDebug() << "SQL Error:" << query.lastError().text();
        qDebug() << "Executed query:" << query.lastQuery();
    }

    return success;
}

bool Vehicule::supprimer(QString matricule)
{
    QSqlQuery query;
    query.prepare("DELETE FROM VEHICULES WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", matricule);

    qDebug() << "Attempting to delete vehicle with matricule:" << matricule;

    bool success = query.exec();

    if (success) {
        qDebug() << "Deletion successful - rows affected:" << query.numRowsAffected();
    } else {
        qDebug() << "SQL Error during deletion:" << query.lastError().text();
        qDebug() << "Executed query:" << query.lastQuery();
        qDebug() << "Bound value:" << matricule;
    }

    return success;
}
