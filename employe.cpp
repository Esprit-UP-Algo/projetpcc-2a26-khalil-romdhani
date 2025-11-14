#include "employe.h"
#include "employesql.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlError>  // utile pour afficher les erreurs SQL
#include <QHeaderView>


Employe::Employe()
{
    ui_id = nullptr;
    ui_nom = nullptr;
    ui_prenom = nullptr;
    ui_telephone = nullptr;
    ui_salaire = nullptr;
    ui_poste = nullptr;
    ui_email = nullptr;
    ui_date_embauche = nullptr;
    ui_pass = nullptr;
    ui_table_ajout_E = nullptr;
    ui_trier_e = nullptr;
    ui_taper_e = nullptr;
    currId = "";
    sqli = new EmployeSQL(this);
}

// ---------- VALIDATION ----------
bool Employe::verifE(const QString& id, const QString& nom, const QString& prenom,
                     const QString& telephone, const QDate& date_embauche,
                     const QString& poste, const QString& salaire,
                     const QString& email, const QString& pass)
{
    if(!verifId(id)) {
        QMessageBox::warning(nullptr, "Erreur", "ID invalide");
        return false;
    }
    if(!verifNomPrenom(nom, prenom)) {
        QMessageBox::warning(nullptr, "Erreur", "Nom ou prénom invalide");
        return false;
    }
    if(!verifTel(telephone)) {
        QMessageBox::warning(nullptr, "Erreur", "Téléphone invalide");
        return false;
    }
    if(!verifDate(date_embauche)) {
        QMessageBox::warning(nullptr, "Erreur", "Date d'embauche invalide");
        return false;
    }
    if(!verifPoste(poste)) {
        QMessageBox::warning(nullptr, "Erreur",
                             "Poste invalide. Les postes autorisés sont:\n"
                             "- responsable de moniteur\n"
                             "- responsable de seance\n"
                             "- responsable de vehicule\n"
                             "- responsable de employe\n"
                             "- responsable de candidat");
        return false;
    }
    if(salaire.toDouble() < 0) {
        QMessageBox::warning(nullptr, "Erreur", "Salaire invalide");
        return false;
    }
    if(!verifEmail(email)) {  // REMPLACEZ l'ancienne vérification par cet appel
        return false;
    }
    if(pass.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Mot de passe vide");
        return false;
    }
    return true;
}

bool Employe::verifId(const QString& id)
{
    if(id.isEmpty()) return false;
    static QRegularExpression pattern("^\\d+$");
    return pattern.match(id).hasMatch();
}

bool Employe::verifNomPrenom(const QString& nom, const QString& prenom)
{
    if(nom.isEmpty() || prenom.isEmpty()) return false;
    static QRegularExpression pattern("^[A-Za-z]+$");
    return pattern.match(nom).hasMatch() && pattern.match(prenom).hasMatch();
}

bool Employe::verifTel(const QString& tel)
{
    QString t = tel;
    t = t.trimmed();        // supprime les espaces au début et à la fin
    t.remove(" ");           // supprime tous les espaces à l'intérieur

    // Vérifie que c'est 8 chiffres et que ça commence par 2, 5, 7 ou 9
    static QRegularExpression pattern("^[2579]\\d{7}$");
    return pattern.match(t).hasMatch();
}
bool Employe::verifPoste(const QString& poste)
{
    if(poste.isEmpty()) return false;

    // Liste des postes autorisés
    QStringList postesAutorises = {
        "responsable de moniteur",
        "responsable de seance",
        "responsable de vehicule",
        "responsable de employe",
        "responsable de candidat"
    };

    // Vérifie si le poste fait partie de la liste (insensible à la casse)
    for(const QString& posteAutorise : postesAutorises) {
        if(poste.trimmed().toLower() == posteAutorise.toLower()) {
            return true;
        }
    }

    return false;
}
    bool Employe::verifDate(const QDate& date_embauche)
{
    return date_embauche <= QDate::currentDate() && date_embauche >= QDate(2000,1,1);
}
bool Employe::verifPass(const QString& pass)
{
    if(pass.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Mot de passe vide");
        return false;
    }

    // Vérifier la longueur minimale
    if(pass.length() < 4) {
        QMessageBox::warning(nullptr, "Erreur", "Le mot de passe doit contenir au moins 4 caractères");
        return false;
    }

    return true;
}
bool Employe::verifEmail(const QString& email)
{
    if(email.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Email vide");
        return false;
    }

    // Expression régulière pour validation d'email
    // Format: local-part@domain.tld
    static QRegularExpression emailRegex(
        "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"
        );

    if(!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(nullptr, "Erreur",
                             "Format d'email invalide.\n"
                             "Exemples valides:\n"
                             "- exemple@domain.com\n"
                             "- nom.prenom@entreprise.org\n"
                             "- user123@mail.co.uk");
        return false;
    }

    return true;
}



// ---------- INITIALISATION ----------
void Employe::initE(QLineEdit* id, QLineEdit* nom, QLineEdit* prenom, QLineEdit* telephone,
                    QLineEdit* salaire, QComboBox* poste, QLineEdit* email,  // QComboBox pour poste
                    QDateEdit* date_embauche, QLineEdit* pass)
{
    ui_id = id;
    ui_nom = nom;
    ui_prenom = prenom;
    ui_telephone = telephone;
    ui_salaire = salaire;
    ui_poste = poste;  // Maintenant c'est un QComboBox
    ui_email = email;
    ui_date_embauche = date_embauche;
    ui_pass = pass;

    // Remplir le comboBox avec les postes autorisés
    if(ui_poste->count() == 0) {
        ui_poste->addItem("responsable de moniteur");
        ui_poste->addItem("responsable de seance");
        ui_poste->addItem("responsable de vehicule");
        ui_poste->addItem("responsable de employe");
        ui_poste->addItem("responsable de candidat");
    }
}
// ---------- TABLE ----------
void Employe::affTab(QTableWidget *table)
{
    this->table = table;

    // Préparer la requête SQL
    QSqlQuery query("SELECT ID_EMPLOYE, NOM_EMP, PRENOM_EMP, TEL_EMP, DATE_EMBAUCHE_EMP, POSTE_EMP, SALAIRE_EMP, EMAIL_EMP, PASS_EMP FROM EMPLOYES");

    // Configuration du tableau
    table->setColumnCount(9);
    table->setHorizontalHeaderLabels(QStringList()
                                     << "ID"
                                     << "Nom"
                                     << "Prénom"
                                     << "Téléphone"
                                     << "Date embauche"
                                     << "Poste"
                                     << "Salaire"
                                     << "Email"
                                     << "Mot de passe");

    table->setRowCount(0);

    int row = 0;
    while (query.next())
    {
        table->insertRow(row);

        for (int j = 0; j < 9; ++j)
        {
            QString cellValue;

            // Si c'est la colonne Date (index 4), formater sans l'heure
            if (j == 4) {
                QDateTime dateTime = query.value(j).toDateTime();
                cellValue = dateTime.toString("yyyy-MM-dd");
            } else {
                cellValue = query.value(j).toString();
            }

            QTableWidgetItem *item = new QTableWidgetItem(cellValue);

            // Centrer le texte
            item->setTextAlignment(Qt::AlignCenter);

            // Empêcher la modification de la colonne ID
            if (j == 0)
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);

            table->setItem(row, j, item);
        }
        row++;
    }

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setEditTriggers(QAbstractItemView::AllEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectItems);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(table, &QTableWidget::cellClicked, this, &Employe::tabClick);
}


void Employe::refTab()
{
    if(ui_trier_e && ui_trier_e->currentText() != "Trier par")
        trierE();
    else if(sqli)
        sqli->refTab(ui_table_ajout_E);
}

// ---------- ACTIONS ----------
void Employe::initTab(QTableWidget *tab_employes)
{
    this->ui_tab_employes = tab_employes;
}

void Employe::ConfE()
{
    if (!ui_id || !ui_nom || !ui_prenom || !ui_telephone || !ui_salaire ||
        !ui_poste || !ui_email || !ui_pass || !ui_date_embauche || !ui_tab_employes)
        return;

    // --- Récupération des valeurs ---
    QString id = ui_id->text().trimmed();
    QString nom = ui_nom->text().trimmed();
    QString prenom = ui_prenom->text().trimmed();
    QString telephone = ui_telephone->text().trimmed();
    QString poste = ui_poste->currentText().trimmed();
    double salaire = ui_salaire->text().trimmed().toDouble();
    QString email = ui_email->text().trimmed();
    QString pass = ui_pass->text().trimmed();
    QDate date_embauche = ui_date_embauche->date();

    // --- Validation ---
    if (!verifE(id, nom, prenom, telephone, date_embauche, poste, QString::number(salaire), email, pass))
        return;

    // --- Vérifier si l'ID existe déjà ---
    QSqlQuery checkIdQuery;
    checkIdQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE ID_EMPLOYE = :id");
    checkIdQuery.bindValue(":id", id);
    if (checkIdQuery.exec() && checkIdQuery.next() && checkIdQuery.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Erreur", "Cet ID existe déjà");
        return;
    }

    // --- VÉRIFIER SI LE MOT DE PASSE EXISTE DÉJÀ ---
    QSqlQuery checkPassQuery;
    checkPassQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE PASS_EMP = :pass");
    checkPassQuery.bindValue(":pass", pass);
    if (checkPassQuery.exec() && checkPassQuery.next() && checkPassQuery.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Erreur", "Ce mot de passe est déjà utilisé par un autre employé");
        return;
    }

    // --- Insertion SQL ---
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES "
                  "(ID_EMPLOYE, NOM_EMP, PRENOM_EMP, TEL_EMP, POSTE_EMP, SALAIRE_EMP, EMAIL_EMP, PASS_EMP, DATE_EMBAUCHE_EMP) "
                  "VALUES (:id, :nom, :prenom, :tel, :poste, :salaire, :email, :pass, TO_DATE(:date, 'YYYY-MM-DD'))");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", telephone);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);
    query.bindValue(":date", date_embauche.toString("yyyy-MM-dd"));

    if (!query.exec())
    {
        QMessageBox::critical(nullptr, "Erreur SQL", "Échec ajout : " + query.lastError().text());
        return;
    }

    // --- Ajouter directement dans le tableau ---
    int row = ui_tab_employes->rowCount();
    ui_tab_employes->insertRow(row);

    // Créer les items avec alignement centré
    for(int i = 0; i < 9; i++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setTextAlignment(Qt::AlignCenter);
        ui_tab_employes->setItem(row, i, item);
    }

    ui_tab_employes->item(row, 0)->setText(id);
    ui_tab_employes->item(row, 1)->setText(nom);
    ui_tab_employes->item(row, 2)->setText(prenom);
    ui_tab_employes->item(row, 3)->setText(telephone);
    ui_tab_employes->item(row, 4)->setText(date_embauche.toString("yyyy-MM-dd"));
    ui_tab_employes->item(row, 5)->setText(poste);
    ui_tab_employes->item(row, 6)->setText(QString::number(salaire));
    ui_tab_employes->item(row, 7)->setText(email);
    ui_tab_employes->item(row, 8)->setText(pass);

    QMessageBox::information(nullptr, "Succès", "Employé ajouté avec succès !");

    // --- Réinitialiser les champs ---
    reinitE();
}



void Employe::modifE()
{
    if (!table) return;

    int row = table->currentRow();
    if (row < 0)
    {
        QMessageBox::warning(nullptr, "Erreur", "Veuillez sélectionner une cellule à modifier.");
        return;
    }

    // --- Récupération des valeurs ---
    QString id      = table->item(row, 0)->text(); // ID non modifiable
    QString nom     = table->item(row, 1)->text();
    QString prenom  = table->item(row, 2)->text();
    QString tel     = table->item(row, 3)->text();
    QString dateStr = table->item(row, 4)->text().trimmed();
    QString poste   = table->item(row, 5)->text();
    QString salaireStr = table->item(row, 6)->text();
    double salaire  = salaireStr.toDouble();
    QString email   = table->item(row, 7)->text();
    QString pass    = table->item(row, 8)->text();

    // --- VÉRIFIER SI LE NOUVEAU MOT DE PASSE EXISTE DÉJÀ (pour un autre employé) ---
    QSqlQuery checkPassQuery;
    checkPassQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE PASS_EMP = :pass AND ID_EMPLOYE != :id");
    checkPassQuery.bindValue(":pass", pass);
    checkPassQuery.bindValue(":id", id);
    if (checkPassQuery.exec() && checkPassQuery.next() && checkPassQuery.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Erreur", "Ce mot de passe est déjà utilisé par un autre employé");
        return;
    }

    // --- Convertir la date en QDate pour validation ---
    QDate date;
    QStringList formats = {"yyyy-MM-dd", "dd/MM/yyyy", "dd-MM-yyyy"};
    for (const QString &fmt : formats) {
        date = QDate::fromString(dateStr, fmt);
        if (date.isValid()) break;
    }

    if (!date.isValid())
    {
        QMessageBox::warning(nullptr, "Erreur",
                             "Format de date invalide. Utilisez yyyy-MM-dd, dd/MM/yyyy ou dd-MM-yyyy.");
        return;
    }

    // --- Formater la date exactement pour Oracle ---
    QString oracleDateStr = date.toString("dd-MMM-yyyy").toUpper(); // ex: 10-NOV-2025

    // --- Requête SQL avec TO_DATE et format Oracle ---
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYES SET NOM_EMP = :nom, PRENOM_EMP = :prenom, TEL_EMP = :tel, "
                  "DATE_EMBAUCHE_EMP = TO_DATE(:date_embauche, 'DD-MON-YYYY'), "
                  "POSTE_EMP = :poste, SALAIRE_EMP = :salaire, EMAIL_EMP = :email, PASS_EMP = :pass "
                  "WHERE ID_EMPLOYE = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":date_embauche", oracleDateStr); // chaîne format Oracle
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);

    // --- Exécution ---
    if (query.exec())
    {
        QMessageBox::information(nullptr, "Succès", "Modification réussie !");
        refTab();
    }
    else
    {
        QMessageBox::critical(nullptr, "Erreur SQL",
                              "Échec mise à jour : " + query.lastError().text());
    }
}



void Employe::tabClick(int row, int /*column*/)
{
    if(!table) return;

    currId = table->item(row, 0)->text();

    // Pour la date, traiter le format
    QString dateStr = table->item(row, 4)->text();
    QDate date;

    // Essayer différents formats
    QStringList formats = {"yyyy-MM-dd", "yyyy-MM-ddTHH:mm:ss.zzz", "dd/MM/yyyy"};
    for (const QString &fmt : formats) {
        date = QDate::fromString(dateStr, fmt);
        if (date.isValid()) break;
    }

    // Si aucun format ne fonctionne, utiliser la date actuelle
    if (!date.isValid()) {
        date = QDate::currentDate();
    }

    ui_id->setText(table->item(row, 0)->text());
    ui_nom->setText(table->item(row, 1)->text());
    ui_prenom->setText(table->item(row, 2)->text());
    ui_telephone->setText(table->item(row, 3)->text());
    ui_date_embauche->setDate(date); // Utiliser la date convertie
    ui_poste->setCurrentText(table->item(row, 5)->text());
    ui_salaire->setText(table->item(row, 6)->text());
    ui_email->setText(table->item(row, 7)->text());
    ui_pass->setText(table->item(row, 8)->text());
}


void Employe::reinitE()
{
    if(ui_id) ui_id->clear();
    if(ui_nom) ui_nom->clear();
    if(ui_prenom) ui_prenom->clear();
    if(ui_telephone) ui_telephone->clear();
    if(ui_salaire) ui_salaire->clear();
    if(ui_poste && ui_poste->count() > 0) {
        ui_poste->setCurrentIndex(0);}
    if(ui_email) ui_email->clear();
    if(ui_pass) ui_pass->clear();
    if(ui_date_embauche) ui_date_embauche->setDate(QDate(2000,1,1));
    currId = "";
}

void Employe::suppE()
{
    if (!table) return;  // vérifie que le tableau est initialisé

    int row = table->currentRow();
    if (row < 0) {
        QMessageBox::warning(nullptr, "Erreur", "Veuillez sélectionner un employé à supprimer.");
        return;
    }

    QString id = table->item(row, 0)->text();  // ID de la ligne sélectionnée

    // Confirmation de suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Supprimer",
                                  "Voulez-vous vraiment supprimer cet employé ?",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM EMPLOYES WHERE ID_EMPLOYE=:id");
        query.bindValue(":id", id);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Erreur SQL", "Échec suppression : " + query.lastError().text());
            return;  // ne ferme pas la fenêtre
        }

        // Supprimer la ligne du tableau sans fermer l'interface
        table->removeRow(row);
        QMessageBox::information(nullptr, "Succès", "Employé supprimé avec succès !");
    }

}

void Employe::trierE()
{
    if(!ui_trier_e || !ui_table_ajout_E) return;
    QString critere = ui_trier_e->currentText();
    if(critere == "Trier par") { refTab(); return; }
    sqli->trierTab(ui_table_ajout_E, critere);
}

void Employe::initRech(QLineEdit* taper_e)
{
    this->ui_taper_e = taper_e;
}

void Employe::rechE()
{
    if(!ui_taper_e || !ui_table_ajout_E) return;
    QString nom = ui_taper_e->text();
    sqli->rech(ui_table_ajout_E, nom);
}

// ---------- EXPORT ----------
void Employe::expoE()
{
    if(!ui_table_ajout_E || ui_table_ajout_E->rowCount() == 0) {
        QMessageBox::warning(nullptr, "Erreur", "Aucune donnée à exporter");
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if(fileName.isEmpty()) return;

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageOrientation(QPageLayout::Landscape);
    printer.setOutputFileName(fileName);

    QPainter painter;
    painter.begin(&printer);
    QFont font = painter.font();
    font.setPointSize(7);
    painter.setFont(font);
    int colPositions[9] = {30, 70, 130, 190, 250, 310, 370, 430, 490};
    int y = 50;
    QStringList headers = {"ID", "Nom", "Prenom", "Tel", "Date Embauche", "Poste", "Salaire", "Email", "Pass"};
    for(int col = 0; col < headers.size(); col++) painter.drawText(colPositions[col], y, headers[col]);
    y += 20;
    painter.drawLine(30, y, 520, y);
    y += 15;

    for(int row = 0; row < ui_table_ajout_E->rowCount(); ++row) {
        for(int col = 0; col < ui_table_ajout_E->columnCount(); ++col) {
            QTableWidgetItem* item = ui_table_ajout_E->item(row, col);
            if(item) painter.drawText(colPositions[col], y, item->text());
        }
        y += 15;
        if(y > 250) { printer.newPage(); y = 50; }
    }
    painter.end();
    QMessageBox::information(nullptr, "Succès", "PDF exporté avec succès");
}

void Employe::initTrier(QComboBox* trier_e)
{
    this->ui_trier_e = trier_e;
    ui_trier_e->clear();
    ui_trier_e->addItem("Trier par");
    ui_trier_e->addItem("Nom croissant");
    ui_trier_e->addItem("Nom décroissant");
    ui_trier_e->addItem("Date embauche croissante");
    ui_trier_e->addItem("Date embauche décroissante");
    connect(ui_trier_e, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Employe::trierE);
}
