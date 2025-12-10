#ifndef SMTP_H
#define SMTP_H

#include <QObject>
#include <QString>
#include <QTextStream>
#include <QSslSocket>

class Smtp : public QObject
{
    Q_OBJECT

public:
    Smtp(const QString &user, const QString &pass, const QString &host, int port = 465, int timeout = 30000);
    ~Smtp();

    void sendMail(const QString &from, const QString &to, const QString &subject, const QString &body);

signals:
    void status(const QString &msg);

private slots:
    void stateChanged(QAbstractSocket::SocketState state);
    void errorReceived(QAbstractSocket::SocketError error);
    void disconnected();
    void connected();
    void readyRead();

private:
    void processResponse();

    enum State {
        Init,
        EhloSent,
        AuthSent,
        UserSent,
        PassSent,
        MailFromSent,
        RcptToSent,
        DataSent,
        MessageSent,
        QuitSent
    };

    QSslSocket *socket;
    QTextStream *t;
    QString message;
    QString from;
    QString rcpt;
    QString user;
    QString pass;
    QString host;
    QString response;
    int port;
    int timeout;
    State state;
};

#endif // SMTP_H
