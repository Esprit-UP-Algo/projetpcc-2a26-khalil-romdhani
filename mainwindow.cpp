#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_c);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fermer_btn_clicked()
{
    close();
}


void MainWindow::on_vehicule_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_v);
}


void MainWindow::on_candidat_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_c);
}


void MainWindow::on_seance_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_s);
}

