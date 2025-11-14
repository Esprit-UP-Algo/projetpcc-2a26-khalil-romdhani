#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "veh.h"
#include "employe.h"
#include "moniteur.h"
#include "geremoniteur.h"
#include "GereCandidat.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize database connection
    Connection* c = Connection::instance();
    bool test = c->createconnect();

    // Initialize Moniteur variables
    isEditingMoniteur = false;
    currentMoniteurCin = "";
    connect(ui->tab_mon, &QTableWidget::cellChanged, this, &MainWindow::on_tab_mon_cellChanged);
    derniereColonneModifiee = -1;
    derniereValeurModifiee.clear();
    dernierCin = "";

    // Initialize Candidat variables
    isEditingCandidat = false;
    currentCandidatId = 0;

    // UI Configuration
    ui->conf_E->setDefault(false);
    ui->conf_E->setAutoDefault(false);
    ui->conf_E->setFocusPolicy(Qt::NoFocus);
    this->showMaximized();
    ui->stackedWidget->setCurrentWidget(ui->page_c);
    setWindowTitle("Qunatam team - Smart Drive");

    // Setup Candidat filters and sorting
    ui->filtrer_c->addItem("Filtrer");
    ui->filtrer_c->addItem("Début");
    ui->filtrer_c->addItem("Code");
    ui->filtrer_c->addItem("Conduite");
    ui->filtrer_c->addItem("Parc");

    ui->trier_c->addItem("Trier");
    ui->trier_c->addItem("Nom croissant");
    ui->trier_c->addItem("Nom décroissant");
    ui->trier_c->addItem("Date naissance croissante");
    ui->trier_c->addItem("Date naissance décroissante");

    // Connect Candidat signals
    connect(ui->filtrer_c, &QComboBox::currentTextChanged, this, &MainWindow::onFiltrerChanged);
    connect(ui->trier_c, &QComboBox::currentTextChanged, this, &MainWindow::onTrierChanged);

    // Initialize and display Candidat table
    Candidat c_temp;
    c_temp.afficher(ui->table_candidat);

    // Initialize Vehicule module
    veh *v = new veh();
    v->initV(ui->matricule, ui->type_v, ui->marque_v, ui->modele_v, ui->kilometrage_v, ui->bon, ui->entretien, ui->panne, ui->date_achat_v, ui->date_maint_v);
    v->initFiltrer(ui->filtrer_v);
    v->initTrier(ui->trier_v);
    connect(ui->conf_v, &QPushButton::clicked, v, &veh::ConfV);
    connect(ui->supp_v, &QPushButton::clicked, v, &veh::suppV);
    connect(ui->reins_v, &QPushButton::clicked, v, &veh::reinitV);
    connect(ui->modif_v, &QPushButton::clicked, v, &veh::modifV);
    connect(ui->table_ajout_v, &QTableWidget::clicked, v, &veh::tabClick);
    v->affTab(ui->table_ajout_v);
    v->refTab();
    v->initRech(ui->taper_v);
    connect(ui->conf_rv, &QPushButton::clicked, v, &veh::rechV);
    connect(ui->expo_v, &QPushButton::clicked, v, &veh::expoV);

    // Initialize Employe module - EXACTLY AS IT WAS
    Employe *emp = new Employe();
    emp->initE(ui->id, ui->nom, ui->prenom, ui->telephone,
               ui->salaire, ui->poste_combo, ui->email,
               ui->date_embauche, ui->pass);
    emp->initTab(ui->tab_employes);
    emp->affTab(ui->tab_employes);
    emp->initTrier(ui->trier_E);
    emp->initRech(ui->taper_E);
    emp->refTab();

    connect(ui->conf_E, &QPushButton::clicked, emp, &Employe::ConfE);
    connect(ui->modif_E, &QPushButton::clicked, emp, &Employe::modifE);
    connect(ui->supp_E, &QPushButton::clicked, emp, &Employe::suppE);
    connect(ui->reins_E, &QPushButton::clicked, emp, &Employe::reinitE);
    connect(ui->conf_rech_E, &QPushButton::clicked, emp, &Employe::rechE);
    connect(ui->expo_tab_E, &QPushButton::clicked, emp, &Employe::expoE);
    connect(ui->tab_employes, &QTableWidget::cellClicked, emp, &Employe::tabClick);

    // Initialize Moniteur table
    Moniteur mon_temp;
    mon_temp.afficher(ui->tab_mon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Navigation slots
void MainWindow::on_fermer_btn_clicked() { close(); }
void MainWindow::on_vehicule_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_v); }
void MainWindow::on_candidat_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_c); }
void MainWindow::on_seance_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_s); }
void MainWindow::on_emp_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_emp); }
void MainWindow::on_moniteur_btn_clicked() { ui->stackedWidget->setCurrentWidget(ui->page_m); }

// Moniteur slots
void MainWindow::on_enregistrer_m_clicked()
{
    Moniteur m;
    ui->tab_mon->blockSignals(true);
    GereMoniteur::confirmerMoniteur(ui, m, isEditingMoniteur, currentMoniteurCin);
    ui->tab_mon->blockSignals(false);
}

void MainWindow::on_modifier_m_clicked()
{
    if (derniereColonneModifiee == -1 || derniereLigneModifiee == -1) {
        QMessageBox::information(this, "Info", "Double-cliquez d'abord sur une cellule à modifier !");
        return;
    }

    QString nouvelleValeur = ui->tab_mon->item(derniereLigneModifiee, derniereColonneModifiee)->text();
    QString champ;

    switch (derniereColonneModifiee) {
    case 1: champ = "NOM_M"; break;
    case 2: champ = "PRENOM_M"; break;
    case 3: champ = "EMAIL_M"; break;
    case 4: champ = "TEL_M"; break;
    case 5: champ = "SPECIALITE_M"; break;
    case 6: champ = "DISPO_M"; break;
    case 7: champ = "EXPERIENCE_M"; break;
    default:
        QMessageBox::warning(this, "Erreur", "Cette colonne ne peut pas être modifiée directement.");
        return;
    }

    QWidget* parent = ui->nom_m->parentWidget();
    QRegularExpression nomRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]{2,30}$");
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpression phoneRegex("^[0-9]{8}$");
    QRegularExpression expRegex("^[0-9]{1,2}$");

    if (champ == "NOM_M" || champ == "PRENOM_M") {
        if (!nomRegex.match(nouvelleValeur).hasMatch()) {
            QMessageBox::warning(parent, "Erreur", "Le nom ou prénom doit contenir uniquement des lettres (2-30 caractères).");
            return;
        }
    } else if (champ == "EMAIL_M") {
        if (!emailRegex.match(nouvelleValeur).hasMatch()) {
            QMessageBox::warning(parent, "Erreur", "Veuillez entrer un email valide !");
            return;
        }
    } else if (champ == "SPECIALITE_M") {
        QString valeur = nouvelleValeur.trimmed().toLower();
        if (valeur == "permis a") nouvelleValeur = "Permis A";
        else if (valeur == "permis b") nouvelleValeur = "Permis B";
        else if (valeur == "permis c") nouvelleValeur = "Permis C";
        else if (valeur == "permis d") nouvelleValeur = "Permis D";

        QStringList specialitesAutorisees = {"Permis A", "Permis B", "Permis C", "Permis D"};
        if (!specialitesAutorisees.contains(nouvelleValeur, Qt::CaseSensitive)) {
            QMessageBox::warning(parent, "Erreur", "La spécialité doit être : Permis A, Permis B, Permis C ou Permis D !");
            return;
        }
    } else if (champ == "TEL_M") {
        if (!phoneRegex.match(nouvelleValeur).hasMatch()) {
            QMessageBox::warning(parent, "Erreur", "Le téléphone doit contenir 8 chiffres !");
            return;
        }
    } else if (champ == "EXPERIENCE_M") {
        if (!expRegex.match(nouvelleValeur).hasMatch()) {
            QMessageBox::warning(parent, "Erreur", "L'expérience doit être un nombre entre 0 et 50.");
            return;
        }
    }

    Moniteur m;
    bool success = m.modifier(dernierCin, champ, nouvelleValeur);

    if (success) {
        QMessageBox::information(this, "Succès", "Modification enregistrée avec succès !");
        ui->tab_mon->blockSignals(true);
        m.afficher(ui->tab_mon);
        ui->tab_mon->blockSignals(false);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour dans la base de données !");
    }

    derniereColonneModifiee = -1;
    derniereLigneModifiee = -1;
    derniereValeurModifiee.clear();
}

void MainWindow::on_tab_mon_doubleClicked(const QModelIndex &index)
{
    int col = index.column();
    int row = index.row();

    if (col == 0) {
        QMessageBox::warning(this, "Erreur", "Le CIN ne peut pas être modifié !");
        return;
    }

    derniereColonneModifiee = col;
    derniereLigneModifiee = row;
    dernierCin = ui->tab_mon->item(row, 0)->text();
}

void MainWindow::on_reinstaller_mon_clicked()
{
    GereMoniteur::reinitialiserFormulaireMoniteur(ui);
}

void MainWindow::on_supp_m_clicked()
{
    GereMoniteur::supprimerMoniteur(ui, m, isEditingMoniteur, currentMoniteurCin);
}

void MainWindow::on_expo_tab_m_clicked()
{
    GereMoniteur::exporterPDFMoniteur(ui);
}

void MainWindow::on_tab_mon_cellChanged(int row, int column)
{
    if (ui->tab_mon->signalsBlocked())
        return;

    QTableWidgetItem* item = ui->tab_mon->item(row, column);
    if (!item)
        return;

    if (column == 0) {
        QMessageBox::warning(this, "Erreur", "Le CIN ne peut pas être modifié !");
        ui->tab_mon->blockSignals(true);
        item->setText(dernierCin);
        ui->tab_mon->blockSignals(false);
        return;
    }

    derniereValeurModifiee = item->text();
    derniereColonneModifiee = column;

    QTableWidgetItem* cinItem = ui->tab_mon->item(row, 0);
    if (cinItem)
        dernierCin = cinItem->text();

    QString champErreur;
    QRegularExpression regex;
    bool valide = true;

    switch (column) {
    case 1:
    case 2:
        regex = QRegularExpression("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]{2,30}$");
        valide = regex.match(item->text()).hasMatch();
        if (!valide) champErreur = "Le nom ou prénom doit contenir uniquement des lettres (2-30 caractères).";
        break;

    case 4:
        regex = QRegularExpression("^[0-9]{8}$");
        valide = regex.match(item->text()).hasMatch();
        if (!valide) champErreur = "Le téléphone doit contenir exactement 8 chiffres.";
        break;
    case 5:
    {
        QString valeur = item->text().trimmed();
        QStringList specialitesAutorisees = {"Permis A", "Permis B", "Permis C", "Permis D"};

        valeur = valeur.toLower();
        if (valeur == "permis a") valeur = "Permis A";
        else if (valeur == "permis b") valeur = "Permis B";
        else if (valeur == "permis c") valeur = "Permis C";
        else if (valeur == "permis d") valeur = "Permis D";

        valide = specialitesAutorisees.contains(valeur, Qt::CaseInsensitive);

        if (!valide)
            champErreur = "La spécialité doit être : Permis A, Permis B, Permis C ou Permis D.";
        else {
            ui->tab_mon->blockSignals(true);
            item->setText(valeur);
            ui->tab_mon->blockSignals(false);
        }
        break;
    }
    case 6:
        regex = QRegularExpression("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        valide = regex.match(item->text()).hasMatch();
        if (!valide) champErreur = "L'adresse email est invalide.";
        break;

    case 7:
        regex = QRegularExpression("^[0-9]{1,2}$");
        valide = regex.match(item->text()).hasMatch();
        if (!valide) champErreur = "L'expérience doit être un nombre entre 0 et 50.";
        break;

    default:
        break;
    }

    if (!valide) {
        QMessageBox::warning(this, "Erreur de saisie", champErreur);
        ui->tab_mon->blockSignals(true);
        item->setText("");
        ui->tab_mon->blockSignals(false);
        derniereColonneModifiee = -1;
        derniereValeurModifiee.clear();
        return;
    }

    derniereValeurModifiee = ui->tab_mon->item(row, column)->text();
    derniereColonneModifiee = column;
    dernierCin = ui->tab_mon->item(row, 0)->text();
}

// Candidat slots
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

void MainWindow::on_conf_rech_c_clicked()
{
    QString searchText = ui->taper_c->text();
    GereCandidat::rechC(ui, searchText);
}

void MainWindow::onFiltrerChanged(const QString &filterText)
{
    GereCandidat::filtreC(ui, filterText);
}

void MainWindow::onTrierChanged(const QString &sortText)
{
    GereCandidat::trierC(ui, sortText);
}
