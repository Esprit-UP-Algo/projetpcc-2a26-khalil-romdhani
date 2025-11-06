#include "mainwindow.h"
#include "connection.h"
#include "login.h"         // ✅ Ajout du login
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1️⃣ Connexion à la base
    Connection* c = Connection::instance();
    bool test = c->createconnect();

    if (!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Base de données"),
                              QObject::tr("Échec de connexion à la base de données.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        return -1;
    }

    // 2️⃣ Si la base est connectée → afficher la fenêtre de login
    Login login;
    if (login.exec() == QDialog::Accepted)   // ✅ L’utilisateur s’est bien connecté
    {
        MainWindow w;
        w.show();

        QMessageBox::information(nullptr, QObject::tr("Base de données"),
                                 QObject::tr("Connexion à la base réussie.\nBienvenue !"),
                                 QMessageBox::Ok);

        return a.exec();
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Fermeture"),
                                 QObject::tr("Connexion annulée."), QMessageBox::Ok);
        return 0;
    }
}
