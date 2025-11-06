#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_seconnecter_E_clicked()
{
    QString username = ui->lineEditlogin->text();
    QString password = ui->lineEditpassword->text();

    // Exemple de login basique (à adapter)
    if (username == "admin" && password == "1234")
    {
        accept();  // ✅ Ferme la fenêtre et retourne QDialog::Accepted
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Nom d’utilisateur ou mot de passe incorrect !");
    }
}
