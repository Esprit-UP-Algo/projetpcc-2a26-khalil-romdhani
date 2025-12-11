#ifndef GROQ_CONFIG_H
#define GROQ_CONFIG_H

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

class GroqConfig {
public:
    static QString getApiKey() {
        QString key = qEnvironmentVariable("GROQ_API_KEY");
        if(!key.isEmpty() && key != "YOUR_GROQ_API_KEY_HERE") return key;

        key = loadKeyFromConfig();
        if(!key.isEmpty() && key != "YOUR_GROQ_API_KEY_HERE") return key;

        showSetupInstructions();
        return "";
    }

private:
    static QString loadKeyFromConfig() {
        QFile configFile("config.json");
        if(!configFile.open(QIODevice::ReadOnly)) return "";
        QJsonDocument doc = QJsonDocument::fromJson(configFile.readAll());
        configFile.close();
        QString key = doc.object()["groq_api_key"].toString();
        return key;
    }

    static void showSetupInstructions() {
        QMessageBox::information(nullptr, "Configuration Groq Requise",
                                 "🔧 **Configuration API Groq**\n\n"
                                 "1. Obtenez une clé API GRATUITE sur: https://console.groq.com\n"
                                 "2. Configurez la variable: GROQ_API_KEY=votre_clé_ici\n"
                                 "3. Redémarrez l'application\n\n"
                                 "✅ Aucune carte de crédit requise!");
    }
};

#endif
