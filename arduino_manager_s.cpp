#include "arduino_manager_s.h"
#include <QTimer>

ArduinoManagerS::ArduinoManagerS(QObject *parent)
    : QObject(parent)
    , m_arduinoComm(nullptr)
{
    m_arduinoComm = new ArduinoComm(this);
    qDebug() << "✅ ArduinoManagerS initialisé.";
}

ArduinoManagerS::~ArduinoManagerS()
{
    if (m_arduinoComm) {
        delete m_arduinoComm;
    }
}

void ArduinoManagerS::compterEtEnvoyerSeances(const QString &salleStr)
{
    if (salleStr.isEmpty()) {
        emit messageWarning("Veuillez entrer un numéro de salle (1-9) !");
        return;
    }

    bool isValid;
    int salleNum = salleStr.toInt(&isValid);
    if (!isValid || salleNum < 1 || salleNum > 9) {
        emit messageWarning("La salle doit être un chiffre entre 1 et 9 !");
        return;
    }

    // Vérif Connexion DB
    if (!Connection::instance()->isConnected()) {
        if (!Connection::instance()->reconnect()) {
            emit messageError("Reconnexion DB échouée !");
            return;
        }
    }

    // COMPTAGE SÉANCES DANS LA SALLE
    int nbSeances = 0;
    QSqlQuery query(Connection::instance()->getDb());
    query.prepare("SELECT COUNT(*) FROM SEANCES WHERE SALLE_S = ?");
    query.addBindValue(salleStr);
    if (!query.exec()) {
        qDebug() << "❌ Erreur comptage:" << query.lastError().text();
        emit messageError("Erreur comptage: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        nbSeances = query.value(0).toInt();
        qDebug() << "📊 Séances en salle" << salleNum << ":" << nbSeances;
    } else {
        qDebug() << "ℹ️ Requête vide.";
        nbSeances = 0;
    }

    // ENVOI VERS ARDUINO (TOUJOURS envoyer, même si 0)
    if (!m_arduinoComm) {
        qDebug() << "❌ ArduinoComm non initialisé !";
        emit messageError("Module Arduino non chargé.");
        return;
    }

    // Toujours envoyer, même si 0 séances
    int chiffreAEnvoyer = nbSeances % 10;  // Unité (ex: 0, 1, 2, ..., 9)

    if (envoyerVersArduino(chiffreAEnvoyer)) {
        qDebug() << "✅ Envoi Arduino:" << chiffreAEnvoyer << "(séances:" << nbSeances << ")";
    } else {
        qDebug() << "❌ Échec envoi Arduino";
        return;
    }

    emit messageInfo(QString("Séances en salle %1 : %2").arg(salleNum).arg(nbSeances));
}

bool ArduinoManagerS::envoyerVersArduino(int nombre)
{
    if (!m_arduinoComm) {
        emit messageError("ArduinoComm non initialisé !");
        return false;
    }

    // Vérifier si le port est ouvert
    if (!m_arduinoComm->isOpen()) {
        qDebug() << "Port série fermé, tentative d'ouverture...";
        if (!ouvrirPort()) {
            emit messageError("Échec ouverture port série: " + m_arduinoComm->errorString());
            return false;
        }
    }

    // Préparer la donnée à envoyer
    QString data = QString::number(nombre) + "\n";
    QByteArray byteData = data.toUtf8();

    qDebug() << "Envoi à Arduino:" << data.trimmed();

    // Envoyer les données
    qint64 bytesWritten = m_arduinoComm->write(byteData);

    if (bytesWritten == -1) {
        qDebug() << "❌ Échec d'envoi:" << m_arduinoComm->errorString();
        emit messageError("Envoi échoué: " + m_arduinoComm->errorString());
        return false;
    }

    // Utiliser QTimer pour attendre sans bloquer
    QEventLoop loop;
    QTimer::singleShot(100, &loop, &QEventLoop::quit);
    loop.exec();

    qDebug() << "✅ Envoi réussi:" << bytesWritten << "octets";

    return true;
}

bool ArduinoManagerS::ouvrirPort(const QString &portName)
{
    // Si aucun port n'est spécifié, essayer les ports COM courants
    if (portName.isEmpty()) {
        QStringList ports;
        ports << "COM3" << "COM4" << "COM5" << "COM6" << "COM7" << "COM8";

        for (const QString &port : ports) {
            qDebug() << "Tentative d'ouverture sur" << port;
            if (m_arduinoComm->openPort(port)) {
                qDebug() << "✅ Port ouvert:" << port;
                return true;
            }
        }

        qDebug() << "❌ Aucun port disponible";
        return false;
    }

    // Ouvrir le port spécifié
    return m_arduinoComm->openPort(portName);
}
