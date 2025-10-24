#include "gerevehicule.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include <QTextDocument>
#include <QPrinter>
#include <QTextTable>
#include <QFileDialog>
#include <QTextCursor>
#include <QPageSize>
#include <QDebug>

bool GereVehicule::verifierVehicule(Ui::MainWindow* ui,
                                    const QString& matricule,
                                    const QString& type,
                                    const QString& marque,
                                    const QString& modele,
                                    const QString& annee,
                                    const QDate& date_maintenance)
{
    QWidget* parent = ui->matricule->parentWidget(); // Pour les QMessageBox

    if (matricule.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le matricule est obligatoire!");
        ui->matricule->setFocus();
        return false;
    }

    QString cleanMatricule = matricule.toUpper().remove(" ");

    QRegularExpression matriculeRegex("^(\\d{2,3})TN(\\d{4})$");
    QRegularExpressionMatch match = matriculeRegex.match(cleanMatricule);

    if (!match.hasMatch()) {
        QMessageBox::warning(parent, "Matricule invalide",
                             "Format de matricule tunisien invalide!\n");
        ui->matricule->setFocus();
        return false;
    }

    int serie = match.captured(1).toInt();
    if (serie < 1 || serie > 999) {
        QMessageBox::warning(parent, "Série invalide", "La série doit être entre 1 et 999!");
        ui->matricule->setFocus();
        return false;
    }

    int numero = match.captured(2).toInt();
    if (numero < 1 || numero > 9999) {
        QMessageBox::warning(parent, "Numéro invalide", "Le numéro d'enregistrement doit être entre 1 et 9999!");
        ui->matricule->setFocus();
        return false;
    }

    if (type == "Choisir") {
        QMessageBox::warning(parent, "Type manquant", "Veuillez choisir un type de véhicule!");
        ui->type_v->setFocus();
        return false;
    }

    if (marque.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "La marque est obligatoire!");
        ui->marque_v->setFocus();
        return false;
    }

    if (modele.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le modèle est obligatoire!");
        ui->modele_v->setFocus();
        return false;
    }

    if (annee.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'année est obligatoire!");
        ui->annee_v->setFocus();
        return false;
    }

    QRegularExpression anneeRegex("^\\d{4}$");
    if (!anneeRegex.match(annee).hasMatch()) {
        QMessageBox::warning(parent, "Année invalide", "L'année doit contenir 4 chiffres!");
        ui->annee_v->setFocus();
        return false;
    }

    int anneeInt = annee.toInt();
    if (anneeInt < 2000 || anneeInt > 2025) {
        QMessageBox::warning(parent, "Année invalide",
                             "L'année doit être entre 2000 et 2025!");
        ui->annee_v->setFocus();
        return false;
    }

    if (!ui->bon->isChecked() && !ui->entretien->isChecked() && !ui->panne->isChecked()) {
        QMessageBox::warning(parent, "État manquant", "Veuillez sélectionner un état!");
        return false;
    }

    int kilometrage = ui->kilometrage_v->text().toInt();
    if (kilometrage < 0) {
        QMessageBox::warning(parent, "Kilométrage invalide", "Le kilométrage doit être un nombre positif!");
        ui->kilometrage_v->setFocus();
        return false;
    }

    QDate anneeDate = QDate(anneeInt, 1, 1);
    if (date_maintenance < anneeDate) {
        QMessageBox::warning(parent, "Date incohérente",
                             "La date de maintenance ne peut pas être antérieure à l'année du véhicule!");
        ui->date_maint_v->setFocus();
        return false;
    }

    if (date_maintenance > QDate::currentDate()) {
        QMessageBox::warning(parent, "Date future",
                             "La date de maintenance ne peut pas être dans le futur!");
        ui->date_maint_v->setFocus();
        return false;
    }

    return true;
}

bool GereVehicule::confirmerVehicule(Ui::MainWindow* ui, Vehicule& v, bool& isEditing, QString& currentMatricule)
{
    QWidget* parent = ui->matricule->parentWidget();

    QString matricule = ui->matricule->text();
    QString type = ui->type_v->currentText();
    QString marque = ui->marque_v->text();
    QString modele = ui->modele_v->text();
    QString annee = ui->annee_v->text();
    QDate date_maintenance = ui->date_maint_v->date();

    QString etat;
    if (ui->bon->isChecked()) {
        etat = "Bon";
    } else if (ui->entretien->isChecked()) {
        etat = "Entretien";
    } else if (ui->panne->isChecked()) {
        etat = "En panne";
    }

    int kilometrage = ui->kilometrage_v->text().toInt();

    if (verifierVehicule(ui, matricule, type, marque, modele, annee, date_maintenance)) {
        bool success = false;
        QString message;

        if (isEditing) {
            success = v.modifier(currentMatricule, matricule, type, marque, modele, annee, etat, kilometrage, date_maintenance);
            message = success ? "Véhicule modifié avec succès!" : "Erreur lors de la modification!";
        } else {
            Vehicule temp(matricule, type, marque, modele, annee, etat, kilometrage, date_maintenance);
            success = temp.ajouter();
            message = success ? "Véhicule ajouté avec succès!" : "Erreur lors de l'ajout! Vérifiez le matricule.";
        }

        if (success) {
            QMessageBox::information(parent, "Succès", message);
            v.afficher(ui->table_ajout_v);
            reinitialiserFormulaire(ui);
            isEditing = false;
            currentMatricule.clear();
            return true;
        } else {
            QMessageBox::critical(parent, "Erreur", message);
            return false;
        }
    }
    return false;
}

void GereVehicule::chargerVehiculePourModification(Ui::MainWindow* ui, const QModelIndex& index, bool& isEditing, QString& currentMatricule)
{
    QWidget* parent = ui->matricule->parentWidget();

    int row = index.row();

    QString matricule = ui->table_ajout_v->item(row, 0)->text();
    QString type = ui->table_ajout_v->item(row, 1)->text();
    QString marque = ui->table_ajout_v->item(row, 2)->text();
    QString modele = ui->table_ajout_v->item(row, 3)->text();
    QString annee = ui->table_ajout_v->item(row, 4)->text();
    QString etat = ui->table_ajout_v->item(row, 5)->text();
    QString kilometrage = ui->table_ajout_v->item(row, 6)->text();
    QString date_maintenance = ui->table_ajout_v->item(row, 7)->text();

    currentMatricule = matricule;
    isEditing = true;

    ui->matricule->setText(matricule);

    int typeIndex = ui->type_v->findText(type);
    if (typeIndex != -1) {
        ui->type_v->setCurrentIndex(typeIndex);
    }

    ui->marque_v->setText(marque);
    ui->modele_v->setText(modele);
    ui->annee_v->setText(annee);
    ui->kilometrage_v->setText(kilometrage);

    if (etat == "Bon") {
        ui->bon->setChecked(true);
    } else if (etat == "Entretien") {
        ui->entretien->setChecked(true);
    } else if (etat == "En panne") {
        ui->panne->setChecked(true);
    }

    QDate date = QDate::fromString(date_maintenance, "yyyy-MM-dd");
    if (!date.isValid()) {
        date = QDate::fromString(date_maintenance, "dd/MM/yyyy");
    }
    if (date.isValid()) {
        ui->date_maint_v->setDate(date);
    }

    QMessageBox::information(parent, "Modification",
                             "Véhicule chargé pour modification!\nCliquez sur 'Confirmer' pour sauvegarder.");
}

void GereVehicule::reinitialiserFormulaire(Ui::MainWindow* ui)
{
    ui->matricule->clear();
    ui->type_v->setCurrentIndex(0);
    ui->marque_v->clear();
    ui->modele_v->clear();
    ui->annee_v->clear();
    ui->bon->setChecked(true);
    ui->kilometrage_v->clear();
    ui->date_maint_v->setDate(QDate(2000, 1, 1));
    ui->matricule->setFocus();
}

bool GereVehicule::supprimerVehicule(Ui::MainWindow* ui, Vehicule& v, bool& isEditing, QString& currentMatricule)
{
    QWidget* parent = ui->matricule->parentWidget();

    QModelIndexList selectedIndexes = ui->table_ajout_v->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(parent, "Aucune sélection", "Veuillez sélectionner un véhicule à supprimer dans le tableau!");
        return false;
    }

    int row = selectedIndexes.first().row();
    QString matricule = ui->table_ajout_v->item(row, 0)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(parent, "Confirmation de suppression",
                                  QString("Êtes-vous sûr de vouloir supprimer le véhicule :\n"
                                          "Matricule: %1")
                                      .arg(matricule),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool success = v.supprimer(matricule);

        if (success) {
            QMessageBox::information(parent, "Succès", "Véhicule supprimé avec succès!");
            v.afficher(ui->table_ajout_v);

            if (currentMatricule == matricule) {
                reinitialiserFormulaire(ui);
                isEditing = false;
                currentMatricule.clear();
            }
            return true;
        } else {
            QMessageBox::critical(parent, "Erreur",
                                  "Erreur lors de la suppression du véhicule!\n"
                                  "Vérifiez les contraintes de clé étrangère.");
            return false;
        }
    }
    return false;
}

void GereVehicule::exporterPDF(Ui::MainWindow* ui)
{
    QWidget* parent = ui->matricule->parentWidget();

    QString fileName = QFileDialog::getSaveFileName(parent,
                                                    "Exporter en PDF",
                                                    QDir::homePath() + "/liste_vehicules.pdf",
                                                    "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    QTextDocument document;
    QTextCursor cursor(&document);

    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(16);
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::darkBlue);

    cursor.insertText("Liste des Véhicules - Smart Drive\n", titleFormat);
    cursor.insertText("Date d'exportation: " + QDate::currentDate().toString("dd/MM/yyyy") + "\n\n");

    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorder(1);
    tableFormat.setBorderBrush(Qt::black);
    tableFormat.setCellSpacing(0);
    tableFormat.setCellPadding(4);
    tableFormat.setAlignment(Qt::AlignCenter);

    int rowCount = ui->table_ajout_v->rowCount();
    int columnCount = ui->table_ajout_v->columnCount();

    if (rowCount == 0) {
        QMessageBox::warning(parent, "Exportation", "Aucune donnée à exporter!");
        return;
    }

    QTextTable *table = cursor.insertTable(rowCount + 1, columnCount, tableFormat);

    QTextCharFormat headerFormat;
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setBackground(QColor(200, 200, 200));

    for (int col = 0; col < columnCount; ++col) {
        QTextTableCell headerCell = table->cellAt(0, col);
        QTextCursor headerCursor = headerCell.firstCursorPosition();
        QString headerText = ui->table_ajout_v->horizontalHeaderItem(col)->text();
        headerCursor.insertText(headerText, headerFormat);
    }

    QTextCharFormat cellFormat;
    cellFormat.setFontPointSize(9);

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->table_ajout_v->item(row, col);
            if (item) {
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(item->text(), cellFormat);
            }
        }
    }

    cursor.movePosition(QTextCursor::End);
    cursor.insertText("\n\nTotal des véhicules: " + QString::number(rowCount));

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Portrait);

    document.print(&printer);

    QMessageBox::information(parent, "Exportation réussie",
                             "La liste des véhicules a été exportée avec succès vers:\n" + fileName);
}
