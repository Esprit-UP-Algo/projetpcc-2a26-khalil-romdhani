#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <QString>

class Arduino
{
public:    // méthodes de la classe Arduino
    Arduino();
    int connect_arduino(const QString &forcedPort = QString()); // permet de connecter le PC à Arduino
    int close_arduino(); // permet de fermer la connexion
    void write_to_arduino(QByteArray); // envoyer des données vers arduino
    QByteArray read_from_arduino(); // recevoir des données de la carte Arduino
    QSerialPort* getserial(); // accesseur
    QString getarduino_port_name();
    // Dans arduino.h, ajoutez dans la classe publique :

    int envoyerSelectionCandidat(int idCandidat, const QString& progression);
    int envoyerReset();
    QString lireReponse();


private:
    QSerialPort *serial; // Cet objet rassemble des informations (vitesse, bits de données, etc.)
    // et des fonctions (envoi, lecture de réception,…) sur ce qu'est une voie série pour Arduino.
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data; // contenant les données lues à partir d'Arduino
};

#endif // ARDUINO_H
