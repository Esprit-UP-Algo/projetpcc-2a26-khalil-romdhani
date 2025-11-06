#include "login.h"


#include <QApplication>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // --- Afficher le logo temporairement (optionnel) ---
    QLabel img;
    img.setPixmap(QPixmap(":/images/logo_app.png")); // ton logo dans ressources.qrc
    img.setScaledContents(true);
    img.resize(110, 110);
    img.show(); // afficher le logo avant la fenêtre

    // --- Ouvrir la fenêtre de connexion ---
    Login l;
    l.show();

    // Exécution de l'application
    return a.exec();
}
