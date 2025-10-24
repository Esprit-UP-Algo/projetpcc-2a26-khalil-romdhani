#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerevehicule.h"
#include "GereCandidat.h"
#include "Candidat.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_c);
    setWindowTitle("Qunatam team - Smart Drive");
    v.afficher(ui->table_ajout_v);
    isEditing = false;

    // Initialize candidate variables
    isEditingCandidat = false;
    currentCandidatId = 0;

    // Display candidates
    Candidat c;
    c.afficher(ui->table_candidat);
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

void MainWindow::on_conf_v_clicked() {
    GereVehicule::confirmerVehicule(ui, v, isEditing, currentMatricule);
}

void MainWindow::on_table_ajout_v_doubleClicked(const QModelIndex &index) {
    GereVehicule::chargerVehiculePourModification(ui, index, isEditing, currentMatricule);
}

void MainWindow::on_reins_v_clicked() {
    GereVehicule::reinitialiserFormulaire(ui);
}

void MainWindow::on_supp_v_clicked() {
    GereVehicule::supprimerVehicule(ui, v, isEditing, currentMatricule);
}

void MainWindow::on_expo_v_clicked() {
    GereVehicule::exporterPDF(ui);
}

// Candidate slots
void MainWindow::on_enregistrer_c_clicked()
{
    if (isEditingCandidat) {
        QMessageBox::information(this, "Information", "Vous êtes en mode modification. Utilisez le bouton 'Modifier' pour confirmer les changements.");
        return;
    }
    GereCandidat::ajouterCandidat(ui);
}

void MainWindow::on_modifier_c_clicked()
{
    GereCandidat::modifierCandidat(ui, c, isEditingCandidat, currentCandidatId);
}

void MainWindow::on_table_candidat_doubleClicked(const QModelIndex &index)
{
    GereCandidat::chargerCandidatPourModification(ui, index, isEditingCandidat, currentCandidatId);
}

void MainWindow::on_supp_c_clicked()
{
    GereCandidat::supprimerCandidat(ui, c, isEditingCandidat, currentCandidatId);
}

void MainWindow::on_expo_tab_c_clicked()
{
    GereCandidat::exporterExcel(ui);
}
