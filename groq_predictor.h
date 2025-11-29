#ifndef GROQ_PREDICTOR_H
#define GROQ_PREDICTOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class GroqPredictor : public QObject
{
    Q_OBJECT
public:
    explicit GroqPredictor(QObject *parent = nullptr);
    void predictBreakdown(const QString& matricule, const QString& type,
                          const QString& marque, const QString& modele, int kilometrage,
                          const QDate& dateAchat, const QDate& dateMaintenance, const QString& etat);

signals:
    void predictionReady(const QString& result);
    void predictionError(const QString& error);

private slots:
    void onNetworkReply(QNetworkReply* reply);

private:
    QNetworkAccessManager* m_networkManager;
    QString m_apiKey;
    QString createFrenchPrompt(const QString& matricule, const QString& type,
                               const QString& marque, const QString& modele,
                               int kilometrage, int vehicleAgeYears,
                               int daysSinceMaintenance, const QString& etat);
};

#endif
