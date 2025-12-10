#include "mainwindow.h"
#include "login.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection* c = Connection::instance();
    bool test = c->createconnect();

    if(!test)
    {
        QMessageBox::critical(nullptr, "Erreur", "Impossible de se connecter à la base !");
        return -1;
    }

    // Login modal
    Login login;
    if (login.exec() == QDialog::Accepted) {
        // Allouer MainWindow sur le tas pour qu'il persiste
        MainWindow *mainWin = new MainWindow();
        mainWin->show();
        return a.exec();
    }

    // Login échoué ou fermé → quitter app
    return 0;
}
