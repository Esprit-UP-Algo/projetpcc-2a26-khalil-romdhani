#include "veh.h"
#include "vehSQL.h"
#include "vehChart.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QVBoxLayout>

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
    ui_filtrer_v = nullptr;
    ui_trier_v = nullptr;
    ui_taper_v = nullptr;
    ui_type_stat = nullptr;  // Initialize
    ui_etat_stat = nullptr;  // Initialize
    currM = "";
    sqli = new vehSQL(this);
}

void veh::initV(QLineEdit* matricule, QComboBox* type_v, QLineEdit* marque_v,
                QLineEdit* modele_v, QLineEdit* kilometrage_v, QRadioButton* bon,
                QRadioButton* entretien, QRadioButton* panne, QDateEdit* date_achat_v,
                QDateEdit* date_maint_v, QGroupBox* type_stat, QGroupBox* etat_stat)  // Updated
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
    this->ui_type_stat = type_stat;  // Store groupbox
    this->ui_etat_stat = etat_stat;  // Store groupbox
}

// ... existing methods ...

void veh::refreshCharts()
{
    if (!ui_type_stat || !ui_etat_stat) return;

    // Remove existing charts from groupboxes
    if (ui_type_stat) {
        QLayout* typeLayout = ui_type_stat->layout();
        if (typeLayout) {
            QLayoutItem* item;
            while ((item = typeLayout->takeAt(0)) != nullptr) {
                if (item->widget()) {
                    item->widget()->deleteLater();
                }
                delete item;
            }
        }
    }

    if (ui_etat_stat) {
        QLayout* etatLayout = ui_etat_stat->layout();
        if (etatLayout) {
            QLayoutItem* item;
            while ((item = etatLayout->takeAt(0)) != nullptr) {
                if (item->widget()) {
                    item->widget()->deleteLater();
                }
                delete item;
            }
        }
    }

    // Create new charts with updated data
    vehChart* chartManager = new vehChart(this);

    QChartView* typeChart = chartManager->createTypeChart();
    QChartView* etatChart = chartManager->createEtatChart();

    // Add new charts to groupboxes
    QLayout* typeLayout = ui_type_stat->layout();
    if(!typeLayout) {
        typeLayout = new QVBoxLayout(ui_type_stat);
    }
    typeLayout->addWidget(typeChart);

    QLayout* etatLayout = ui_etat_stat->layout();
    if(!etatLayout) {
        etatLayout = new QVBoxLayout(ui_etat_stat);
    }
    etatLayout->addWidget(etatChart);
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
        return false;
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


void veh::affTab(QTableWidget* table)
{
    this->ui_table_ajout_v = table;
    ui_table_ajout_v->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void veh::refTab()
{
    if(ui_filtrer_v && ui_filtrer_v->currentText() != "Tous") {
        filtrerV();
        if(ui_trier_v && ui_trier_v->currentText() != "Trier par") {
            trierV();
        }
    } else {
        if(ui_trier_v && ui_trier_v->currentText() != "Trier par") {
            trierV();
        } else {
            sqli->refTab(ui_table_ajout_v);
        }
    }
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

void veh::initFiltrer(QComboBox* filtrer_v)
{
    this->ui_filtrer_v = filtrer_v;
    ui_filtrer_v->clear();
    ui_filtrer_v->addItem("Tous");
    ui_filtrer_v->addItem("Voiture");
    ui_filtrer_v->addItem("Moto");
    ui_filtrer_v->addItem("AutoBus");
    ui_filtrer_v->addItem("Camion poids lourd");
    connect(ui_filtrer_v, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &veh::filtrerV);
}

void veh::filtrerV()
{
    if(!ui_filtrer_v || !ui_table_ajout_v) return;

    QString filtre = ui_filtrer_v->currentText();
    sqli->filtrerTab(ui_table_ajout_v, filtre);
}

void veh::initTrier(QComboBox* trier_v)
{
    this->ui_trier_v = trier_v;
    ui_trier_v->clear();
    ui_trier_v->addItem("Trier par");
    ui_trier_v->addItem("Année croissante");
    ui_trier_v->addItem("Année décroissante");
    ui_trier_v->addItem("Kilométrage croissant");
    ui_trier_v->addItem("Kilométrage décroissant");
    connect(ui_trier_v, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &veh::trierV);
}

void veh::trierV()
{
    if(!ui_trier_v || !ui_table_ajout_v) return;

    QString critere = ui_trier_v->currentText();
    if(critere == "Trier par") {
        refTab();
        return;
    }

    sqli->trierTab(ui_table_ajout_v, critere);
}

void veh::initRech(QLineEdit* taper_v)
{
    this->ui_taper_v = taper_v;
}

void veh::rechV()
{
    if(!ui_taper_v || !ui_table_ajout_v) return;

    QString modele = ui_taper_v->text();
    sqli->rech(ui_table_ajout_v, modele);
}

void veh::expoV()
{
    if(!ui_table_ajout_v || ui_table_ajout_v->rowCount() == 0) {
        QMessageBox::warning(nullptr, "erreur", "aucune donnee a exporter");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(nullptr, "exporter en PDF", "", "PDF Files (*.pdf)");
    if(fileName.isEmpty()) return;

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageOrientation(QPageLayout::Landscape);
    printer.setOutputFileName(fileName);

    QPainter painter;
    painter.begin(&printer);
    QFont font = painter.font();
    font.setPointSize(7);
    painter.setFont(font);
    int colPositions[8] = {30, 80, 130, 180, 230, 280, 330, 380};
    int y = 50;
    QStringList headers = {"Matricule", "Type", "Marque", "Modèle", "Date d'achat", "État", "Km", "Date de révision"};
    for(int col = 0; col < headers.size(); col++) {
        painter.drawText(colPositions[col], y, headers[col]);
    }
    y += 20;
    painter.drawLine(30, y, 400, y);
    y += 15;

    for(int row = 0; row < ui_table_ajout_v->rowCount(); ++row) {
        for(int col = 0; col < ui_table_ajout_v->columnCount(); ++col) {
            QTableWidgetItem* item = ui_table_ajout_v->item(row, col);
            if(item) {
                QString text = item->text();
                if(text.contains("T00:00:00.000")) {
                    text = text.split("T").first();
                }
                painter.drawText(colPositions[col], y, text);
            }
        }
        y += 15;
        if(y > 250) {
            printer.newPage();
            y = 50;
        }
    }
    painter.end();
    QMessageBox::information(nullptr, "succès", "PDF exporte avec succes");
}

