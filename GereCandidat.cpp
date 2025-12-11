#include "GereCandidat.h"
#include "ui_mainwindow.h"
#include "Candidat.h"
#include "JournalCandidat.h"
#include "ImageVer_C.h"
#include "FeedbackUtilisateur.h"
#include <QCheckBox>
#include <QComboBox>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFileDialog>
#include <QDesktopServices>
#include <QSqlQuery>
#include <QDebug>
#include <QTextStream>
#include <QSqlError>
#include <QProgressBar>
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QObject>

// Initialisation du pointeur journal
JournalCandidat* GereCandidat::m_journal = nullptr;

void GereCandidat::setJournal(JournalCandidat *journal)
{
    m_journal = journal;
}

// MÉTHODE POUR TROUVER MAINWINDOW
MainWindow* trouverMainWindow(QWidget* widget) {
    while (widget) {
        MainWindow* mainWindow = qobject_cast<MainWindow*>(widget);
        if (mainWindow) return mainWindow;
        widget = widget->parentWidget();
    }
    return nullptr;
}

// 🔥 CORRECTION : MÉTHODE DE VALIDATION AVEC ANCIEN ID
GereCandidat::ResultatOperation GereCandidat::validerDonneesCandidat(const QVariantMap& donnees, int ancienId)
{
    // Validation ID
    int id = donnees["id"].toInt();
    if (id < 1000 || id > 9999) {
        return ResultatOperation(false,
                                 "🔢 ID candidat invalide",
                                 "L'ID doit être un nombre entre 1000 et 9999",
                                 ERREUR_VALIDATION);
    }

    // Validation nom
    QString nom = donnees["nom"].toString().trimmed();
    if (nom.isEmpty()) {
        return ResultatOperation(false,
                                 "👤 Nom manquant",
                                 "Le nom est obligatoire",
                                 ERREUR_VALIDATION);
    }
    if (nom.length() > 20) {
        return ResultatOperation(false,
                                 "👤 Nom trop long",
                                 "Le nom ne peut pas dépasser 20 caractères",
                                 ERREUR_VALIDATION);
    }

    QRegularExpression nomRegex("^[a-zA-ZÀ-ÿ\\s\\-']+$");
    if (!nomRegex.match(nom).hasMatch()) {
        return ResultatOperation(false,
                                 "👤 Nom invalide",
                                 "Le nom ne peut contenir que des lettres, espaces, traits d'union et apostrophes",
                                 ERREUR_VALIDATION);
    }

    // Validation prénom
    QString prenom = donnees["prenom"].toString().trimmed();
    if (prenom.isEmpty()) {
        return ResultatOperation(false,
                                 "👤 Prénom manquant",
                                 "Le prénom est obligatoire",
                                 ERREUR_VALIDATION);
    }
    if (prenom.length() > 20) {
        return ResultatOperation(false,
                                 "👤 Prénom trop long",
                                 "Le prénom ne peut pas dépasser 20 caractères",
                                 ERREUR_VALIDATION);
    }
    if (!nomRegex.match(prenom).hasMatch()) {
        return ResultatOperation(false,
                                 "👤 Prénom invalide",
                                 "Le prénom ne peut contenir que des lettres, espaces, traits d'union et apostrophes",
                                 ERREUR_VALIDATION);
    }

    // Validation date de naissance
    QDate dateNaissance = donnees["date_naissance"].toDate();
    QDate aujourdhui = QDate::currentDate();
    int age = dateNaissance.daysTo(aujourdhui) / 365;

    if (age < 18) {
        return ResultatOperation(false,
                                 "🎂 Âge insuffisant",
                                 "Le candidat doit avoir au moins 18 ans",
                                 ERREUR_VALIDATION);
    }

    // Validation téléphone
    QString telephone = donnees["telephone"].toString().trimmed();
    QRegularExpression telRegex("^[259]\\d{7}$");
    if (!telRegex.match(telephone).hasMatch()) {
        return ResultatOperation(false,
                                 "📞 Numéro de téléphone invalide",
                                 "Le téléphone doit avoir 8 chiffres et commencer par 2, 5 ou 9\nExemple : 51234567",
                                 ERREUR_VALIDATION);
    }

    // Validation email
    QString email = donnees["email"].toString().trimmed();
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        return ResultatOperation(false,
                                 "📧 Adresse email invalide",
                                 "Veuillez saisir une adresse email valide\nExemple : nom@domaine.com",
                                 ERREUR_VALIDATION);
    }

    // Validation niveau permis
    if (donnees["niveau_permis"].toString() == "Choisir") {
        return ResultatOperation(false,
                                 "🚗 Niveau de permis manquant",
                                 "Veuillez choisir un niveau de permis",
                                 ERREUR_VALIDATION);
    }

    // 🔥 CORRECTION : Vérification doublon ID - seulement si l'ID a changé ou en création
    QSqlQuery query;
    if (ancienId == 0) {
        // Mode création : vérifier que l'ID n'existe pas
        query.prepare("SELECT COUNT(*) FROM CANDIDATS WHERE ID_CANDIDAT = :id");
        query.bindValue(":id", id);
        if (query.exec() && query.next() && query.value(0).toInt() > 0) {
            return ResultatOperation(false,
                                     "🔢 ID déjà existant",
                                     QString("L'ID %1 est déjà utilisé par un autre candidat").arg(id),
                                     ERREUR_DOUBLON);
        }
    } else {
        // Mode modification : vérifier que l'ID n'est pas utilisé par un AUTRE candidat
        query.prepare("SELECT COUNT(*) FROM CANDIDATS WHERE ID_CANDIDAT = :id AND ID_CANDIDAT != :ancienId");
        query.bindValue(":id", id);
        query.bindValue(":ancienId", ancienId);
        if (query.exec() && query.next() && query.value(0).toInt() > 0) {
            return ResultatOperation(false,
                                     "🔢 ID déjà existant",
                                     QString("L'ID %1 est déjà utilisé par un autre candidat").arg(id),
                                     ERREUR_DOUBLON);
        }
    }

    return ResultatOperation(true, "✅ Validation réussie");
}

GereCandidat::ResultatOperation GereCandidat::validerImage(const QString& cheminImage)
{
    if (cheminImage.isEmpty()) {
        return ResultatOperation(true, "Aucune image à valider");
    }

    QFileInfo fileInfo(cheminImage);

    // Vérifier existence fichier
    if (!fileInfo.exists()) {
        return ResultatOperation(false,
                                 "🖼️ Fichier image introuvable",
                                 QString("Le fichier '%1' n'existe pas").arg(cheminImage),
                                 ERREUR_FICHIER);
    }

    // Vérifier taille fichier (max 10MB)
    if (fileInfo.size() > 10 * 1024 * 1024) {
        return ResultatOperation(false,
                                 "🖼️ Fichier trop volumineux",
                                 QString("L'image ne doit pas dépasser 10 Mo\nTaille actuelle : %1 Mo")
                                     .arg(fileInfo.size() / (1024.0 * 1024.0), 0, 'f', 2),
                                 ERREUR_IMAGE);
    }

    // Vérifier format supporté
    QString extension = fileInfo.suffix().toLower();
    QStringList formatsSupportes = {"jpg", "jpeg", "png", "bmp"};
    if (!formatsSupportes.contains(extension)) {
        return ResultatOperation(false,
                                 "🖼️ Format non supporté",
                                 "Formats supportés : JPG, JPEG, PNG, BMP",
                                 ERREUR_IMAGE);
    }

    return ResultatOperation(true, "✅ Image valide");
}

QVariantMap GereCandidat::extraireDonneesFormulaire(Ui::MainWindow* ui)
{
    QVariantMap donnees;

    donnees["id"] = ui->id_c->text().toInt();
    donnees["nom"] = ui->nom_c->text().trimmed();
    donnees["prenom"] = ui->prenom_c->text().trimmed();
    donnees["date_naissance"] = ui->dateN_c->date();
    donnees["adresse"] = ui->adr_c->text().trimmed();
    donnees["telephone"] = ui->tel_c->text().trimmed();
    donnees["email"] = ui->email_c->text().trimmed();
    donnees["niveau_permis"] = ui->nvpermis_c->currentText();

    // Récupérer le chemin de l'image depuis MainWindow
    QWidget* parent = ui->id_c->parentWidget();
    if (parent) {
        MainWindow* mainWindow = trouverMainWindow(parent);
        if (mainWindow && mainWindow->getImageVerif()) {
            donnees["chemin_image"] = mainWindow->getImageVerif()->getCheminImage();
        } else {
            donnees["chemin_image"] = "";
        }
    } else {
        donnees["chemin_image"] = "";
    }

    return donnees;
}

QString GereCandidat::formaterMessageErreur(int type, const QString& details)
{
    switch (type) {
    case ERREUR_BDD:
        return QString("Erreur base de données : %1").arg(details);
    case ERREUR_VALIDATION:
        return QString("Erreur de validation : %1").arg(details);
    case ERREUR_FICHIER:
        return QString("Erreur fichier : %1").arg(details);
    case ERREUR_DOUBLON:
        return QString("Doublon détecté : %1").arg(details);
    case ERREUR_IMAGE:
        return QString("Erreur image : %1").arg(details);
    default:
        return details;
    }
}

// MÉTHODES EXISTANTES AMÉLIORÉES

bool GereCandidat::verifierCandidat(Ui::MainWindow* ui)
{
    QVariantMap donnees = extraireDonneesFormulaire(ui);
    // 🔥 CORRECTION : Utiliser ancienId = 0 pour la vérification simple
    ResultatOperation validation = validerDonneesCandidat(donnees, 0);

    if (!validation.succes) {
        FeedbackUtilisateur::afficherErreur(ui->id_c->parentWidget(),
                                            validation.message,
                                            "",
                                            validation.detailsTechniques);
        return false;
    }

    return true;
}

bool GereCandidat::ajouterCandidat(Ui::MainWindow* ui, ImageVer_C* imageVerif, bool& isEditing)
{
    if (isEditing) {
        QMessageBox::information(ui->id_c->parentWidget(), "ℹ️ Information",
                                 "Vous êtes en mode modification.\n"
                                 "Utilisez le bouton 'Modifier' pour confirmer les changements.");
        return false;
    }

    QWidget* parent = ui->id_c->parentWidget();

    // Afficher indicateur chargement
    FeedbackUtilisateur::afficherChargement(parent, "Validation des données...");

    // 1. Validation des données
    QVariantMap donnees = extraireDonneesFormulaire(ui);

    // 🔥 CORRECTION : Utiliser ancienId = 0 pour le mode création
    ResultatOperation validation = validerDonneesCandidat(donnees, 0);

    if (!validation.succes) {
        FeedbackUtilisateur::masquerChargement();
        FeedbackUtilisateur::afficherErreur(parent,
                                            validation.message,
                                            "",
                                            validation.detailsTechniques);
        return false;
    }

    // 2. Validation de l'image si présente
    QString cheminPhotoFinal = "";
    if (donnees.contains("chemin_image") && !donnees["chemin_image"].toString().isEmpty()) {
        FeedbackUtilisateur::afficherChargement(parent, "Validation de la photo...");
        ResultatOperation validationImage = validerImage(donnees["chemin_image"].toString());
        if (!validationImage.succes) {
            FeedbackUtilisateur::masquerChargement();
            FeedbackUtilisateur::afficherErreur(parent,
                                                validationImage.message,
                                                "",
                                                validationImage.detailsTechniques);
            return false;
        }

        // 🔥 CORRECTION AMÉLIORÉE : Sauvegarde IMMÉDIATE de l'image après validation
        FeedbackUtilisateur::afficherChargement(parent, "Sauvegarde de la photo...");

        if (imageVerif) {
            if (imageVerif->sauvegarderImagePourCandidat(donnees["id"].toInt())) {
                cheminPhotoFinal = imageVerif->getCheminImage();
                qDebug() << "✅ Photo sauvegardée avec succès :" << cheminPhotoFinal;
            } else {
                FeedbackUtilisateur::masquerChargement();
                FeedbackUtilisateur::afficherAvertissement(parent,
                                                           "⚠️ Attention - Photo non sauvegardée",
                                                           "La photo n'a pas pu être sauvegardée, mais le candidat sera ajouté sans photo.");
                cheminPhotoFinal = ""; // Continuer sans photo
            }
        }
    }

    // 3. Préparation des données pour l'insertion
    QString nvPermis = donnees["niveau_permis"].toString().left(1);

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

    // 4. Insertion en base de données
    FeedbackUtilisateur::afficherChargement(parent, "Ajout du candidat en base...");

    Candidat candidat(donnees["id"].toInt(),
                      donnees["nom"].toString(),
                      donnees["prenom"].toString(),
                      donnees["date_naissance"].toDate(),
                      donnees["adresse"].toString(),
                      donnees["telephone"].toString(),
                      donnees["email"].toString(),
                      nvPermis,
                      progression,
                      cheminPhotoFinal);

    bool success = candidat.ajouter();

    FeedbackUtilisateur::masquerChargement();

    if (success) {
        QString messageSucces = QString("Le candidat a été ajouté avec succès !\n\n"
                                        "👤 Nom : %1 %2\n"
                                        "🔢 ID : %3\n"
                                        "📧 Email : %4")
                                    .arg(donnees["nom"].toString())
                                    .arg(donnees["prenom"].toString())
                                    .arg(donnees["id"].toInt())
                                    .arg(donnees["email"].toString());

        // 🔥 AJOUT : Message spécifique si une photo a été sauvegardée
        if (!cheminPhotoFinal.isEmpty()) {
            messageSucces += "\n📸 Photo : Sauvegardée avec succès";
        }

        FeedbackUtilisateur::afficherSucces(parent, "✅ Candidat ajouté avec succès", messageSucces);

        // Journalisation
        if (m_journal) {
            QString action = "CRÉATION";
            if (!cheminPhotoFinal.isEmpty()) {
                action += " (avec photo)";
            }
            m_journal->ajouterEntree(action, donnees["id"].toInt(),
                                     donnees["nom"].toString() + " " + donnees["prenom"].toString());
        }

        // Mise à jour interface
        Candidat temp;
        temp.afficher(ui->table_candidat);

        // Réinitialiser le formulaire
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

        // Réinitialiser l'image
        if (imageVerif) {
            imageVerif->reinitialiser();
        }

        return true;
    } else {
        FeedbackUtilisateur::afficherErreur(parent,
                                            "❌ Erreur lors de l'ajout",
                                            "Impossible d'ajouter le candidat dans la base de données.",
                                            "Vérifiez la connexion à la base de données et que l'ID n'existe pas déjà.");
        return false;
    }
}

bool GereCandidat::modifierCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId, ImageVer_C* imageVerif)
{
    if (!isEditing) {
        FeedbackUtilisateur::afficherAvertissement(ui->id_c->parentWidget(),
                                                   "Modification",
                                                   "Aucun candidat sélectionné pour modification !");
        return false;
    }

    QWidget* parent = ui->id_c->parentWidget();
    FeedbackUtilisateur::afficherChargement(parent, "Validation des modifications...");

    // 1. Validation des données
    QVariantMap donnees = extraireDonneesFormulaire(ui);

    // 🔥 CORRECTION : Passer l'ancien ID pour la validation
    ResultatOperation validation = validerDonneesCandidat(donnees, currentId);

    if (!validation.succes) {
        FeedbackUtilisateur::masquerChargement();
        FeedbackUtilisateur::afficherErreur(parent,
                                            validation.message,
                                            "",
                                            validation.detailsTechniques);
        return false;
    }

    // 2. Validation et sauvegarde de l'image
    QString cheminPhotoFinal = "";
    bool nouvellePhotoSauvegardee = false;

    if (donnees.contains("chemin_image") && !donnees["chemin_image"].toString().isEmpty()) {
        FeedbackUtilisateur::afficherChargement(parent, "Validation de la nouvelle photo...");
        ResultatOperation validationImage = validerImage(donnees["chemin_image"].toString());
        if (!validationImage.succes) {
            FeedbackUtilisateur::masquerChargement();
            FeedbackUtilisateur::afficherErreur(parent,
                                                validationImage.message,
                                                "",
                                                validationImage.detailsTechniques);
            return false;
        }

        // 🔥 CORRECTION AMÉLIORÉE : Sauvegarde IMMÉDIATE de la nouvelle image
        FeedbackUtilisateur::afficherChargement(parent, "Sauvegarde de la nouvelle photo...");

        if (imageVerif) {
            if (imageVerif->sauvegarderImagePourCandidat(currentId)) {
                cheminPhotoFinal = imageVerif->getCheminImage();
                nouvellePhotoSauvegardee = true;
                qDebug() << "✅ Nouvelle photo sauvegardée avec succès :" << cheminPhotoFinal;
            } else {
                FeedbackUtilisateur::masquerChargement();
                FeedbackUtilisateur::afficherAvertissement(parent,
                                                           "⚠️ Attention - Photo non sauvegardée",
                                                           "La nouvelle photo n'a pas pu être sauvegardée, mais la modification du candidat continuera.");
                // Récupérer l'ancien chemin de photo
                QSqlQuery query;
                query.prepare("SELECT PHOTO_PATH FROM CANDIDATS WHERE ID_CANDIDAT = :id");
                query.bindValue(":id", currentId);
                if (query.exec() && query.next()) {
                    cheminPhotoFinal = query.value(0).toString();
                }
            }
        }
    } else {
        // Garder l'ancienne photo si pas de nouvelle
        QSqlQuery query;
        query.prepare("SELECT PHOTO_PATH FROM CANDIDATS WHERE ID_CANDIDAT = :id");
        query.bindValue(":id", currentId);
        if (query.exec() && query.next()) {
            cheminPhotoFinal = query.value(0).toString();
        }
    }

    // 3. Préparation des données
    int nouveauId = donnees["id"].toInt();
    QString nvPermis = donnees["niveau_permis"].toString().left(1);

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

    // 4. Modification en base
    FeedbackUtilisateur::afficherChargement(parent, "Application des modifications...");

    bool success = c.modifier(currentId, nouveauId,
                              donnees["nom"].toString(),
                              donnees["prenom"].toString(),
                              donnees["date_naissance"].toDate(),
                              donnees["adresse"].toString(),
                              donnees["telephone"].toString(),
                              donnees["email"].toString(),
                              nvPermis,
                              progression,
                              cheminPhotoFinal);

    FeedbackUtilisateur::masquerChargement();

    if (success) {
        QString messageSucces = QString("Les modifications ont été sauvegardées avec succès !\n\n"
                                        "👤 Nom : %1 %2\n"
                                        "🔢 ID : %3")
                                    .arg(donnees["nom"].toString())
                                    .arg(donnees["prenom"].toString())
                                    .arg(nouveauId);

        // 🔥 AJOUT : Message spécifique si une nouvelle photo a été sauvegardée
        if (nouvellePhotoSauvegardee) {
            messageSucces += "\n📸 Photo : Mise à jour réussie";
        }

        FeedbackUtilisateur::afficherSucces(parent, "✅ Candidat modifié avec succès", messageSucces);

        // JOURNALISATION
        if (m_journal) {
            QString action = "MODIFICATION";
            if (nouvellePhotoSauvegardee) {
                action += " (photo mise à jour)";
            }
            m_journal->ajouterEntree(action, nouveauId,
                                     donnees["nom"].toString() + " " + donnees["prenom"].toString());
        }

        c.afficher(ui->table_candidat);
        isEditing = false;
        currentId = 0;

        // Réinitialiser l'image
        if (imageVerif) {
            imageVerif->reinitialiser();
        }

        return true;
    } else {
        FeedbackUtilisateur::afficherErreur(parent,
                                            "❌ Erreur lors de la modification",
                                            "Impossible de modifier le candidat dans la base de données.",
                                            "Vérifiez la connexion à la base de données.");
        return false;
    }
}

void GereCandidat::chargerCandidatPourModification(Ui::MainWindow* ui, const QModelIndex &index, bool& isEditing, int& currentId, ImageVer_C* imageVerif)
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

    // Charger la photo depuis la base de données
    if (imageVerif) {
        imageVerif->chargerImagePourModification(currentId);
    }

    FeedbackUtilisateur::afficherSucces(parent,
                                        "✏️ Candidat chargé pour modification",
                                        QString("Le candidat a été chargé pour modification.\n\n"
                                                "👤 %1 %2\n"
                                                "🔢 ID : %3\n\n"
                                                "Modifiez les champs nécessaires et cliquez sur 'Modifier' pour sauvegarder.")
                                            .arg(nom)
                                            .arg(prenom)
                                            .arg(id));
}

bool GereCandidat::supprimerCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId, ImageVer_C* imageVerif)
{
    QWidget* parent = ui->id_c->parentWidget();

    QModelIndexList selectedIndexes = ui->table_candidat->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        FeedbackUtilisateur::afficherAvertissement(parent,
                                                   "Aucune sélection",
                                                   "Veuillez sélectionner un candidat à supprimer dans le tableau !");
        return false;
    }

    int row = selectedIndexes.first().row();
    QString id = ui->table_candidat->item(row, 0)->text();
    QString nom = ui->table_candidat->item(row, 1)->text();
    QString prenom = ui->table_candidat->item(row, 2)->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(parent, "🗑️ Confirmation de suppression",
                                  QString("Êtes-vous sûr de vouloir supprimer ce candidat ?\n\n"
                                          "🔢 ID : %1\n"
                                          "👤 Nom : %2 %3\n\n"
                                          "⚠️ Cette action est irréversible !")
                                      .arg(id, nom, prenom),
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        FeedbackUtilisateur::afficherChargement(parent, "Suppression du candidat...");

        bool success = c.supprimer(id.toInt());

        FeedbackUtilisateur::masquerChargement();

        if (success) {
            FeedbackUtilisateur::afficherSucces(parent,
                                                "✅ Candidat supprimé",
                                                QString("Le candidat a été supprimé avec succès.\n\n"
                                                        "👤 %1 %2\n"
                                                        "🔢 ID : %3")
                                                    .arg(nom)
                                                    .arg(prenom)
                                                    .arg(id));

            // JOURNALISATION
            if (m_journal) {
                m_journal->ajouterEntree("SUPPRESSION", id.toInt(), nom + " " + prenom);
            }

            c.afficher(ui->table_candidat);

            // Si on supprime le candidat en cours d'édition, reset le formulaire
            if (currentId == id.toInt()) {
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

                // Réinitialiser l'image
                if (imageVerif) {
                    imageVerif->reinitialiser();
                }

                isEditing = false;
                currentId = 0;
            }
            return true;
        } else {
            FeedbackUtilisateur::afficherErreur(parent,
                                                "❌ Erreur lors de la suppression",
                                                "Impossible de supprimer le candidat.",
                                                "Vérifiez les contraintes de clé étrangère ou la connexion à la base de données.");
            return false;
        }
    }

    FeedbackUtilisateur::afficherInfo(parent,
                                      "Suppression annulée",
                                      "La suppression a été annulée.");
    return false;
}

void GereCandidat::filtreC(Ui::MainWindow* ui, const QString &filterText)
{
    if (filterText == "Filtrer" || filterText.isEmpty() || filterText == "Tous") {
        // Réinitialiser avec tous les candidats depuis BDD
        Candidat c;
        c.afficher(ui->table_candidat);
        FeedbackUtilisateur::afficherToast(ui->id_c->parentWidget(), "Filtre désactivé");
        return;
    }

    // Filtrer directement avec une requête SQL
    QSqlQuery query;
    query.prepare("SELECT ID_CANDIDAT, NOM_C, PRENOM_C, DATE_N_C, ADRESSE_C, "
                  "TELEPHONE_C, EMAIL, NV_PERMIS, PROGRESSION, PHOTO_PATH "
                  "FROM CANDIDATS WHERE PROGRESSION = :progression");
    query.bindValue(":progression", filterText);

    if (query.exec()) {
        ui->table_candidat->setRowCount(0);
        int row = 0;
        while (query.next()) {
            ui->table_candidat->insertRow(row);
            ui->table_candidat->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->table_candidat->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->table_candidat->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->table_candidat->setItem(row, 3, new QTableWidgetItem(query.value(3).toDate().toString("dd/MM/yyyy")));
            ui->table_candidat->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->table_candidat->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
            ui->table_candidat->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
            ui->table_candidat->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
            ui->table_candidat->setItem(row, 8, new QTableWidgetItem(query.value(8).toString()));
            row++;
        }

        FeedbackUtilisateur::afficherToast(ui->id_c->parentWidget(),
                                           QString("Filtre appliqué : %1 - %2 résultat(s)").arg(filterText).arg(row));
    }
}

void GereCandidat::trierC(Ui::MainWindow* ui, const QString &sortText)
{
    QString orderByClause;

    if (sortText == "Trier" || sortText.isEmpty()) {
        orderByClause = "ID_CANDIDAT ASC";
    }
    else if (sortText == "Nom croissant") {
        orderByClause = "NOM_C ASC, PRENOM_C ASC";
    }
    else if (sortText == "Nom décroissant") {
        orderByClause = "NOM_C DESC, PRENOM_C DESC";
    }
    else if (sortText == "Date naissance croissante") {
        orderByClause = "DATE_N_C ASC";
    }
    else if (sortText == "Date naissance décroissante") {
        orderByClause = "DATE_N_C DESC";
    }
    else {
        orderByClause = "ID_CANDIDAT ASC";
    }

    // Trier directement avec SQL
    QSqlQuery query;
    QString sql = "SELECT ID_CANDIDAT, NOM_C, PRENOM_C, DATE_N_C, ADRESSE_C, "
                  "TELEPHONE_C, EMAIL, NV_PERMIS, PROGRESSION, PHOTO_PATH "
                  "FROM CANDIDATS ORDER BY " + orderByClause;

    if (query.exec(sql)) {
        ui->table_candidat->setRowCount(0);
        int row = 0;
        while (query.next()) {
            ui->table_candidat->insertRow(row);
            ui->table_candidat->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->table_candidat->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->table_candidat->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->table_candidat->setItem(row, 3, new QTableWidgetItem(query.value(3).toDate().toString("dd/MM/yyyy")));
            ui->table_candidat->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->table_candidat->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
            ui->table_candidat->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
            ui->table_candidat->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
            ui->table_candidat->setItem(row, 8, new QTableWidgetItem(query.value(8).toString()));
            row++;
        }
    }

    FeedbackUtilisateur::afficherToast(ui->id_c->parentWidget(),
                                       QString("Tri appliqué : %1").arg(sortText));
}

void GereCandidat::rechC(Ui::MainWindow* ui, const QString &searchText)
{
    QString searchTerm = searchText.trimmed();

    if (searchTerm.isEmpty()) {
        // Réinitialiser avec tous les candidats
        Candidat c;
        c.afficher(ui->table_candidat);
        FeedbackUtilisateur::afficherToast(ui->id_c->parentWidget(), "Recherche annulée");
        return;
    }

    // Recherche avec SQL LIKE sur plusieurs colonnes
    QSqlQuery query;
    query.prepare("SELECT ID_CANDIDAT, NOM_C, PRENOM_C, DATE_N_C, ADRESSE_C, "
                  "TELEPHONE_C, EMAIL, NV_PERMIS, PROGRESSION, PHOTO_PATH "
                  "FROM CANDIDATS WHERE "
                  "ID_CANDIDAT LIKE :search OR "
                  "NOM_C LIKE :search OR "
                  "PRENOM_C LIKE :search OR "
                  "EMAIL LIKE :search OR "
                  "TELEPHONE_C LIKE :search");
    query.bindValue(":search", "%" + searchTerm + "%");

    if (query.exec()) {
        ui->table_candidat->setRowCount(0);
        int resultatsTrouves = 0;

        while (query.next()) {
            ui->table_candidat->insertRow(resultatsTrouves);
            ui->table_candidat->setItem(resultatsTrouves, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->table_candidat->setItem(resultatsTrouves, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->table_candidat->setItem(resultatsTrouves, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->table_candidat->setItem(resultatsTrouves, 3, new QTableWidgetItem(query.value(3).toDate().toString("dd/MM/yyyy")));
            ui->table_candidat->setItem(resultatsTrouves, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->table_candidat->setItem(resultatsTrouves, 5, new QTableWidgetItem(query.value(5).toString()));
            ui->table_candidat->setItem(resultatsTrouves, 6, new QTableWidgetItem(query.value(6).toString()));
            ui->table_candidat->setItem(resultatsTrouves, 7, new QTableWidgetItem(query.value(7).toString()));
            ui->table_candidat->setItem(resultatsTrouves, 8, new QTableWidgetItem(query.value(8).toString()));
            resultatsTrouves++;
        }

        if (resultatsTrouves > 0) {
            FeedbackUtilisateur::afficherToast(ui->id_c->parentWidget(),
                                               QString("%1 résultat(s) trouvé(s)").arg(resultatsTrouves));
        } else {
            FeedbackUtilisateur::afficherAvertissement(ui->id_c->parentWidget(),
                                                       "Aucun résultat",
                                                       QString("Aucun candidat trouvé pour : \"%1\"").arg(searchText));
            // Réafficher tous les candidats
            Candidat c;
            c.afficher(ui->table_candidat);
        }
    }
}

void GereCandidat::exporterExcel(Ui::MainWindow* ui)
{
    QWidget* parent = ui->id_c->parentWidget();

    QString fileName = QFileDialog::getSaveFileName(parent,
                                                    "💾 Exporter vers Excel",
                                                    QDir::homePath() + "/liste_candidats_complete.csv",
                                                    "Fichiers CSV (*.csv);;Fichiers Excel (*.xlsx)");

    if (fileName.isEmpty()) {
        FeedbackUtilisateur::afficherInfo(parent,
                                          "Exportation annulée",
                                          "L'exportation a été annulée.");
        return;
    }

    // Ajouter l'extension si nécessaire
    if (!fileName.endsWith(".csv", Qt::CaseInsensitive) && !fileName.endsWith(".xlsx", Qt::CaseInsensitive)) {
        fileName += ".csv";
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        FeedbackUtilisateur::afficherErreur(parent,
                                            "Erreur d'exportation",
                                            "Impossible de créer le fichier !",
                                            QString("Chemin : %1").arg(fileName));
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    // En-têtes complètes
    QStringList headers;
    headers << "ID" << "Nom" << "Prénom" << "Date Naissance" << "Adresse"
            << "Téléphone" << "Email" << "Niveau Permis" << "Progression" << "Chemin Photo";
    out << headers.join(";") << "\n";

    // REQUÊTE SQL POUR TOUS LES CANDIDATS - SANS FILTRES
    QSqlQuery query;
    query.prepare("SELECT ID_CANDIDAT, NOM_C, PRENOM_C, DATE_N_C, ADRESSE_C, "
                  "TELEPHONE_C, EMAIL, NV_PERMIS, PROGRESSION, PHOTO_PATH "
                  "FROM CANDIDATS ORDER BY ID_CANDIDAT");

    int lignesExportees = 0;

    if (query.exec()) {
        while (query.next()) {
            QStringList rowData;

            // ID
            QString id = query.value(0).toString();
            rowData << "\"" + id + "\"";

            // Nom
            QString nom = query.value(1).toString();
            nom.replace("\"", "\"\"");
            rowData << "\"" + nom + "\"";

            // Prénom
            QString prenom = query.value(2).toString();
            prenom.replace("\"", "\"\"");
            rowData << "\"" + prenom + "\"";

            // Date de naissance
            QString dateNaissance = query.value(3).toDate().toString("dd/MM/yyyy");
            rowData << "\"" + dateNaissance + "\"";

            // Adresse
            QString adresse = query.value(4).toString();
            adresse.replace("\"", "\"\"");
            rowData << "\"" + adresse + "\"";

            // Téléphone
            QString telephone = query.value(5).toString();
            rowData << "\"" + telephone + "\"";

            // Email
            QString email = query.value(6).toString();
            email.replace("\"", "\"\"");
            rowData << "\"" + email + "\"";

            // Niveau permis
            QString niveauPermis = query.value(7).toString();
            rowData << "\"" + niveauPermis + "\"";

            // Progression
            QString progression = query.value(8).toString();
            rowData << "\"" + progression + "\"";

            // Chemin photo
            QString photoPath = query.value(9).toString();
            photoPath.replace("\"", "\"\"");
            rowData << "\"" + photoPath + "\"";

            out << rowData.join(";") << "\n";
            lignesExportees++;
        }
    } else {
        FeedbackUtilisateur::afficherErreur(parent,
                                            "Erreur d'exportation",
                                            "Impossible de récupérer les données depuis la base !",
                                            query.lastError().text());
        file.close();
        return;
    }

    file.close();

    // Message de confirmation clair
    QString message = QString("✅ Exportation COMPLÈTE réussie !\n\n"
                              "📊 **Tous les candidats** exportés : %1 candidat(s)\n"
                              "📁 Fichier : %2\n\n"
                              "💡 *Note : L'exportation inclut tous les candidats de la base de données, "
                              "sans tenir compte des filtres ou recherches actives.*")
                          .arg(lignesExportees)
                          .arg(fileName);

    FeedbackUtilisateur::afficherSucces(parent, "✅ Exportation complète réussie", message);

    // Demander si l'utilisateur veut ouvrir le fichier
    QMessageBox::StandardButton openFile = QMessageBox::question(parent,
                                                                 "Ouvrir le fichier ?",
                                                                 "Voulez-vous ouvrir le fichier exporté maintenant ?",
                                                                 QMessageBox::Yes | QMessageBox::No,
                                                                 QMessageBox::Yes);

    if (openFile == QMessageBox::Yes) {
        bool ouvert = QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
        if (!ouvert) {
            FeedbackUtilisateur::afficherAvertissement(parent,
                                                       "Ouverture impossible",
                                                       "Impossible d'ouvrir le fichier automatiquement.\n"
                                                       "Veuillez l'ouvrir manuellement.");
        }
    }
}

// === PROGRESSION ===
void GereCandidat::rechercherProgression(Ui::MainWindow* ui, const QString &idText)
{
    if (idText.isEmpty()) {
        ui->progressBar_c->setValue(0);
        ui->progressBar_c->setFormat("Début - 0%");
        updateProgressBarColor(ui, 0);
        return;
    }

    if (idText.length() == 4) {
        bool ok;
        int idCandidat = idText.toInt(&ok);

        if (ok && idCandidat >= 1000 && idCandidat <= 9999) {
            QSqlQuery query;
            query.prepare("SELECT PROGRESSION FROM CANDIDATS WHERE ID_CANDIDAT = :id");
            query.bindValue(":id", idCandidat);

            if (query.exec() && query.next()) {
                QString progression = query.value(0).toString();
                int valeurProgression = 0;
                QString texteAffichage = "";

                if (progression == "Début") {
                    valeurProgression = 0;
                    texteAffichage = "Début - 0%";
                } else if (progression == "Code") {
                    valeurProgression = 50;
                    texteAffichage = "Code - 50%";
                } else if (progression == "Conduite") {
                    valeurProgression = 75;
                    texteAffichage = "Conduite - 75%";
                } else if (progression == "Parc") {
                    valeurProgression = 100;
                    texteAffichage = "Parc - 100%";
                } else {
                    valeurProgression = 0;
                    texteAffichage = "Début - 0%";
                }

                ui->progressBar_c->setValue(valeurProgression);
                ui->progressBar_c->setFormat(texteAffichage);
                updateProgressBarColor(ui, valeurProgression);
                return;
            }
        }
    }

    ui->progressBar_c->setValue(0);
    ui->progressBar_c->setFormat("Début - 0%");
    updateProgressBarColor(ui, 0);
}

void GereCandidat::setupProgressBar(Ui::MainWindow* ui)
{
    ui->progressBar_c->setMinimum(0);
    ui->progressBar_c->setMaximum(100);
    ui->progressBar_c->setValue(0);

    ui->progressBar_c->setStyleSheet(
        "QProgressBar {"
        "    border: 2px solid #2c3e50;"
        "    border-radius: 10px;"
        "    background-color: #ecf0f1;"
        "    text-align: center;"
        "    color: #2c3e50;"
        "    font-weight: bold;"
        "    font-size: 12px;"
        "}"
        "QProgressBar::chunk {"
        "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "    stop:0 #3498db, stop:0.5 #2980b9, stop:1 #1f618d);"
        "    border-radius: 8px;"
        "}"
        );

    ui->progressBar_c->setFormat("Début - 0%");
}

void GereCandidat::updateProgressBarColor(Ui::MainWindow* ui, int valeur)
{
    QString styleSheet;

    if (valeur == 0) {
        styleSheet =
            "QProgressBar {"
            "    border: 2px solid #7f8c8d;"
            "    border-radius: 10px;"
            "    background-color: #ecf0f1;"
            "    text-align: center;"
            "    color: #7f8c8d;"
            "    font-weight: bold;"
            "    font-size: 12px;"
            "}"
            "QProgressBar::chunk {"
            "    background-color: #bdc3c7;"
            "    border-radius: 8px;"
            "}";
    }
    else if (valeur <= 50) {
        styleSheet =
            "QProgressBar {"
            "    border: 2px solid #e67e22;"
            "    border-radius: 10px;"
            "    background-color: #ecf0f1;"
            "    text-align: center;"
            "    color: #e67e22;"
            "    font-weight: bold;"
            "    font-size: 12px;"
            "}"
            "QProgressBar::chunk {"
            "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
            "    stop:0 #f39c12, stop:1 #e67e22);"
            "    border-radius: 8px;"
            "}";
    }
    else if (valeur <= 75) {
        styleSheet =
            "QProgressBar {"
            "    border: 2px solid #3498db;"
            "    border-radius: 10px;"
            "    background-color: #ecf0f1;"
            "    text-align: center;"
            "    color: #3498db;"
            "    font-weight: bold;"
            "    font-size: 12px;"
            "}"
            "QProgressBar::chunk {"
            "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
            "    stop:0 #3498db, stop:1 #2980b9);"
            "    border-radius: 8px;"
            "}";
    }
    else {
        styleSheet =
            "QProgressBar {"
            "    border: 2px solid #27ae60;"
            "    border-radius: 10px;"
            "    background-color: #ecf0f1;"
            "    text-align: center;"
            "    color: #27ae60;"
            "    font-weight: bold;"
            "    font-size: 12px;"
            "}"
            "QProgressBar::chunk {"
            "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
            "    stop:0 #2ecc71, stop:1 #27ae60);"
            "    border-radius: 8px;"
            "}";
    }

    ui->progressBar_c->setStyleSheet(styleSheet);
}

// === JOURNAL ===
void GereCandidat::viderJournal(JournalCandidat* journal, QWidget* parent)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(parent, "🗑️ Confirmation",
                                  "Êtes-vous sûr de vouloir vider le journal?\n\n"
                                  "Cette action est irréversible!",
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        journal->viderJournal();
        QMessageBox::information(parent, "✅ Succès", "Journal vidé avec succès!");
    }
}

void GereCandidat::voirJournalComplet(JournalCandidat* journal, QWidget* parent)
{
    QDialog *dialog = new QDialog(parent);
    dialog->setWindowTitle("📋 Journal complet des actions");
    dialog->setMinimumSize(700, 500);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QListWidget *listComplet = new QListWidget(dialog);
    listComplet->setAlternatingRowColors(true);

    // Use the journal parameter to get the log file path
    QString cheminFichierLog;
    if (journal) {
        // If journal has a method to get the log path, use it
        cheminFichierLog = journal->getCheminFichierLog();
    } else {
        // Fallback to default path
        cheminFichierLog = QApplication::applicationDirPath() + "/journal_candidats.log";
    }

    QFile fichierLog(cheminFichierLog);
    if (fichierLog.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&fichierLog);
        stream.setEncoding(QStringConverter::Utf8);

        while (!stream.atEnd()) {
            QString ligne = stream.readLine();
            if (!ligne.isEmpty()) {
                listComplet->addItem(ligne);
            }
        }
        fichierLog.close();
    } else {
        // Show error if file can't be opened
        listComplet->addItem("❌ Impossible d'ouvrir le fichier journal");
        listComplet->addItem("📁 Fichier: " + cheminFichierLog);
    }

    QPushButton *btnFermer = new QPushButton("Fermer", dialog);
    QObject::connect(btnFermer, &QPushButton::clicked, dialog, &QDialog::accept);

    layout->addWidget(new QLabel("Historique complet des actions:", dialog));
    layout->addWidget(listComplet);
    layout->addWidget(btnFermer);

    dialog->exec();
    delete dialog;
}


// MÉTHODES HELPERS
int GereCandidat::getValeurProgression(const QString &progression)
{
    if (progression == "Début") return 0;
    if (progression == "Code") return 50;
    if (progression == "Conduite") return 75;
    if (progression == "Parc") return 100;
    return 0;
}

QString GereCandidat::getTexteProgression(const QString &progression)
{
    if (progression == "Début") return "Début - 0%";
    if (progression == "Code") return "Code - 50%";
    if (progression == "Conduite") return "Conduite - 75%";
    if (progression == "Parc") return "Parc - 100%";
    return "Début - 0%";
}
