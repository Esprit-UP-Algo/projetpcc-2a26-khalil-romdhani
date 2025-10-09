#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindowC::MainWindowC(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowC)
{
    ui->setupUi(this);
}

MainWindowC::~MainWindowC()
{
    delete ui;
}
