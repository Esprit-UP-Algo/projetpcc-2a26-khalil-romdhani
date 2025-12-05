#include "vehSQL.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QLineEdit>
#include <QComboBox>
#include <QRadioButton>
#include <QDateEdit>
#include <QTableWidget>
#include <QHeaderView>

vehSQL::vehSQL(QObject* parent) : QObject(parent)
{
}

void vehSQL::refTab(QTableWidget* ui_table_ajout_v)
{
    if(!ui_table_ajout_v) return;

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "erreur", "connexion a la base de donnees echouee");
        return;
    }

    QSqlQuery query("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES");

    ui_table_ajout_v->setRowCount(0);
    ui_table_ajout_v->setColumnCount(8);
    QStringList headers;
    headers << "Matricule" << "Type" << "Marque" << "Modele" << "Annee" << "Etat" << "Kilometrage" << "Date Maintenance";
    ui_table_ajout_v->setHorizontalHeaderLabels(headers);

    int row = 0;
    while(query.next()) {
        ui_table_ajout_v->insertRow(row);
        for(int col = 0; col < 8; col++) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            ui_table_ajout_v->setItem(row, col, item);
        }
        row++;
    }

    ui_table_ajout_v->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void vehSQL::ConfV(QLineEdit* ui_matricule, QComboBox* ui_type_v, QLineEdit* ui_marque_v,
                   QLineEdit* ui_modele_v, QLineEdit* ui_kilometrage_v, QRadioButton* ui_bon,
                   QRadioButton* ui_entretien, QRadioButton* ui_panne, QDateEdit* ui_date_achat_v,
                   QDateEdit* ui_date_maint_v, QString& currM)
{
    QString matricule = ui_matricule->text();
    QString type = ui_type_v->currentText();
    QString marque = ui_marque_v->text();
    QString modele = ui_modele_v->text();
    QString kilometrage = ui_kilometrage_v->text();
    QDate dateAchat = ui_date_achat_v->date();
    QDate dateMaint = ui_date_maint_v->date();

    bool bon = ui_bon->isChecked();
    bool entretien = ui_entretien->isChecked();
    bool panne = ui_panne->isChecked();
    QString etat;
    if(bon) etat = "Bon";
    else if(entretien) etat = "Entretien";
    else if(panne) etat = "Panne";

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "erreur", "connexion a la base de donnees echouee");
        return;
    }

    if(chercheMat(matricule)) {
        QMessageBox::warning(nullptr, "erreur", "matricule existe deja");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO VEHICULES (MATRICULE, TYPE_V, MARQUE_V, MODELE_V, ANNEE_V, ETAT_V, KILOMETRAGE_V, DATE_MAINT_V) "
                  "VALUES (:matricule, :type, :marque, :modele, TO_DATE(:annee, 'YYYY-MM-DD'), :etat, :kilometrage, TO_DATE(:date_maint, 'YYYY-MM-DD'))");

    query.bindValue(":matricule", matricule);
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":modele", modele);
    query.bindValue(":annee", dateAchat.toString("yyyy-MM-dd"));
    query.bindValue(":etat", etat);
    query.bindValue(":kilometrage", kilometrage.toInt());
    query.bindValue(":date_maint", dateMaint.toString("yyyy-MM-dd"));

    if(query.exec()) {
        QMessageBox::information(nullptr, "success", "vehicule cree avec succes");
        currM = "";
        ui_matricule->clear();
        ui_marque_v->clear();
        ui_modele_v->clear();
        ui_kilometrage_v->clear();
        ui_type_v->setCurrentText("Choisir");
        ui_bon->setChecked(false);
        ui_entretien->setChecked(false);
        ui_panne->setChecked(false);
        ui_date_achat_v->setDate(QDate(2000, 1, 1));
        ui_date_maint_v->setDate(QDate(2000, 1, 1));
    } else {
        QMessageBox::warning(nullptr, "erreur", "erreur lors de l'insertion: " + query.lastError().text());
    }
}

void vehSQL::modifV(QLineEdit* ui_matricule, QComboBox* ui_type_v, QLineEdit* ui_marque_v,
                    QLineEdit* ui_modele_v, QLineEdit* ui_kilometrage_v, QRadioButton* ui_bon,
                    QRadioButton* ui_entretien, QRadioButton* ui_panne, QDateEdit* ui_date_achat_v,
                    QDateEdit* ui_date_maint_v, QString& currM)
{
    QString type = ui_type_v->currentText();
    QString marque = ui_marque_v->text();
    QString modele = ui_modele_v->text();
    QString kilometrage = ui_kilometrage_v->text();
    QDate dateAchat = ui_date_achat_v->date();
    QDate dateMaint = ui_date_maint_v->date();

    QString nouvMat = ui_matricule->text();

    bool bon = ui_bon->isChecked();
    bool entretien = ui_entretien->isChecked();
    bool panne = ui_panne->isChecked();
    QString etat;
    if(bon) etat = "Bon";
    else if(entretien) etat = "Entretien";
    else if(panne) etat = "Panne";

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "erreur", "connexion a la base de donnees echouee");
        return;
    }

    if(nouvMat != currM)
    {
        QMessageBox::warning(nullptr,"erreur","matricule ne peut pas etre modifiee");
        return;
    }
    QSqlQuery query;
    query.prepare("UPDATE VEHICULES SET TYPE_V = :type, MARQUE_V = :marque, "
                  "MODELE_V = :modele, ANNEE_V = TO_DATE(:annee, 'YYYY-MM-DD'), ETAT_V = :etat, "
                  "KILOMETRAGE_V = :kilometrage, DATE_MAINT_V = TO_DATE(:date_maint, 'YYYY-MM-DD') "
                  "WHERE MATRICULE = :matricule");

    query.bindValue(":matricule", currM);
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":modele", modele);
    query.bindValue(":annee", dateAchat.toString("yyyy-MM-dd"));
    query.bindValue(":etat", etat);
    query.bindValue(":kilometrage", kilometrage.toInt());
    query.bindValue(":date_maint", dateMaint.toString("yyyy-MM-dd"));

    if(query.exec()) {
        QMessageBox::information(nullptr, "success", "vehicule modifie avec succes");
        currM = "";
        ui_matricule->clear();
        ui_marque_v->clear();
        ui_modele_v->clear();
        ui_kilometrage_v->clear();
        ui_type_v->setCurrentText("Choisir");
        ui_bon->setChecked(false);
        ui_entretien->setChecked(false);
        ui_panne->setChecked(false);
        ui_date_achat_v->setDate(QDate(2000, 1, 1));
        ui_date_maint_v->setDate(QDate(2000, 1, 1));
    } else {
        QMessageBox::warning(nullptr, "erreur", "erreur lors de la modification: " + query.lastError().text());
    }
}

void vehSQL::suppV(QString& currM)
{
    if(currM.isEmpty()) {
        QMessageBox::warning(nullptr, "erreur", "selectionnez un vehicule a supprimer");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "confirmation",
                                  "voulez-vous supprimer " + currM + "?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Connection* conn = Connection::instance();
        if(!conn->createconnect()) {
            QMessageBox::warning(nullptr, "erreur", "connexion a la base de donnees echouee");
            return;
        }

        QSqlQuery query;
        query.prepare("DELETE FROM VEHICULES WHERE MATRICULE = :matricule");
        query.bindValue(":matricule", currM);

        if(query.exec()) {
            QMessageBox::information(nullptr, "suppresion", "vehicule supprime");
            currM = "";
        } else {
            QMessageBox::warning(nullptr, "erreur", "erreur lors de la suppression: " + query.lastError().text());
        }
    }
}

QString vehSQL::tabClick(const QModelIndex &index, QLineEdit* ui_matricule, QComboBox* ui_type_v,
                         QLineEdit* ui_marque_v, QLineEdit* ui_modele_v, QLineEdit* ui_kilometrage_v,
                         QRadioButton* ui_bon, QRadioButton* ui_entretien, QRadioButton* ui_panne,
                         QDateEdit* ui_date_achat_v, QDateEdit* ui_date_maint_v, QTableWidget* table)
{
    if(!table) {
        return "";
    }

    int row = index.row();
    if(row < 0 || row >= table->rowCount()) {
        return "";
    }

    QTableWidgetItem* item = table->item(row, 0);
    if(!item) {
        return "";
    }

    QString matricule = item->text();
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "erreur", "connexion a la base de donnees echouee");
        return "";
    }

    QSqlQuery query;
    query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, ANNEE_V, ETAT_V, KILOMETRAGE_V, DATE_MAINT_V FROM VEHICULES WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", matricule);
    if(query.exec() && query.next()) {
        ui_matricule->setText(query.value(0).toString());
        ui_type_v->setCurrentText(query.value(1).toString());
        ui_marque_v->setText(query.value(2).toString());
        ui_modele_v->setText(query.value(3).toString());
        QDate dateAchat = query.value(4).toDate();
        ui_date_achat_v->setDate(dateAchat);
        QString etat = query.value(5).toString();
        ui_bon->setChecked(etat == "Bon");
        ui_entretien->setChecked(etat == "Entretien");
        ui_panne->setChecked(etat == "Panne");
        ui_kilometrage_v->setText(query.value(6).toString());
        QDate dateMaint = query.value(7).toDate();
        ui_date_maint_v->setDate(dateMaint);
    }

    return matricule;
}

bool vehSQL::chercheMat(const QString& matricule, const QString& suppMat)
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        return false;
    }

    QSqlQuery checkQuery;
    if(suppMat.isEmpty()) {
        checkQuery.prepare("SELECT COUNT(*) FROM VEHICULES WHERE MATRICULE = :matricule");
        checkQuery.bindValue(":matricule", matricule);
    } else {
        checkQuery.prepare("SELECT COUNT(*) FROM VEHICULES WHERE MATRICULE = :matricule AND MATRICULE != :old_matricule");
        checkQuery.bindValue(":matricule", matricule);
        checkQuery.bindValue(":old_matricule", suppMat);
    }

    if(checkQuery.exec() && checkQuery.next()) {
        return checkQuery.value(0).toInt() > 0;
    }
    return false;
}

int vehSQL::recBonnb()
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VEHICULES WHERE ETAT_V = 'Bon'");
    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int vehSQL::recEntrenb()
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VEHICULES WHERE ETAT_V = 'Entretien'");
    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int vehSQL::recPannenb()
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VEHICULES WHERE ETAT_V = 'Panne'");
    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int vehSQL::recVoiturenb()
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VEHICULES WHERE TYPE_V = 'Voiture'");
    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int vehSQL::recMotonb()
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VEHICULES WHERE TYPE_V = 'Moto'");
    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int vehSQL::recBusnb()
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VEHICULES WHERE TYPE_V = 'AutoBus'");
    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

int vehSQL::recCamionnb()
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM VEHICULES WHERE TYPE_V = 'Camion poids lourd'");
    if(query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

QMap<QString, QVariant> vehSQL::fetchVehicleForCarteGrise(const QString& matricule)
{
    QMap<QString, QVariant> vehicleData;

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        return vehicleData;
    }

    QSqlQuery query;
    query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, ANNEE_V FROM VEHICULES WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", matricule);

    if(query.exec() && query.next()) {
        vehicleData["matricule"] = query.value(0).toString();
        vehicleData["type"] = query.value(1).toString();
        vehicleData["marque"] = query.value(2).toString();
        vehicleData["modele"] = query.value(3).toString();
        vehicleData["date_achat"] = query.value(4).toDate();
    }

    return vehicleData;
}



//teb3a seance
QSqlQueryModel* vehSQL::getVehiculesDisponibles()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT MATRICULE, MARQUE_V || ' ' || MODELE_V as VEHICULE FROM VEHICULES WHERE UPPER(TRIM(ETAT_V)) = 'BON' ORDER BY MARQUE_V, MODELE_V");

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur récupération véhicules disponibles:" << model->lastError().text();
    } else {
        qDebug() << "✅ Véhicules disponibles trouvés:" << model->rowCount();
    }

    return model;
}

// ✅ Récupérer les véhicules disponibles pour une date/heure spécifique (exclut ceux déjà utilisés)
QSqlQueryModel* vehSQL::getVehiculesDisponibles(const QDate& date, const QString& heureDebut, const QString& heureFin, int idSeanceExclue)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString dateStr = date.toString("dd/MM/yyyy");

    QString queryStr = "SELECT MATRICULE, MARQUE_V || ' ' || MODELE_V as VEHICULE "
                       "FROM VEHICULES v "
                       "WHERE UPPER(TRIM(v.ETAT_V)) = 'BON' "
                       "AND v.MATRICULE NOT IN ("
                       "    SELECT s.MATRICULE "
                       "    FROM SEANCES s "
                       "    WHERE TO_CHAR(s.DATE_S, 'DD/MM/YYYY') = :date "
                       "    AND s.ID_SEANCE != :idExclu "
                       "    AND s.MATRICULE IS NOT NULL "
                       "    AND ("
                       "        (:debut < s.HEURE_FIN_S AND :fin > s.HEURE_DEBUT_S)"
                       "    )"
                       ") "
                       "ORDER BY MARQUE_V, MODELE_V";

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":date", dateStr);
    query.bindValue(":debut", heureDebut);
    query.bindValue(":fin", heureFin);
    query.bindValue(":idExclu", idSeanceExclue);

    if (!query.exec()) {
        qDebug() << "❌ Erreur récupération véhicules disponibles (avec filtre):" << query.lastError().text();
        // En cas d'erreur, retourner la version simple
        return getVehiculesDisponibles();
    }

    model->setQuery(std::move(query));

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur récupération véhicules disponibles:" << model->lastError().text();
    }

    return model;
}
