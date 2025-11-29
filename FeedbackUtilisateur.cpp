#include "FeedbackUtilisateur.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QLabel>
#include <QTimer>

QProgressDialog* FeedbackUtilisateur::m_dialogChargement = nullptr;

void FeedbackUtilisateur::afficherSucces(QWidget* parent, const QString& titre, const QString& message)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(titre);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStyleSheet(
        "QMessageBox {"
        "    background-color: #f8fff9;"
        "    border: 1px solid #c3e6cb;"
        "}"
        "QMessageBox QLabel {"
        "    color: #155724;"
        "    font-size: 12px;"
        "}"
        "QPushButton {"
        "    background-color: #28a745;"
        "    color: white;"
        "    border: none;"
        "    padding: 8px 16px;"
        "    border-radius: 4px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #218838;"
        "}"
        );
    msgBox.exec();
}

void FeedbackUtilisateur::afficherErreur(QWidget* parent, const QString& titre, const QString& message, const QString& details)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle("❌ " + titre);

    QString texteComplet = message;
    if (!details.isEmpty()) {
        texteComplet += "\n\n🔧 Détails techniques :\n" + details;
    }

    msgBox.setText(texteComplet);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setStyleSheet(
        "QMessageBox {"
        "    background-color: #fdf2f2;"
        "    border: 1px solid #f5c6cb;"
        "}"
        "QMessageBox QLabel {"
        "    color: #721c24;"
        "    font-size: 12px;"
        "}"
        "QPushButton {"
        "    background-color: #dc3545;"
        "    color: white;"
        "    border: none;"
        "    padding: 8px 16px;"
        "    border-radius: 4px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #c82333;"
        "}"
        );
    msgBox.exec();
}

void FeedbackUtilisateur::afficherAvertissement(QWidget* parent, const QString& titre, const QString& message)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle("⚠️ " + titre);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStyleSheet(
        "QMessageBox {"
        "    background-color: #fff3cd;"
        "    border: 1px solid #ffeaa7;"
        "}"
        "QMessageBox QLabel {"
        "    color: #856404;"
        "    font-size: 12px;"
        "}"
        "QPushButton {"
        "    background-color: #ffc107;"
        "    color: #212529;"
        "    border: none;"
        "    padding: 8px 16px;"
        "    border-radius: 4px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #e0a800;"
        "}"
        );
    msgBox.exec();
}

void FeedbackUtilisateur::afficherInfo(QWidget* parent, const QString& titre, const QString& message)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle("ℹ️ " + titre);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStyleSheet(
        "QMessageBox {"
        "    background-color: #d1ecf1;"
        "    border: 1px solid #bee5eb;"
        "}"
        "QMessageBox QLabel {"
        "    color: #0c5460;"
        "    font-size: 12px;"
        "}"
        );
    msgBox.exec();
}

void FeedbackUtilisateur::afficherToast(QWidget* parent, const QString& message, int dureeMs)
{
    if (!parent) return;

    QLabel* toast = new QLabel(parent);
    toast->setText("✨ " + message);
    toast->setAlignment(Qt::AlignCenter);
    toast->setStyleSheet(
        "QLabel {"
        "    background-color: #28a745;"
        "    color: white;"
        "    padding: 12px 24px;"
        "    border-radius: 8px;"
        "    font-weight: bold;"
        "    font-size: 12px;"
        "    border: 2px solid #1e7e34;"
        "}"
        );

    toast->adjustSize();

    // Positionner en haut à droite du parent
    QPoint position(parent->width() - toast->width() - 20, 20);
    toast->move(position);
    toast->show();
    toast->raise();

    // Animation de disparition
    QTimer::singleShot(dureeMs, toast, [toast]() {
        QPropertyAnimation* animation = new QPropertyAnimation(toast, "windowOpacity");
        animation->setDuration(500);
        animation->setStartValue(1);
        animation->setEndValue(0);
        animation->start();

        QObject::connect(animation, &QPropertyAnimation::finished, toast, &QLabel::deleteLater);
    });
}

void FeedbackUtilisateur::afficherChargement(QWidget* parent, const QString& message)
{
    if (m_dialogChargement) {
        masquerChargement();
    }

    m_dialogChargement = new QProgressDialog(parent);
    m_dialogChargement->setWindowTitle("Chargement...");
    m_dialogChargement->setLabelText("⏳ " + message);
    m_dialogChargement->setCancelButton(nullptr);
    m_dialogChargement->setRange(0, 0); // Progress bar indéterminée
    m_dialogChargement->setModal(true);
    m_dialogChargement->setStyleSheet(
        "QProgressDialog {"
        "    background-color: white;"
        "    border: 2px solid #3498db;"
        "    border-radius: 8px;"
        "}"
        "QLabel {"
        "    color: #2c3e50;"
        "    font-size: 12px;"
        "    font-weight: bold;"
        "}"
        );

    m_dialogChargement->show();
    QApplication::processEvents();
}

void FeedbackUtilisateur::masquerChargement()
{
    if (m_dialogChargement) {
        m_dialogChargement->close();
        delete m_dialogChargement;
        m_dialogChargement = nullptr;
    }
}
