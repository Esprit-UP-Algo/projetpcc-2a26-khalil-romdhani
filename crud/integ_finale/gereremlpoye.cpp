#include "gereremploye.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QFileDialog>
#include <QDesktopServices>
#include <QTextStream>

bool gereremploye::verifierEmploye(Ui::MainWindow* ui)
{
    QWidget* parent = ui->tab_employes->parentWidget();

    // Vérification nom
    QString nom = ui->nom->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le nom est obligatoire!");
        ui->nom->setFocus();
        return false;
    }
    QRegularExpression nomRegex("^[a-zA-ZÀ-ÿ\\s\\-']+$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(parent, "Nom invalide", "Le nom ne peut contenir que des lettres, espaces et traits d’union!");
        ui->nom->setFocus();
        return false;
    }

    // Vérification prénom
    QString prenom = ui->prenom->text().trimmed();
    if (prenom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le prénom est obligatoire!");
        ui->prenom->setFocus();
        return false;
    }
    if (!nomRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(parent, "Prénom invalide", "Le prénom ne peut contenir que des lettres, espaces et traits d’union!");
        ui->prenom->setFocus();
        return false;
    }

    // Vérification téléphone
    QString telephone = ui->telephone->text().trimmed();
    QRegularExpression telRegex("^[259]\\d{7}$");
    if (!telRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(parent, "Téléphone invalide", "Le téléphone doit comporter 8 chiffres et commencer par 2, 5 ou 9!");
        ui->telephone->setFocus();
        return false;
    }

    // Vérification date d’embauche
    QDate embauche = ui->date_embauche->date();
    if (embauche > QDate::currentDate()) {
        QMessageBox::warning(parent, "Date invalide", "La date d'embauche ne peut pas être dans le futur!");
        ui->date_embauche->setFocus();
        return false;
    }

    // Vérification poste
    QString poste = ui->poste->text().trimmed();
    if (poste.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le poste est obligatoire!");
        ui->poste->setFocus();
        return false;
    }

    // Vérification salaire
    bool ok;
    double salaire = ui->salaire->text().toDouble(&ok);
    if (!ok || salaire <= 0) {
        QMessageBox::warning(parent, "Salaire invalide", "Le salaire doit être un nombre positif!");
        ui->salaire->setFocus();
        return false;
    }

    return true;
}

bool gereremploye::ajouterEmploye(Ui::MainWindow* ui)
{
    if (!verifierEmploye(ui))
        return false;

    QString nom = ui->nom->text().trimmed();
    QString prenom = ui->prenom->text().trimmed();
    QString telephone = ui->telephone->text().trimmed();
    QDate embauche = ui->date_embauche->date();
    QString poste = ui->poste->text().trimmed();
    double salaire = ui->salaire->text().toDouble();

    Employe e(nom, prenom, telephone, embauche, poste, salaire);

    if (e.ajouter()) {
        QMessageBox::information(ui->tab_employes->parentWidget(), "Succès", "Employé ajouté avec succès!");
        e.afficher(ui->tab_employes);
        return true;
    } else {
        QMessageBox::critical(ui->tab_employes->parentWidget(), "Erreur", "Erreur lors de l'ajout de l'employé !");
        return false;
    }
}

bool gereremploye::modifierEmploye(Ui::MainWindow* ui, Employe& e, bool& isEditing)
{
    if (!isEditing) {
        QMessageBox::warning(ui->tab_employes->parentWidget(), "Modification", "Aucun employé sélectionné!");
        return false;
    }

    if (!verifierEmploye(ui))
        return false;

    QString nom = ui->nom->text().trimmed();
    QString prenom = ui->prenom->text().trimmed();
    QString telephone = ui->telephone->text().trimmed();
    QDate embauche = ui->date_embauche->date();
    QString poste = ui->poste->text().trimmed();
    double salaire = ui->salaire->text().toDouble();

    bool success = e.modifier(nom, prenom, telephone, embauche, poste, salaire);

    if (success) {
        QMessageBox::information(ui->tab_employes->parentWidget(), "Succès", "Employé modifié avec succès!");
        e.afficher(ui->tab_employes);
        isEditing = false;
        return true;
    } else {
        QMessageBox::critical(ui->tab_employes->parentWidget(), "Erreur", "Erreur lors de la modification de l'employé!");
        return false;
    }
}

void gereremploye::chargeremployePourModification(Ui::MainWindow* ui, const QModelIndex &index, bool& isEditing)
{
    int row = index.row();
    isEditing = true;

    ui->nom->setText(ui->tab_employes->item(row, 0)->text());
    ui->prenom->setText(ui->tab_employes->item(row, 1)->text());
    ui->telephone->setText(ui->tab_employes->item(row, 2)->text());
    ui->date_embauche->setDate(QDate::fromString(ui->tab_employes->item(row, 3)->text(), "dd/MM/yyyy"));
    ui->poste->setText(ui->tab_employes->item(row, 4)->text());
    ui->salaire->setText(ui->tab_employes->item(row, 5)->text());
}

bool gereemploye::supprimerEmploye(Ui::MainWindow* ui, Employe& e, bool& isEditing)
{
    QWidget* parent = ui->tab_employes->parentWidget();

    QModelIndexList selected = ui->tab_employes->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(parent, "Suppression", "Veuillez sélectionner un employé à supprimer!");
        return false;
    }



    QMessageBox::StandardButton confirm = QMessageBox::question(parent, "Confirmation",
                                                                "Voulez-vous vraiment supprimer cet employé ?",
                                                                QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes) {
        if (e.supprimer()) { // supprimer par index dans la table ou adapter la méthode supprimer
            QMessageBox::information(parent, "Succès", "Employé supprimé avec succès!");
            e.afficher(ui->tab_employes);
            isEditing = false;
            return true;
        } else {
            QMessageBox::critical(parent, "Erreur", "Erreur lors de la suppression de l'employé!");
            return false;
        }
    }
    return false;
}

void gereremploye::exporterExcel(Ui::MainWindow* ui)
{
    QWidget* parent = ui->tab_employes->parentWidget();

    if (ui->tab_employes->rowCount() == 0) {
        QMessageBox::warning(parent, "Exportation", "Aucune donnée à exporter!");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(parent, "Exporter vers CSV",
                                                    QDir::homePath() + "/liste_employes.csv", "Fichiers CSV (*.csv)");

    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".csv", Qt::CaseInsensitive)) fileName += ".csv";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(parent, "Erreur", "Impossible de créer le fichier!");
        return;
    }

    QTextStream out(&file);
    QStringList headers;
    for (int col = 0; col < ui->tab_employes->columnCount(); ++col) {
        headers << "\"" + ui->tab_employes->horizontalHeaderItem(col)->text() + "\"";
    }
    out << headers.join(";") << "\n";

    for (int row = 0; row < ui->tab_employes->rowCount(); ++row) {
        QStringList data;
        for (int col = 0; col < ui->tab_employes->columnCount(); ++col) {
            QString text = ui->tab_employes->item(row, col) ? ui->tab_employes->item(row, col)->text() : "";
            text.replace("\"", "\"\"");
            data << "\"" + text + "\"";
        }
        out << data.join(";") << "\n";
    }

    file.close();

    QMessageBox::information(parent, "Exportation réussie",
                             "La liste des employés a été exportée avec succès vers:\n" + fileName);

    if (QMessageBox::question(parent, "Ouvrir le fichier",
                              "Voulez-vous ouvrir le fichier maintenant?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    }
}
void gereremploye::reinitialiserFormulaire(Ui::MainWindow* ui)
{
    ui->nom->clear();
    ui->prenom->clear();
    ui->poste->clear();
    ui->salaire->clear();
    ui->tab_employes->clearSelection();
}
