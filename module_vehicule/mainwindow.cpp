#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->img->setPixmap(QPixmap(":/images/logo_app.png"));
    ui->img->setScaledContents(true);
    ui->img->setFixedSize(150,110);
    ui->img->move(15,50);
}

MainWindow::~MainWindow()
{
    delete ui;
}
