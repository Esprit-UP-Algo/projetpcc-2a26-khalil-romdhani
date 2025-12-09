#ifndef ARDUINOMANAGER_H
#define ARDUINOMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>
#include "arduino.h"

class ArduinoManager : public QObject
{
    Q_OBJECT

public:
    enum ButtonType {
        BUTTON_NONE = 0,
        BUTTON_CODE = 1,
        BUTTON_CONDUITE = 2,
        BUTTON_PARC = 3,
        BUTTON_CONFIRM = 4
    };

    explicit ArduinoManager(QObject *parent = nullptr);
    ~ArduinoManager();
    bool connectToArduino();
    void disconnect();
    bool isConnected() const;
    void sendCandidateSelection(int id, int percent);
    void sendUpdateSuccess();
    void sendError(const QString &message);
    void sendDisplayMessage(const QString &message);
    void setLEDColor(const QString &color, bool blink = false);
    void sendCandidateDetails(int id, int percent, const QString &nom, const QString &prenom);
signals:
    void connectionStatusChanged(bool connected);
    void buttonPressed(ArduinoManager::ButtonType button);
    void arduinoError(const QString &error);

private slots:
    void onDataReceived();
    void checkConnection();

private:
    void processIncomingData(const QByteArray &data);
    ButtonType parseButtonCommand(const QString &command);

    Arduino *m_arduino;
    QTimer *m_connectionTimer;
    bool m_isConnected;
    QByteArray m_buffer;
};

#endif // ARDUINOMANAGER_H
