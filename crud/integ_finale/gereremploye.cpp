#include "GereEmploye.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QFileDialog>
#include <QDesktopServices>
#include <QTextStream>
#include <QDate>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QDebug>

// Vérifier les champs avant ajout/modification
bool GereEmploye::verifierEmploye(Ui::MainWindow* ui)
{
    QWidget* parent = ui->id_e->parentWidget();

    // ID
    if (ui->id_e->text().isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'ID employé est obligatoire!");
        ui->id_e->setFocus();
        return false;
    }
    bool ok;
    int id = ui->id_e->text().toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(parent, "ID invalide", "L'ID doit être un nombre entier positif!");
        ui->id_e->setFocus();
        return false;
    }

    // Nom
    QString nom = ui->nom->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le nom est obligatoire!");
        ui->nom->setFocus();
        return false;
    }
    QRegularExpression nomRegex("^[a-zA-ZÀ-ÿ\\s\\-']+$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(parent, "Nom invalide", "Le nom ne peut contenir que des lettres, espaces et traits d'union!");
        ui->nom->setFocus();
        return false;
    }

    // Prénom
    QString prenom = ui->prenom->text().trimmed();
    if (prenom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le prénom est obligatoire!");
        ui->prenom->setFocus();
        return false;
    }
    if (!nomRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(parent, "Prénom invalide", "Le prénom ne peut contenir que des lettres, espaces et traits d'union!");
        ui->prenom->setFocus();
        return false;
    }

    // Téléphone
    QString tel = ui->telephone->text().trimmed();
    QRegularExpression telRegex("^[259]\\d{7}$");
    if (!telRegex.match(tel).hasMatch()) {
        QMessageBox::warning(parent, "Téléphone invalide", "Le téléphone doit avoir 8 chiffres et commencer par 2, 5 ou 9!");
        ui->telephone->setFocus();
        return false;
    }

    // Poste
    QString poste = ui->poste->text().trimmed();
    if (poste.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le poste est obligatoire!");
        ui->poste->setFocus();
        return false;
    }

    // Salaire
    bool okSalaire;
    double salaire = ui->salaire->text().toDouble(&okSalaire);
    if (!okSalaire || salaire <= 0) {
        QMessageBox::warning(parent, "Salaire invalide", "Le salaire doit être un nombre positif!");
        ui->salaire->setFocus();
        return false;
    }

    // Date d’embauche
    QDate dateEmbauche = ui->date_embauche->date();
    if (dateEmbauche > QDate::currentDate()) {
        QMessageBox::warning(parent, "Date invalide", "La date d'embauche ne peut pas être dans le futur!");
        ui->date_embauche->setFocus();
        return false;
    }

    return true;
}

// Ajouter un employé
bool GereEmploye::ajouterEmploye(Ui::MainWindow* ui)
{
    // Vérifier les champs avant l'ajout
    if (!verifierEmploye(ui)) return false;

    // Créer l'objet Employe avec les données du formulaire
    Employe e(
        ui->id_e->text().toInt(),
        ui->nom->text(),
        ui->prenom->text(),
        ui->telephone->text(),
        ui->date_embauche->date(),
        ui->poste->text(),
        ui->salaire->text().toDouble()
        );

    // Appeler la méthode ajouter() de la classe Employe
    bool success = e.ajouter();

    // Affichage d'un message selon le résultat
    if (success) {
        QMessageBox::information(ui->id_e->parentWidget(), "Succès", "Employé ajouté avec succès !");
        e.afficher(ui->tab_employes);  // Mettre à jour le tableau
    } else {
        QMessageBox::critical(ui->id_e->parentWidget(), "Erreur", "Erreur lors de l'ajout ! Vérifiez que l'ID n'existe pas déjà.");
    }

    return success;
}


// Modifier un employé
bool GereEmploye::modifierEmploye(Ui::MainWindow* ui, Employe &e, bool &isEditing, int &currentId)
{
    if (!isEditing) {
        QMessageBox::warning(ui->id_e->parentWidget(), "Modification", "Aucun employé sélectionné!");
        return false;
    }

    if (!verifierEmploye(ui)) return false;

    int nouveauId = ui->id_e->text().toInt();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString telephone = ui->telephone->text();
    QDate dateEmbauche = ui->date_embauche->date();
    QString poste = ui->poste->text();
    double salaire = ui->salaire->text().toDouble();

    bool success = e.modifier(currentId, nouveauId, nom, prenom, telephone, dateEmbauche, poste, salaire);

    if (success) {
        QMessageBox::information(ui->id_e->parentWidget(), "Succès", "Employé modifié avec succès!");
        e.afficher(ui->tab_employes);
        isEditing = false;
        currentId = 0;
    } else {
        QMessageBox::critical(ui->id_e->parentWidget(), "Erreur", "Erreur lors de la modification!");
    }

    return success;
}

// Supprimer un employé
bool GereEmploye::supprimerEmploye(Ui::MainWindow* ui, Employe &e, bool &isEditing, int &currentId)
{
    QModelIndexList selectedIndexes = ui->tab_employes->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(ui->id_e->parentWidget(), "Aucune sélection", "Veuillez sélectionner un employé!");
        return false;
    }

    int row = selectedIndexes.first().row();
    int id = ui->tab_employes->item(row, 0)->text().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(ui->id_e->parentWidget(), "Confirmation",
                                  QString("Voulez-vous supprimer l'employé ID %1 ?").arg(id),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        bool success = e.supprimer(id);
        if (success) {
            QMessageBox::information(ui->id_e->parentWidget(), "Succès", "Employé supprimé!");
            e.afficher(ui->tab_employes);
            isEditing = false;
            if (currentId == id) currentId = 0;
        }
        return success;
    }
    return false;
}

// Charger un employé pour modification
void GereEmploye::chargerEmployePourModification(Ui::MainWindow* ui, const QModelIndex &index, bool &isEditing, int &currentId)
{
    int row = index.row();
    currentId = ui->tab_employes->item(row, 0)->text().toInt();
    isEditing = true;

    ui->id_e->setText(ui->tab_employes->item(row, 0)->text());
    ui->nom->setText(ui->tab_employes->item(row, 1)->text());
    ui->prenom->setText(ui->tab_employes->item(row, 2)->text());
    ui->telephone->setText(ui->tab_employes->item(row, 3)->text());
    ui->date_embauche->setDate(QDate::fromString(ui->tab_employes->item(row, 4)->text(), "dd/MM/yyyy"));
    ui->poste->setText(ui->tab_employes->item(row, 5)->text());
    ui->salaire->setText(ui->tab_employes->item(row, 6)->text());
}

// Exporter vers Excel
void GereEmploye::exporterExcel(Ui::MainWindow* ui)
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Exporter vers CSV", "", "CSV (*.csv)");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".csv")) fileName += ".csv";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream out(&file);
    QTableWidget* table = ui->tab_employes;

    QStringList headers;
    for (int c = 0; c < table->columnCount(); ++c)
        headers << table->horizontalHeaderItem(c)->text();
    out << headers.join(";") << "\n";

    for (int r = 0; r < table->rowCount(); ++r) {
        QStringList row;
        for (int c = 0; c < table->columnCount(); ++c)
            row << table->item(r, c)->text();
        out << row.join(";") << "\n";
    }

    file.close();
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

// Réinitialiser le formulaire
void GereEmploye::reinitialiserFormulaire(Ui::MainWindow* ui)
{
    ui->id_e->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->telephone->clear();
    ui->date_embauche->setDate(QDate::currentDate());
    ui->poste->clear();
    ui->salaire->clear();
}
