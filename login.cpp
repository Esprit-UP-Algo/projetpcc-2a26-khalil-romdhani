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
#include <QSqlError>
#include <QCoreApplication>
#include "smtp.h"
#include "connection.h"

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

    // Focus starts on ID
    ui->id->setFocus();

    // Timer for auto-closing the servo after opening
    servoTimer = new QTimer(this);
    servoTimer->setSingleShot(true);
    connect(servoTimer, &QTimer::timeout, this, &Login::closeServo);

    connect(ui->connect, &QPushButton::clicked, this, &Login::on_connect_clicked);
    connect(ui->forgotPasswordButton, &QPushButton::clicked, this, &Login::on_forgotPasswordButton_clicked);
    connect(ui->faceRecognitionButton, &QPushButton::clicked, this, &Login::on_faceRecognitionButton_clicked);

    ui->faceRecognitionButton->setText("🔍 Identification Faciale");

    // Initialiser la lecture clavier via Arduino (port COM11)
    initKeypad();
}

Login::~Login()
{
    if (keypadTimer) {
        keypadTimer->stop();
    }
    closeServo(); // ensure servo is closed when app/login shuts down
    arduino.close_arduino();
    delete ui;
}

/* ================= CLASSIC LOGIN ================= */
void Login::on_connect_clicked()
{
    QString id = ui->id->text().trimmed();
    QString mdp = ui->mdp->text().trimmed();

    qDebug() << "[Login] Attempt" << "ID:" << id << "MDP:" << mdp;

    // Assure the DB connection is open
    Connection *conn = Connection::instance();
    if (!conn->createconnect()) {
        qDebug() << "[Login][SQL] Connexion échouée";
        QMessageBox::warning(this, "Erreur", "Connexion base de données échouée.");
        return;
    }

    if (id.isEmpty() || mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        updatePresenceFlag(id, false);
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NOM_EMP, PRENOM_EMP FROM EMPLOYES WHERE ID_EMPLOYE = :id AND TRIM(PASS_EMP) = :mdp");
    query.bindValue(":id", id);
    query.bindValue(":mdp", mdp);

    if (!query.exec()) {
        qDebug() << "[Login][SQL] Exec error:" << query.lastError().text();
        QMessageBox::warning(this, "Erreur", "Problème de connexion base.");
        return;
    }

    if (query.next()) {
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();

        QMessageBox::information(this, "Connexion réussie", "Bonjour " + prenom + " " + nom + "!");

        // Marquer la présence en base
        updatePresenceFlag(id, true);
        lastAuthenticatedId = id;
        schedulePresenceResetOnExit(id);

        // Ouvrir le servo pendant 10s
        arduino.write_to_arduino(QByteArray("OPEN\n"));
        if (servoTimer)
            servoTimer->start(10000); // 10 seconds

        // Accept the dialog so main.cpp opens MainWindow
        this->accept();

    } else {
        qDebug() << "[Login] No match found for ID/MDP";

        // Diagnostic: inspect stored password for this ID (if any)
        QSqlQuery diag;
        diag.prepare("SELECT TRIM(PASS_EMP) FROM EMPLOYES WHERE ID_EMPLOYE = :id");
        diag.bindValue(":id", id);
        if (diag.exec() && diag.next()) {
            QString stored = diag.value(0).toString();
            qDebug() << "[Login][Diag] Stored PASS_EMP for ID" << id << "=" << stored;
        } else if (!diag.exec()) {
            qDebug() << "[Login][Diag] Failed to read PASS_EMP:" << diag.lastError().text();
        } else {
            qDebug() << "[Login][Diag] No EMPLOYE row found for ID" << id;
        }

        QMessageBox::warning(this, "Erreur", "ID ou mot de passe incorrect.");
        updatePresenceFlag(id, false);
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

/* ================= KEYPAD (ARDUINO) ================= */
void Login::initKeypad()
{
    keypadTimer = new QTimer(this);
    connect(keypadTimer, &QTimer::timeout, this, &Login::pollKeypad);

    // Forcer COM11 comme demandé, avec détection fallback gérée dans Arduino::connect_arduino
    int connectStatus = arduino.connect_arduino("COM11");
    keypadConnected = (connectStatus == 0);

    if (keypadConnected) {
        keypadTimer->start(80); // poll a bit faster to avoid missed keys
        qDebug() << "[Keypad] Connecté sur COM11";
    } else {
        qDebug() << "[Keypad] Arduino non détecté sur COM11 - saisie via clavier PC uniquement.";
    }
}

void Login::pollKeypad()
{
    if (!keypadConnected)
        return;

    QByteArray payload = arduino.read_from_arduino();
    if (payload.isEmpty())
        return;

    processKeypadInput(payload);
}

void Login::processKeypadInput(const QByteArray &data)
{
    for (char byte : data) {
        if (byte == '\r' || byte == '\n')
            continue;

        char key = static_cast<char>(byte);

        // Ignore anything non-printable to avoid ghost chars
        if (!QChar::fromLatin1(key).isPrint())
            continue;

        // '*' -> passer au champ mot de passe
        if (key == '*') {
            setActiveField(FieldPassword);
            qDebug() << "[Keypad] Saisie mot de passe";
            continue;
        }

        // 'D' -> revenir au champ ID
        if (key == 'D') {
            setActiveField(FieldId);
            qDebug() << "[Keypad] Saisie identifiant";
            continue;
        }

        // 'C' -> basculer entre ID et MDP
        if (key == 'C') {
            setActiveField(activeField == FieldId ? FieldPassword : FieldId);
            qDebug() << "[Keypad] Toggle champ ->" << (activeField == FieldId ? "ID" : "MDP");
            continue;
        }

        // 'A' -> réinitialiser les champs
        if (key == 'A') {
            ui->id->clear();
            ui->mdp->clear();
            setActiveField(FieldId);
            qDebug() << "[Keypad] Champs réinitialisés";
            continue;
        }

        // 'B' -> backspace sur le champ actif
        if (key == 'B') {
            QLineEdit *target = (activeField == FieldId) ? ui->id : ui->mdp;
            QString text = target->text();
            if (!text.isEmpty())
                text.chop(1);
            target->setText(text);
            continue;
        }

        // '#' -> valider / tenter la connexion
        if (key == '#') {
            // Si on est sur l'ID et que le MDP est vide, passer au MDP au lieu de valider
            if (activeField == FieldId && ui->mdp->text().isEmpty()) {
                setActiveField(FieldPassword);
                continue;
            }
            on_connect_clicked();
            continue;
        }

        // Sinon, on ajoute le caractère tapé
        QLineEdit *target = (activeField == FieldId) ? ui->id : ui->mdp;
        QChar qkey = QChar::fromLatin1(key);
        if (qkey.isPrint()) {
            target->setText(target->text() + qkey);
        }
    }
}

void Login::setActiveField(ActiveField field)
{
    activeField = field;
    if (field == FieldId) {
        ui->id->setFocus();
    } else {
        ui->mdp->setFocus();
    }
}

void Login::updatePresenceFlag(const QString &id, bool present)
{
    if (id.isEmpty())
        return;

    // EMPLOYES (ID_EMPLOYE)
    QSqlQuery presenceEmp;
    presenceEmp.prepare("UPDATE EMPLOYES SET PRESENCE = :p WHERE ID_EMPLOYE = :id");
    presenceEmp.bindValue(":p", present ? 1 : 0);
    presenceEmp.bindValue(":id", id);

    if (!presenceEmp.exec()) {
        qDebug() << "[Presence][Emp] Échec mise à jour pour" << id << ":" << presenceEmp.lastError().text();
    } else if (presenceEmp.numRowsAffected() > 0) {
        qDebug() << "[Presence][Emp] ID" << id << "=>" << (present ? 1 : 0);
    } else {
        qDebug() << "[Presence][Emp] Aucun employé trouvé pour ID" << id;
    }
}

void Login::closeServo()
{
    // Send close command if we previously opened it
    arduino.write_to_arduino(QByteArray("CLOSE\n"));
}

void Login::schedulePresenceResetOnExit(const QString &id)
{
    // Avoid multiple connections for the same session
    static bool hooked = false;
    if (hooked)
        return;
    hooked = true;

    QObject::connect(qApp, &QCoreApplication::aboutToQuit, qApp, [id]() {
        Connection *conn = Connection::instance();
        if (!conn->createconnect())
            return;
        QSqlQuery q;
        q.prepare("UPDATE EMPLOYES SET PRESENCE = 0 WHERE ID_EMPLOYE = :id");
        q.bindValue(":id", id);
        q.exec();
    });
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
