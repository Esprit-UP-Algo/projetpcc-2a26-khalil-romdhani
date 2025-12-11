#include "veh_func.h"
#include "connection.h"
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QSqlError>
#include <QHeaderView>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QPrinter>
#include <QFileDialog>
#include <QTextTableFormat>


veh_func::veh_func(QObject* parent) : QObject(parent),
    ui_trier_v(nullptr),
    ui_filtrer_v(nullptr),
    ui_taper_v(nullptr),
    ui_table_v(nullptr)
{
}

void veh_func::initUI(QComboBox* trier_v, QComboBox* filtrer_v, QLineEdit* taper_v, QTableWidget* table_v)
{
    this->ui_trier_v = trier_v;
    this->ui_filtrer_v = filtrer_v;
    this->ui_taper_v = taper_v;
    this->ui_table_v = table_v;

    if(ui_trier_v) {
        ui_trier_v->clear();
        ui_trier_v->addItem("Trier par");
        ui_trier_v->addItem("Kilométrage croissant");
        ui_trier_v->addItem("Kilométrage décroissant");
    }

    if(ui_filtrer_v) {
        ui_filtrer_v->clear();
        ui_filtrer_v->addItem("Filtrer par type");
        ui_filtrer_v->addItem("Voiture");
        ui_filtrer_v->addItem("Moto");
        ui_filtrer_v->addItem("AutoBus");
        ui_filtrer_v->addItem("Camion poids lourd");
    }

    if(ui_table_v) {
        ui_table_v->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui_table_v->setSelectionBehavior(QAbstractItemView::SelectRows);
    }

    refTab();
}

void veh_func::refTab()
{
    if(!ui_table_v) return;

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "Erreur", "Connexion à la base de données échouée");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES");

    ui_table_v->setRowCount(0);
    ui_table_v->setColumnCount(8);
    QStringList headers;
    headers << "Matricule" << "Type" << "Marque" << "Modèle" << "Date d'achat" << "État" << "Kilométrage" << "Date Maintenance";
    ui_table_v->setHorizontalHeaderLabels(headers);

    int row = 0;
    if(query.exec()) {
        while(query.next()) {
            ui_table_v->insertRow(row);
            for(int col = 0; col < 8; col++) {
                QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
                ui_table_v->setItem(row, col, item);
            }
            row++;
        }
        ui_table_v->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Erreur lors du chargement des données: " + query.lastError().text());
    }
}

void veh_func::trierV()
{
    if(!ui_trier_v || !ui_table_v) return;

    QString trier = ui_trier_v->currentText();
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "Erreur", "Connexion à la base de données échouée");
        return;
    }

    QSqlQuery query;

    if(trier == "Kilométrage croissant") {
        query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES ORDER BY KILOMETRAGE_V ASC");
    }
    else if(trier == "Kilométrage décroissant") {
        query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES ORDER BY KILOMETRAGE_V DESC");
    }
    else {
        refTab();
        return;
    }

    if(query.exec()) {
        ui_table_v->setRowCount(0);
        int row = 0;
        while(query.next()) {
            ui_table_v->insertRow(row);
            for(int col = 0; col < 8; col++) {
                QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
                ui_table_v->setItem(row, col, item);
            }
            row++;
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Erreur lors du tri: " + query.lastError().text());
    }
}

void veh_func::filtrerV()
{
    if(!ui_filtrer_v || !ui_table_v) return;

    QString filtrer = ui_filtrer_v->currentText();
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "Erreur", "Connexion à la base de données échouée");
        return;
    }

    QSqlQuery query;

    if(filtrer == "Voiture") {
        query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES WHERE TYPE_V = 'Voiture'");
    }
    else if(filtrer == "Moto") {
        query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES WHERE TYPE_V = 'Moto'");
    }
    else if(filtrer == "AutoBus") {
        query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES WHERE TYPE_V = 'AutoBus'");
    }
    else if(filtrer == "Camion poids lourd") {
        query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES WHERE TYPE_V = 'Camion poids lourd'");
    }
    else {
        refTab();
        return;
    }

    if(query.exec()) {
        ui_table_v->setRowCount(0);
        int row = 0;
        while(query.next()) {
            ui_table_v->insertRow(row);
            for(int col = 0; col < 8; col++) {
                QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
                ui_table_v->setItem(row, col, item);
            }
            row++;
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Erreur lors du filtrage: " + query.lastError().text());
    }
}

void veh_func::rechercherV()
{
    if(!ui_taper_v || !ui_table_v) return;

    QString matricule = ui_taper_v->text().trimmed();
    if(matricule.isEmpty()) {
        refTab();
        return;
    }

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "Erreur", "Connexion à la base de données échouée");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", matricule);

    if(query.exec()) {
        ui_table_v->setRowCount(0);
        int row = 0;
        while(query.next()) {
            ui_table_v->insertRow(row);
            for(int col = 0; col < 8; col++) {
                QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
                ui_table_v->setItem(row, col, item);
            }
            row++;
        }
        if(row == 0) {
            QMessageBox::information(nullptr, "Recherche", "Aucun véhicule trouvé avec ce matricule");
        }
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Erreur lors de la recherche: " + query.lastError().text());
    }
}

void veh_func::exporterPDF()
{
    if(!ui_table_v) return;
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF","vehicules.pdf", "PDF Files (*.pdf)");
    if(filePath.isEmpty()) return;
    QSqlQuery query;
    query.prepare("SELECT MATRICULE, TYPE_V, MARQUE_V, MODELE_V, TO_CHAR(ANNEE_V, 'YYYY-MM-DD'), ETAT_V, KILOMETRAGE_V, TO_CHAR(DATE_MAINT_V, 'YYYY-MM-DD') FROM VEHICULES");
    QTextDocument document;
    QTextCursor cursor(&document);
    cursor.insertText("Liste des Véhicules\n", QTextCharFormat());
    cursor.insertText("Smart Drive - Quantam Team\n\n", QTextCharFormat());
    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setBorder(1);
    tableFormat.setCellSpacing(0);
    tableFormat.setCellPadding(4);
    QTextTable *table = cursor.insertTable(1, 8, tableFormat);
    QStringList headers = {"Matricule", "Type", "Marque", "Modèle", "Année", "État", "Kilométrage", "Date Maintenance"};
    for(int i = 0; i < headers.size(); ++i) {
        QTextTableCell cell = table->cellAt(0, i);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(headers[i]);
    }
    int row = 1;
    while(query.next()) {
        table->appendRows(1);
        for(int col = 0; col < 8; ++col) {
            QTextTableCell cell = table->cellAt(row, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(query.value(col).toString());
        }
        row++;
    }
    cursor.movePosition(QTextCursor::End);
    cursor.insertText(QString("\n\nTotal des véhicules: %1").arg(row-1));
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    document.print(&printer);
}
