#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "veh.h"
#include "vehChart.h"
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    ui->stackedWidget->setCurrentWidget(ui->page_accueil);
    setWindowTitle("Qunatam team - Smart Drive");

    veh *v = new veh();
    v->initV(ui->matricule, ui->type_v, ui->marque_v, ui->modele_v, ui->kilometrage_v, ui->bon, ui->entretien, ui->panne, ui->date_achat_v, ui->date_maint_v, ui->type_stat, ui->etat_stat);  // Updated
    v->initFiltrer(ui->filtrer_v);
    v->initTrier(ui->trier_v);
    connect(ui->conf_v, &QPushButton::clicked, v, &veh::ConfV);
    connect(ui->supp_v, &QPushButton::clicked, v, &veh::suppV);
    connect(ui->reins_v, &QPushButton::clicked, v, &veh::reinitV);
    connect(ui->modif_v, &QPushButton::clicked, v, &veh::modifV);
    connect(ui->table_ajout_v, &QTableWidget::clicked, v, &veh::tabClick);
    v->affTab(ui->table_ajout_v);
    v->refTab();
    v->initRech(ui->taper_v);
    connect(ui->conf_rv, &QPushButton::clicked, v, &veh::rechV);
    connect(ui->expo_v, &QPushButton::clicked, v, &veh::expoV);

    // Connect the refresh charts button
    connect(ui->acc_stat_v, &QPushButton::clicked, v, &veh::refreshCharts);

    // Initialize charts for the first time
    v->refreshCharts();
}

// ... rest of the code ...
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fermer_btn_clicked() { close(); }
void MainWindow::on_vehicule_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_v); }
void MainWindow::on_candidat_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_c); }
void MainWindow::on_seance_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_s); }
void MainWindow::on_emp_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_emp); }
void MainWindow::on_moniteur_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_m); }
void MainWindow::on_accueil_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_accueil); }
void MainWindow::on_vehicule_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_v); }
void MainWindow::on_candidat_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_c); }
void MainWindow::on_seance_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_s); }
void MainWindow::on_emp_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_emp); }
void MainWindow::on_moniteur_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_m); }
