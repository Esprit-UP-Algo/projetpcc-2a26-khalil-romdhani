#ifndef ARDUINO_MANAGER_S_H
#define ARDUINO_MANAGER_S_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QThread>           // Pour QThread::msleep
#include <QElapsedTimer>     // Alternative
#include <QCoreApplication>  // Pour processEvents
#include "arduino_comm.h"
#include "connection.h"
#include <QDebug>

class ArduinoManagerS : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoManagerS(QObject *parent = nullptr);
    ~ArduinoManagerS();

    void compterEtEnvoyerSeances(const QString &salleStr);
    bool envoyerVersArduino(int nombre);
    bool ouvrirPort(const QString &portName = "COM5");

    ArduinoComm* getArduinoComm() const { return m_arduinoComm; }

signals:
    void messageInfo(const QString &message);
    void messageWarning(const QString &message);
    void messageError(const QString &message);

private:
    ArduinoComm *m_arduinoComm;
    QSqlDatabase m_db;
};

#endif // ARDUINO_MANAGER_S_H
