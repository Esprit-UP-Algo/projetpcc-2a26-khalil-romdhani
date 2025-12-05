#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "moniteur.h"
#include "geremoniteur.h"
#include "GereCandidat.h"
#include "employe.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QDebug>
#include <QTextCursor>
#include <QTime>
#include <QVBoxLayout>
#include "Candidat.h"
#include "StatCandidat.h"
#include "JournalCandidat.h"
#include "ImageVer_C.h"
#include "groq_manager.h"
#include "veh_func.h"
#include "veh.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
    , m_statCandidat(nullptr)
    , m_journalCandidat(new JournalCandidat(this))
    , m_imageVerif(nullptr)
{
    ui->setupUi(this);

    Connection* c = Connection::instance();

    // chat
    db = c->getDb();
    setWindowTitle("Qunatam team - Smart Drive");

    // Initialisation de l'objet Employe
    m_employe = new Employe();

    initialiserInterface();
    initialiserGestionImages();
    initialiserJournal();
    initialiserStatistiques();
    connecterSignaux();
    m_groqManager = new GroqManager(this);
    m_groqManager->setupUI(ui->matricule_gemini, ui->resultat_gemini, ui->conf_v_gemini, ui->reins_v_gemini);

    // Module Véhicule
    veh *v = new veh();
    v->initV(ui->matricule, ui->type_v, ui->marque_v, ui->modele_v, ui->kilometrage_v, ui->bon, ui->entretien, ui->panne, ui->date_achat_v, ui->date_maint_v, ui->type_stat, ui->etat_stat);
    connect(ui->conf_v, &QPushButton::clicked, v, &veh::ConfV);
    connect(ui->supp_v, &QPushButton::clicked, v, &veh::suppV);
    connect(ui->reins_v, &QPushButton::clicked, v, &veh::reinitV);
    connect(ui->modif_v, &QPushButton::clicked, v, &veh::modifV);
    connect(ui->table_ajout_v, &QTableWidget::clicked, v, &veh::tabClick);
    v->affTab(ui->table_ajout_v);
    connect(ui->acc_stat_v, &QPushButton::clicked, v, &veh::refreshCharts);
    v->refreshCharts();
    v->initCarteGrise(ui->matricule_carte);
    connect(ui->conf_v_carte, &QPushButton::clicked, v, &veh::confCarteGrise);
    connect(ui->reins_v_carte, &QPushButton::clicked, v, &veh::reinsCarteGrise);
    m_vehFunc = new veh_func(this);
    QTableWidget* filterTable = ui->table_ajout_v;
    if (!filterTable) {
        filterTable = ui->table_ajout_v;
    }
    m_vehFunc->initUI(ui->trier_v, ui->filtrer_v, ui->taper_v, filterTable);
    connect(ui->trier_v, QOverload<int>::of(&QComboBox::currentIndexChanged), [this]() { m_vehFunc->trierV(); });
    connect(ui->filtrer_v, QOverload<int>::of(&QComboBox::currentIndexChanged), [this]() { m_vehFunc->filtrerV(); });
    connect(ui->conf_rv, &QPushButton::clicked, [this]() { m_vehFunc->rechercherV(); });
    connect(ui->expo_v, &QPushButton::clicked, [this]() { m_vehFunc->exporterPDF(); });

    // Module Séance
    m_gestionSeanceUI = new GestionSeanceUI(ui, this);
    m_gestionSeanceUI->initialiserUI();

    // Initialize Moniteur variables
    isEditingMoniteur = false;
    currentMoniteurCin = "";
    derniereColonneModifiee = -1;
    derniereLigneModifiee = -1;
    derniereValeurModifiee.clear();
    dernierCin = "";

    m_chart = nullptr;
    m_chartView = nullptr;
    m_chartExperience = nullptr;
    m_chartViewExperience = nullptr;

    // ✅ DÉSACTIVER les signaux pendant l'initialisation
    ui->tab_mon->blockSignals(true);
    // ✅ Configurer date_inactivite avec une date par défaut
    ui->date_inactivite->setDate(QDate::currentDate());

    Moniteur m_temp;
    m_temp.afficher(ui->tab_mon);
    headerStyle =
        "QHeaderView::section {"
        "    background-color: #0F2434;"
        "    color: white;"
        "    font-weight: bold;"
        "    padding: 8px;"
        "    border: none;"
        "    border-right: 1px solid #1A3A4F;"
        "    border-bottom: 1px solid #1A3A4F;"
        "}"
        "QHeaderView::section:vertical {"
        "    background-color: #0F2434;"
        "    color: white;"
        "    border-right: 1px solid #1A3A4F;"
        "    border-bottom: none;"
        "}"
        "QTableCornerButton::section {"
        "    background-color: #0F2434;"
        "    border: none;"
        "}";

    // Appliquer le style initial
    ui->tab_mon->setStyleSheet(headerStyle);
    ui->tab_mon->verticalHeader()->setVisible(true);

    configurerGraphique();
    afficherStatistiquesChart();
    configurerHistogrammeExperience();
    afficherHistogrammeExperience();

    // Clignotement
    timerClignotement = new QTimer(this);
    clignotementEtat = false;

    // ====================== CONNEXIONS DIRECTES MONITEURS ======================
    connect(ui->enregistrer_m, &QPushButton::clicked, this, [this]() {
        Moniteur m;
        ui->tab_mon->blockSignals(true);
        GereMoniteur::confirmerMoniteur(ui, m, isEditingMoniteur, currentMoniteurCin);
        ui->tab_mon->blockSignals(false);
    });

    connect(ui->modifier_m, &QPushButton::clicked, this, [this]() {
        bool success = GereMoniteur::modifierMoniteurDirect(ui, derniereColonneModifiee, derniereLigneModifiee, dernierCin, derniereValeurModifiee);
        if (success) {
            GereMoniteur::rechargerTableauMoniteurs(ui, derniereColonneModifiee, derniereLigneModifiee, derniereValeurModifiee, dernierCin);
            mettreAJourClignotement();
        }
    });

    connect(ui->reinstaller_mon, &QPushButton::clicked, this, [this]() {
        GereMoniteur::reinitialiserFormulaireMoniteur(ui);
    });

    connect(ui->supp_m, &QPushButton::clicked, this, [this]() {
        GereMoniteur::supprimerMoniteur(ui, m, isEditingMoniteur, currentMoniteurCin);
    });

    connect(ui->expo_tab_m, &QPushButton::clicked, this, [this]() {
        GereMoniteur::exporterPDFMoniteur(ui);
    });

    connect(ui->tab_mon, &QTableWidget::doubleClicked, this, [this](const QModelIndex &index) {
        GereMoniteur::gererDoubleClicTableau(ui, index, derniereColonneModifiee, derniereLigneModifiee, derniereValeurModifiee, dernierCin);
    });

    connect(ui->tab_mon, &QTableWidget::cellChanged, this, [this](int row, int column) {
        GereMoniteur::gererChangementCellule(ui, row, column, derniereColonneModifiee, derniereLigneModifiee, derniereValeurModifiee, dernierCin);
    });

    connect(ui->taper_mon, &QLineEdit::textChanged, this, [this](const QString &text) {
        GereMoniteur::rechercherMoniteur(ui, text);
    });

    connect(ui->trier_mon, &QComboBox::currentTextChanged, this, [this](const QString &critere) {
        GereMoniteur::trierMoniteurs(ui, critere);
    });

    connect(ui->filtrer_mon, &QComboBox::currentTextChanged, this, [this](const QString &typePermis) {
        GereMoniteur::filtrerMoniteurs(ui, typePermis);
    });

    connect(timerClignotement, &QTimer::timeout, this, [this]() {
        GereMoniteur::mettreAJourClignotement(ui, timerClignotement, clignotementEtat, derniereColonneModifiee, derniereLigneModifiee);
    });

    demarrerClignotement();

    // ====================== MODULE EMPLOYE ======================
    // Initialiser les champs Employé
    m_employe->initE(ui->id, ui->nom, ui->prenom, ui->telephone, ui->salaire,
                     ui->poste_combo, ui->email, ui->date_embauche, ui->pass);

    // Initialiser les tableaux et filtres Employé
    m_employe->initTab(ui->tab_employes);
    m_employe->initTrier(ui->trier_E);
    m_employe->initRech(ui->taper_E);

    // Afficher le tableau initial
    m_employe->affTab(ui->tab_employes);

    // Connecter les boutons Employé
    connect(ui->conf_E, &QPushButton::clicked, m_employe, &Employe::ConfE);
    connect(ui->modif_E, &QPushButton::clicked, m_employe, &Employe::modifE);
    connect(ui->supp_E, &QPushButton::clicked, m_employe, &Employe::suppE);
    connect(ui->reins_E, &QPushButton::clicked, m_employe, &Employe::reinitE);
    connect(ui->conf_rech_E, &QPushButton::clicked, m_employe, &Employe::rechParIdOuNom);
    connect(ui->expo_tab_E, &QPushButton::clicked, m_employe, &Employe::expoE);
    connect(ui->tab_employes, &QTableWidget::cellClicked, m_employe, &Employe::tabClick);

    // Connecter le tri
    connect(ui->trier_E, QOverload<int>::of(&QComboBox::currentIndexChanged),
            m_employe, &Employe::trierE);

    // Connecter la recherche en temps réel
    connect(ui->taper_E, &QLineEdit::textChanged,
            [this]() { m_employe->rechParIdOuNom(); });

    // Connecter les statistiques
    connect(ui->stat_emp_btn, &QPushButton::clicked, [this]() {
        m_employe->afficherStatistiquesGraphique(ui->tab_widget2_E);
    });

    // ChatBot
    assistant = new ChatBot(this);
    assistant->setDatabase(db);   // IMPORTANT

    connect(ui->sendButton, &QPushButton::clicked, this, [this]() {
        QString q = ui->userInput->text().trimmed();
        if (q.isEmpty()) return;

        ui->chatDisplay->append("<b>Vous :</b> " + q);
        ui->userInput->clear();

        assistant->ask(q);
    });

    connect(assistant, &ChatBot::replyReady, this, [this](const QString &reply) {
        ui->chatDisplay->append("<b>Assistant :</b> " + reply);
    });

    connect(assistant, &ChatBot::errorOccured, this, [this](const QString &err) {
        ui->chatDisplay->append("<span style='color:red'>Erreur : " + err + "</span>");
    });

    connect(ui->btnRafraichirStats, &QPushButton::clicked, this, [this]() {
        afficherStatistiquesChart();
        afficherHistogrammeExperience();
        qDebug() << "🔄 Statistiques rafraîchies manuellement";
    });

    // ✅ RÉACTIVER les signaux après
    ui->tab_mon->blockSignals(false);

    // UI Configuration
    ui->conf_E->setDefault(false);
    ui->conf_E->setAutoDefault(false);
    ui->conf_E->setFocusPolicy(Qt::NoFocus);
    this->showMaximized();
    ui->stackedWidget->setCurrentWidget(ui->page_acceuil);
    setWindowTitle("Qunatam team - Smart Drive");
}

// ====================== NAVIGATION SLOTS ======================

void MainWindow::on_fermer_btn_clicked() { close(); }
void MainWindow::on_acceuil_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_acceuil); }
void MainWindow::on_vehicule_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_v); }
void MainWindow::on_candidat_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_c); }
void MainWindow::on_seance_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_s); }
void MainWindow::on_emp_btn_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->page_emp);
    // Rafraîchir le tableau Employés quand on accède à la page
    m_employe->affTab(ui->tab_employes);
}
void MainWindow::on_moniteur_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_m);
    rechargerTableauMoniteurs();
    demarrerClignotement();
    QTimer::singleShot(100, this, [this]() {
        mettreAJourClignotement();
    });
    GereMoniteur::afficherStatistiquesChart(ui, m_chart);
    GereMoniteur::afficherHistogrammeExperience(ui, m_chartExperience);
    qDebug() << "✅ Page moniteur avec graphique QChart";
}

void MainWindow::initialiserInterface()
{
    isEditingCandidat = false;
    currentCandidatId = 0;
    ui->filtrer_c->addItem("Début");
    Candidat c;
    c.afficher(ui->table_candidat);
}

void MainWindow::initialiserGestionImages()
{
    m_imageVerif = new ImageVer_C(ui->Photobtn_c, ui->Photoaff_c, this);
    qDebug() << "🎯 Gestion des images initialisée";
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
}

void MainWindow::on_accueil_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_acceuil); }
void MainWindow::on_vehicule_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_v); }
void MainWindow::on_candidat_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_c); }
void MainWindow::on_seance_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_s); }
void MainWindow::on_emp_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_emp); }
void MainWindow::on_moniteur_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_m);
}

// ====================== MONITEUR SLOTS IMPLEMENTATIONS ======================

void MainWindow::on_enregistrer_m_clicked()
{
    Moniteur m;
    ui->tab_mon->blockSignals(true);
    GereMoniteur::confirmerMoniteur(ui, m, isEditingMoniteur, currentMoniteurCin);
    ui->tab_mon->blockSignals(false);
}

void MainWindow::on_reinstaller_mon_clicked()
{
    GereMoniteur::reinitialiserFormulaireMoniteur(ui);
}

void MainWindow::on_tab_mon_doubleClicked(const QModelIndex &index)
{
    GereMoniteur::gererDoubleClicTableau(ui, index, derniereColonneModifiee, derniereLigneModifiee, derniereValeurModifiee, dernierCin);
}

void MainWindow::on_supp_m_clicked()
{
    GereMoniteur::supprimerMoniteur(ui, m, isEditingMoniteur, currentMoniteurCin);
}

void MainWindow::on_expo_tab_m_clicked()
{
    GereMoniteur::exporterPDFMoniteur(ui);
}

void MainWindow::on_modifier_m_clicked()
{
    bool success = GereMoniteur::modifierMoniteurDirect(ui, derniereColonneModifiee, derniereLigneModifiee, dernierCin, derniereValeurModifiee);
    if (success) {
        GereMoniteur::rechargerTableauMoniteurs(ui, derniereColonneModifiee, derniereLigneModifiee, derniereValeurModifiee, dernierCin);
        mettreAJourClignotement();
    }
}

void MainWindow::on_tab_mon_cellChanged(int row, int column)
{
    GereMoniteur::gererChangementCellule(ui, row, column, derniereColonneModifiee, derniereLigneModifiee, derniereValeurModifiee, dernierCin);
}

void MainWindow::on_taper_mon_textChanged(const QString &text)
{
    GereMoniteur::rechercherMoniteur(ui, text);
}

void MainWindow::on_filtrer_mon_currentTextChanged(const QString &typePermis)
{
    GereMoniteur::filtrerMoniteurs(ui, typePermis);
}

void MainWindow::trierMoniteurs(const QString &critere)
{
    GereMoniteur::trierMoniteurs(ui, critere);
}

void MainWindow::configurerGraphique()
{
    GereMoniteur::configurerGraphique(ui, m_chart, m_chartView);
}

void MainWindow::afficherStatistiquesChart()
{
    GereMoniteur::afficherStatistiquesChart(ui, m_chart);
}

void MainWindow::configurerHistogrammeExperience()
{
    GereMoniteur::configurerHistogrammeExperience(ui, m_chartExperience, m_chartViewExperience);
}

void MainWindow::afficherHistogrammeExperience()
{
    GereMoniteur::afficherHistogrammeExperience(ui, m_chartExperience);
}

void MainWindow::mettreAJourClignotement()
{
    GereMoniteur::mettreAJourClignotement(ui, timerClignotement, clignotementEtat, derniereColonneModifiee, derniereLigneModifiee);
}

void MainWindow::rechargerTableauMoniteurs()
{
    GereMoniteur::rechargerTableauMoniteurs(ui, derniereColonneModifiee, derniereLigneModifiee, derniereValeurModifiee, dernierCin);
}

void MainWindow::demarrerClignotement()
{
    GereMoniteur::demarrerClignotement(ui, timerClignotement, clignotementEtat);
}

MainWindow::~MainWindow()
{
    if (timerClignotement && timerClignotement->isActive()) {
        timerClignotement->stop();
        delete timerClignotement;
    }
    delete m_gestionSeanceUI;
    delete m_employe;  // Nettoyer l'objet Employe
    delete ui;
}

void MainWindow::on_enregistrer_c_clicked()
{
    GereCandidat::ajouterCandidat(ui, m_imageVerif, isEditingCandidat);
    m_statCandidat->mettreAJourDonnees(ui->table_candidat);
}

void MainWindow::on_modifier_c_clicked()
{
    if (GereCandidat::modifierCandidat(ui, c, isEditingCandidat, currentCandidatId, m_imageVerif)) {
        m_statCandidat->mettreAJourDonnees(ui->table_candidat);
        isEditingCandidat = false;
        currentCandidatId = 0;
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

void MainWindow::on_refresh_s_clicked() { m_gestionSeanceUI->on_refresh_s_clicked(); }
void MainWindow::on_confirm_ajout_s_clicked() { m_gestionSeanceUI->on_confirm_ajout_s_clicked(); }
void MainWindow::on_confirm_s_clicked() { m_gestionSeanceUI->on_confirm_s_clicked(); }
void MainWindow::on_tab_s_clicked(const QModelIndex &index) { m_gestionSeanceUI->on_tab_s_clicked(index); }
void MainWindow::on_reins_s_clicked() { m_gestionSeanceUI->on_reins_s_clicked(); }
void MainWindow::on_supp_s_clicked() { m_gestionSeanceUI->on_supp_s_clicked(); }
void MainWindow::on_filtre_s_clicked() { m_gestionSeanceUI->on_filtre_s_clicked(); }
void MainWindow::on_tri_s_currentIndexChanged(int index) { m_gestionSeanceUI->on_tri_s_currentIndexChanged(index); }
void MainWindow::on_exp_s_clicked() { m_gestionSeanceUI->on_exp_s_clicked(); }
void MainWindow::on_calendar_s_clicked(const QDate &date) { m_gestionSeanceUI->on_calendar_s_clicked(date); }
void MainWindow::on_calendar_s_selectionChanged() { m_gestionSeanceUI->on_calendar_s_selectionChanged(); }
void MainWindow::on_mapType_s_currentIndexChanged(int index) { m_gestionSeanceUI->on_mapType_s_currentIndexChanged(index); }
void MainWindow::on_centerMap_s_clicked() { m_gestionSeanceUI->on_centerMap_s_clicked(); }
