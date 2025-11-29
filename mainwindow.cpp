#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GereCandidat.h"
#include "Candidat.h"
#include "JournalCandidat.h"
#include "ImageVer_C.h"
#include "veh.h"
#include "vehSQL.h"
#include "veh_func.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_statCandidat(nullptr)
    , m_journalCandidat(new JournalCandidat(this))
    , m_imageVerif(nullptr)
{
    ui->setupUi(this);
    this->showMaximized();
    ui->stackedWidget->setCurrentWidget(ui->page_acceuil);
    setWindowTitle("Qunatam team - Smart Drive");
    initialiserInterface();
    initialiserGestionImages();
    initialiserJournal();
    initialiserStatistiques();
    connecterSignaux();
    m_groqManager = new GroqManager(this);
    m_groqManager->setupUI(ui->matricule_gemini, ui->resultat_gemini, ui->conf_v_gemini, ui->reins_v_gemini);
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
void MainWindow::on_fermer_btn_clicked() { close(); }
void MainWindow::on_acceuil_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_acceuil); }
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

MainWindow::~MainWindow()
{
    delete ui;
}
