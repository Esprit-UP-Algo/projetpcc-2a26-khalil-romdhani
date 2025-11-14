#include "GereCandidat.h"
#include "ui_mainwindow.h"
#include "Candidat.h"
#include <QCheckBox>
#include <QComboBox>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFileDialog>
#include <QDesktopServices>

bool GereCandidat::verifierCandidat(Ui::MainWindow* ui)
{
    QWidget* parent = ui->id_c->parentWidget();

    if (ui->id_c->text().isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'ID candidat est obligatoire!");
        ui->id_c->setFocus();
        return false;
    }

    bool ok;
    int id = ui->id_c->text().toInt(&ok);
    if (!ok || id < 1000 || id > 9999) {
        QMessageBox::warning(parent, "ID invalide", "L'ID candidat doit être un nombre entre 1000 et 9999!");
        ui->id_c->setFocus();
        return false;
    }

    QString nom = ui->nom_c->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le nom est obligatoire!");
        ui->nom_c->setFocus();
        return false;
    }

    if (nom.length() > 20) {
        QMessageBox::warning(parent, "Nom trop long", "Le nom ne peut pas dépasser 20 caractères!");
        ui->nom_c->setFocus();
        return false;
    }

    QRegularExpression nomRegex("^[a-zA-ZÀ-ÿ\\s\\-']+$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(parent, "Nom invalide", "Le nom ne peut contenir que des lettres, espaces et traits d'union!");
        ui->nom_c->setFocus();
        return false;
    }

    QString prenom = ui->prenom_c->text().trimmed();
    if (prenom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le prénom est obligatoire!");
        ui->prenom_c->setFocus();
        return false;
    }

    if (prenom.length() > 20) {
        QMessageBox::warning(parent, "Prénom trop long", "Le prénom ne peut pas dépasser 20 caractères!");
        ui->prenom_c->setFocus();
        return false;
    }

    if (!nomRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(parent, "Prénom invalide", "Le prénom ne peut contenir que des lettres, espaces et traits d'union!");
        ui->prenom_c->setFocus();
        return false;
    }

    QDate dateNaissance = ui->dateN_c->date();
    QDate aujourdhui = QDate::currentDate();
    int age = dateNaissance.daysTo(aujourdhui) / 365;

    if (age < 18) {
        QMessageBox::warning(parent, "Âge insuffisant", "Le candidat doit avoir au moins 18 ans!");
        ui->dateN_c->setFocus();
        return false;
    }

    QString adresse = ui->adr_c->text().trimmed();
    if (adresse.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'adresse est obligatoire!");
        ui->adr_c->setFocus();
        return false;
    }

    if (adresse.length() > 50) {
        QMessageBox::warning(parent, "Adresse trop longue", "L'adresse ne peut pas dépasser 50 caractères!");
        ui->adr_c->setFocus();
        return false;
    }

    QString telephone = ui->tel_c->text().trimmed();
    if (telephone.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le téléphone est obligatoire!");
        ui->tel_c->setFocus();
        return false;
    }

    QRegularExpression telRegex("^[259]\\d{7}$");
    if (!telRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(parent, "Téléphone invalide", "Le téléphone doit avoir 8 chiffres et commencer par 2, 5 ou 9!");
        ui->tel_c->setFocus();
        return false;
    }

    QString email = ui->email_c->text().trimmed();
    if (email.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'email est obligatoire!");
        ui->email_c->setFocus();
        return false;
    }

    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(parent, "Email invalide", "Veuillez saisir une adresse email valide!");
        ui->email_c->setFocus();
        return false;
    }

    if (ui->nvpermis_c->currentText() == "Choisir") {
        QMessageBox::warning(parent, "Niveau manquant", "Veuillez choisir un niveau de permis!");
        ui->nvpermis_c->setFocus();
        return false;
    }

    bool codeChecked = ui->code_c->isChecked();
    bool parcChecked = ui->parc_c->isChecked();
    bool conduiteChecked = ui->conduite_c->isChecked();

    if (conduiteChecked && !codeChecked) {
        QMessageBox::warning(parent, "Progression invalide", "La conduite ne peut être sélectionnée sans le code!");
        return false;
    }

    if (parcChecked && (!codeChecked || !conduiteChecked)) {
        QMessageBox::warning(parent, "Progression invalide", "Le Parc ne peut être sélectionné sans le code et la conduite!");
        return false;
    }

    return true;
}

bool GereCandidat::ajouterCandidat(Ui::MainWindow* ui)
{
    if (!verifierCandidat(ui)) {
        return false;
    }

    int id = ui->id_c->text().toInt();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QDate dateNaissance = ui->dateN_c->date();
    QString adresse = ui->adr_c->text().trimmed();
    QString telephone = ui->tel_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString nvPermis = ui->nvpermis_c->currentText();
    nvPermis = nvPermis.left(1);

    QString progression;
    bool codeChecked = ui->code_c->isChecked();
    bool parcChecked = ui->parc_c->isChecked();
    bool conduiteChecked = ui->conduite_c->isChecked();

    if (parcChecked) {
        progression = "Parc";
    } else if (conduiteChecked) {
        progression = "Conduite";
    } else if (codeChecked) {
        progression = "Code";
    } else {
        progression = "Début";
    }

    Candidat candidat(id, nom, prenom, dateNaissance, adresse, telephone, email, nvPermis, progression);
    bool success = candidat.ajouter();

    if (success) {
        QMessageBox::information(ui->id_c->parentWidget(), "Succès", "Candidat ajouté avec succès!");

        Candidat temp;
        temp.afficher(ui->table_candidat);

        return true;
    } else {
        QMessageBox::critical(ui->id_c->parentWidget(), "Erreur", "Erreur lors de l'ajout du candidat! Vérifiez que l'ID n'existe pas déjà dans la base de données.");
        return false;
    }
}

bool GereCandidat::modifierCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId)
{
    if (!isEditing) {
        QMessageBox::warning(ui->id_c->parentWidget(), "Modification", "Aucun candidat sélectionné pour modification!");
        return false;
    }

    if (!verifierCandidat(ui)) {
        return false;
    }

    int nouveauId = ui->id_c->text().toInt();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QDate dateNaissance = ui->dateN_c->date();
    QString adresse = ui->adr_c->text().trimmed();
    QString telephone = ui->tel_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString nvPermis = ui->nvpermis_c->currentText();
    nvPermis = nvPermis.left(1);

    QString progression;
    bool codeChecked = ui->code_c->isChecked();
    bool parcChecked = ui->parc_c->isChecked();
    bool conduiteChecked = ui->conduite_c->isChecked();

    if (parcChecked) {
        progression = "Parc";
    } else if (conduiteChecked) {
        progression = "Conduite";
    } else if (codeChecked) {
        progression = "Code";
    } else {
        progression = "Début";
    }

    bool success = c.modifier(currentId, nouveauId, nom, prenom, dateNaissance, adresse, telephone, email, nvPermis, progression);

    if (success) {
        QMessageBox::information(ui->id_c->parentWidget(), "Succès", "Candidat modifié avec succès!");

        c.afficher(ui->table_candidat);
        isEditing = false;
        currentId = 0;

        return true;
    } else {
        QMessageBox::critical(ui->id_c->parentWidget(), "Erreur", "Erreur lors de la modification du candidat!");
        return false;
    }
}

void GereCandidat::chargerCandidatPourModification(Ui::MainWindow* ui, const QModelIndex &index, bool& isEditing, int& currentId)
{
    QWidget* parent = ui->id_c->parentWidget();

    int row = index.row();

    QString id = ui->table_candidat->item(row, 0)->text();
    QString nom = ui->table_candidat->item(row, 1)->text();
    QString prenom = ui->table_candidat->item(row, 2)->text();
    QString dateNaissance = ui->table_candidat->item(row, 3)->text();
    QString adresse = ui->table_candidat->item(row, 4)->text();
    QString telephone = ui->table_candidat->item(row, 5)->text();
    QString email = ui->table_candidat->item(row, 6)->text();
    QString nvPermis = ui->table_candidat->item(row, 7)->text();
    QString progression = ui->table_candidat->item(row, 8)->text();

    currentId = id.toInt();
    isEditing = true;

    ui->id_c->setText(id);
    ui->nom_c->setText(nom);
    ui->prenom_c->setText(prenom);

    QDate date = QDate::fromString(dateNaissance, "dd/MM/yyyy");
    if (date.isValid()) {
        ui->dateN_c->setDate(date);
    }

    ui->adr_c->setText(adresse);
    ui->tel_c->setText(telephone);
    ui->email_c->setText(email);

    int permisIndex = ui->nvpermis_c->findText(nvPermis, Qt::MatchContains);
    if (permisIndex != -1) {
        ui->nvpermis_c->setCurrentIndex(permisIndex);
    }

    ui->code_c->setChecked(false);
    ui->parc_c->setChecked(false);
    ui->conduite_c->setChecked(false);

    if (progression == "Code") {
        ui->code_c->setChecked(true);
    } else if (progression == "Conduite") {
        ui->code_c->setChecked(true);
        ui->conduite_c->setChecked(true);
    } else if (progression == "Parc") {
        ui->code_c->setChecked(true);
        ui->conduite_c->setChecked(true);
        ui->parc_c->setChecked(true);
    }

    QMessageBox::information(parent, "Modification", "Candidat chargé pour modification!\nCliquez sur 'Modifier' pour sauvegarder.");
}
bool GereCandidat::supprimerCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId)
{
    QWidget* parent = ui->id_c->parentWidget();

    QModelIndexList selectedIndexes = ui->table_candidat->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(parent, "Aucune sélection", "Veuillez sélectionner un candidat à supprimer dans le tableau!");
        return false;
    }

    int row = selectedIndexes.first().row();
    QString id = ui->table_candidat->item(row, 0)->text();
    QString nom = ui->table_candidat->item(row, 1)->text();
    QString prenom = ui->table_candidat->item(row, 2)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(parent, "Confirmation de suppression",
                                  QString("Êtes-vous sûr de vouloir supprimer le candidat :\n"
                                          "ID: %1\n"
                                          "Nom: %2 %3")
                                      .arg(id, nom, prenom),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool success = c.supprimer(id.toInt());

        if (success) {
            QMessageBox::information(parent, "Succès", "Candidat supprimé avec succès!");
            c.afficher(ui->table_candidat);

            // If we were editing the deleted candidate, reset the form
            if (currentId == id.toInt()) {
                // Clear the form
                ui->id_c->clear();
                ui->nom_c->clear();
                ui->prenom_c->clear();
                ui->dateN_c->setDate(QDate(2000, 1, 1));
                ui->adr_c->clear();
                ui->tel_c->clear();
                ui->email_c->clear();
                ui->nvpermis_c->setCurrentIndex(0);
                ui->code_c->setChecked(false);
                ui->conduite_c->setChecked(false);
                ui->parc_c->setChecked(false);

                isEditing = false;
                currentId = 0;
            }
            return true;
        } else {
            QMessageBox::critical(parent, "Erreur",
                                  "Erreur lors de la suppression du candidat!\n"
                                  "Vérifiez les contraintes de clé étrangère.");
            return false;
        }
    }
    return false;
}

void GereCandidat::exporterExcel(Ui::MainWindow* ui)
{
    QWidget* parent = ui->id_c->parentWidget();

    if (ui->table_candidat->rowCount() == 0) {
        QMessageBox::warning(parent, "Exportation", "Aucune donnée à exporter!");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(parent,
                                                    "Exporter vers Excel",
                                                    QDir::homePath() + "/liste_candidats.csv",
                                                    "Fichiers CSV (*.csv)");

    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.endsWith(".csv", Qt::CaseInsensitive)) {
        fileName += ".csv";
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(parent, "Erreur", "Impossible de créer le fichier!");
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::System); // Use system encoding

    QStringList headers;
    for (int col = 0; col < ui->table_candidat->columnCount(); ++col) {
        headers << "\"" + ui->table_candidat->horizontalHeaderItem(col)->text() + "\"";
    }
    out << headers.join(";") << "\n";

    for (int row = 0; row < ui->table_candidat->rowCount(); ++row) {
        QStringList rowData;
        for (int col = 0; col < ui->table_candidat->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table_candidat->item(row, col);
            QString text = item ? item->text() : "";
            // Escape quotes and wrap in quotes
            text.replace("\"", "\"\"");
            rowData << "\"" + text + "\"";
        }
        out << rowData.join(";") << "\n";
    }

    file.close();

    QMessageBox::information(parent, "Exportation réussie",
                             "La liste des candidats a été exportée avec succès vers:\n" + fileName);

    QMessageBox::StandardButton openFile = QMessageBox::question(parent, "Ouvrir le fichier",
                                                                 "Voulez-vous ouvrir le fichier maintenant?",
                                                                 QMessageBox::Yes | QMessageBox::No);
    if (openFile == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    }
}


void GereCandidat::filtreC(Ui::MainWindow* ui, const QString &filterText)
{
    if (filterText == "Filtrer") {
        for (int row = 0; row < ui->table_candidat->rowCount(); ++row) {
            ui->table_candidat->setRowHidden(row, false);
        }
        return;
    }

    for (int row = 0; row < ui->table_candidat->rowCount(); ++row) {
        QTableWidgetItem *progressionItem = ui->table_candidat->item(row, 8); // PROGRESSION column
        if (progressionItem) {
            bool shouldShow = (progressionItem->text() == filterText);
            ui->table_candidat->setRowHidden(row, !shouldShow);
        }
    }
}

void GereCandidat::trierC(Ui::MainWindow* ui, const QString &sortText)
{
    if (sortText == "Trier") {
        ui->table_candidat->sortByColumn(0, Qt::AscendingOrder); // Sort by ID
        return;
    }

    if (sortText == "Nom croissant") {
        ui->table_candidat->sortByColumn(1, Qt::AscendingOrder);
    }
    else if (sortText == "Nom décroissant") {
        ui->table_candidat->sortByColumn(1, Qt::DescendingOrder);
    }
    else if (sortText == "Date naissance croissante") {
        ui->table_candidat->sortByColumn(3, Qt::AscendingOrder);
    }
    else if (sortText == "Date naissance décroissante") {
        ui->table_candidat->sortByColumn(3, Qt::DescendingOrder);
    }
}

void GereCandidat::rechC(Ui::MainWindow* ui, const QString &searchText)
{
    QString searchTerm = searchText.trimmed().toLower();

    // If search is empty, show all rows
    if (searchTerm.isEmpty()) {
        for (int row = 0; row < ui->table_candidat->rowCount(); ++row) {
            ui->table_candidat->setRowHidden(row, false);
        }
        return;
    }

    // Search in Nom column (column 1)
    for (int row = 0; row < ui->table_candidat->rowCount(); ++row) {
        QTableWidgetItem *nomItem = ui->table_candidat->item(row, 1); // Nom column
        if (nomItem) {
            bool shouldShow = nomItem->text().toLower().contains(searchTerm);
            ui->table_candidat->setRowHidden(row, !shouldShow);
        }
    }
}
