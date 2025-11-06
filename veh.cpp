#include "veh.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QModelIndex>

veh::veh()
{
    ui_matricule = nullptr;
    ui_type_v = nullptr;
    ui_marque_v = nullptr;
    ui_modele_v = nullptr;
    ui_kilometrage_v = nullptr;
    ui_bon = nullptr;
    ui_entretien = nullptr;
    ui_panne = nullptr;
    ui_date_achat_v = nullptr;
    ui_date_maint_v = nullptr;
    ui_table_ajout_v = nullptr;
    currM = "";
}

void veh::initV(QLineEdit* matricule, QComboBox* type_v, QLineEdit* marque_v,QLineEdit* modele_v, QLineEdit* kilometrage_v, QRadioButton* bon,QRadioButton* entretien, QRadioButton* panne, QDateEdit* date_achat_v,QDateEdit* date_maint_v)
{
    this->ui_matricule = matricule;
    this->ui_type_v = type_v;
    this->ui_marque_v = marque_v;
    this->ui_modele_v = modele_v;
    this->ui_kilometrage_v = kilometrage_v;
    this->ui_bon = bon;
    this->ui_entretien = entretien;
    this->ui_panne = panne;
    this->ui_date_achat_v = date_achat_v;
    this->ui_date_maint_v = date_maint_v;
}

bool veh::verifV(const QString& matricule, const QString& type, const QString& marque,const QString& modele, const QString& etat,const QString& kilometrage, const QDate& dateAchat, const QDate& dateMaint)
{
    if(!verifMat(matricule))
    {
        QMessageBox::warning(nullptr, "erreur", "verifier matricule");
        return false;
    }
    if(type == "Choisir")
    {
        QMessageBox::warning(nullptr, "erreur", "choisir type");
        return false;
    }
    if(!verifMarq(type, marque))
    {
        QMessageBox::warning(nullptr, "erreur", "verifier marque");
        return false;
    }
    if(marque == "Peugeot" && modele != "208")
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre 208");
        return false;
    }
    if(marque == "Yamaha" && modele != "R3")
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre R3");
        return false;
    }
    if(marque == "Iveco" && modele != "Domino")
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre Domino");
        return false;
    }
    if(marque == "Volvo" && modele != "FE")
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre FE");
        return false;
    }
    if(!verifDate(dateAchat, dateMaint))
    {
        QMessageBox::warning(nullptr, "erreur", "verifier date");
        return false;
    }
    if(etat.isEmpty())
    {
        QMessageBox::warning(nullptr, "erreur", "choisir etat");
        return false;
    }
    if(!verifKm(kilometrage))
    {
        QMessageBox::warning(nullptr, "erreur", "verifier kilometrage");
        return false;
    }
    return true;
}

bool veh::verifMat(const QString& mat)
{
    if(mat.isEmpty())
        return false;
    static QRegularExpression pattern("^\\d{4}\\s*[Tt][Nn]\\s*\\d{2}$");
    QRegularExpressionMatch match = pattern.match(mat);
    if(!match.hasMatch())
        return false;
    return true;
}

bool veh::verifMarq(const QString& type, const QString& marque)
{
    if(type == "Voiture" && marque != "Peugeot") {
        return false;
    }
    if(type == "Moto" && marque != "Yamaha") {
        return false;
    }
    if(type == "AutoBus" && marque != "Iveco") {
        return false;
    }
    if(type == "Camion poids lourd" && marque != "Volvo") {
        return false;
    }
    return true;
}

bool veh::verifDate(const QDate& dateAchat, const QDate& dateMaint)
{
    if(dateAchat <= QDate(2015,1,1) || dateAchat > QDate::currentDate())
        return false;
    if(dateMaint < dateAchat)
        return false;
    return true;
}

bool veh::verifKm(const QString& km)
{
    if(km.isEmpty())
        return false;
    static QRegularExpression digit("^\\d+$");
    if(!digit.match(km).hasMatch())
        return false;
    if(km.length()>7)
        return false;
    int k = km.toInt();
    if(k<0)
        return false;
    return true;
}

void veh::ConfV()
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
    else etat = "";

    if(verifV(matricule, type, marque, modele, etat, kilometrage, dateAchat, dateMaint))
    {
        QSqlQuery query;
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM VEHICULES WHERE MATRICULE = :matricule");
        checkQuery.bindValue(":matricule", matricule);
        if(checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
            QMessageBox::warning(nullptr, "erreur", "matricule existe deja");
            return;
        }

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
            reinitV();
            refTab();
        }
    }
}

void veh::modifV()
{
    if(currM.isEmpty()) {
        QMessageBox::warning(nullptr, "erreur", "selectionner un vehicule a modifier");
        return;
    }

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
    else etat = "";

    if(verifV(matricule, type, marque, modele, etat, kilometrage, dateAchat, dateMaint))
    {
        if(matricule != currM) {
            QSqlQuery checkQuery;
            checkQuery.prepare("SELECT COUNT(*) FROM VEHICULES WHERE MATRICULE = :matricule AND MATRICULE != :old_matricule");
            checkQuery.bindValue(":matricule", matricule);
            checkQuery.bindValue(":old_matricule", currM);
            if(checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
                QMessageBox::warning(nullptr, "erreur", "matricule existe deja");
                return;
            }
        }

        QSqlQuery query;
        query.prepare("UPDATE VEHICULES SET MATRICULE = :new_matricule, TYPE_V = :type, MARQUE_V = :marque, "
                      "MODELE_V = :modele, ANNEE_V = TO_DATE(:annee, 'YYYY-MM-DD'), ETAT_V = :etat, "
                      "KILOMETRAGE_V = :kilometrage, DATE_MAINT_V = TO_DATE(:date_maint, 'YYYY-MM-DD') "
                      "WHERE MATRICULE = :old_matricule");

        query.bindValue(":old_matricule", currM);
        query.bindValue(":new_matricule", matricule);
        query.bindValue(":type", type);
        query.bindValue(":marque", marque);
        query.bindValue(":modele", modele);
        query.bindValue(":annee", dateAchat.toString("yyyy-MM-dd"));
        query.bindValue(":etat", etat);
        query.bindValue(":kilometrage", kilometrage.toInt());
        query.bindValue(":date_maint", dateMaint.toString("yyyy-MM-dd"));

        if(query.exec()) {
            QMessageBox::information(nullptr, "success", "vehicule modifie avec succes");
            refTab();
            currM = "";
            reinitV();
        }
    }
}

void veh::tabClick(const QModelIndex &index)
{
    int row = index.row();
    QString matricule = ui_table_ajout_v->item(row, 0)->text();
    currM = matricule;
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
}
void veh::reinitV()
{
    if(ui_matricule) ui_matricule->clear();
    if(ui_marque_v) ui_marque_v->clear();
    if(ui_modele_v) ui_modele_v->clear();
    if(ui_kilometrage_v) ui_kilometrage_v->clear();
    if(ui_type_v) ui_type_v->setCurrentText("Choisir");
    if(ui_bon) ui_bon->setChecked(false);
    if(ui_entretien) ui_entretien->setChecked(false);
    if(ui_panne) ui_panne->setChecked(false);
    if(ui_date_achat_v) ui_date_achat_v->setDate(QDate(2000, 1, 1));
    if(ui_date_maint_v) ui_date_maint_v->setDate(QDate(2000, 1, 1));
    currM = "";
}
void veh::affTab(QTableWidget* table)
{
    this->ui_table_ajout_v = table;
    ui_table_ajout_v->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void veh::refTab()
{
    if(!ui_table_ajout_v) return;
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
void veh::suppV()
{
    if(currM.isEmpty()) {
        QMessageBox::warning(nullptr, "erreur", "selectionnez un vehicule a supprimer");
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "confirmation",
                                  "voulez-vous supprimer" + currM + "?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM VEHICULES WHERE MATRICULE = :matricule");
        query.bindValue(":matricule", currM);

        if(query.exec()) {
            QMessageBox::information(nullptr, "suppresion", "vehicule supprime");
            refTab();
            currM = "";
            reinitV();
        }
    }
}
