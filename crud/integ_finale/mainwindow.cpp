#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "GereEmploye.h"
#include "employe.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->confirmer_E, &QPushButton::clicked, this, &MainWindow::on_confirmer_E_clicked);
    connect(ui->modifier_E, &QPushButton::clicked, this, &MainWindow::on_modifier_E_clicked);
    connect(ui->supp_E, &QPushButton::clicked, this, &MainWindow::on_supp_E_clicked);
    connect(ui->reinstaller_E, &QPushButton::clicked, this, &MainWindow::on_reinstaller_E_clicked);
    connect(ui->expo_tab_E, &QPushButton::clicked, this, &MainWindow::on_expo_tab_E_clicked);
    connect(ui->tab_employes, &QTableWidget::doubleClicked, this, &MainWindow::on_tab_employes_doubleClicked);

    ui->stackedWidget->setCurrentWidget(ui->page_c);
    setWindowTitle("Qunatam team - Smart Drive");



}
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


// Ajouter un employé
void MainWindow::on_confirmer_E_clicked()
{
    // Toujours ajouter un nouvel employé (ignorer isEditing pour l'ajout)
    if (GereEmploye::ajouterEmploye(ui)) {
        isEditingEmploye = false; // on sort du mode modification
    }
}

// Modifier un employé
void MainWindow::on_modifier_E_clicked()
{
    GereEmploye::modifierEmploye(ui, e, isEditingEmploye ,currentIdEmploye);
    GereEmploye::reinitialiserFormulaire(ui);
    isEditingEmploye = false;
    currentIdEmploye = -1;
}

// Supprimer un employé
void MainWindow::on_supp_E_clicked()
{
    GereEmploye::supprimerEmploye(ui, e, isEditingEmploye, currentIdEmploye);
}

// Double-click sur la table pour remplir le formulaire
void MainWindow::on_tab_employes_doubleClicked(const QModelIndex &index)
{
    currentIdEmploye = ui->tab_employes->item(index.row(), 0)->text().toInt();
    isEditingEmploye = true;
    GereEmploye::chargerEmployePourModification(ui, index, isEditingEmploye, currentIdEmploye);
}

// Exporter les employés
void MainWindow::on_expo_tab_E_clicked()
{
    GereEmploye::exporterExcel(ui);
}

// Réinitialiser le formulaire employé
void MainWindow::on_reinstaller_E_clicked()
{
    GereEmploye::reinitialiserFormulaire(ui);
    isEditingEmploye = false;
    currentIdEmploye = -1;
}
void MainWindow::onAjouterClicked() { /* TODO */ }
void MainWindow::onModifierClicked() { /* TODO */ }
void MainWindow::onSupprimerClicked() { /* TODO */ }
void MainWindow::onRechercherClicked() { /* TODO */ }
void MainWindow::onExporterClicked() { /* TODO */ }
