#ifndef IMAGEVER_C_H
#define IMAGEVER_C_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QDir>
#include <QApplication>
#include <QBuffer>
#include <QDebug>
#include <QCryptographicHash>
#include <QSqlQuery> // AJOUT IMPORTANT
#include <QSqlError> // AJOUT IMPORTANT

class ImageVer_C : public QObject
{
    Q_OBJECT

public:
    explicit ImageVer_C(QPushButton* btnSelect, QLabel* labelAffichage, QObject *parent = nullptr);
    ~ImageVer_C();

    // Méthodes principales
    bool selectionnerEtVerifierImage();
    bool chargerImageExistante(const QString& chemin);
    QString getCheminImage() const;
    void reinitialiser();
    bool sauvegarderImagePourCandidat(int idCandidat);
    bool chargerImagePourModification(int idCandidat); // NOUVELLE MÉTHODE
    void reinitialiserInterface(); // NOUVELLE MÉTHODE

private:
    // Méthodes helper
    bool estImageValide(const QImage& image);
    void redimensionnerEtAfficher(const QImage& image);
    QString genererNomFichierUnique(int idCandidat, const QString& cheminSource);
    QImage optimiserImagePourStockage(const QImage& image);

    // Membres
    QPushButton* m_btnSelect;
    QLabel* m_labelAffichage;
    QString m_cheminImage;
};

#endif // IMAGEVER_C_H
