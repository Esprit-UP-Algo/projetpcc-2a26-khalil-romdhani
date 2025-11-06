#include "login.h"
#include "mainwindow.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)       // <-- correspond exactement à la classe de base
    , ui(new Ui::login)
{
    ui->setupUi(this);      // <-- OK, setupUi attend QDialog*
    connect(ui->seconnecter_E, &QPushButton::clicked, this, &Login::onLoginClicked);
}

Login::~Login()
{
    delete ui;
}


void Login::onLoginClicked()
{
    QString username = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    // Exemple simple : on autorise toute saisie non vide
    if(!username.isEmpty() && !password.isEmpty()) {
        MainWindow *mainWin = new MainWindow();
        mainWin->show();
        this->close();  // ferme la fenêtre de login
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un login et mot de passe");
    }
}

