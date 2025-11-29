#include "mainwindow.h"
#include "login.h"  // AJOUTEZ CETTE INCLUSION
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection* c = Connection::instance();
    bool test = c->createconnect();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        // Afficher la fenêtre de login au lieu de MainWindow directement
        Login login;
        if (login.exec() == QDialog::Accepted) {
            // Si le login est réussi, ouvrir MainWindow
            MainWindow w;
            w.show();
            return a.exec();
        } else {
            // Si le login est annulé ou échoué, quitter l'application
            return 0;
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        return -1;
    }
}
