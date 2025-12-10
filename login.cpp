#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQuery>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QProcess>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <QApplication>
#include "smtp.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // ========== CORRECTED VERSION ==========
    // Store the exact size of the frame_login BEFORE modifying layouts
    QSize frameSize = ui->frame_login->size();

    // Remove all existing layouts and widgets except frame_login
    // First, reparent frame_login to nullptr temporarily
    ui->frame_login->setParent(nullptr);

    // Clear everything from the dialog
    QLayout* oldLayout = this->layout();
    if (oldLayout) {
        // Remove all widgets from old layout
        QLayoutItem* item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget() && item->widget() != ui->frame_login) {
                item->widget()->hide();
                delete item->widget();
            }
            delete item;
        }
        delete oldLayout;
    }

    // Now set frame_login as the only content with no layout
    ui->frame_login->setParent(this);
    ui->frame_login->move(0, 0);  // Position at top-left corner

    // Set dialog to exact frame size
    this->setFixedSize(frameSize);
    // ========== END CORRECTED VERSION ==========

    // Original code - NO OTHER CHANGES:
    ui->mdp->setEchoMode(QLineEdit::Password);
    ui->faceRecognitionButton->setAutoDefault(false);
    ui->connect->setAutoDefault(false);
    ui->forgotPasswordButton->setAutoDefault(false);

    connect(ui->connect, &QPushButton::clicked, this, &Login::on_connect_clicked);
    connect(ui->forgotPasswordButton, &QPushButton::clicked, this, &Login::on_forgotPasswordButton_clicked);
    connect(ui->faceRecognitionButton, &QPushButton::clicked, this, &Login::on_faceRecognitionButton_clicked);

    ui->faceRecognitionButton->setText("🔍 Identification Faciale");
}

Login::~Login()
{
    delete ui;
}

/* ================= CLASSIC LOGIN ================= */
void Login::on_connect_clicked()
{
    QString id = ui->id->text();
    QString mdp = ui->mdp->text();

    if (id.isEmpty() || mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NOM_EMP, PRENOM_EMP FROM EMPLOYES WHERE ID_EMPLOYE = :id AND PASS_EMP = :mdp");
    query.bindValue(":id", id);
    query.bindValue(":mdp", mdp);

    if (query.exec() && query.next()) {
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();

        QMessageBox::information(this, "Connexion réussie", "Bonjour " + prenom + " " + nom + "!");

        // Accept the dialog so main.cpp opens MainWindow
        this->accept();

    } else {
        QMessageBox::warning(this, "Erreur", "ID ou mot de passe incorrect.");
    }
}

/* ================= FACE RECOGNITION LOGIN ================= */
void Login::on_faceRecognitionButton_clicked()
{
    ui->faceRecognitionButton->setEnabled(false);
    ui->faceRecognitionButton->setText("🔍 Analyse en cours...");

    QString pythonPath = "C:/Users/Yasmine/AppData/Local/Programs/Python/Python313/python.exe";
    QString scriptPath = "C:/Users/Yasmine/facial_auth_database/face_recognition_wrapper.py";

    QProcess process;

    // Execute Python script and wait for completion (max 15 sec)
    process.start(pythonPath, QStringList() << scriptPath);
    if (!process.waitForFinished(15000)) {
        QMessageBox::warning(this, "Erreur", "⛔ Timeout ! La caméra n'a pas répondu.");
        resetFaceButton();
        return;
    }

    QString output = process.readAllStandardOutput().trimmed();
    QString error = process.readAllStandardError().trimmed();

    qDebug() << "PYTHON OUT =" << output;
    qDebug() << "PYTHON ERR =" << error;

    // ✅ Only your face is valid
    if (output == "2") {
        QMessageBox::information(this, "Succès", "🎉 Reconnaissance réussie ! Bonjour Yesmine Khssib");
        this->accept();  // Close login and open MainWindow
        return;
    }

    // Otherwise, face not recognized
    QMessageBox::warning(this, "Erreur", "Visage non reconnu ! Seul le visage autorisé peut se connecter.");
    resetFaceButton();
}

void Login::resetFaceButton()
{
    // ✅ CORRECTION: Reactivate button WITHOUT closing interface
    ui->faceRecognitionButton->setEnabled(true);
    ui->faceRecognitionButton->setText("🔍 Identification Faciale");
    qDebug() << "Bouton réactivé - Interface Login toujours ouverte";
}

/* ================= FORGOTTEN PASSWORD ================= */

/* Generate random code */
QString Login::generateRandomCode()
{
    QString code;
    for (int i = 0; i < 6; ++i)
        code.append(QString::number(QRandomGenerator::global()->bounded(10)));
    return code;
}

/* Send code by email */
bool Login::sendPasswordResetCode(const QString &email, const QString &code)
{
    QString subject = "Code de réinitialisation - Smart Drive";
    QString body = "Votre code est : " + code;

    Smtp *smtp = new Smtp("yesminekhssib75@gmail.com",
                          "duho zojw klgb qzrm",
                          "smtp.gmail.com", 465);

    smtp->sendMail("yesminekhssib75@gmail.com", email, subject, body);
    return true;
}

/* ================= FORGOTTEN PASSWORD - MODIFIED VERSION ================= */
void Login::on_forgotPasswordButton_clicked()
{
    bool ok;
    QString email = QInputDialog::getText(this, "Réinitialisation mot de passe",
                                          "Veuillez saisir votre adresse email :",
                                          QLineEdit::Normal, "", &ok);
    if (!ok || email.isEmpty())
        return;

    // REMOVE database verification
    // We accept ALL emails without verification

    QString resetCode = generateRandomCode();

    if (!sendPasswordResetCode(email, resetCode)) {
        QMessageBox::warning(this, "Erreur", "Échec d'envoi du code !");
        return;
    }

    // Temporarily store email and code for verification
    tempEmail = email;
    tempResetCode = resetCode;

    QString enteredCode = QInputDialog::getText(this, "Code reçu",
                                                "Entrez le code reçu :", QLineEdit::Normal, "", &ok);
    if (!ok || enteredCode != tempResetCode) {
        QMessageBox::warning(this, "Erreur", "Code incorrect !");
        tempEmail.clear();
        tempResetCode.clear();
        return;
    }

    // If code is correct, ask for new password
    QString newPassword = QInputDialog::getText(this, "Nouveau mot de passe",
                                                "Entrez nouveau mot de passe :", QLineEdit::Password, "", &ok);
    if (ok && !newPassword.isEmpty()) {
        // Now verify if email exists to update password
        QSqlQuery query;
        query.prepare("SELECT ID_EMPLOYE FROM EMPLOYES WHERE Email_EMP = :email");
        query.bindValue(":email", tempEmail);

        if (query.exec() && query.next()) {
            QString id = query.value(0).toString();

            QSqlQuery update;
            update.prepare("UPDATE EMPLOYES SET PASS_EMP = :p WHERE ID_EMPLOYE = :id");
            update.bindValue(":p", newPassword);
            update.bindValue(":id", id);

            if (update.exec()) {
                QMessageBox::information(this, "Succès", "Mot de passe mis à jour !");
            } else {
                QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour !");
            }
        } else {
            QMessageBox::information(this, "Information",
                                     "Code vérifié avec succès !\n"
                                     "Note: Cet email n'est pas associé à un compte existant.");
        }

        // Clean temporary variables
        tempEmail.clear();
        tempResetCode.clear();
    }
}
