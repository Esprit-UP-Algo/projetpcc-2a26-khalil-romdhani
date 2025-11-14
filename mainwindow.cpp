#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gereseance.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_s); // Page séances par défaut
    setWindowTitle("SmartSchool - Gestion Auto-École");

    isEditingSeance = false;
    currentSeanceId = -1;


    ui->date_s->setDate(QDate::currentDate());
    ui->deb_s->setTime(QTime(8, 0));
    ui->fin_s->setTime(QTime(9, 0));

    afficherSeances();
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
    QMessageBox::information(this, "Information", "Module Véhicules - En développement");
}

void MainWindow::on_candidat_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_c);
    QMessageBox::information(this, "Information", "Module Candidats - En développement");
}

void MainWindow::on_seance_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_s);
}

void MainWindow::on_emp_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_emp);
    QMessageBox::information(this, "Information", "Module Employés - En développement");
}

void MainWindow::on_moniteur_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_m);
    QMessageBox::information(this, "Information", "Module Moniteurs - En développement");
}


void MainWindow::afficherSeances() {
    QSqlQueryModel *model = s.afficher();

    ui->tab_s->setRowCount(0);
    ui->tab_s->setColumnCount(12);

    QStringList headers;
    headers << "ID Séance" << "Type" << "Date" << "Heure début" << "Heure fin"
            << "Salle" << "Circuit départ" << "Longitude" << "Latitude départ"
            << "Longitude arrivée" << "Latitude arrivée" << "ID Moniteur";
    ui->tab_s->setHorizontalHeaderLabels(headers);

    ui->tab_s->setRowCount(model->rowCount());
    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < 12; ++j) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    ui->tab_s->resizeColumnsToContents();
    delete model;
}

void MainWindow::on_confirm_ajout_s_clicked()
{
    if (GereSeance::confirmerSeance(ui, s, isEditingSeance, currentSeanceId)) {
        afficherSeances();
    }
}

void MainWindow::on_confirm_s_clicked()
{
    // RECHERCHE PAR ID
    QString idRecherche = ui->recherche_s->text().trimmed();

    if (idRecherche.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Recherche vide");
        msgBox.setText("Veuillez saisir un ID pour la recherche !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->recherche_s->setFocus();
        ui->recherche_s->selectAll();
        return;
    }


    bool ok;
    int id = idRecherche.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("ID invalide");
        msgBox.setText("L'ID de recherche doit être un nombre positif !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->recherche_s->setFocus();
        ui->recherche_s->selectAll();
        return;
    }


    QSqlQueryModel *model = s.rechercher("ID", idRecherche);

    if (model->rowCount() == 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Aucun résultat");
        msgBox.setText(QString("Aucune séance trouvée avec l'ID : %1").arg(idRecherche));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();


        afficherSeances();
    } else {

        ui->tab_s->setRowCount(0);
        ui->tab_s->setRowCount(model->rowCount());

        for (int i = 0; i < model->rowCount(); ++i) {
            for (int j = 0; j < 12; ++j) {
                QString data = model->data(model->index(i, j)).toString();
                ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
            }
        }

        QMessageBox msgBox;
        msgBox.setWindowTitle("Recherche réussie");
        msgBox.setText(QString("%1 séance(s) trouvée(s) avec l'ID : %2").arg(model->rowCount()).arg(idRecherche));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
    }

    delete model;
}

void MainWindow::on_tab_s_clicked(const QModelIndex &index)
{
    GereSeance::chargerSeancePourModification(ui, index, isEditingSeance, currentSeanceId);
}

void MainWindow::on_supp_s_clicked()
{
    if (GereSeance::supprimerSeance(ui, s, isEditingSeance, currentSeanceId)) {
        afficherSeances();
    }
}

void MainWindow::on_reins_s_clicked()
{
    GereSeance::reinitialiserFormulaire(ui);
    isEditingSeance = false;
    currentSeanceId = -1;
    QMessageBox::information(this, "Réinitialisation", "Formulaire réinitialisé avec succès !");
}

void MainWindow::on_filtre_s_clicked()
{
    QString valeur = ui->recherche_s->text();
    QString critere = "ID";

    QSqlQueryModel *model = s.rechercher(critere, valeur);

    ui->tab_s->setRowCount(0);
    ui->tab_s->setRowCount(model->rowCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < 12; ++j) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Recherche", "Aucune séance trouvée avec cet ID !");
    }

    delete model;
}

void MainWindow::on_tri_s_currentIndexChanged(int index)
{
    QString critere;
    QString ordre = "ASC";

    switch(index) {
    case 1: critere = "DATE_S"; break;
    case 2: critere = "TYPE_S"; break;
    default: return;
    }

    QSqlQueryModel *model = s.trier(critere, ordre);

    ui->tab_s->setRowCount(0);
    ui->tab_s->setRowCount(model->rowCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < 12; ++j) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tab_s->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    delete model;
}

void MainWindow::on_exp_s_clicked()
{
    GereSeance::exporterSeanceExcel(ui);
}


void MainWindow::on_conf_v_clicked()
{
    QMessageBox::information(this, "Information", "Module Véhicules - En développement");
}

void MainWindow::on_reins_v_clicked()
{
    QMessageBox::information(this, "Information", "Module Véhicules - En développement");
}

void MainWindow::on_supp_v_clicked()
{
    QMessageBox::information(this, "Information", "Module Véhicules - En développement");
}

void MainWindow::on_expo_v_clicked()
{
    QMessageBox::information(this, "Information", "Module Véhicules - En développement");
}

void MainWindow::on_enregistrer_c_clicked()
{
    QMessageBox::information(this, "Information", "Module Candidats - En développement");
}

void MainWindow::on_modifier_c_clicked()
{
    QMessageBox::information(this, "Information", "Module Candidats - En développement");
}

void MainWindow::on_supp_c_clicked()
{
    QMessageBox::information(this, "Information", "Module Candidats - En développement");
}

void MainWindow::on_expo_tab_c_clicked()
{
    QMessageBox::information(this, "Information", "Module Candidats - En développement");
}
