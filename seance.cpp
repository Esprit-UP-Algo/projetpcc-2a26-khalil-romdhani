#include "seance.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>

Seance::Seance()
    : id(0) {}

Seance::Seance(int id, QString type, QDate date, QString debut_h, QString fin_h,
               QString salle, QString circuit_dep, QString longitude,
               QString circuit_dep_latitude, QString circuit_arrive_longitude,
               QString circuit_arrive_latitude, QString cin_moniteur,
               QString matricule_vehicule, QString nom_candidat)
{
    this->id = id;
    this->type = type;
    this->date = date;
    this->debut_h = debut_h;
    this->fin_h = fin_h;
    this->salle = salle;
    this->circuit_dep = circuit_dep;
    this->longitude = longitude;
    this->circuit_dep_latitude = circuit_dep_latitude;
    this->circuit_arrive_longitude = circuit_arrive_longitude;
    this->circuit_arrive_latitude = circuit_arrive_latitude;
    this->cin_moniteur = cin_moniteur;
    this->matricule_vehicule = matricule_vehicule;
    this->nom_candidat = nom_candidat;
}

bool Seance::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SEANCES (ID_SEANCE, TYPE_S, DATE_S, HEURE_DEBUT_S, HEURE_FIN_S, "
                  "SALLE_S, CIRCUIT_DEP_S, LONGITUDE_S, CIRCUIT_DEP_LATITUDE, "
                  "CIRCUIT_ARRIVE_LONGITUDE, CIRCUIT_ARRIVE_LATIUDE, "
                  "MATRICULE, NOM_C) "
                  "VALUES (:id, :type, TO_DATE(:date, 'DD/MM/YYYY'), :debut, :fin, "
                  ":salle, :circuit_dep, :longitude, :circuit_dep_latitude, "
                  ":circuit_arrive_longitude, :circuit_arrive_latitude, "
                  ":matricule, :nom_candidat)");

    QString dateOracle = date.toString("dd/MM/yyyy");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", dateOracle);
    query.bindValue(":debut", debut_h);
    query.bindValue(":fin", fin_h);
    query.bindValue(":salle", salle);
    query.bindValue(":circuit_dep", circuit_dep);
    query.bindValue(":longitude", longitude);
    query.bindValue(":circuit_dep_latitude", circuit_dep_latitude);
    query.bindValue(":circuit_arrive_longitude", circuit_arrive_longitude);
    query.bindValue(":circuit_arrive_latitude", circuit_arrive_latitude);
    query.bindValue(":matricule", matricule_vehicule);
    query.bindValue(":nom_candidat", nom_candidat);

    if (!query.exec()) {
        QString error = query.lastError().text();
        qDebug() << "❌ Erreur ajout séance:" << error;
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Erreur lors de l'ajout de la séance:\n" + error);
        return false;
    }

    qDebug() << "✅ Séance ajoutée avec succès - ID:" << id;
    return true;
}

bool Seance::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE SEANCES SET TYPE_S = :type, DATE_S = TO_DATE(:date, 'DD/MM/YYYY'), "
                  "HEURE_DEBUT_S = :debut, HEURE_FIN_S = :fin, SALLE_S = :salle, "
                  "CIRCUIT_DEP_S = :circuit_dep, LONGITUDE_S = :longitude, "
                  "CIRCUIT_DEP_LATITUDE = :circuit_dep_latitude, "
                  "CIRCUIT_ARRIVE_LONGITUDE = :circuit_arrive_longitude, "
                  "CIRCUIT_ARRIVE_LATIUDE = :circuit_arrive_latitude, "
                  "MATRICULE = :matricule, NOM_C = :nom_candidat "
                  "WHERE ID_SEANCE = :id");
    QString dateOracle = date.toString("dd/MM/yyyy");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", dateOracle);
    query.bindValue(":debut", debut_h);
    query.bindValue(":fin", fin_h);
    query.bindValue(":salle", salle);
    query.bindValue(":circuit_dep", circuit_dep);
    query.bindValue(":longitude", longitude);
    query.bindValue(":circuit_dep_latitude", circuit_dep_latitude);
    query.bindValue(":circuit_arrive_longitude", circuit_arrive_longitude);
    query.bindValue(":circuit_arrive_latitude", circuit_arrive_latitude);
    query.bindValue(":matricule", matricule_vehicule);
    query.bindValue(":nom_candidat", nom_candidat);

    if (!query.exec()) {
        QString error = query.lastError().text();
        qDebug() << "❌ Erreur modification séance:" << error;
        QMessageBox::critical(nullptr, "Erreur de modification", "Erreur lors de la modification de la séance:\n" + error);
        return false;
    }

    bool success = query.numRowsAffected() > 0;
    if (success) {
        qDebug() << "✅ Séance modifiée avec succès - ID:" << id;
    } else {
        QMessageBox::warning(nullptr, "Modification", "Aucune séance trouvée avec cet ID!");
    }
    return success;
}

bool Seance::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SEANCES WHERE ID_SEANCE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QString error = query.lastError().text();
        qDebug() << "❌ Erreur suppression séance:" << error;
        QMessageBox::critical(nullptr, "Erreur de suppression", "Erreur lors de la suppression de la séance:\n" + error);
        return false;
    }

    bool success = query.numRowsAffected() > 0;
    if (success) {
        qDebug() << "✅ Séance supprimée avec succès - ID:" << id;
    } else {
        QMessageBox::warning(nullptr, "Suppression", "Aucune séance trouvée avec cet ID!");
    }
    return success;
}

QSqlQueryModel* Seance::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT ID_SEANCE, TYPE_S, TO_CHAR(DATE_S, 'DD/MM/YYYY'), HEURE_DEBUT_S, HEURE_FIN_S, "
                       "SALLE_S, CIRCUIT_DEP_S, LONGITUDE_S, CIRCUIT_DEP_LATITUDE, "
                       "CIRCUIT_ARRIVE_LONGITUDE, CIRCUIT_ARRIVE_LATIUDE, "
                       "MATRICULE, NOM_C "
                       "FROM SEANCES ORDER BY ID_SEANCE";

    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        QString error = model->lastError().text();
        qDebug() << "❌ Erreur affichage séances:" << error;
        QMessageBox::critical(nullptr, "Erreur d'affichage", "Erreur lors du chargement des séances:\n" + error);
    } else {
        qDebug() << "✅ Affichage des séances -" << model->rowCount() << "lignes trouvées";
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Séance"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Heure fin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salle"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Circuit départ"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Latitude départ"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Longitude arrivée"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Latitude arrivée"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Matricule Véhicule"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Nom Candidat"));

    return model;
}

QSqlQueryModel* Seance::rechercher(QString critere, QString valeur)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryString;

    if (critere == "ID") {
        queryString = "SELECT ID_SEANCE, TYPE_S, TO_CHAR(DATE_S, 'DD/MM/YYYY'), HEURE_DEBUT_S, HEURE_FIN_S, "
                      "SALLE_S, CIRCUIT_DEP_S, LONGITUDE_S, CIRCUIT_DEP_LATITUDE, "
                      "CIRCUIT_ARRIVE_LONGITUDE, CIRCUIT_ARRIVE_LATIUDE, "
                      "MATRICULE, NOM_C "
                      "FROM SEANCES WHERE ID_SEANCE = " + valeur;
    } else if (critere == "Type") {
        queryString = "SELECT ID_SEANCE, TYPE_S, TO_CHAR(DATE_S, 'DD/MM/YYYY'), HEURE_DEBUT_S, HEURE_FIN_S, "
                      "SALLE_S, CIRCUIT_DEP_S, LONGITUDE_S, CIRCUIT_DEP_LATITUDE, "
                      "CIRCUIT_ARRIVE_LONGITUDE, CIRCUIT_ARRIVE_LATIUDE, "
                      "MATRICULE, NOM_C "
                      "FROM SEANCES WHERE UPPER(TYPE_S) LIKE UPPER('%" + valeur + "%')";
    } else if (critere == "Date") {
        queryString = "SELECT ID_SEANCE, TYPE_S, TO_CHAR(DATE_S, 'DD/MM/YYYY'), HEURE_DEBUT_S, HEURE_FIN_S, "
                      "SALLE_S, CIRCUIT_DEP_S, LONGITUDE_S, CIRCUIT_DEP_LATITUDE, "
                      "CIRCUIT_ARRIVE_LONGITUDE, CIRCUIT_ARRIVE_LATIUDE, "
                      "MATRICULE, NOM_C "
                      "FROM SEANCES WHERE TO_CHAR(DATE_S, 'DD/MM/YYYY') LIKE '%" + valeur + "%'";
    } else {
        queryString = "SELECT ID_SEANCE, TYPE_S, TO_CHAR(DATE_S, 'DD/MM/YYYY'), HEURE_DEBUT_S, HEURE_FIN_S, "
                      "SALLE_S, CIRCUIT_DEP_S, LONGITUDE_S, CIRCUIT_DEP_LATITUDE, "
                      "CIRCUIT_ARRIVE_LONGITUDE, CIRCUIT_ARRIVE_LATIUDE, "
                      "MATRICULE, NOM_C "
                      "FROM SEANCES WHERE ID_SEANCE = " + valeur;
    }

    model->setQuery(queryString);

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur recherche:" << model->lastError().text();
    } else {
        qDebug() << "✅ Recherche effectuée -" << model->rowCount() << "résultats";
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Séance"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Heure fin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salle"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Circuit départ"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Latitude départ"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Longitude arrivée"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Latitude arrivée"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Matricule Véhicule"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Nom Candidat"));

    return model;
}

QSqlQueryModel* Seance::trier(QString colonne, QString ordre)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString queryString = "SELECT ID_SEANCE, TYPE_S, TO_CHAR(DATE_S, 'DD/MM/YYYY'), HEURE_DEBUT_S, HEURE_FIN_S, "
                          "SALLE_S, CIRCUIT_DEP_S, LONGITUDE_S, CIRCUIT_DEP_LATITUDE, "
                          "CIRCUIT_ARRIVE_LONGITUDE, CIRCUIT_ARRIVE_LATIUDE, "
                          "MATRICULE, NOM_C FROM SEANCES ";

    if (colonne == "ID_SEANCE" || colonne == "ID") {
        queryString += "ORDER BY ID_SEANCE " + ordre;
    } else if (colonne == "TYPE_S" || colonne == "Type") {
        queryString += "ORDER BY TYPE_S " + ordre;
    } else if (colonne == "DATE_S" || colonne == "Date") {
        queryString += "ORDER BY DATE_S " + ordre;
    } else if (colonne == "HEURE_DEBUT_S" || colonne == "Heure début") {
        queryString += "ORDER BY HEURE_DEBUT_S " + ordre;
    } else if (colonne == "HEURE_FIN_S" || colonne == "Heure fin") {
        queryString += "ORDER BY HEURE_FIN_S " + ordre;
    } else {
        queryString += "ORDER BY ID_SEANCE " + ordre;
    }

    model->setQuery(queryString);

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur tri:" << model->lastError().text();
    } else {
        qDebug() << "✅ Tri effectué -" << model->rowCount() << "lignes";
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Séance"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Heure fin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salle"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Circuit départ"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Latitude départ"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Longitude arrivée"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Latitude arrivée"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Matricule Véhicule"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Nom Candidat"));

    return model;
}

bool Seance::exporterExcel()
{
    QSqlQueryModel* model = afficher();
    if (model->rowCount() == 0) {
        QMessageBox::critical(nullptr, "Erreur Export", "Aucune donnée à exporter ! Le tableau des séances est vide.");
        delete model;
        return false;
    }


    // Utiliser CSV au lieu de Excel
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Exporter les séances", "seances_export.csv", "Fichiers CSV (*.csv)");
    if (fileName.isEmpty()) {
        delete model;
        return false;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible de créer le fichier !");
        delete model;
        return false;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    // En-têtes
    QStringList headers;
    headers << "ID Séance" << "Type" << "Date" << "Heure début" << "Heure fin"
            << "Salle" << "Circuit départ" << "Longitude" << "Latitude départ"
            << "Longitude arrivée" << "Latitude arrivée" << "Matricule Véhicule" << "Nom Candidat";

    // Écrire les en-têtes
    out << headers.join(";") << "\n";

    // Écrire les données
    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList rowData;
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            // Nettoyer les données pour CSV
            data.replace(";", ",").replace("\"", "'");
            rowData << data;
        }
        out << rowData.join(";") << "\n";
    }

    file.close();
    delete model;

    QMessageBox::information(nullptr, "Succès", "Séances exportées avec succès vers le fichier CSV !\nLe fichier peut être ouvert dans Excel.");
    return true;
}
int Seance::compterSeancesParSalle(char salle)
{
    if (salle < '1' || salle > '9') {
        qDebug() << "❌ Salle invalide:" << salle;
        return -1;  // Erreur
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SEANCES WHERE SALLE_S = :salle");
    query.bindValue(":salle", QString(salle));

    if (!query.exec()) {
        qDebug() << "❌ Erreur comptage salle:" << query.lastError().text();
        return -1;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "✅ Séances en salle" << salle << ":" << count;
        return count;
    }

    return 0;  // Aucune séance
}
