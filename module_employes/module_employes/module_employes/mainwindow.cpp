#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configurer QTableWidget directement
    ui->tab_employes->setColumnCount(6);
    QStringList headers = {"Nom", "Prénom", "Téléphone", "Salaire", "Poste", "Date d’embauche"};
    ui->tab_employes->setHorizontalHeaderLabels(headers);
    ui->tab_employes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tab_employes->setStyleSheet(
        "QHeaderView::section { background-color: #001f3f; color: white; font-weight: bold; }"
        "QTableWidget { background-color: rgb(240,240,240); gridline-color: gray; }"
        );

    // Logo
    ui->img->setPixmap(QPixmap(":/images/logo_app.png"));
    ui->img->setScaledContents(true);
    ui->img->setFixedSize(150, 110);
    ui->img->move(15, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Bouton fermer
void MainWindow::on_fermer_btn_clicked()
{
    close();
}

// Bouton ajouter
void MainWindow::on_conf_ajout_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString tel = ui->telephone->text();
    QString salaire = ui->salaire->text();
    QString poste = ui->poste->text();
    QDate date_embauche = ui->date_embauche->date();

    static const QRegularExpression regexNom("^[A-Za-z]{2,20}$");
    static const QRegularExpression regexTel("^[0-9]{8}$");
    static const QRegularExpression regexSalaire("^[0-9]+(\\.[0-9]{1,2})?$");

    if (!regexNom.match(nom).hasMatch() || !regexNom.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres (2 à 20 caractères).");
        return;
    }

    if (!regexTel.match(tel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    if (!regexSalaire.match(salaire).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le salaire doit être un nombre valide.");
        return;
    }

    if (poste.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir le poste de l'employé.");
        return;
    }

    // Ajout dans la table
    int row = ui->tab_employes->rowCount();
    ui->tab_employes->insertRow(row);

    ui->tab_employes->setItem(row, 0, new QTableWidgetItem(nom));
    ui->tab_employes->setItem(row, 1, new QTableWidgetItem(prenom));
    ui->tab_employes->setItem(row, 2, new QTableWidgetItem(tel));
    ui->tab_employes->setItem(row, 3, new QTableWidgetItem(salaire));
    ui->tab_employes->setItem(row, 4, new QTableWidgetItem(poste));
    ui->tab_employes->setItem(row, 5, new QTableWidgetItem(date_embauche.toString("dd/MM/yyyy")));
}

// Bouton réinitialiser
void MainWindow::on_reinstaller_emp_clicked()
{
    ui->nom->clear();
    ui->prenom->clear();
    ui->telephone->clear();
    ui->salaire->clear();
    ui->poste->clear();
    ui->date_embauche->setDate(QDate::currentDate());
}
