#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configurer QTableWidget directement
    ui->tab_mon->setColumnCount(6);
    QStringList headers = {"Nom", "Prénom", "Téléphone", "Email", "Spécialité", "Disponibilité"};
    ui->tab_mon->setHorizontalHeaderLabels(headers);
    ui->tab_mon->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tab_mon->setStyleSheet(
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

void MainWindow::on_fermer_btn_clicked()
{
    close();
}

void MainWindow::on_conf_ajout_clicked()
{
    QString nom = ui->nom->text();
    static const QRegularExpression regexnom("^[A-Za-z]{1,12}$");
    if (!regexnom.match(nom).hasMatch())
    {
        QMessageBox::warning(this,"Erreur","Veuillez vérifier le nom .");
        return;
    }
    QString specialite = ui->specialite->currentText();
    if (specialite == "Choisir"){
        QMessageBox::warning(this, "Erreur" , "Veuillez choisir une specialite");
        return;
    }
    QString prenom = ui->prenom->text();
    static const QRegularExpression regexprenom("^[A-Za-z]{1,12}$");
    if (!regexprenom.match(prenom).hasMatch())
    {
        QMessageBox::warning(this ,"Erreur","Veuillez vérifier que le prenom doit contenir uniquement des lettres ." );
        return;
    }
    QString email = ui->email->text();
    static const QRegularExpression regexemail("^[A-Za-z0-9]{1,12}$");
    if (!regexemail.match(email).hasMatch())
    {
        QMessageBox::warning(this ,"Erreur","Le mail doit contenir uniquement des lettres et chiffres et ne dépasse pas 12 caractères." );
        return;
    }
    QString telephone = ui->telephone->text();
    static const QRegularExpression regextelephone("^[0-9]{1,4}$");
    if (!regextelephone.match(telephone).hasMatch() )
    {
        QMessageBox::warning(this ,"Erreur", "Le telephone n'est pa valide .");
        return;
    }
    if(!ui->actif->isChecked() && !ui->inactif->isChecked())
    {
        QMessageBox::warning(this,"Erreur","Veuillez choisir la disponibilité.");
        return;
    }
    QString disponibilite;
    if (ui->actif->isChecked()) disponibilite = "actif";
    else if (ui->inactif->isChecked()) disponibilite = "inactif";


    QString experience = ui->experience->text();
    static const QRegularExpression regexexperience("^[0-9]{1,6}$");
    if (!regexexperience.match(experience).hasMatch() || experience <"0" || experience > "100")
    {
        QMessageBox::warning(this,"Erreur","Veuillez vérifier le kilométrage.");
        return;
    }

    QList<QStandardItem*> row;
    row << new QStandardItem(nom)
        << new QStandardItem(specialite)
        << new QStandardItem(prenom)
        << new QStandardItem(email)
        << new QStandardItem(telephone)
        << new QStandardItem(disponibilite)
        << new QStandardItem(experience);
    tab->appendRow(row);
}

void MainWindow::on_reinstaller_vehc_clicked()
{
    ui->specialite->setCurrentIndex(0);
    ui->prenom->clear();
    ui->telephone->clear();
    ui->nom->clear();
    ui->email->clear();
    ui->actif->setAutoExclusive(false);
    ui->actif->setChecked(false);
    ui->inactif->setChecked(false);
    ui->actif->setAutoExclusive(true);
    ui->experience->clear();

}
