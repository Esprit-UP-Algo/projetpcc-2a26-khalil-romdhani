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

private slots:
    void on_connect_clicked();

private:
    Ui::Login *ui;
    bool verifierIdentifiants(const QString& id, const QString& password);
    void verifierContenuBase(); // AJOUTEZ CETTE LIGNE
};

#endif // LOGIN_H
