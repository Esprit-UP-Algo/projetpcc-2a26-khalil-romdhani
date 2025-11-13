#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->mdp->setEchoMode(QLineEdit::Password);
     verifierContenuBase();
    // Debug initial
    qDebug() << "=== DÉMARRAGE LOGIN ===";
    verifierContenuBase(); // Vérifier le contenu de la base au démarrage
}

Login::~Login()
{
    delete ui;
}

// Fonction pour vérifier le contenu de la base de données
void Login::verifierContenuBase()
{
    QSqlQuery query("SELECT ID_EMPLOYE, NOM_EMP, PRENOM_EMP, PASS_EMP FROM EMPLOYES");

    qDebug() << "=== CONTENU DE LA TABLE EMPLOYES ===";
    int count = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        QString pass = query.value(3).toString();

        qDebug() << "ID:" << id << "| Nom:" << nom << prenom << "| Pass:" << pass;
        count++;
    }

    if (count == 0) {
        qDebug() << "❌ TABLE EMPLOYES VIDE - Aucun employé trouvé!";
        qDebug() << "👉 Vous devez d'abord ajouter des employés via l'interface";
    } else {
        qDebug() << "✅" << count << "employé(s) trouvé(s) dans la base";
    }
    qDebug() << "=====================================";
}

bool Login::verifierIdentifiants(const QString& id, const QString& password)
{
    if (id.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Veuillez saisir un ID et un mot de passe");
        return false;
    }

    qDebug() << "🔑 Tentative de connexion:";
    qDebug() << "   ID saisi:" << id;
    qDebug() << "   Mot de passe saisi:" << password;

    // TEST 1: Vérifier d'abord si l'ID existe
    QSqlQuery checkIdQuery;
    checkIdQuery.prepare("SELECT ID_EMPLOYE, PASS_EMP FROM EMPLOYES WHERE ID_EMPLOYE = :id");
    checkIdQuery.bindValue(":id", id);

    if (!checkIdQuery.exec()) {
        qDebug() << "❌ Erreur SQL (vérification ID):" << checkIdQuery.lastError().text();
        return false;
    }

    if (checkIdQuery.next()) {
        // L'ID existe, vérifier le mot de passe
        QString vraiPassword = checkIdQuery.value(1).toString();
        qDebug() << "✅ ID trouvé - Mot de passe en base:" << vraiPassword;

        if (password == vraiPassword) {
            qDebug() << "🎉 CONNEXION RÉUSSIE!";
            return true;
        } else {
            qDebug() << "❌ Mot de passe incorrect";
            qDebug() << "   Saisi:" << password;
            qDebug() << "   En base:" << vraiPassword;
            QMessageBox::warning(nullptr, "Erreur",
                                 "Mot de passe incorrect!\n"
                                 "ID existe mais le mot de passe ne correspond pas.");
            return false;
        }
    } else {
        // L'ID n'existe pas
        qDebug() << "❌ ID non trouvé dans la base de données";

        // Afficher tous les IDs disponibles pour aider au debug
        QSqlQuery allIdsQuery("SELECT ID_EMPLOYE FROM EMPLOYES");
        QStringList idsDisponibles;
        while (allIdsQuery.next()) {
            idsDisponibles << allIdsQuery.value(0).toString();
        }

        if (idsDisponibles.isEmpty()) {
            QMessageBox::warning(nullptr, "Erreur",
                                 "Cet ID n'existe pas.\n"
                                 "La table EMPLOYES est vide.\n"
                                 "Ajoutez d'abord des employés via l'interface principale.");
        } else {
            QMessageBox::warning(nullptr, "Erreur",
                                 "Cet ID n'existe pas.\n"
                                 "IDs disponibles: " + idsDisponibles.join(", "));
        }
        return false;
    }
}

void Login::on_connect_clicked()
{
    QString id = ui->id->text().trimmed();
    QString password = ui->mdp->text();

    if (verifierIdentifiants(id, password)) {
        this->accept(); // Ferme le login et retourne Accepted
    } else {
        ui->mdp->clear();
        ui->mdp->setFocus();
    }
}
