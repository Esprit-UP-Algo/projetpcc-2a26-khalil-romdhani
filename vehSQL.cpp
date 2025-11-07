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

vehSQL::vehSQL(QObject* parent) : QObject(parent)
{
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

void vehSQL::refTab(QTableWidget* ui_table_ajout_v)
{
    if(!ui_table_ajout_v) return;

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "erreur", "connexion a la base de donnees echouee");
        return;
    }

    ui_table_ajout_v->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_table_ajout_v->setRowCount(0);
    QSqlQuery query("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, ANNEE_V, ETAT_V, KILOMETRAGE_V, DATE_MAINT_V FROM VEHICULES");
    int row = 0;
    while(query.next()) {
        ui_table_ajout_v->insertRow(row);
        ui_table_ajout_v->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui_table_ajout_v->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui_table_ajout_v->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui_table_ajout_v->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui_table_ajout_v->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui_table_ajout_v->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        ui_table_ajout_v->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
        ui_table_ajout_v->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
        row++;
    }
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
