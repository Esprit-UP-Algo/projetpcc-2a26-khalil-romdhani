#include "veh.h"
#include "vehSQL.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QDebug>

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
    sqli = new vehSQL(this);
}

bool veh::verifV(const QString& matricule, const QString& type, const QString& marque,
                 const QString& modele, const QString& etat, const QString& kilometrage,
                 const QDate& dateAchat, const QDate& dateMaint)
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
    if(marque == "Peugeot" && (modele != "208" && modele != "301"))
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre 208 ou 301");
        return false;
    }
    if(marque == "Kia" && modele != "Picanto")
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre Picanto");
        return false;
    }
    if(marque == "Yamaha" && (modele != "R3" && modele != "YBR 125"))
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre R3 ou YBR 125");
        return false;
    }
    if(marque == "Iveco" && modele != "Domino")
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre Domino");
        return false;
    }
    if (marque == "Isuzu" && modele != "Eco Classic")
    {
        QMessageBox::warning(nullptr,"erreur","modele doit etre Eco Classic");
    }
    if(marque == "Volvo" && (modele != "FE" && modele != "FM"))
    {
        QMessageBox::warning(nullptr, "erreur", "modele doit etre FE ou FM");
        return false;
    }
    if(marque == "DAF" && modele !="CF")
    {
        QMessageBox::warning(nullptr,"erreur","modele doit etre CF");
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
    if(type == "Voiture" && (marque != "Peugeot" && marque !="Kia")) {
        return false;
    }
    if(type == "Moto" && marque != "Yamaha") {
        return false;
    }
    if(type == "AutoBus" && (marque != "Iveco" && marque != "Isuzu")) {
        return false;
    }
    if(type == "Camion poids lourd" && (marque != "Volvo" && marque !="DAF")) {
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

void veh::initV(QLineEdit* matricule, QComboBox* type_v, QLineEdit* marque_v,
                QLineEdit* modele_v, QLineEdit* kilometrage_v, QRadioButton* bon,
                QRadioButton* entretien, QRadioButton* panne, QDateEdit* date_achat_v,
                QDateEdit* date_maint_v)
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

void veh::affTab(QTableWidget* table)
{
    this->ui_table_ajout_v = table;
    ui_table_ajout_v->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void veh::refTab()
{
    sqli->refTab(ui_table_ajout_v);
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
        sqli->ConfV(ui_matricule, ui_type_v, ui_marque_v, ui_modele_v, ui_kilometrage_v,
                    ui_bon, ui_entretien, ui_panne, ui_date_achat_v, ui_date_maint_v, currM);
        refTab();
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
        sqli->modifV(ui_matricule, ui_type_v, ui_marque_v, ui_modele_v, ui_kilometrage_v,
                     ui_bon, ui_entretien, ui_panne, ui_date_achat_v, ui_date_maint_v, currM);
        refTab();
    }
}

void veh::tabClick(const QModelIndex &i)
{
    currM = sqli->tabClick(i, ui_matricule, ui_type_v, ui_marque_v, ui_modele_v, ui_kilometrage_v,
                           ui_bon, ui_entretien, ui_panne, ui_date_achat_v, ui_date_maint_v, ui_table_ajout_v);
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

void veh::suppV()
{
    sqli->suppV(currM);
    refTab();
}
