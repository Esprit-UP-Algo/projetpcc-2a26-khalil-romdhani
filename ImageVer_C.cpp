#include "ImageVer_C.h"
#include "FeedbackUtilisateur.h"
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>

ImageVer_C::ImageVer_C(QPushButton* btnSelect, QLabel* labelAffichage, QObject *parent)
    : QObject(parent),
    m_btnSelect(btnSelect),
    m_labelAffichage(labelAffichage)
{
    qDebug() << "🚀 Initialisation de ImageVer_C...";

    // Connecter le bouton
    if (m_btnSelect) {
        QObject::connect(m_btnSelect, &QPushButton::clicked,
                         this, &ImageVer_C::selectionnerEtVerifierImage);
        qDebug() << "✅ Bouton connecté";
    }

    // Configurer le QLabel
    if (m_labelAffichage) {
        m_labelAffichage->setAlignment(Qt::AlignCenter);
        m_labelAffichage->setStyleSheet(
            "QLabel {"
            "    border: 2px solid #cccccc;"
            "    border-radius: 8px;"
            "    background-color: #f8f9fa;"
            "    color: #6c757d;"
            "    font-weight: bold;"
            "    padding: 10px;"
            "}"
            );
        m_labelAffichage->setText("Aucune photo\nsélectionnée");
        qDebug() << "✅ QLabel configuré";
    }
}

ImageVer_C::~ImageVer_C()
{
    qDebug() << "🧹 ImageVer_C détruit";
}

bool ImageVer_C::selectionnerEtVerifierImage()
{
    qDebug() << "📸 Début de la sélection d'image...";

    QString chemin = QFileDialog::getOpenFileName(
        m_btnSelect->parentWidget(),
        "📷 Sélectionner une photo portrait du candidat",
        QDir::homePath(),
        "Images (*.png *.jpg *.jpeg *.bmp);;Tous les fichiers (*.*)"
        );

    if (chemin.isEmpty()) {
        qDebug() << "❌ Sélection annulée par l'utilisateur";
        FeedbackUtilisateur::afficherInfo(m_btnSelect->parentWidget(),
                                          "Sélection annulée",
                                          "Aucune photo n'a été sélectionnée.");
        return false;
    }

    qDebug() << "📁 Image sélectionnée:" << chemin;

    // Charger l'image
    QImage image(chemin);
    if (image.isNull()) {
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Erreur de chargement",
                                            "Impossible de charger l'image sélectionnée.",
                                            "Le fichier est peut-être corrompu ou dans un format non supporté.");
        return false;
    }

    qDebug() << "✅ Image chargée - Dimensions:" << image.width() << "x" << image.height();

    // Vérifier la validité de l'image
    if (!estImageValide(image)) {
        qDebug() << "❌ Image non valide";
        return false;
    }

    // Si validation réussie
    m_cheminImage = chemin;
    redimensionnerEtAfficher(image);

    FeedbackUtilisateur::afficherSucces(m_btnSelect->parentWidget(),
                                        "✅ Photo validée",
                                        "L'image a été acceptée et est prête à être sauvegardée.\n\n"
                                        "Vérification manuelle : Portrait confirmé ✓");

    qDebug() << "🎯 Image validée et affichée";
    return true;
}

bool ImageVer_C::estImageValide(const QImage& image)
{
    // Vérifications basiques seulement
    if (image.isNull()) {
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Image invalide",
                                            "L'image sélectionnée est invalide ou corrompue.");
        return false;
    }

    // Taille minimale
    if (image.width() < 150 || image.height() < 150) {
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Image trop petite",
                                            QString("L'image est trop petite pour un portrait.\n\n"
                                                    "📏 Dimensions minimales requises : 150x150 pixels\n"
                                                    "📏 Dimensions actuelles : %1x%2 pixels")
                                                .arg(image.width())
                                                .arg(image.height()));
        return false;
    }

    // Ratio d'aspect (portrait)
    double ratio = static_cast<double>(image.width()) / image.height();
    qDebug() << "📐 Ratio d'aspect:" << ratio;

    if (ratio < 0.5 || ratio > 2.0) {
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Format inapproprié",
                                            "Le format de l'image ne convient pas pour un portrait.\n\n"
                                            "Veuillez sélectionner une photo où le visage\n"
                                            "est clairement visible et bien cadré.");
        return false;
    }

    // Vérification taille fichier
    QFileInfo fileInfo(m_cheminImage);
    if (fileInfo.size() > 10 * 1024 * 1024) { // 10MB
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Fichier trop volumineux",
                                            "L'image est trop lourde.\n\n"
                                            "Taille maximale : 10 Mo\n"
                                            "Taille actuelle : " + QString::number(fileInfo.size() / (1024.0 * 1024.0), 'f', 2) + " Mo");
        return false;
    }

    // En mode manuel, on demande une vérification visuelle
    QMessageBox::StandardButton reponse = QMessageBox::question(
        m_btnSelect->parentWidget(),
        "🔍 Validation manuelle requise",
        "Veuillez vérifier visuellement :\n\n"
        "• ✅ L'image contient-elle un visage humain ?\n"
        "• ✅ Est-ce un portrait clair et approprié ?\n"
        "• ✅ La photo est-elle de bonne qualité ?\n\n"
        "Confirmez-vous que c'est un portrait valide ?",
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::Yes
        );

    if (reponse == QMessageBox::Yes) {
        qDebug() << "✅ Validation manuelle confirmée";
        return true;
    } else {
        qDebug() << "❌ Validation manuelle refusée";
        FeedbackUtilisateur::afficherInfo(m_btnSelect->parentWidget(),
                                          "Validation annulée",
                                          "La photo n'a pas été validée.\nVeuillez sélectionner une autre image.");
        return false;
    }
}

void ImageVer_C::redimensionnerEtAfficher(const QImage& image)
{
    if (!m_labelAffichage) return;

    qDebug() << "🖼️ Redimensionnement de l'image...";

    QImage imageRedimensionnee = image.scaled(m_labelAffichage->width(),
                                              m_labelAffichage->height(),
                                              Qt::KeepAspectRatio,
                                              Qt::SmoothTransformation);

    m_labelAffichage->setPixmap(QPixmap::fromImage(imageRedimensionnee));
    m_labelAffichage->setText("");

    // Changer le style pour indiquer une image valide
    m_labelAffichage->setStyleSheet(
        "QLabel {"
        "    border: 2px solid #28a745;"
        "    border-radius: 8px;"
        "    background-color: #f8fff9;"
        "}"
        );

    qDebug() << "✅ Image affichée dans le QLabel";
}

bool ImageVer_C::chargerImageExistante(const QString& chemin)
{
    qDebug() << "📂 Chargement image existante:" << chemin;

    if (chemin.isEmpty()) {
        reinitialiser();
        return false;
    }

    // Essayer le chemin absolu d'abord
    QImage image(chemin);

    // Si échec, essayer le chemin relatif dans photos/
    if (image.isNull()) {
        QString cheminRelatif = "photos/" + QFileInfo(chemin).fileName();
        qDebug() << "🔄 Essai avec chemin relatif:" << cheminRelatif;
        image.load(cheminRelatif);

        if (image.isNull()) {
            qDebug() << "❌ Impossible de charger l'image existante";
            FeedbackUtilisateur::afficherAvertissement(m_btnSelect->parentWidget(),
                                                       "Photo non trouvée",
                                                       "La photo associée à ce candidat n'a pas pu être chargée.\n"
                                                       "Elle a peut-être été déplacée ou supprimée.");
            reinitialiser();
            return false;
        }
        m_cheminImage = cheminRelatif;
    } else {
        m_cheminImage = chemin;
    }

    redimensionnerEtAfficher(image);
    FeedbackUtilisateur::afficherToast(m_btnSelect->parentWidget(), "Photo chargée");
    qDebug() << "✅ Image existante chargée avec succès";
    return true;
}

bool ImageVer_C::sauvegarderImagePourCandidat(int idCandidat)
{
    qDebug() << "💾 Début sauvegarde image pour candidat ID:" << idCandidat;

    if (m_cheminImage.isEmpty()) {
        qDebug() << "ℹ️ Aucune image à sauvegarder";
        return true; // Pas d'erreur si pas d'image
    }

    if (idCandidat <= 0) {
        qDebug() << "❌ ID candidat invalide pour sauvegarde image";
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Erreur de sauvegarde",
                                            "ID candidat invalide pour sauvegarder la photo.");
        return false;
    }

    // Créer le dossier photos s'il n'existe pas
    QDir dir("photos");
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "❌ Impossible de créer le dossier photos";
            FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                                "Erreur de sauvegarde",
                                                "Impossible de créer le dossier de stockage des photos.");
            return false;
        }
        qDebug() << "✅ Dossier photos créé";
    }

    // Générer le nouveau chemin avec hash pour éviter les doublons
    QString nomFichier = genererNomFichierUnique(idCandidat, m_cheminImage);
    QString nouveauChemin = QString("photos/%1").arg(nomFichier);

    qDebug() << "📁 Chemin de sauvegarde:" << nouveauChemin;

    // Vérifier si le fichier existe déjà
    if (QFile::exists(nouveauChemin)) {
        qDebug() << "⚠️ Fichier existe déjà, suppression de l'ancien:" << nouveauChemin;
        if (!QFile::remove(nouveauChemin)) {
            qDebug() << "❌ Impossible de supprimer l'ancien fichier";
            FeedbackUtilisateur::afficherAvertissement(m_btnSelect->parentWidget(),
                                                       "Attention",
                                                       "Impossible de remplacer l'ancienne photo.\n"
                                                       "La nouvelle photo ne sera pas sauvegardée.");
            return false;
        }
    }

    // Charger et sauvegarder l'image avec compression
    QImage image(m_cheminImage);
    if (image.isNull()) {
        qDebug() << "❌ Impossible de charger l'image source:" << m_cheminImage;
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Erreur d'image",
                                            "Impossible de charger l'image sélectionnée.\n"
                                            "Le fichier est peut-être corrompu.");
        return false;
    }

    // Optimiser l'image pour le stockage
    QImage imageOptimisee = optimiserImagePourStockage(image);

    bool success = imageOptimisee.save(nouveauChemin, "JPEG", 85); // Qualité 85%

    if (success) {
        m_cheminImage = nouveauChemin;
        qDebug() << "✅ Image sauvegardée:" << nouveauChemin;

        FeedbackUtilisateur::afficherToast(m_btnSelect->parentWidget(),
                                           "✅ Photo sauvegardée avec succès");
    } else {
        qDebug() << "❌ Erreur sauvegarde image:" << nouveauChemin;
        FeedbackUtilisateur::afficherErreur(m_btnSelect->parentWidget(),
                                            "Erreur de sauvegarde",
                                            "Impossible de sauvegarder la photo.\n"
                                            "Vérifiez les permissions du dossier.");
    }

    return success;
}

QString ImageVer_C::genererNomFichierUnique(int idCandidat, const QString& cheminSource)
{
    QFileInfo fileInfo(cheminSource);
    QString extension = fileInfo.suffix().toLower();
    if (extension != "jpg" && extension != "jpeg") {
        extension = "jpg"; // Standardiser en JPG
    }

    // Ajouter un hash du contenu pour éviter les doublons
    QFile file(cheminSource);
    if (file.open(QIODevice::ReadOnly)) {
        QCryptographicHash hash(QCryptographicHash::Md5);
        if (hash.addData(&file)) {
            QString hashString = hash.result().toHex().left(8);
            return QString("%1_%2.%3").arg(idCandidat).arg(hashString).arg(extension);
        }
    }

    // Fallback simple si hash échoue
    return QString("%1.%2").arg(idCandidat).arg(extension);
}

QImage ImageVer_C::optimiserImagePourStockage(const QImage& image)
{
    // Redimensionner si trop grande (max 800px côté le plus long)
    const int tailleMax = 800;
    QImage imageRedimensionnee = image;

    if (image.width() > tailleMax || image.height() > tailleMax) {
        imageRedimensionnee = image.scaled(tailleMax, tailleMax,
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation);
        qDebug() << "🖼️ Image redimensionnée de" << image.size() << "à" << imageRedimensionnee.size();
    }

    return imageRedimensionnee;
}

QString ImageVer_C::getCheminImage() const
{
    return m_cheminImage;
}

void ImageVer_C::reinitialiser()
{
    qDebug() << "🔄 Réinitialisation de ImageVer_C";

    m_cheminImage.clear();
    if (m_labelAffichage) {
        m_labelAffichage->clear();
        m_labelAffichage->setText("Aucune photo\nsélectionnée");
        m_labelAffichage->setStyleSheet(
            "QLabel {"
            "    border: 2px solid #cccccc;"
            "    border-radius: 8px;"
            "    background-color: #f8f9fa;"
            "    color: #6c757d;"
            "    font-weight: bold;"
            "    padding: 10px;"
            "}"
            );
    }
    qDebug() << "✅ ImageVer_C réinitialisé";
}

bool ImageVer_C::chargerImagePourModification(int idCandidat)
{
    if (idCandidat <= 0) {
        reinitialiser();
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT PHOTO_PATH FROM CANDIDATS WHERE ID_CANDIDAT = :id");
    query.bindValue(":id", idCandidat);

    if (query.exec() && query.next()) {
        QString photoPath = query.value(0).toString();
        qDebug() << "📁 Chargement photo pour modification:" << photoPath;

        if (!photoPath.isEmpty()) {
            bool chargementReussi = chargerImageExistante(photoPath);
            if (chargementReussi) {
                qDebug() << "✅ Photo chargée avec succès pour modification";
                return true;
            } else {
                qDebug() << "❌ Échec du chargement de la photo existante";
                reinitialiser();
                return false;
            }
        } else {
            reinitialiser();
            qDebug() << "ℹ️ Aucune photo existante pour ce candidat";
            return true; // Pas d'erreur si pas de photo
        }
    } else {
        reinitialiser();
        qDebug() << "❌ Erreur lors de la récupération de la photo depuis la BD";
        return false;
    }
}

void ImageVer_C::reinitialiserInterface()
{
    reinitialiser();
}
