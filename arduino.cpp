#include "arduino.h"
#include <QDebug>

Arduino::Arduino()
{
    serial = new QSerialPort();
    arduino_is_available = false;
    arduino_port_name = "";
    data = "";
}

int Arduino::connect_arduino(const QString &forcedPort)
{
    arduino_is_available = false;
    arduino_port_name.clear();

    // 1) Try an explicitly requested port first (ex: COM11)
    if (!forcedPort.isEmpty()) {
        serial->setPortName(forcedPort);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            arduino_is_available = true;
            arduino_port_name = forcedPort;
            qDebug() << "[Arduino] Connected on forced port" << forcedPort;
            return 0;
        } else {
            qDebug() << "[Arduino] Failed to open forced port" << forcedPort << ":" << serial->errorString();
            serial->close();
        }
    }

    // 2) Auto-detect by vendor/product ID (fallback)
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id
                && serial_port_info.productIdentifier() == arduino_uno_product_id)
            {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                break;
            }
        }
    }

    qDebug() << "[Arduino] auto-detected port:" << arduino_port_name;
    if(arduino_is_available)
    {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite))
        {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int Arduino::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}

void Arduino::write_to_arduino(QByteArray d)
{
    if(serial->isWritable())
    {
        serial->write(d);
    }
    else
    {
        qDebug() << "Couldn't write to serial!";
    }
}

QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable())
    {
        data = serial->readAll();
        return data;
    }
    return QByteArray();
}

QSerialPort* Arduino::getserial()
{
    return serial;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

int Arduino::envoyerSelectionCandidat(int idCandidat, const QString& progression)
{
    if(serial->isWritable()) {
        QByteArray commande = "SELECT:" + QByteArray::number(idCandidat) + ":" + progression.toUtf8() + "\n";
        serial->write(commande);
        qDebug() << "Commande envoyée à Arduino:" << commande;
        return 0;
    }
    return 1;
}

int Arduino::envoyerReset()
{
    if(serial->isWritable()) {
        QByteArray commande = "RESET\n";
        serial->write(commande);
        qDebug() << "Reset envoyé à Arduino";
        return 0;
    }
    return 1;
}

QString Arduino::lireReponse()
{
    if(serial->isReadable()) {
        QByteArray data = serial->readAll();
        QString reponse = QString::fromUtf8(data).trimmed();
        if(!reponse.isEmpty()) {
            qDebug() << "Réponse Arduino:" << reponse;
        }
        return reponse;
    }
    return QString();
}
