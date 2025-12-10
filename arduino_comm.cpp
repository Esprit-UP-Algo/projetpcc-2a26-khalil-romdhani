#include "arduino_comm.h"

ArduinoComm::ArduinoComm(QObject *parent)
    : QObject(parent), m_serial(new QSerialPort(this))
{
    // Configuration par défaut série (Arduino standard)
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    // Connect signals internes
    connect(m_serial, &QSerialPort::readyRead, this, &ArduinoComm::handleReadyRead);
    connect(m_serial, QOverload<QSerialPort::SerialPortError>::of(&QSerialPort::errorOccurred),
            this, &ArduinoComm::handleError);
}

ArduinoComm::~ArduinoComm()
{
    closePort();
}

bool ArduinoComm::openPort(const QString &portName, qint32 baudRate)
{
    if (isOpen()) {
        qDebug() << "Port déjà ouvert:" << m_serial->portName();
        return true;
    }

    m_serial->setPortName(portName);
    m_serial->setBaudRate(baudRate);

    if (m_serial->open(QIODevice::ReadWrite)) {
        qDebug() << "✅ Port série ouvert:" << portName << "@" << baudRate;
        return true;
    } else {
        QString err = m_serial->errorString();
        qDebug() << "❌ Échec ouverture port" << portName << ":" << err;
        emit errorOccurred(err);
        return false;
    }
}

bool ArduinoComm::isOpen() const
{
    return m_serial->isOpen();
}

QString ArduinoComm::portName() const
{
    return m_serial->portName();
}

QString ArduinoComm::errorString() const
{
    return m_serial->errorString();
}

qint64 ArduinoComm::sendNumber(int number)
{
    if (!isOpen()) {
        qDebug() << "❌ Port fermé – Impossible d'envoyer" << number;
        return -1;
    }

    QByteArray data = QByteArray::number(number) + "\n";  // Ex: "2\n" pour Arduino
    return write(data);
}

qint64 ArduinoComm::write(const QByteArray &data)
{
    if (!isOpen()) {
        qDebug() << "❌ Port fermé – Impossible d'écrire";
        return -1;
    }

    qint64 bytes = m_serial->write(data);
    if (bytes == -1) {
        qDebug() << "❌ Échec write:" << errorString();
        emit errorOccurred(errorString());
    } else {
        qDebug() << "📤 Écrit" << bytes << "octets:" << data;
    }
    return bytes;
}

void ArduinoComm::flush()
{
    if (isOpen()) {
        m_serial->flush();
        qDebug() << "📤 Flush effectué.";
    }
}

void ArduinoComm::closePort()
{
    if (isOpen()) {
        m_serial->close();
        qDebug() << "🔒 Port fermé:" << portName();
    }
}

// Slots privés
void ArduinoComm::handleReadyRead()
{
    QByteArray data = m_serial->readAll();
    qDebug() << "📥 Reçu:" << data;
    emit dataReceived(data);  // Pour debug ou UI update
}

void ArduinoComm::handleError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        QString err = m_serial->errorString();
        qDebug() << "⚠️ Erreur série:" << error << "-" << err;
        emit errorOccurred(err);
    }
}
