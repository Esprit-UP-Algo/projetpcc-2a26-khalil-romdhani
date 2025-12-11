#include "groq_manager.h"
#include "groq_predictor.h"
#include "connection.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QSqlQuery>

GroqManager::GroqManager(QObject *parent) : QObject(parent), m_predictor(new GroqPredictor(this))
{
    connect(m_predictor, &GroqPredictor::predictionReady, this, &GroqManager::onPredictionReady);
    connect(m_predictor, &GroqPredictor::predictionError, this, &GroqManager::onPredictionError);
}

void GroqManager::setupUI(QLineEdit* matriculeInput, QTextEdit* resultOutput,
                          QPushButton* predictButton, QPushButton* clearButton)
{
    m_matriculeInput = matriculeInput;
    m_resultOutput = resultOutput;
    connect(predictButton, &QPushButton::clicked, this, &GroqManager::onPredictClicked);
    connect(clearButton, &QPushButton::clicked, this, &GroqManager::onClearClicked);
}

void GroqManager::onPredictClicked()
{
    QString matricule = m_matriculeInput->text().trimmed();

    if(matricule.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "❌ Saisir un matricule"); return;
    }

    QRegularExpression pattern("^\\d{4}\\s*[Tt][Nn]\\s*\\d{2}$");
    if(!pattern.match(matricule).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur", "❌ Format invalide: 1234TN56"); return;
    }

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "Erreur", "❌ Connexion BD échouée"); return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM VEHICULES WHERE MATRICULE = :matricule");
    checkQuery.bindValue(":matricule", matricule);
    if(!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(nullptr, "Erreur", "❌ Matricule non trouvé"); return;
    }

    QSqlQuery vehicleQuery;
    vehicleQuery.prepare("SELECT TYPE_V, MARQUE_V, MODELE_V, KILOMETRAGE_V, ANNEE_V, DATE_MAINT_V, ETAT_V FROM VEHICULES WHERE MATRICULE = :matricule");
    vehicleQuery.bindValue(":matricule", matricule);
    if(!vehicleQuery.exec() || !vehicleQuery.next()) {
        QMessageBox::warning(nullptr, "Erreur", "❌ Erreur données"); return;
    }

    m_resultOutput->setPlainText("🔄 **Analyse en cours...**\nPatientez...");
    m_predictor->predictBreakdown(matricule,
                                  vehicleQuery.value(0).toString(), vehicleQuery.value(1).toString(),
                                  vehicleQuery.value(2).toString(), vehicleQuery.value(3).toInt(),
                                  vehicleQuery.value(4).toDate(), vehicleQuery.value(5).toDate(),
                                  vehicleQuery.value(6).toString());
}

void GroqManager::onClearClicked()
{
    m_matriculeInput->clear();
    m_resultOutput->clear();
}

void GroqManager::onPredictionReady(const QString& result)
{
    m_resultOutput->setPlainText(result);
}

void GroqManager::onPredictionError(const QString& error)
{
    m_resultOutput->setPlainText("❌ **ERREUR**\n\n" + error);
}
