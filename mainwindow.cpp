 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GereCandidat.h"
#include "Candidat.h"
#include "JournalCandidat.h"
#include "ImageVer_C.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_statCandidat(nullptr)
    , m_journalCandidat(new JournalCandidat(this))
    , m_imageVerif(nullptr)
    , m_arduinoManager(new ArduinoManager(this))
    , m_arduinoControlActive(false)
    , m_arduinoControlledId(0)
{
    ui->setupUi(this);
    initialiserInterface();
    initialiserGestionImages();
    initialiserJournal();
    initialiserStatistiques();
    initialiserArduino();
    connecterSignaux();
}

void MainWindow::initialiserInterface()
{
    ui->stackedWidget->setCurrentWidget(ui->page_c);
    setWindowTitle("Qunatam team - Smart Drive");
    isEditingCandidat = false;
    currentCandidatId = 0;
    ui->filtrer_c->addItem("Début");
    Candidat c;
    c.afficher(ui->table_candidat);
}

void MainWindow::initialiserGestionImages()
{
    m_imageVerif = new ImageVer_C(ui->Photobtn_c, ui->Photoaff_c, this);
}

void MainWindow::initialiserJournal()
{
    if (ui->his_c) {
        m_journalCandidat->setListWidget(ui->his_c);
        m_journalCandidat->chargerHistorique();
        GereCandidat::setJournal(m_journalCandidat);
    }
}

void MainWindow::initialiserStatistiques()
{
    m_statCandidat = new StatCandidat(this);
    QVBoxLayout *layout = new QVBoxLayout(ui->aff_stat_c);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(m_statCandidat);
    m_statCandidat->setTempsReelEnabled(true);
    m_statCandidat->setIntervalleMAJ(2000);
    m_statCandidat->setAnimationEnabled(true);
    m_statCandidat->mettreAJourDonnees(ui->table_candidat);
}

void MainWindow::connecterSignaux()
{
    connect(ui->filtrer_c, &QComboBox::currentTextChanged,
            this, &MainWindow::onFiltrerChanged);
    connect(ui->trier_c, &QComboBox::currentTextChanged,
            this, &MainWindow::onTrierChanged);
    connect(ui->prog_idcandidat, &QLineEdit::textChanged,
            this, &MainWindow::on_prog_idcandidat_textChanged);
    connect(ui->table_candidat->model(), &QAbstractItemModel::dataChanged,
            this, [this]() { m_statCandidat->mettreAJourDonnees(ui->table_candidat); });
    connect(ui->table_candidat->model(), &QAbstractItemModel::layoutChanged,
            this, [this]() { m_statCandidat->mettreAJourDonnees(ui->table_candidat); });
    connect(ui->conduite_c, &QCheckBox::stateChanged, this, [this](int state) {
        if (state == Qt::Checked && !ui->code_c->isChecked()) {
            ui->code_c->setChecked(true);
            ui->statusbar->showMessage("'Code' automatiquement coché pour 'Conduite'", 2000);
        }
    });

    connect(ui->parc_c, &QCheckBox::stateChanged, this, [this](int state) {
        if (state == Qt::Checked) {
            if (!ui->code_c->isChecked()) {
                ui->code_c->setChecked(true);
            }
            if (!ui->conduite_c->isChecked()) {
                ui->conduite_c->setChecked(true);
            }
            ui->statusbar->showMessage("Prérequis automatiquement cochés pour 'Parc'", 2000);
        }
    });
}

void MainWindow::on_fermer_btn_clicked() { close(); }
void MainWindow::on_vehicule_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_v); }
void MainWindow::on_candidat_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_c); }
void MainWindow::on_seance_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_s); }
void MainWindow::on_emp_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_emp); }
void MainWindow::on_moniteur_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_m); }

void MainWindow::on_enregistrer_c_clicked()
{
    GereCandidat::ajouterCandidat(ui, m_imageVerif, isEditingCandidat);
    m_statCandidat->mettreAJourDonnees(ui->table_candidat);
}

void MainWindow::on_modifier_c_clicked()
{
    bool wasArduinoControlled = m_arduinoControlActive;
    int arduinoId = m_arduinoControlledId;

    if (GereCandidat::modifierCandidat(ui, c, isEditingCandidat, currentCandidatId, m_imageVerif)) {
        m_statCandidat->mettreAJourDonnees(ui->table_candidat);
        isEditingCandidat = false;
        currentCandidatId = 0;
        if (wasArduinoControlled && m_arduinoManager->isConnected()) {
            m_arduinoManager->sendUpdateSuccess();
            m_arduinoControlActive = false;
            m_arduinoControlledId = 0;
        }
    } else {
        if (wasArduinoControlled && m_arduinoManager->isConnected()) {
            m_arduinoManager->sendError("MODIF_FAILED");
        }
    }
}

void MainWindow::on_supp_c_clicked()
{
    if (GereCandidat::supprimerCandidat(ui, c, isEditingCandidat, currentCandidatId, m_imageVerif)) {
        m_statCandidat->mettreAJourDonnees(ui->table_candidat);
    }
}

void MainWindow::on_table_candidat_doubleClicked(const QModelIndex &index)
{
    GereCandidat::chargerCandidatPourModification(ui, index, isEditingCandidat, currentCandidatId, m_imageVerif);
    if (m_arduinoManager->isConnected() && isEditingCandidat && currentCandidatId > 0) {
        QSqlQuery query;
        query.prepare("SELECT PROGRESSION FROM CANDIDATS WHERE ID_CANDIDAT = :id");
        query.bindValue(":id", currentCandidatId);
        if (query.exec() && query.next()) {
            QString progression = query.value(0).toString();
            int percent = 0;
            if (progression == "Début") percent = 0;
            else if (progression == "Code") percent = 50;
            else if (progression == "Conduite") percent = 75;
            else if (progression == "Parc") percent = 100;
            QSqlQuery queryInfo;
            queryInfo.prepare("SELECT NOM_C, PRENOM_C FROM CANDIDATS WHERE ID_CANDIDAT = :id");
            queryInfo.bindValue(":id", currentCandidatId);
            QString nom = "", prenom = "";
            if (queryInfo.exec() && queryInfo.next()) {
                nom = queryInfo.value(0).toString();
                prenom = queryInfo.value(1).toString();
            }
            ui->code_c->setChecked(false);
            ui->conduite_c->setChecked(false);
            ui->parc_c->setChecked(false);

            if (progression == "Code") {
                ui->code_c->setChecked(true);
            } else if (progression == "Conduite") {
                ui->code_c->setChecked(true);
                ui->conduite_c->setChecked(true);
            } else if (progression == "Parc") {
                ui->code_c->setChecked(true);
                ui->conduite_c->setChecked(true);
                ui->parc_c->setChecked(true);
            }
            m_arduinoManager->sendCandidateDetails(currentCandidatId, percent, nom, prenom);
        }
    }
}
void MainWindow::onFiltrerChanged(const QString &filterText)
{
    GereCandidat::filtreC(ui, filterText);
    m_statCandidat->mettreAJourDonnees(ui->table_candidat);
}

void MainWindow::onTrierChanged(const QString &sortText)
{
    GereCandidat::trierC(ui, sortText);
    m_statCandidat->mettreAJourDonnees(ui->table_candidat);
}

void MainWindow::on_conf_rech_c_clicked()
{
    GereCandidat::rechC(ui, ui->taper_c->text());
    m_statCandidat->mettreAJourDonnees(ui->table_candidat);
}

void MainWindow::on_prog_idcandidat_textChanged(const QString &text)
{
    GereCandidat::rechercherProgression(ui, text);
}

void MainWindow::on_viderJournal_clicked()
{
    GereCandidat::viderJournal(m_journalCandidat, this);
}

void MainWindow::on_voirJournalComplet_clicked()
{
    GereCandidat::voirJournalComplet(m_journalCandidat, this);
}

void MainWindow::on_expo_tab_c_clicked()
{
    GereCandidat::exporterExcel(ui);
}

void MainWindow::initialiserArduino()
{

    connect(m_arduinoManager, &ArduinoManager::buttonPressed,
            this, &MainWindow::onArduinoButtonPressed);
    connect(m_arduinoManager, &ArduinoManager::connectionStatusChanged,
            this, &MainWindow::onArduinoConnectionChanged);
    bool connected = m_arduinoManager->connectToArduino();

    if (connected) {
        ui->statusbar->showMessage("Arduino: Connecté", 3000);
    } else {
        ui->statusbar->showMessage("Arduino: Non connecté - Vérifiez le câble USB", 5000);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onArduinoButtonPressed(ArduinoManager::ButtonType button)
{
    qDebug() << "=== BOUTON ARDUINO PRESSÉ ===";
    qDebug() << "Type:" << button;
    if (!isEditingCandidat) {
        qDebug() << "ERREUR: Pas en mode édition";
        QMessageBox::warning(this, "Erreur", "Veuillez d'abord double-cliquer sur un candidat!");
        m_arduinoManager->sendError("NO_CANDIDATE");
        return;
    }

    if (currentCandidatId <= 0) {
        qDebug() << "ERREUR: ID candidat invalide";
        m_arduinoManager->sendError("NO_CANDIDATE");
        return;
    }
    switch (button) {
    case ArduinoManager::BUTTON_CODE:
        qDebug() << "Action: Cocher CODE";
        ui->code_c->setChecked(true);
        ui->conduite_c->setChecked(false);
        ui->parc_c->setChecked(false);
        updateArduinoDisplay(50, "Code");
        break;

    case ArduinoManager::BUTTON_CONDUITE:  // D3
        qDebug() << "Action: Cocher CONDUITE";

        if (!ui->code_c->isChecked()) {
            qDebug() << "ERREUR: Code requis pour Conduite";
            QMessageBox::warning(this, "Prérequis manquant",
                                 "Le 'Code' doit être validé avant la 'Conduite'!");
            m_arduinoManager->sendError("NEEDS_CODE");
            return;
        }

        ui->conduite_c->setChecked(true);
        ui->parc_c->setChecked(false);
        updateArduinoDisplay(75, "Conduite");
        break;

    case ArduinoManager::BUTTON_PARC:
        qDebug() << "Action: Cocher PARC";

        if (!ui->code_c->isChecked() || !ui->conduite_c->isChecked()) {
            qDebug() << "ERREUR: Code ET Conduite requis pour Parc";
            QMessageBox::warning(this, "Prérequis manquants",
                                 "Le 'Code' ET la 'Conduite' doivent être validés avant le 'Parc'!");
            m_arduinoManager->sendError("NEEDS_BOTH");
            return;
        }

        ui->parc_c->setChecked(true);
        updateArduinoDisplay(100, "Parc");
        break;

    case ArduinoManager::BUTTON_CONFIRM:
        qDebug() << "Action: CONFIRMER modification";
        handleArduinoConfirm();
        break;

    default:
        qDebug() << "ERREUR: Bouton inconnu";
        break;
    }

    qDebug() << "Checkboxes après traitement:";
    qDebug() << "  Code:" << ui->code_c->isChecked();
    qDebug() << "  Conduite:" << ui->conduite_c->isChecked();
    qDebug() << "  Parc:" << ui->parc_c->isChecked();
    qDebug() << "=== FIN TRAITEMENT ===";
}

void MainWindow::onArduinoConnectionChanged(bool connected)
{
    if (connected) {
        ui->statusbar->showMessage("✅ Arduino connecté", 2000);
    } else {
        ui->statusbar->showMessage("❌ Arduino déconnecté", 5000);
        m_arduinoControlActive = false;
    }
}

void MainWindow::handleArduinoConfirm()
{
    if (!isEditingCandidat || currentCandidatId <= 0) {
        QMessageBox::warning(this, "Aucun candidat",
                             "Aucun candidat sélectionné pour modification!");
        m_arduinoManager->sendError("NO_CANDIDATE");
        return;
    }

    QString nouvelleProgression = "Début";
    if (ui->parc_c->isChecked()) {
        nouvelleProgression = "Parc";
    } else if (ui->conduite_c->isChecked()) {
        nouvelleProgression = "Conduite";
    } else if (ui->code_c->isChecked()) {
        nouvelleProgression = "Code";
    }
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE CANDIDATS SET PROGRESSION = :progression WHERE ID_CANDIDAT = :id");
    updateQuery.bindValue(":progression", nouvelleProgression);
    updateQuery.bindValue(":id", currentCandidatId);

    if (updateQuery.exec()) {
        Candidat c;
        c.afficher(ui->table_candidat);
        m_statCandidat->mettreAJourDonnees(ui->table_candidat);
        m_arduinoManager->sendUpdateSuccess();
        QSqlQuery selectQuery;
        selectQuery.prepare("SELECT NOM_C, PRENOM_C FROM CANDIDATS WHERE ID_CANDIDAT = :id");
        selectQuery.bindValue(":id", currentCandidatId);

        if (selectQuery.exec() && selectQuery.next()) {
            QString nom = selectQuery.value(0).toString();
            QString prenom = selectQuery.value(1).toString();
            int newPercent = 0;
            if (nouvelleProgression == "Début") newPercent = 0;
            else if (nouvelleProgression == "Code") newPercent = 50;
            else if (nouvelleProgression == "Conduite") newPercent = 75;
            else if (nouvelleProgression == "Parc") newPercent = 100;

            m_arduinoManager->sendCandidateDetails(currentCandidatId, newPercent, nom, prenom);
        }
        isEditingCandidat = false;
        currentCandidatId = 0;
        m_arduinoControlActive = false;
        QMessageBox::information(this, "Succès",
                                 QString("Candidat mis à jour avec succès!\n"
                                         "Nouvelle progression: %1").arg(nouvelleProgression));

    } else {
        QMessageBox::critical(this, "Erreur BDD",
                              "Impossible de mettre à jour la base de données!");
        m_arduinoManager->sendError("SQL_ERROR");
    }
}


QString MainWindow::getCurrentProgression() const
{
    if (ui->parc_c->isChecked()) {
        return "Parc";
    } else if (ui->conduite_c->isChecked()) {
        return "Conduite";
    } else if (ui->code_c->isChecked()) {
        return "Code";
    } else {
        return "Début";
    }
}
void MainWindow::updateArduinoDisplay(int percent, const QString &progression)
{
    if (m_arduinoManager->isConnected() && currentCandidatId > 0) {
        m_arduinoManager->sendCandidateSelection(currentCandidatId, percent);
        ui->statusbar->showMessage(
            QString("Arduino: Candidat %1 → %2% (%3)")
                .arg(currentCandidatId)
                .arg(percent)
                .arg(progression),
            3000);
    }
}
void MainWindow::debugArduinoState(const QString &message)
{
    qDebug() << "🔍 Arduino State:" << message;
    qDebug() << "   isEditingCandidat:" << isEditingCandidat;
    qDebug() << "   currentCandidatId:" << currentCandidatId;
    qDebug() << "   arduinoConnected:" << m_arduinoManager->isConnected();
    qDebug() << "   Checkboxes - Code:" << ui->code_c->isChecked()
             << "Conduite:" << ui->conduite_c->isChecked()
             << "Parc:" << ui->parc_c->isChecked();
}

void MainWindow::resetCheckboxesFromProgression(const QString &progression)
{
    ui->code_c->setChecked(false);
    ui->conduite_c->setChecked(false);
    ui->parc_c->setChecked(false);
    if (progression == "Code") {
        ui->code_c->setChecked(true);
    }
    else if (progression == "Conduite") {
        ui->code_c->setChecked(true);
        ui->conduite_c->setChecked(true);
    }
    else if (progression == "Parc") {
        ui->code_c->setChecked(true);
        ui->conduite_c->setChecked(true);
        ui->parc_c->setChecked(true);
    }
}
