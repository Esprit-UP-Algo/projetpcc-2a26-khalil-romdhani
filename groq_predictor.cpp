#include "groq_predictor.h"
#include "groq_config.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QDate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QNetworkRequest>

GroqPredictor::GroqPredictor(QObject *parent) : QObject(parent), m_networkManager(new QNetworkAccessManager(this))
{
    m_apiKey = GroqConfig::getApiKey();
    connect(m_networkManager, &QNetworkAccessManager::finished, this, &GroqPredictor::onNetworkReply);
}

void GroqPredictor::predictBreakdown(const QString& matricule, const QString& type, const QString& marque,
                                     const QString& modele, int kilometrage, const QDate& dateAchat,
                                     const QDate& dateMaintenance, const QString& etat)
{
    if(m_apiKey.isEmpty()) {
        emit predictionError("❌ Clé API Groq non configurée");
        return;
    }

    qDebug() << "API Key:" << m_apiKey;
    qDebug() << "API Key length:" << m_apiKey.length();
    qDebug() << "First 10 chars:" << m_apiKey.left(10);

    int vehicleAgeYears = QDate::currentDate().year() - dateAchat.year();
    if(vehicleAgeYears < 0) vehicleAgeYears = 0;

    int daysSinceMaintenance = dateMaintenance.daysTo(QDate::currentDate());
    if(daysSinceMaintenance < 0) daysSinceMaintenance = 0;

    QString prompt = createFrenchPrompt(matricule, type, marque, modele, kilometrage, vehicleAgeYears, daysSinceMaintenance, etat);

    QNetworkRequest request;
    QUrl apiUrl("https://api.groq.com/openai/v1/chat/completions");
    request.setAttribute(QNetworkRequest::Http2AllowedAttribute, false);
    request.setUrl(apiUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(m_apiKey).toUtf8());

    QJsonObject requestBody;
    requestBody["model"] = "llama-3.1-8b-instant";
    requestBody["temperature"] = 0.3;
    requestBody["max_tokens"] = 1024;

    QJsonArray messages;
    QJsonObject systemMessage;
    systemMessage["role"] = "system";
    systemMessage["content"] = "Tu es un expert automobile Tunisien. Réponds en français de manière concise et technique.";
    messages.append(systemMessage);

    QJsonObject userMessage;
    userMessage["role"] = "user";
    userMessage["content"] = prompt;
    messages.append(userMessage);

    requestBody["messages"] = messages;

    QJsonDocument doc(requestBody);
    QByteArray jsonData = doc.toJson();

    qDebug() << "Envoi requête à Groq API...";
    m_networkManager->post(request, jsonData);
}

QString GroqPredictor::createFrenchPrompt(const QString& matricule, const QString& type, const QString& marque, const QString& modele,
                                          int kilometrage, int vehicleAgeYears, int daysSinceMaintenance, const QString& etat)
{
    return QString(
               "Analyse ce véhicule tunisien et prédit le risque de panne:\n\n"
               "MATRICULE: %1\n"
               "TYPE: %2\n"
               "MARQUE: %3\n"
               "MODÈLE: %4\n"
               "KILOMÉTRAGE: %5 km\n"
               "ÂGE: %6 ans\n"
               "DERNIER ENTRETIEN: il y a %7 jours\n"
               "ÉTAT ACTUEL: %8\n\n"
               "Réponds en français avec ce format exact:\n"
               "🚗 VÉHICULE: [marque et modèle]\n"
               "⚠️ RISQUE: [Faible/Moyen/Élevé]\n"
               "📊 PROBABILITÉ: [XX%]\n"
               "⏰ DÉLAI: [X semaines/mois]\n"
               "🔧 PROBLÈMES: [liste]\n"
               "✅ ACTIONS: [liste]\n"
               "💡 CONSEIL: [conseil expert]"
               ).arg(matricule).arg(type).arg(marque).arg(modele)
        .arg(kilometrage).arg(vehicleAgeYears).arg(daysSinceMaintenance).arg(etat);
}

void GroqPredictor::onNetworkReply(QNetworkReply* reply)
{
    if(reply->error() != QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        qDebug() << "Full error response:" << response;

        emit predictionError("❌ Erreur réseau: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    reply->deleteLater();

    if(doc.isNull()) {
        emit predictionError("❌ Réponse API invalide");
        return;
    }

    QJsonObject responseObj = doc.object();

    if(responseObj.contains("error")) {
        QString errorMsg = responseObj["error"].toObject()["message"].toString();
        emit predictionError("❌ Erreur API Groq: " + errorMsg);
        return;
    }

    QString groqText = "";
    if(responseObj.contains("choices")) {
        QJsonArray choices = responseObj["choices"].toArray();
        if(!choices.isEmpty()) {
            QJsonObject firstChoice = choices[0].toObject();
            if(firstChoice.contains("message")) {
                QJsonObject message = firstChoice["message"].toObject();
                if(message.contains("content")) {
                    groqText = message["content"].toString();
                }
            }
        }
    }

    if(groqText.isEmpty()) {
        emit predictionError("❌ Réponse vide de l'API Groq");
        return;
    }

    emit predictionReady("🤖 **PRÉDICTION GROQ AI**\n\n" + groqText + "\n\n---\n*Généré par Groq Cloud AI*");
}
