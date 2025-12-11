#ifndef CHATBOT_H
#define CHATBOT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QSqlDatabase>
#include <QTimer>

class ChatBot : public QObject
{
    Q_OBJECT
public:
    explicit ChatBot(QObject *parent = nullptr);
    void setDatabase(const QSqlDatabase &db);
    void ask(const QString &message);

signals:
    void replyReady(const QString &reply);
    void errorOccured(const QString &err);

private slots:
    void onFinished(QNetworkReply *reply);

private:
    // helpers
    QString detectSql(const QString &question) const;
    QString execSql(const QString &sql) const;
    QString buildPrompt(const QString &question, const QString &sqlResult, bool isGeneralQuestion) const;
    bool isGeneralKnowledgeQuestion(const QString &question) const; // ✅ NOUVELLE FONCTION

private:
    QNetworkAccessManager *manager;
    QSqlDatabase m_db;
    QTimer *timeoutTimer;
};

#endif // CHATBOT_H
