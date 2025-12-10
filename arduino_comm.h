#ifndef ARDUINO_COMM_H
#define ARDUINO_COMM_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QIODevice>

class ArduinoComm : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoComm(QObject *parent = nullptr);
    ~ArduinoComm();

    // Ouverture du port série
    bool openPort(const QString &portName = "COM3", qint32 baudRate = QSerialPort::Baud9600);

    // Vérifications
    bool isOpen() const;
    QString portName() const;
    QString errorString() const;

    // Envoi de données
    qint64 sendNumber(int number);  // Envoi nombre comme string + \n (ex: "2\n" pour afficheur)
    qint64 write(const QByteArray &data);
    void flush();  // Force envoi immédiat

    // Fermeture
    void closePort();

signals:
    void dataReceived(const QByteArray &data);  // Signal pour réception (optionnel, connecte à slot si besoin)
    void errorOccurred(const QString &error);   // Signal pour erreurs série

private slots:
    void handleReadyRead();    // Lecture auto si connecté
    void handleError(QSerialPort::SerialPortError error);  // Gestion erreurs série

private:
    QSerialPort *m_serial;
};

#endif // ARDUINO_COMM_H
