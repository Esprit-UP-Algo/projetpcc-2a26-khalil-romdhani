#include "ArduinoManager.h"
#include <QDebug>
#include <QThread>

ArduinoManager::ArduinoManager(QObject *parent)
    : QObject(parent)
    , m_arduino(new Arduino())
    , m_connectionTimer(new QTimer(this))
    , m_isConnected(false)
{
    m_connectionTimer->setInterval(5000);
    connect(m_connectionTimer, &QTimer::timeout, this, &ArduinoManager::checkConnection);
}

ArduinoManager::~ArduinoManager()
{
    disconnect();
    delete m_arduino;
}

bool ArduinoManager::connectToArduino()
{
    int result = m_arduino->connect_arduino();

    if (result == 0) {
        m_isConnected = true;
        qDebug() << "✅ Arduino connecté sur port:" << m_arduino->getarduino_port_name();
        m_connectionTimer->start();
        connect(m_arduino->getserial(), &QSerialPort::readyRead,
                this, &ArduinoManager::onDataReceived);

        emit connectionStatusChanged(true);
        return true;
    } else {
        m_isConnected = false;
        emit connectionStatusChanged(false);
        return false;
    }
}

void ArduinoManager::disconnect()
{
    if (m_isConnected) {
        m_arduino->close_arduino();
        m_isConnected = false;
        m_connectionTimer->stop();
        emit connectionStatusChanged(false);
    }
}

bool ArduinoManager::isConnected() const
{
    return m_isConnected;
}

void ArduinoManager::sendCandidateSelection(int id, int percent)
{
    QString command = QString("SHOW:%1:%2\n")
    .arg(id)
        .arg(percent);

    m_arduino->write_to_arduino(command.toUtf8());
}
void ArduinoManager::sendUpdateSuccess()
{
    if (!m_isConnected) return;
    m_arduino->write_to_arduino("SUCCESS\n");
}

void ArduinoManager::sendError(const QString &message)
{
    if (!m_isConnected) return;
    QString shortMessage;

    if (message.contains("CONDUITE", Qt::CaseInsensitive)) {
        shortMessage = "NEEDS_CODE";
    }
    else if (message.contains("PARC", Qt::CaseInsensitive)) {
        shortMessage = "NEEDS_BOTH";
    }
    else if (message.contains("CANDIDAT", Qt::CaseInsensitive)) {
        shortMessage = "NO_CANDIDATE";
    }
    else {
        shortMessage = message.left(15); // Limiter à 15 caractères
    }

    QString command = QString("ERROR:%1\n").arg(shortMessage);
    m_arduino->write_to_arduino(command.toUtf8());
}

void ArduinoManager::sendDisplayMessage(const QString &message)
{
    if (!m_isConnected) return;

    QString command = QString("MSG:%1\n").arg(message.left(20));
    m_arduino->write_to_arduino(command.toUtf8());
}

void ArduinoManager::setLEDColor(const QString &color, bool blink)
{
    if (!m_isConnected) return;

    QString command = QString("LED:%1:%2\n")
                          .arg(color)
                          .arg(blink ? "BLINK" : "SOLID");
    m_arduino->write_to_arduino(command.toUtf8());
}

void ArduinoManager::onDataReceived()
{
    QByteArray data = m_arduino->read_from_arduino();

    if (!data.isEmpty()) {
        m_buffer.append(data);

        while (m_buffer.contains('\n')) {
            int newlinePos = m_buffer.indexOf('\n');
            QByteArray line = m_buffer.left(newlinePos).trimmed();
            m_buffer = m_buffer.mid(newlinePos + 1);

            if (!line.isEmpty()) {
                processIncomingData(line);
            }
        }
    }
}

void ArduinoManager::processIncomingData(const QByteArray &data)
{
    QString command = QString::fromUtf8(data);
    ButtonType button = parseButtonCommand(command);
    if (button != BUTTON_NONE) {
        emit buttonPressed(button);
    }
}

ArduinoManager::ButtonType ArduinoManager::parseButtonCommand(const QString &command)
{
    if (command == "BTN:CODE") {
        return BUTTON_CODE;
    }
    else if (command == "BTN:CONDUITE") {
        return BUTTON_CONDUITE;
    }
    else if (command == "BTN:PARC") {
        return BUTTON_PARC;
    }
    else if (command == "CONFIRM") {
        return BUTTON_CONFIRM;
    }

    return BUTTON_NONE;
}

void ArduinoManager::checkConnection()
{
    if (!m_isConnected) {
        connectToArduino();
    }
}

void ArduinoManager::sendCandidateDetails(int id, int percent, const QString &nom, const QString &prenom)
{
    if (!m_isConnected) {
        return;
    }
    QString nomCourt = nom.left(8);
    QString prenomCourt = prenom.left(8);
    QString command = QString("DETAILS:%1:%2:%3:%4\n")
                          .arg(id)
                          .arg(percent)
                          .arg(nomCourt)
                          .arg(prenomCourt);

    m_arduino->write_to_arduino(command.toUtf8());
}
