#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_login.h"

class Login : public QDialog   // <-- important : QDialog direct
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void onLoginClicked();

private:
    Ui::login *ui;   // <-- classe générée par Qt Designer (minuscule)
};

#endif // LOGIN_H
