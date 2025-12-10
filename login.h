#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

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

private:
    Ui::Login *ui;

    QString tempEmail;
    QString tempResetCode;

    void resetFaceButton();
    QString generateRandomCode();
    bool sendPasswordResetCode(const QString &email, const QString &code);
};

#endif // LOGIN_H
