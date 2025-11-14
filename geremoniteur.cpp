//geremoniteur.cpp
#include "geremoniteur.h"
#include "ui_mainwindow.h"
#include "moniteur.h"
#include <QTextDocument>
#include <QPrinter>
#include <QTextTable>
#include <QFileDialog>
#include <QTextCursor>
#include <QPageSize>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>

// ✅ Vérification des champs
bool GereMoniteur::verifierMoniteur(Ui::MainWindow* ui,
                                    const QString& nom,
                                    const QString& prenom,
                                    const QString& email,
                                     const QString& disponibilite,
                                    const QString& telephone,
                                    const QString& specialite,
                                    const QString& experience)
{
    QWidget* parent = ui->nom_m->parentWidget();

    // Nom
    if (nom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le nom est obligatoire !");
        ui->nom_m->setFocus();
        return false;
    }

    QRegularExpression nomRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]{2,30}$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(parent, "Nom invalide", "Le nom doit contenir uniquement des lettres (2 à 30 caractères).");
        ui->nom_m->setFocus();
        return false;
    }

    // Prénom
    if (prenom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le prénom est obligatoire !");
        ui->prenom_m->setFocus();
        return false;
    }

    if (!nomRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(parent, "Prénom invalide", "Le prénom doit contenir uniquement des lettres (2 à 30 caractères).");
        ui->prenom_m->setFocus();
        return false;
    }

    // Email
    if (email.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'email est obligatoire !");
        ui->email_monituer->setFocus();
        return false;
    }

    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(parent, "Email invalide", "Veuillez entrer une adresse email valide !");
        ui->email_monituer->setFocus();
        return false;
    }

    // Téléphone
    if (telephone.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le téléphone est obligatoire !");
        ui->telephone_m->setFocus();
        return false;
    }
QString tel = ui->telephone_m->text();
  // 🔹 Enlève les espaces avant/après
    tel.remove(QRegularExpression("[^0-9]"));  // 🔹 Garde uniquement les chiffres

    if (tel.length() != 8) {
        QMessageBox::warning(parent, "Téléphone invalide",
                             "Le téléphone doit contenir exactement 8 chiffres.");
        ui->telephone_m->setFocus();
        return false;
    }


    // Spécialité
    if (specialite == "Choisir") {
        QMessageBox::warning(parent, "Spécialité manquante", "Veuillez choisir une spécialité !");
        ui->specialite->setFocus();
        return false;
    }

    // Disponibilité
    if (!ui->actif->isChecked() && !ui->inactif->isChecked()) {
        QMessageBox::warning(parent, "Disponibilité manquante", "Veuillez sélectionner une disponibilité !");
        return false;
    }

    // Expérience
    if (experience.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'expérience est obligatoire !");
        ui->experience_m->setFocus();
        return false;
    }

    QRegularExpression expRegex("^[0-9]{1,2}$");
    if (!expRegex.match(experience).hasMatch()) {
        QMessageBox::warning(parent, "Expérience invalide", "L'expérience doit être un nombre entre 0 et 50 ans.");
        ui->experience_m->setFocus();
        return false;
    }

    int expInt = experience.toInt();
    if (expInt < 0 || expInt > 50) {
        QMessageBox::warning(parent, "Expérience invalide", "L'expérience doit être comprise entre 0 et 50 ans.");
        ui->experience_m->setFocus();
        return false;
    }

    return true;
}
void GereMoniteur::chargerMoniteurPourModification(Ui::MainWindow* ui, const QModelIndex& index, bool& isEditing, QString& currentMoniteurCin)
{
    QWidget* parent = ui->nom_m->parentWidget();
    int row = index.row();

    // ✅ On récupère directement le CIN depuis la colonne 0 du tableau
    QString cin_m = ui->tab_mon->item(row, 0)->text();
    if (cin_m.isEmpty()) {
        QMessageBox::warning(parent, "Erreur", "Impossible de récupérer le CIN du moniteur !");
        return;
    }

    QString nom = ui->tab_mon->item(row, 1)->text();
    QString prenom = ui->tab_mon->item(row, 2)->text();
    QString email = ui->tab_mon->item(row, 3)->text();
    QString telephone = ui->tab_mon->item(row, 4)->text();
    QString specialite = ui->tab_mon->item(row, 5)->text();
    QString disponibilite = ui->tab_mon->item(row, 6)->text();
    QString experience = ui->tab_mon->item(row, 7)->text();

    // ✅ On met à jour la variable de suivi
    currentMoniteurCin = cin_m;
    isEditing = true;

    // ✅ On remplit les champs du formulaire
    ui->nom_m->setText(nom);
    ui->prenom_m->setText(prenom);
    ui->email_monituer->setText(email);
    ui->telephone_m->setText(telephone);
    ui->experience_m->setText(experience);

    int indexSpec = ui->specialite->findText(specialite);
    if (indexSpec != -1)
        ui->specialite->setCurrentIndex(indexSpec);

    if (disponibilite == "Actif")
        ui->actif->setChecked(true);
    else if (disponibilite == "Inactif")
        ui->inactif->setChecked(true);

    QMessageBox::information(parent, "Modification",
                             "Moniteur chargé pour modification ! Cliquez sur 'Enregistrer' pour sauvegarder.");
}

// ✅ Ajouter ou modifier un moniteur
bool GereMoniteur::confirmerMoniteur(Ui::MainWindow* ui, Moniteur& m, bool& isEditing, QString& currentMoniteurcin)
{
    QWidget* parent = ui->nom_m->parentWidget();

    QString nom = ui->nom_m->text();
    QString prenom = ui->prenom_m->text();
    QString email = ui->email_monituer->text();
    QString telephone = ui->telephone_m->text();
    QString specialite = ui->specialite->currentText();

    QString disponibilite;
    if (ui->actif->isChecked()) disponibilite = "Actif";
    else if (ui->inactif->isChecked()) disponibilite = "Inactif";

    QString experience = ui->experience_m->text();

    if (verifierMoniteur(ui, nom, prenom, email, telephone, disponibilite, specialite, experience)) {
        bool success = false;
        QString message;

        int expInt = experience.toInt();

        if (isEditing) {
            // ✅ Correction : CIN_M est de type QString, pas int
            QString cin_m = currentMoniteurcin;


            success = m.modifier(cin_m, nom, prenom, email, telephone, disponibilite, specialite, expInt, 0);

            message = success ? "Moniteur modifié avec succès !" : "Erreur lors de la modification.";

            message = success ? "Moniteur modifié avec succès !" : "Erreur lors de la modification.";
        } else {
            // ✅ On n’a pas besoin de CIN_M : il est généré automatiquement dans Oracle
            Moniteur temp(nom, prenom, email, telephone, disponibilite, specialite, expInt, 0);
            success = temp.ajouter();
            message = success ? "Moniteur ajouté avec succès !" : "Erreur lors de l'ajout à la base de données.";
        }

        if (success) {
            QMessageBox::information(parent, "Succès", message);
            ui->tab_mon->blockSignals(true);   // 🚫 Empêche les signaux pendant le remplissage
            m.afficher(ui->tab_mon);
            ui->tab_mon->blockSignals(false);  // ✅ Réactive les signaux

            reinitialiserFormulaireMoniteur(ui);
            isEditing = false;
            currentMoniteurcin = "";
            return true;
        } else {
            QMessageBox::critical(parent, "Erreur SQL", message);
        }
    }
    return false;
}

// ✅ Réinitialiser le formulaire
void GereMoniteur::reinitialiserFormulaireMoniteur(Ui::MainWindow* ui)
{
    ui->nom_m->clear();
    ui->prenom_m->clear();
    ui->email_monituer->clear();
    ui->telephone_m->clear();
    ui->specialite->setCurrentIndex(0);
    ui->actif->setChecked(false);
    ui->inactif->setChecked(false);
    ui->experience_m->clear();
    ui->nom_m->setFocus();
}

// ✅ Supprimer avec double clic sélectionné
bool GereMoniteur::supprimerMoniteur(Ui::MainWindow* ui, Moniteur& m, bool& isEditing, QString& currentMoniteurcin)
{
    QWidget* parent = ui->nom_m->parentWidget();

    // 🔹 Récupérer le CIN_M à partir de la ligne sélectionnée du tableau
    QModelIndex index = ui->tab_mon->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(parent, "Sélection requise", "Veuillez sélectionner un moniteur à supprimer !");
        return false;
    }

    int row = index.row();

    QString cin_m = ui->tab_mon->item(row, 0)->text();
    QString nom = ui->tab_mon->item(row, 1)->text();
    QString prenom = ui->tab_mon->item(row, 2)->text();


    if (cin_m.isEmpty()) {
        QMessageBox::warning(parent, "Erreur", "Impossible de récupérer le CIN du moniteur !");
        return false;
    }


    // 🔹 On récupère directement le CIN de la table (inutile de le rechercher)
    currentMoniteurcin = cin_m;

    auto reply = QMessageBox::question(
        parent,
        "Confirmation de suppression",
        QString("Supprimer le moniteur %1 %2 (CIN : %3) ?").arg(prenom, nom, cin_m),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        bool success = m.supprimer(cin_m);  // ✅ on passe CIN_M comme QString
        if (success) {
            QMessageBox::information(parent, "Succès", "Moniteur supprimé !");
            ui->tab_mon->blockSignals(true);   // 🚫 Empêche les signaux pendant le remplissage
            m.afficher(ui->tab_mon);
            ui->tab_mon->blockSignals(false);  // ✅ Réactive les signaux

            reinitialiserFormulaireMoniteur(ui);
            isEditing = false;
            currentMoniteurcin.clear();

            return true;
        } else {
            QMessageBox::critical(parent, "Erreur", "Erreur lors de la suppression !");
        }
    }
    return false;
}


// ✅ Export PDF
void GereMoniteur::exporterPDFMoniteur(Ui::MainWindow* ui)
{
    QWidget* parent = ui->nom_m->parentWidget();

    QString fileName = QFileDialog::getSaveFileName(parent, "Exporter en PDF",
                                                    QDir::homePath() + "/liste_moniteurs.pdf",
                                                    "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QTextDocument document;
    QTextCursor cursor(&document);
    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(16);
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::darkBlue);

    cursor.insertText("Liste des Moniteurs - Smart Drive\n", titleFormat);
    cursor.insertText("Date d'exportation: " + QDate::currentDate().toString("dd/MM/yyyy") + "\n\n");

    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(4);
    tableFormat.setAlignment(Qt::AlignCenter);

    int rowCount = ui->tab_mon->rowCount();
    int colCount = ui->tab_mon->columnCount();

    QTextTable* table = cursor.insertTable(rowCount + 1, colCount, tableFormat);

    for (int c = 0; c < colCount; ++c)
        table->cellAt(0, c).firstCursorPosition().insertText(ui->tab_mon->horizontalHeaderItem(c)->text());

    for (int r = 0; r < rowCount; ++r)
        for (int c = 0; c < colCount; ++c)
            if (auto* item = ui->tab_mon->item(r, c))
                table->cellAt(r + 1, c).firstCursorPosition().insertText(item->text());

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    document.print(&printer);

    QMessageBox::information(parent, "Exportation réussie", "Fichier PDF enregistré : " + fileName);
}
