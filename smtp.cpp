#include "smtp.h"
#include <QDebug>
#include <QSslSocket>
#include <QTextStream>

Smtp::Smtp(const QString &user, const QString &pass, const QString &host, int port, int timeout) {
    socket = new QSslSocket(this);

    // INITIALISATION IMPORTANTE
    t = new QTextStream(socket);

    connect(socket, &QAbstractSocket::stateChanged, this, &Smtp::stateChanged);
    connect(socket, &QAbstractSocket::errorOccurred, this, &Smtp::errorReceived);
    connect(socket, &QAbstractSocket::disconnected, this, &Smtp::disconnected);
    connect(socket, &QAbstractSocket::connected, this, &Smtp::connected);
    connect(socket, &QAbstractSocket::readyRead, this, &Smtp::readyRead);

    this->user = user;
    this->pass = pass;
    this->host = host;
    this->port = port;
    this->timeout = timeout;

    // Initialiser l'état
    state = Init;
}

Smtp::~Smtp() {
    if (t) {
        delete t;
        t = nullptr;
    }
    if (socket) {
        delete socket;
        socket = nullptr;
    }
}

void Smtp::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body) {
    message = "To: " + to + "\n";
    message.append("From: " + from + "\n");
    message.append("Subject: " + subject + "\n");
    message.append("\n");
    message.append(body);
    message.replace(QString::fromLatin1("\n"), QString::fromLatin1("\r\n"));
    message.replace(QString::fromLatin1("\r\n.\r\n"), QString::fromLatin1("\r\n..\r\n"));

    this->from = from;
    rcpt = to;
    state = Init;

    qDebug() << "🔌 Connexion à" << host << ":" << port;
    socket->connectToHostEncrypted(host, port);

    if (!socket->waitForConnected(timeout)) {
        qDebug() << "❌ Échec connexion:" << socket->errorString();
        emit status("Connection failed: " + socket->errorString());
        return;
    }

    qDebug() << "✅ Connecté au serveur SMTP";
}

void Smtp::stateChanged(QAbstractSocket::SocketState socketState) {
    qDebug() << "🔧 État socket:" << socketState;
}

void Smtp::errorReceived(QAbstractSocket::SocketError error) {
    qDebug() << "❌ Erreur socket:" << error << "-" << socket->errorString();
    emit status("Socket Error: " + socket->errorString());
}

void Smtp::disconnected() {
    qDebug() << "🔌 Déconnecté du serveur SMTP";
    emit status("Disconnected");
}

void Smtp::connected() {
    qDebug() << "🔗 Connecté au serveur SMTP, attente du message de bienvenue...";
    emit status("Connected to SMTP server");
}

void Smtp::readyRead() {
    QString responseLine;

    // Lire toutes les lignes disponibles
    while (socket->canReadLine()) {
        responseLine = socket->readLine();
        response += responseLine;
        qDebug() << "📨 Réponse serveur:" << responseLine.trimmed();
    }

    // Traiter la réponse complète
    if (response.endsWith("\r\n") || response.endsWith("\n")) {
        processResponse();
        response = ""; // Reset pour la prochaine réponse
    }
}

void Smtp::processResponse() {
    QString responseCode = response.left(3);
    bool ok;
    int code = responseCode.toInt(&ok);

    if (!ok) {
        qDebug() << "❌ Réponse SMTP invalide:" << response;
        emit status("Invalid SMTP response: " + response);
        return;
    }

    qDebug() << "🔄 Traitement code:" << code << "| État actuel:" << state;

    switch (state) {
    case Init:
        if (code == 220) {
            // Serveur prêt - envoyer EHLO
            *t << "EHLO localhost\r\n";
            t->flush();
            state = EhloSent;
            qDebug() << "📤 Envoyé: EHLO localhost";
        } else {
            qDebug() << "❌ Réponse inattendue lors de l'init:" << response;
            emit status("Unexpected response: " + response);
        }
        break;

    case EhloSent:
        if (code == 250) {
            // EHLO accepté - démarrer l'authentification
            *t << "AUTH LOGIN\r\n";
            t->flush();
            state = AuthSent;
            qDebug() << "📤 Envoyé: AUTH LOGIN";
        } else {
            qDebug() << "❌ Échec EHLO:" << response;
            emit status("EHLO failed: " + response);
        }
        break;

    case AuthSent:
        if (code == 334) {
            if (response.contains("VXNlcm5hbWU6", Qt::CaseInsensitive) ||
                response.contains("334", Qt::CaseInsensitive)) {
                // Demande du username
                *t << user.toUtf8().toBase64() << "\r\n";
                t->flush();
                state = UserSent;
                qDebug() << "📤 Envoyé: Username (base64)";
            }
        } else {
            qDebug() << "❌ Échec AUTH LOGIN:" << response;
            emit status("AUTH LOGIN failed: " + response);
        }
        break;

    case UserSent:
        if (code == 334) {
            if (response.contains("UGFzc3dvcmQ6", Qt::CaseInsensitive) ||
                response.contains("334", Qt::CaseInsensitive)) {
                // Demande du password
                *t << pass.toUtf8().toBase64() << "\r\n";
                t->flush();
                state = PassSent;
                qDebug() << "📤 Envoyé: Password (base64)";
            }
        } else {
            qDebug() << "❌ Échec username:" << response;
            emit status("Username auth failed: " + response);
        }
        break;

    case PassSent:
        if (code == 235) {
            // Authentification réussie
            *t << "MAIL FROM: <" << from << ">\r\n";
            t->flush();
            state = MailFromSent;
            qDebug() << "📤 Envoyé: MAIL FROM";
        } else {
            qDebug() << "❌ Échec authentification:" << response;
            emit status("Authentication failed: " + response);
        }
        break;

    case MailFromSent:
        if (code == 250) {
            // MAIL FROM accepté
            *t << "RCPT TO: <" << rcpt << ">\r\n";
            t->flush();
            state = RcptToSent;
            qDebug() << "📤 Envoyé: RCPT TO";
        } else {
            qDebug() << "❌ Échec MAIL FROM:" << response;
            emit status("MAIL FROM failed: " + response);
        }
        break;

    case RcptToSent:
        if (code == 250) {
            // RCPT TO accepté
            *t << "DATA\r\n";
            t->flush();
            state = DataSent;
            qDebug() << "📤 Envoyé: DATA";
        } else {
            qDebug() << "❌ Échec RCPT TO:" << response;
            emit status("RCPT TO failed: " + response);
        }
        break;

    case DataSent:
        if (code == 354) {
            // Prêt à recevoir les données
            *t << message << "\r\n.\r\n";
            t->flush();
            state = MessageSent;
            qDebug() << "📤 Envoyé: Message body";
        } else {
            qDebug() << "❌ Échec DATA:" << response;
            emit status("DATA command failed: " + response);
        }
        break;

    case MessageSent:
        if (code == 250) {
            // Message accepté
            *t << "QUIT\r\n";
            t->flush();
            state = QuitSent;
            qDebug() << "📤 Envoyé: QUIT";
        } else {
            qDebug() << "❌ Échec envoi message:" << response;
            emit status("Message sending failed: " + response);
        }
        break;

    case QuitSent:
        if (code == 221) {
            // Déconnexion propre
            qDebug() << "✅ Message envoyé avec succès!";
            emit status("Message sent successfully");
            socket->disconnectFromHost();
        } else {
            qDebug() << "⚠️  Réponse inattendue après QUIT:" << response;
        }
        break;

    default:
        qDebug() << "❌ État inconnu:" << state;
        break;
    }
}
