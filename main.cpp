#include "mainwindow.h"

#include <QPixmap>
#include <QApplication>
#include <QTableWidget>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QLabel img;
    img.setPixmap(QPixmap(":/images/logo_app.png"));
    img.setScaledContents(true);
    img.resize(110, 110);
    return a.exec();

}
