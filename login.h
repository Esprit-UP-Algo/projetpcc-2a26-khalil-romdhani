#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QTimer>
#include "arduino.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void loginSuccess();

private slots:
    void on_connect_clicked();
    void on_faceRecognitionButton_clicked();
    void on_forgotPasswordButton_clicked();
    void pollKeypad();
    void closeServo();

private:
    enum ActiveField { FieldId, FieldPassword };

    Ui::Login *ui;
    Arduino arduino;
    QTimer *keypadTimer = nullptr;
    QTimer *servoTimer = nullptr;
    bool keypadConnected = false;
    ActiveField activeField = FieldId;
    QString lastAuthenticatedId;

    void initKeypad();
    void processKeypadInput(const QByteArray &data);
    void setActiveField(ActiveField field);
    void updatePresenceFlag(const QString &id, bool present);
    void schedulePresenceResetOnExit(const QString &id);

    QString tempEmail;
    QString tempResetCode;

    void resetFaceButton();
    QString generateRandomCode();
    bool sendPasswordResetCode(const QString &email, const QString &code);
};

#endif // LOGIN_H
