#ifndef FEEDBACKUTILISATEUR_H
#define FEEDBACKUTILISATEUR_H

#include <QMessageBox>
#include <QProgressDialog>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include <QApplication>
#include <QScreen>

class FeedbackUtilisateur
{
public:
    static void afficherSucces(QWidget* parent, const QString& titre, const QString& message);
    static void afficherErreur(QWidget* parent, const QString& titre, const QString& message, const QString& details = "");
    static void afficherAvertissement(QWidget* parent, const QString& titre, const QString& message);
    static void afficherInfo(QWidget* parent, const QString& titre, const QString& message);

    static void afficherToast(QWidget* parent, const QString& message, int dureeMs = 3000);
    static void afficherChargement(QWidget* parent, const QString& message);
    static void masquerChargement();

private:
    static QProgressDialog* m_dialogChargement;
};

#endif
