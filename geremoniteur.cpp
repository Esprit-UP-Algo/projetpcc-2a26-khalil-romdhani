//geremoniteur.cpp
#include "geremoniteur.h"
#include "ui_mainwindow.h"
#include "moniteur.h"
#include <QTextDocument>
#include <QPrinter>
#include <QTextTable>
#include <QFileDialog>
#include <QTextCursor>
#include <QPageSize>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include <QSqlError>  // ✅ Pour QSqlError complet
#include <algorithm>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QDebug>
#include <QTextCursor>
#include <QTime>
#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QBrush>
#include <QFont>
#include <QLayout>
#include <QTimer>
// ✅ Vérification des champs
bool GereMoniteur::verifierMoniteur(Ui::MainWindow* ui,
                                    const QString& nom,
                                    const QString& prenom,
                                    const QString& email,
                                     const QString& disponibilite,
                                    const QString& telephone,
                                    const QString& specialite,
                                    const QString& experience)
{
    QWidget* parent = ui->nom_m->parentWidget();

    // Nom
    if (nom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le nom est obligatoire !");
        ui->nom_m->setFocus();
        return false;
    }

    QRegularExpression nomRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]{2,30}$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(parent, "Nom invalide", "Le nom doit contenir uniquement des lettres (2 à 30 caractères).");
        ui->nom_m->setFocus();
        return false;
    }

    // Prénom
    if (prenom.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le prénom est obligatoire !");
        ui->prenom_m->setFocus();
        return false;
    }

    if (!nomRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(parent, "Prénom invalide", "Le prénom doit contenir uniquement des lettres (2 à 30 caractères).");
        ui->prenom_m->setFocus();
        return false;
    }

    // Email
    if (email.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'email est obligatoire !");
        ui->email_monituer->setFocus();
        return false;
    }

    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(parent, "Email invalide", "Veuillez entrer une adresse email valide !");
        ui->email_monituer->setFocus();
        return false;
    }

    // Téléphone
    if (telephone.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "Le téléphone est obligatoire !");
        ui->telephone_m->setFocus();
        return false;
    }
QString tel = ui->telephone_m->text();
  // 🔹 Enlève les espaces avant/après
    tel.remove(QRegularExpression("[^0-9]"));  // 🔹 Garde uniquement les chiffres

    if (tel.length() != 8) {
        QMessageBox::warning(parent, "Téléphone invalide",
                             "Le téléphone doit contenir exactement 8 chiffres.");
        ui->telephone_m->setFocus();
        return false;
    }


    // Spécialité
    if (specialite == "Choisir") {
        QMessageBox::warning(parent, "Spécialité manquante", "Veuillez choisir une spécialité !");
        ui->specialite->setFocus();
        if (ui->inactif->isChecked()) {
            if (!ui->date_inactivite->date().isValid()) {
                QMessageBox::warning(parent, "Date requise",
                                     "Veuillez sélectionner une date d'inactivité pour un moniteur inactif !");
                ui->date_inactivite->setFocus();
        return false;
            }
        }
    }

    if (!ui->actif->isChecked() && !ui->inactif->isChecked()) {
        QMessageBox::warning(parent, "Disponibilité manquante", "Veuillez sélectionner une disponibilité !");
        return false;
    }

    // ✅ Vérification date d'inactivité SI inactif
    if (ui->inactif->isChecked()) {
        if (!ui->date_inactivite->date().isValid()) {
            QMessageBox::warning(parent, "Date requise",
                                 "Veuillez sélectionner une date d'inactivité pour un moniteur inactif !");
            ui->date_inactivite->setFocus();
            return false;
        }
    }

    // Expérience
    if (experience.isEmpty()) {
        QMessageBox::warning(parent, "Champ manquant", "L'expérience est obligatoire !");
        ui->experience_m->setFocus();
        return false;
    }

    QRegularExpression expRegex("^[0-9]{1,2}$");
    if (!expRegex.match(experience).hasMatch()) {
        QMessageBox::warning(parent, "Expérience invalide", "L'expérience doit être un nombre entre 0 et 50 ans.");
        ui->experience_m->setFocus();
        return false;
    }

    int expInt = experience.toInt();
    if (expInt < 0 || expInt > 50) {
        QMessageBox::warning(parent, "Expérience invalide", "L'expérience doit être comprise entre 0 et 50 ans.");
        ui->experience_m->setFocus();
        return false;
    }

    return true;
}
void GereMoniteur::chargerMoniteurPourModification(Ui::MainWindow* ui, const QModelIndex& index, bool& isEditing, QString& currentMoniteurCin)
{
    QWidget* parent = ui->nom_m->parentWidget();
    int row = index.row();

    // ✅ On récupère directement le CIN depuis la colonne 0 du tableau
    QString cin_m = ui->tab_mon->item(row, 0)->text();
    if (cin_m.isEmpty()) {
        QMessageBox::warning(parent, "Erreur", "Impossible de récupérer le CIN du moniteur !");
        return;
    }

    QString nom = ui->tab_mon->item(row, 1)->text();
    QString prenom = ui->tab_mon->item(row, 2)->text();
    QString email = ui->tab_mon->item(row, 3)->text();
    QString telephone = ui->tab_mon->item(row, 4)->text();
    QString specialite = ui->tab_mon->item(row, 5)->text();
    QString disponibilite = ui->tab_mon->item(row, 6)->text();
    QString experience = ui->tab_mon->item(row, 7)->text();

    // ✅ On met à jour la variable de suivi
    currentMoniteurCin = cin_m;
    isEditing = true;

    // ✅ On remplit les champs du formulaire
    ui->nom_m->setText(nom);
    ui->prenom_m->setText(prenom);
    ui->email_monituer->setText(email);
    ui->telephone_m->setText(telephone);
    ui->experience_m->setText(experience);

    int indexSpec = ui->specialite->findText(specialite);
    if (indexSpec != -1)
        ui->specialite->setCurrentIndex(indexSpec);

    if (disponibilite == "Actif")
        ui->actif->setChecked(true);
    else if (disponibilite == "Inactif")
        ui->inactif->setChecked(true);

    QMessageBox::information(parent, "Modification",
                             "Moniteur chargé pour modification ! Cliquez sur 'Enregistrer' pour sauvegarder.");
}

// ✅ Ajouter ou modifier un moniteur
bool GereMoniteur::confirmerMoniteur(Ui::MainWindow* ui, Moniteur& m, bool& isEditing, QString& currentMoniteurcin)
{
    QWidget* parent = ui->nom_m->parentWidget();
    QDate date_inactivite;

    QString nom = ui->nom_m->text();
    QString prenom = ui->prenom_m->text();
    QString email = ui->email_monituer->text();
    QString telephone = ui->telephone_m->text();
    QString specialite = ui->specialite->currentText();

    QString disponibilite;
    if (ui->actif->isChecked()) disponibilite = "Actif";
    else if (ui->inactif->isChecked()) disponibilite = "Inactif";

    QString experience = ui->experience_m->text();

    if (verifierMoniteur(ui, nom, prenom, email, telephone, disponibilite, specialite, experience)) {
        bool success = false;
        QString message;

        int expInt = experience.toInt();

        if (ui->inactif->isChecked()) {
            date_inactivite = ui->date_inactivite->date();
        } else {
            date_inactivite = QDate();  // si actif → date vide
        }

        if (isEditing) {
            // ✅ Correction : CIN_M est de type QString, pas int
            QString cin_m = currentMoniteurcin;


            success = m.modifier(cin_m, nom, prenom, email, telephone, disponibilite, specialite, expInt, 0,date_inactivite);

            message = success ? "Moniteur modifié avec succès !" : "Erreur lors de la modification.";

            message = success ? "Moniteur modifié avec succès !" : "Erreur lors de la modification.";
        } else {
            // ✅ On n’a pas besoin de CIN_M : il est généré automatiquement dans Oracle
            Moniteur temp(nom, prenom, email, telephone, disponibilite, specialite, expInt, 0,date_inactivite);
            success = temp.ajouter();
            message = success ? "Moniteur ajouté avec succès !" : "Erreur lors de l'ajout à la base de données.";
        }

        if (success) {
            QMessageBox::information(parent, "Succès", message);
            ui->tab_mon->blockSignals(true);   // 🚫 Empêche les signaux pendant le remplissage
            m.afficher(ui->tab_mon);
            ui->tab_mon->blockSignals(false);  // ✅ Réactive les signaux

            reinitialiserFormulaireMoniteur(ui);
            isEditing = false;
            currentMoniteurcin = "";
            return true;
        } else {
            QMessageBox::critical(parent, "Erreur SQL", message);
        }
    }
    return false;
}

// ✅ Réinitialiser le formulaire
void GereMoniteur::reinitialiserFormulaireMoniteur(Ui::MainWindow* ui)
{
    ui->nom_m->clear();
    ui->prenom_m->clear();
    ui->email_monituer->clear();
    ui->telephone_m->clear();
    ui->specialite->setCurrentIndex(0);
    ui->actif->setChecked(false);
    ui->inactif->setChecked(false);
    ui->experience_m->clear();
    ui->nom_m->setFocus();
}

// ✅ Supprimer avec double clic sélectionné
bool GereMoniteur::supprimerMoniteur(Ui::MainWindow* ui, Moniteur& m, bool& isEditing, QString& currentMoniteurcin)
{
    QWidget* parent = ui->nom_m->parentWidget();

    // 🔹 Récupérer le CIN_M à partir de la ligne sélectionnée du tableau
    QModelIndex index = ui->tab_mon->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(parent, "Sélection requise", "Veuillez sélectionner un moniteur à supprimer !");
        return false;
    }

    int row = index.row();

    QString cin_m = ui->tab_mon->item(row, 0)->text();
    QString nom = ui->tab_mon->item(row, 1)->text();
    QString prenom = ui->tab_mon->item(row, 2)->text();


    if (cin_m.isEmpty()) {
        QMessageBox::warning(parent, "Erreur", "Impossible de récupérer le id du moniteur !");
        return false;
    }


    // 🔹 On récupère directement le CIN de la table (inutile de le rechercher)
    currentMoniteurcin = cin_m;

    auto reply = QMessageBox::question(
        parent,
        "Confirmation de suppression",
        QString("Supprimer le moniteur %1 %2 (CIN : %3) ?").arg(prenom, nom, cin_m),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        bool success = m.supprimer(cin_m);  // ✅ on passe CIN_M comme QString
        if (success) {
            QMessageBox::information(parent, "Succès", "Moniteur supprimé !");
            ui->tab_mon->blockSignals(true);   // 🚫 Empêche les signaux pendant le remplissage
            m.afficher(ui->tab_mon);
            ui->tab_mon->blockSignals(false);  // ✅ Réactive les signaux

            reinitialiserFormulaireMoniteur(ui);
            isEditing = false;
            currentMoniteurcin.clear();

            return true;
        } else {
            QMessageBox::critical(parent, "Erreur", "Erreur lors de la suppression !");
        }
    }
    return false;
}


// ✅ Export PDF
void GereMoniteur::exporterPDFMoniteur(Ui::MainWindow* ui)
{
    QWidget* parent = ui->nom_m->parentWidget();

    QString fileName = QFileDialog::getSaveFileName(parent, "Exporter en PDF",
                                                    QDir::homePath() + "/liste_moniteurs.pdf",
                                                    "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QTextDocument document;
    QTextCursor cursor(&document);
    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(16);
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::darkBlue);

    cursor.insertText("Liste des Moniteurs - Smart Drive\n", titleFormat);
    cursor.insertText("Date d'exportation: " + QDate::currentDate().toString("dd/MM/yyyy") + "\n\n");

    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(4);
    tableFormat.setAlignment(Qt::AlignCenter);

    int rowCount = ui->tab_mon->rowCount();
    int colCount = ui->tab_mon->columnCount();

    QTextTable* table = cursor.insertTable(rowCount + 1, colCount, tableFormat);

    for (int c = 0; c < colCount; ++c)
        table->cellAt(0, c).firstCursorPosition().insertText(ui->tab_mon->horizontalHeaderItem(c)->text());

    for (int r = 0; r < rowCount; ++r)
        for (int c = 0; c < colCount; ++c)
            if (auto* item = ui->tab_mon->item(r, c))
                table->cellAt(r + 1, c).firstCursorPosition().insertText(item->text());

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    document.print(&printer);

    QMessageBox::information(parent, "Exportation réussie", "Fichier PDF enregistré : " + fileName);
}
bool GereMoniteur::verifierChamp(const QString &champ, const QString &valeur, QString &erreur)
{
    erreur.clear();

    if (champ == "NOM_M" || champ == "PRENOM_M") {
        QRegularExpression nomRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]{2,30}$");
        if (!nomRegex.match(valeur).hasMatch()) {
            erreur = "Le nom ou prénom doit contenir uniquement des lettres (2-30 caractères).";
            return false;
        }
    }
    else if (champ == "EMAIL_M") {
        QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        if (!emailRegex.match(valeur).hasMatch()) {
            erreur = "Veuillez entrer une adresse email valide !";
            return false;
        }
    }
    else if (champ == "TEL_M") {
        QRegularExpression telRegex("^[0-9]{8}$");
        if (!telRegex.match(valeur).hasMatch()) {
            erreur = "Le téléphone doit contenir exactement 8 chiffres.";
            return false;
        }
    }
    else if (champ == "SPECIALITE_M") {
        QString val = valeur.trimmed().toLower();
        if (val == "permis a") val = "Permis A";
        else if (val == "permis b") val = "Permis B";
        else if (val == "permis c") val = "Permis C";
        else if (val == "permis d") val = "Permis D";
        QStringList ok = {"Permis A", "Permis B", "Permis C", "Permis D"};
        if (!ok.contains(val, Qt::CaseSensitive)) {
            erreur = "La spécialité doit être : Permis A, Permis B, Permis C ou Permis D.";
            return false;
        }
    }
    else if (champ == "EXPERIENCE_M") {
        QRegularExpression expRegex("^[0-9]{1,2}$");
        if (!expRegex.match(valeur).hasMatch()) {
            erreur = "L'expérience doit être un nombre entre 0 et 50.";
            return false;
        }
        int exp = valeur.toInt();
        if (exp < 0 || exp > 50) {
            erreur = "L'expérience doit être comprise entre 0 et 50 ans.";
            return false;
        }
    }
    return true;
}

// PAR :
// ✅ CORRIGER la méthode statistiquesSpecialites
QVector<int> GereMoniteur::statistiquesSpecialites()
{
    QVector<int> stats(4, 0); // [Permis A, Permis B, Permis C, Permis D]
    QSqlQuery query;

    query.prepare("SELECT SPECIALITE_M, COUNT(*) FROM MONITEURS GROUP BY SPECIALITE_M");

    if (query.exec()) {
        while (query.next()) {
            QString specialite = query.value(0).toString().trimmed().toUpper();
            int count = query.value(1).toInt();

            qDebug() << "🔍 Spécialité trouvée:" << specialite << "Count:" << count;

            if (specialite.contains("A"))
                stats[0] += count;
            else if (specialite.contains("B"))
                stats[1] += count;
            else if (specialite.contains("C"))
                stats[2] += count;
            else if (specialite.contains("D"))
                stats[3] += count;
        }
    } else {
        qDebug() << "❌ Erreur SQL statistiques:" << query.lastError().text();
    }

    qDebug() << "📊 Stats finales - A:" << stats[0] << "B:" << stats[1] << "C:" << stats[2] << "D:" << stats[3];
    return stats;
}
// ✅ Recherche de moniteurs
void GereMoniteur::rechercherMoniteur(Ui::MainWindow* ui, const QString& text)
{
    QString search = text.trimmed().toLower();

    for (int i = 0; i < ui->tab_mon->rowCount(); ++i) {
        bool match = false;

        // Recherche dans le CIN (colonne 0)
        QTableWidgetItem *itemCin = ui->tab_mon->item(i, 0);
        if (itemCin) {
            QString cin = itemCin->text().toLower();
            if (cin.contains(search)) {
                match = true;
            }
        }

        // Recherche dans le nom (colonne 1) - optionnel
        if (!match) {
            QTableWidgetItem *itemNom = ui->tab_mon->item(i, 1);
            if (itemNom) {
                QString nom = itemNom->text().toLower();
                if (nom.contains(search)) {
                    match = true;
                }
            }
        }

        ui->tab_mon->setRowHidden(i, !match);
    }

    qDebug() << "🔍 Recherche :" << search;
}

// ✅ Filtrage des moniteurs
void GereMoniteur::filtrerMoniteurs(Ui::MainWindow* ui, const QString& typePermis)
{
    // ✅ Si "Filtrer" ou option par défaut est sélectionné, RAFRAÎCHIR depuis la base
    if (typePermis == "filtrer" || typePermis == "Tous" || typePermis.isEmpty()) {
        Moniteur m_temp;
        m_temp.afficher(ui->tab_mon); // Recharger depuis la base
        qDebug() << "✅ Filtrage désactivé - Tableau rechargé depuis la base";
        return;
    }

    // ✅ Appliquer le filtre normal
    int colPermis = 5; // colonne spécialité

    int countVisible = 0;
    for (int i = 0; i < ui->tab_mon->rowCount(); ++i) {
        QString permis = ui->tab_mon->item(i, colPermis)->text().trimmed();
        bool match = (permis == typePermis);
        ui->tab_mon->setRowHidden(i, !match);

        if (match) countVisible++;
    }

    qDebug() << "🔍 Filtrage appliqué :" << typePermis << "-" << countVisible << "moniteurs visibles";
}

// ✅ Tri des moniteurs
void GereMoniteur::trierMoniteurs(Ui::MainWindow* ui, const QString& critere)
{
    if (critere.isEmpty() || critere == "Sélectionner") {
        return;
    }

    ui->tab_mon->blockSignals(true);

    int colNom = 1;
    int colExp = 7;

    QList<QList<QString>> lignes;

    // Récupération des données
    for (int i = 0; i < ui->tab_mon->rowCount(); ++i) {
        QList<QString> row;
        for (int j = 0; j < ui->tab_mon->columnCount(); ++j) {
            QTableWidgetItem *item = ui->tab_mon->item(i, j);
            row.append(item ? item->text() : "");
        }
        lignes.append(row);
    }

    // APPLICATION DU TRI - VERSION ROBUSTE
    QString critereLower = critere.toLower().trimmed();

    // Vérifications multiples pour couvrir toutes les variations
    if (critereLower.contains("a-z") ||
        critereLower.contains("croissant") ||
        critere == "A-Z") {
        // Tri A-Z
        std::sort(lignes.begin(), lignes.end(),
                  [&](const QList<QString> &a, const QList<QString> &b){
                      return a[colNom].toLower() < b[colNom].toLower();
                  });
        qDebug() << "✅ Tri A-Z appliqué";
    }
    else if (critereLower.contains("z-a") ||
             critereLower.contains("décroissant") ||
             critere == "Z-A") {
        // Tri Z-A
        std::sort(lignes.begin(), lignes.end(),
                  [&](const QList<QString> &a, const QList<QString> &b){
                      return a[colNom].toLower() > b[colNom].toLower();
                  });
        qDebug() << "✅ Tri Z-A appliqué";
    }
    else if (critereLower.contains("expérience (+)") ||
             critereLower.contains("experience (+)") ||
             critereLower.contains("expérience croissante") ||
             critereLower.contains("exp+") ||
             critere == "Expérience (+)") {
        // Tri expérience croissante
        std::sort(lignes.begin(), lignes.end(),
                  [&](const QList<QString> &a, const QList<QString> &b){
                      auto convertirExp = [](const QString &texte) {
                          if (texte.isEmpty()) return 0;
                          QString nombreStr;
                          for (const QChar &c : texte) {
                              if (c.isDigit()) nombreStr.append(c);
                          }
                          return nombreStr.isEmpty() ? 0 : nombreStr.toInt();
                      };
                      return convertirExp(a[colExp]) < convertirExp(b[colExp]);
                  });
        qDebug() << "✅ Tri expérience croissante appliqué";
    }
    else if (critereLower.contains("expérience(-)") ||
             critereLower.contains("experience(-)") ||
             critereLower.contains("expérience décroissante") ||
             critereLower.contains("experience décroissante")) {
        // Tri expérience DÉCROISSANTE
        std::sort(lignes.begin(), lignes.end(),
                  [&](const QList<QString> &a, const QList<QString> &b){
                      auto convertirExp = [](const QString &texte) {
                          if (texte.isEmpty()) return 0;
                          QString nombreStr;
                          for (const QChar &c : texte) {
                              if (c.isDigit()) nombreStr.append(c);
                          }
                          return nombreStr.isEmpty() ? 0 : nombreStr.toInt();
                      };
                      return convertirExp(a[colExp]) > convertirExp(b[colExp]);
                  });
        qDebug() << "✅ Tri expérience DÉCROISSANTE appliqué";
    }
    else {
        qDebug() << "❌ Critère de tri non reconnu :" << critere;
        ui->tab_mon->blockSignals(false);
        return;
    }

    // Mise à jour du tableau
    ui->tab_mon->setRowCount(0);

    for (auto &row : lignes) {
        int r = ui->tab_mon->rowCount();
        ui->tab_mon->insertRow(r);

        for (int j = 0; j < row.size(); ++j) {
            ui->tab_mon->setItem(r, j, new QTableWidgetItem(row[j]));
        }
    }

    ui->tab_mon->blockSignals(false);
}

// ✅ Gestion du double-clic sur le tableau
void GereMoniteur::gererDoubleClicTableau(Ui::MainWindow* ui, const QModelIndex &index,
                                          int& derniereColonneModifiee, int& derniereLigneModifiee,
                                          QString& derniereValeurModifiee, QString& dernierCin)
{
    int col = index.column();
    int row = index.row();

    if (col == 0) {
        QMessageBox::warning(ui->tab_mon, "Erreur", "Le CIN ne peut pas être modifié !");
        return;
    }

    for (int c = 0; c < ui->tab_mon->columnCount(); ++c) {
        QTableWidgetItem *item = ui->tab_mon->item(row, c);
        if (item) {
            item->setBackground(QBrush()); // Couleur normale
            item->setForeground(QBrush()); // Couleur normale
        }
    }

    // ✅ Sauvegarder l'ancienne valeur avant modification
    QTableWidgetItem* item = ui->tab_mon->item(row, col);
    if (item) {
        derniereValeurModifiee = item->text();
    }

    derniereColonneModifiee = col;
    derniereLigneModifiee = row;

    QTableWidgetItem* cinItem = ui->tab_mon->item(row, 0);
    if (cinItem) {
        dernierCin = cinItem->text();
    }

    qDebug() << "✅ Double-clic sur cellule - Ligne:" << row << "Colonne:" << col << "Ancienne valeur:" << derniereValeurModifiee;
}

// ✅ Gestion du changement de cellule
void GereMoniteur::gererChangementCellule(Ui::MainWindow* ui, int row, int column,
                                          int& derniereColonneModifiee, int& derniereLigneModifiee,
                                          QString& derniereValeurModifiee, QString& dernierCin)
{
    // ✅ Vérifier si les signaux sont bloqués
    if (ui->tab_mon->signalsBlocked())
        return;

    // ✅ Vérifier les indices valides
    if (row < 0 || column < 0 || row >= ui->tab_mon->rowCount() || column >= ui->tab_mon->columnCount())
        return;

    QTableWidgetItem* item = ui->tab_mon->item(row, column);
    if (!item)
        return;

    // ✅ Ignorer si c'est la même valeur que la dernière sauvegardée
    QString nouvelleValeur = item->text();
    if (nouvelleValeur == derniereValeurModifiee && column == derniereColonneModifiee && row == derniereLigneModifiee) {
        return;
    }

    // ✅ Vérifier si c'est une modification légitime (après double-clic)
    if (derniereColonneModifiee == -1 || derniereLigneModifiee == -1) {
        // Ce n'est pas une modification légitime, ignorer
        return;
    }

    if (column == 0) {
        QMessageBox::warning(ui->tab_mon, "Erreur", "Le CIN ne peut pas être modifié !");
        ui->tab_mon->blockSignals(true);

        // Restaurer l'ancienne valeur
        if (!dernierCin.isEmpty()) {
            item->setText(dernierCin);
        }

        ui->tab_mon->blockSignals(false);
        return;
    }

    // ✅ Nouveau contrôle centralisé
    QString champ;
    switch (column) {
    case 1: champ = "NOM_M"; break;
    case 2: champ = "PRENOM_M"; break;
    case 3: champ = "EMAIL_M"; break;
    case 4: champ = "TEL_M"; break;
    case 5: champ = "SPECIALITE_M"; break;
    case 6: champ = "DISPO_M"; break;
    case 7: champ = "EXPERIENCE_M"; break;
    default:
        // Pour les autres colonnes, ne rien faire
        return;
    }

    QString erreur;
    QString valeur = item->text();

    if (!GereMoniteur::verifierChamp(champ, valeur, erreur)) {
        QMessageBox::warning(ui->tab_mon, "Erreur de saisie", erreur);
        ui->tab_mon->blockSignals(true);
        item->setText(derniereValeurModifiee); // Restaurer l'ancienne valeur
        ui->tab_mon->blockSignals(false);
        return;
    }

    // Sauvegarder le CIN
    QTableWidgetItem* cinItem = ui->tab_mon->item(row, 0);
    if (cinItem) {
        dernierCin = cinItem->text();
    }
}

// ✅ Modification directe d'un moniteur
bool GereMoniteur::modifierMoniteurDirect(Ui::MainWindow* ui,
                                          int derniereColonneModifiee, int derniereLigneModifiee,
                                          QString dernierCin, QString derniereValeurModifiee)
{
    if (derniereColonneModifiee == -1 || derniereLigneModifiee == -1) {
        QMessageBox::information(ui->tab_mon, "Info", "Double-cliquez d'abord sur une cellule à modifier !");
        return false;
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
        QMessageBox::warning(ui->tab_mon, "Erreur", "Cette colonne ne peut pas être modifiée directement.");
        return false;
    }

    QString erreur;
    if (!GereMoniteur::verifierChamp(champ, nouvelleValeur, erreur)) {
        QMessageBox::warning(ui->tab_mon, "Erreur de saisie", erreur);
        return false;
    }

    Moniteur m;
    bool success = false;

    // ✅ GESTION AUTOMATIQUE DE LA DATE D'INACTIVITÉ
    if (champ == "DISPO_M") {
        QSqlQuery query;

        if (nouvelleValeur.toLower() == "actif") {
            // ✅ Actif → vider la date d'inactivité
            query.prepare("UPDATE MONITEURS SET DISPO_M = :dispo, DATE_INACTIVITE = NULL WHERE CIN_M = :cin");
            query.bindValue(":dispo", "actif");
            query.bindValue(":cin", dernierCin);
        } else if (nouvelleValeur.toLower() == "inactif") {
            // ✅ Inactif → mettre la date actuelle
            query.prepare("UPDATE MONITEURS SET DISPO_M = :dispo, DATE_INACTIVITE = :date_inactivite WHERE CIN_M = :cin");
            query.bindValue(":dispo", "inactif");
            query.bindValue(":date_inactivite", QDate::currentDate());
            query.bindValue(":cin", dernierCin);
        } else {
            // Autre valeur → modification normale
            query.prepare("UPDATE MONITEURS SET DISPO_M = :dispo WHERE CIN_M = :cin");
            query.bindValue(":dispo", nouvelleValeur);
            query.bindValue(":cin", dernierCin);
        }

        success = query.exec();

        if (success) {
            // ✅ Mettre à jour l'affichage immédiatement
            QTableWidgetItem *itemDate = ui->tab_mon->item(derniereLigneModifiee, 9);
            if (itemDate) {
                if (nouvelleValeur.toLower() == "actif") {
                    itemDate->setText("");
                } else if (nouvelleValeur.toLower() == "inactif") {
                    itemDate->setText(QDate::currentDate().toString("dd/MM/yyyy"));
                }
            }
        }
    } else {
        // Modification normale pour les autres champs
        success = m.modifier(dernierCin, champ, nouvelleValeur);
    }

    if (success) {
        QMessageBox::information(ui->tab_mon, "Succès", "Modification enregistrée avec succès !");
        return true;
    } else {
        QMessageBox::critical(ui->tab_mon, "Erreur", "Échec de la mise à jour dans la base de données !");
        qDebug() << "Erreur SQL:" << QSqlDatabase::database().lastError().text();
        return false;
    }
}
// ✅ Configuration du graphique des spécialités
void GereMoniteur::configurerGraphique(Ui::MainWindow* ui, QChart*& m_chart, QChartView*& m_chartView)
{
    // ✅ DÉTRUIRE l'ancien graphique si il existe
    if (m_chartView) {
        delete m_chartView;
        m_chartView = nullptr;
    }
    if (m_chart) {
        delete m_chart;
        m_chart = nullptr;
    }

    // ✅ CRÉER le nouveau graphique
    m_chart = new QChart();
    m_chart->setTitle("Répartition des Moniteurs par Permis");
    m_chart->setTitleFont(QFont("Arial", 12, QFont::Bold));
    m_chart->setAnimationOptions(QChart::AllAnimations);
    m_chart->setTheme(QChart::ChartThemeBlueIcy);

    // ✅ CRÉER la vue du graphique
    m_chartView = new QChartView(m_chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setMinimumSize(600, 400);

    // ✅ VIDER et AJOUTER au layout
    QLayout *layout = ui->statmon->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->statmon);
        ui->statmon->setLayout(layout);
    }

    layout->addWidget(m_chartView);
    layout->setContentsMargins(0, 0, 0, 0);

    qDebug() << "✅ Graphique configuré dans statmon";
}

// ✅ Affichage des statistiques des spécialités
void GereMoniteur::afficherStatistiquesChart(Ui::MainWindow* ui, QChart* m_chart)
{
    if (!m_chart) {
        qDebug() << "❌ Graphique non initialisé";
        return;
    }

    qDebug() << "📊 Mise à jour du graphique...";

    QVector<int> stats = GereMoniteur::statistiquesSpecialites();
    int total = stats[0] + stats[1] + stats[2] + stats[3];

    qDebug() << "📊 Total moniteurs:" << total;

    // ✅ EFFACER les séries existantes
    m_chart->removeAllSeries();

    if (total == 0) {
        m_chart->setTitle("Aucun moniteur trouvé\nVeuillez ajouter des moniteurs");

        // ✅ Ajouter un message visuel
        QPieSeries *emptySeries = new QPieSeries();
        QPieSlice *emptySlice = emptySeries->append("Aucune donnée", 1);
        emptySlice->setColor(Qt::lightGray);
        emptySlice->setExploded(false);
        emptySlice->setLabelVisible(false);
        m_chart->addSeries(emptySeries);

        qDebug() << "📊 Aucune donnée à afficher";
        return;
    }

    // ✅ CALCULER les pourcentages
    double pourcentageA = total > 0 ? (stats[0] * 100.0) / total : 0;
    double pourcentageB = total > 0 ? (stats[1] * 100.0) / total : 0;
    double pourcentageC = total > 0 ? (stats[2] * 100.0) / total : 0;
    double pourcentageD = total > 0 ? (stats[3] * 100.0) / total : 0;

    // ✅ CRÉER un graphique en camembert
    QPieSeries *series = new QPieSeries();

    // ✅ AJOUTER les segments avec vérification
    if (stats[0] > 0) {
        QPieSlice *sliceA = series->append(QString("Permis A\n%1 (%2%)").arg(stats[0]).arg(pourcentageA, 0, 'f', 1), stats[0]);
        sliceA->setColor(QColor("#E74C3C"));
        sliceA->setLabelVisible(true);
    }

    if (stats[1] > 0) {
        QPieSlice *sliceB = series->append(QString("Permis B\n%1 (%2%)").arg(stats[1]).arg(pourcentageB, 0, 'f', 1), stats[1]);
        sliceB->setColor(QColor("#FFCE56"));
        sliceB->setLabelVisible(true);
    }

    if (stats[2] > 0) {
        QPieSlice *sliceC = series->append(QString("Permis C\n%1 (%2%)").arg(stats[2]).arg(pourcentageC, 0, 'f', 1), stats[2]);
        sliceC->setColor(QColor("#27AE60"));
        sliceC->setLabelVisible(true);
    }

    if (stats[3] > 0) {
        QPieSlice *sliceD = series->append(QString("Permis D\n%1 (%2%)").arg(stats[3]).arg(pourcentageD, 0, 'f', 1), stats[3]);
        sliceD->setColor(QColor("#3498DB"));
        sliceD->setLabelVisible(true);
    }

    // ✅ CONFIGURER la série
    m_chart->addSeries(series);
    m_chart->setTitle(QString("Répartition des Moniteurs par Permis\nTotal: %1 moniteurs").arg(total));

    series->setLabelsVisible(true);
    series->setLabelsPosition(QPieSlice::LabelOutside);

    // ✅ FORMATER les labels
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelBrush(QBrush(Qt::black));
        slice->setLabelFont(QFont("Arial", 9, QFont::Bold));
    }

    qDebug() << "✅ Graphique mis à jour avec succès";
}

// ✅ Configuration de l'histogramme d'expérience
void GereMoniteur::configurerHistogrammeExperience(Ui::MainWindow* ui, QChart*& m_chartExperience, QChartView*& m_chartViewExperience)
{
    // ✅ DÉTRUIRE l'ancien graphique si il existe
    if (m_chartViewExperience) {
        delete m_chartViewExperience;
        m_chartViewExperience = nullptr;
    }
    if (m_chartExperience) {
        delete m_chartExperience;
        m_chartExperience = nullptr;
    }

    // ✅ CRÉER le nouveau graphique
    m_chartExperience = new QChart();
    m_chartExperience->setTitle("Répartition des Moniteurs par Années d'Expérience");
    m_chartExperience->setTitleFont(QFont("Arial", 12, QFont::Bold));
    m_chartExperience->setAnimationOptions(QChart::SeriesAnimations);
    m_chartExperience->setTheme(QChart::ChartThemeBlueIcy);

    // ✅ CRÉER la vue du graphique
    m_chartViewExperience = new QChartView(m_chartExperience);
    m_chartViewExperience->setRenderHint(QPainter::Antialiasing);
    m_chartViewExperience->setMinimumSize(600, 400);

    // ✅ STYLE du widget
    m_chartViewExperience->setStyleSheet("background-color: white; border: 1px solid #ddd; border-radius: 8px;");

    // ✅ VIDER et AJOUTER au layout du widget "statex"
    QLayout *layout = ui->statex->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->statex);
        ui->statex->setLayout(layout);
    }

    layout->addWidget(m_chartViewExperience);
    layout->setContentsMargins(0, 0, 0, 0);

    qDebug() << "✅ Histogramme d'expérience configuré dans statex";
}

// ✅ Affichage de l'histogramme d'expérience
void GereMoniteur::afficherHistogrammeExperience(Ui::MainWindow* ui, QChart* m_chartExperience)
{
    if (!m_chartExperience) {
        qDebug() << "❌ Graphique d'expérience non initialisé";
        return;
    }

    qDebug() << "📊 Génération de l'histogramme d'expérience...";

    // ✅ CATÉGORIES d'expérience
    QStringList categories = {"0-5 ans", "6-10 ans", "11-15 ans", "16-20 ans", "20+ ans"};
    QVector<int> counts(5, 0);

    // ✅ COMPTER les moniteurs par catégorie d'expérience
    QSqlQuery query;
    query.prepare("SELECT EXPERIENCE_M FROM MONITEURS");

    int totalMoniteurs = 0;

    if (query.exec()) {
        while (query.next()) {
            int experience = query.value(0).toInt();
            if (experience <= 5) counts[0]++;
            else if (experience <= 10) counts[1]++;
            else if (experience <= 15) counts[2]++;
            else if (experience <= 20) counts[3]++;
            else counts[4]++;
            totalMoniteurs++;
        }
    } else {
        qDebug() << "❌ Erreur SQL:" << query.lastError().text();
        return;
    }

    if (totalMoniteurs == 0) {
        m_chartExperience->setTitle("Aucun moniteur trouvé\nVeuillez ajouter des moniteurs");
        qDebug() << "📊 Aucune donnée pour l'histogramme";
        return;
    }

    // ✅ SUPPRIMER TOUS les axes existants avant de recréer
    for (QAbstractAxis* axis : m_chartExperience->axes()) {
        m_chartExperience->removeAxis(axis);
        delete axis;
    }

    // ✅ SUPPRIMER TOUTES les séries existantes
    m_chartExperience->removeAllSeries();

    // ✅ CRÉER une NOUVELLE série de barres
    QBarSeries *series = new QBarSeries();
    QBarSet *barSet = new QBarSet(""); // ✅ Label vide pour la légende

    // ✅ AJOUTER les données
    for (int count : counts) {
        *barSet << count;
    }

    // ✅ COULEUR des barres
    barSet->setColor(QColor("#27AE60")); // Vert uniforme

    series->append(barSet);

    // ✅ AJOUTER la série au chart
    m_chartExperience->addSeries(series);

    // ✅ CONFIGURER l'axe X - CATÉGORIES
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Années d'expérience");
    axisX->setTitleFont(QFont("Arial", 10, QFont::Bold));
    axisX->setLabelsFont(QFont("Arial", 9));
    m_chartExperience->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // ✅ CONFIGURER l'axe Y - VALEURS
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de moniteurs");
    axisY->setTitleFont(QFont("Arial", 10, QFont::Bold));
    axisY->setLabelFormat("%d");
    axisY->setLabelsFont(QFont("Arial", 9));

    // ✅ Ajuster la plage de l'axe Y
    int maxCount = *std::max_element(counts.begin(), counts.end());
    axisY->setRange(0, maxCount + 1);

    m_chartExperience->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // ✅ TITRE du graphique
    m_chartExperience->setTitle(QString("Répartition par Années d'Expérience - Total: %1 moniteurs").arg(totalMoniteurs));
    m_chartExperience->setTitleFont(QFont("Arial", 12, QFont::Bold));

    // ✅ DÉSACTIVER la légende (inutile pour un seul jeu de données)
    m_chartExperience->legend()->setVisible(false);

    // ✅ LABELS sur les barres
    series->setLabelsVisible(true);
    series->setLabelsFormat("@value");
    series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);

    // ✅ ANIMATIONS
    m_chartExperience->setAnimationOptions(QChart::SeriesAnimations);

    qDebug() << "✅ Histogramme d'expérience généré avec succès";
    qDebug() << "📊 Données - 0-5 ans:" << counts[0]
             << "| 6-10 ans:" << counts[1]
             << "| 11-15 ans:" << counts[2]
             << "| 16-20 ans:" << counts[3]
             << "| 20+ ans:" << counts[4];
}

// ✅ Démarrer le clignotement
void GereMoniteur::demarrerClignotement(Ui::MainWindow* ui, QTimer* timerClignotement, bool& clignotementEtat)
{
    if (timerClignotement) {
        // ✅ Forcer un premier état rouge
        clignotementEtat = true;
        GereMoniteur::mettreAJourClignotement(ui, timerClignotement, clignotementEtat, -1, -1);

        // Puis démarrer le timer
        timerClignotement->start(600); // 600ms pour un clignotement plus visible
        qDebug() << "▶️ Clignotement démarré - Intervalle: 600ms";
    }
}

// ✅ Arrêter le clignotement
void GereMoniteur::arreterClignotement(Ui::MainWindow* ui, QTimer* timerClignotement)
{
    timerClignotement->stop();

    // Remettre toutes les cellules en état normal
    for (int row = 0; row < ui->tab_mon->rowCount(); ++row) {
        for (int col = 0; col < ui->tab_mon->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tab_mon->item(row, col);
            if (item) {
                item->setBackground(QBrush()); // Couleur par défaut
                item->setForeground(QBrush()); // Couleur par défaut
            }
        }
    }
}

// ✅ Mettre à jour l'état du clignotement
void GereMoniteur::mettreAJourClignotement(Ui::MainWindow* ui, QTimer* timerClignotement, bool& clignotementEtat,
                                           int derniereColonneModifiee, int derniereLigneModifiee)
{
    if (!timerClignotement || !timerClignotement->isActive()) {
        return;
    }

    // ✅ NE PAS clignoter pendant la modification
    if (derniereColonneModifiee != -1 && derniereLigneModifiee != -1) {
        return;
    }

    clignotementEtat = !clignotementEtat;
    QDate aujourdhui = QDate::currentDate();

    qDebug() << "🔄 Mise à jour clignotement - État:" << clignotementEtat;

    ui->tab_mon->blockSignals(true);

    for (int row = 0; row < ui->tab_mon->rowCount(); ++row) {
        QTableWidgetItem *itemDate = ui->tab_mon->item(row, 9);

        bool doitClignoter = false;
        if (itemDate && !itemDate->text().isEmpty()) {
            QDate dateInactivite = QDate::fromString(itemDate->text().trimmed(), "dd/MM/yyyy");
            if (dateInactivite.isValid() && dateInactivite <= aujourdhui) {
                doitClignoter = true;
            }
        }

        for (int col = 0; col < ui->tab_mon->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tab_mon->item(row, col);
            if (!item) {
                item = new QTableWidgetItem();
                ui->tab_mon->setItem(row, col, item);
            }

            if (doitClignoter) {
                if (clignotementEtat) {
                    // ✅ ROUGE VIF
                    item->setBackground(QBrush(QColor(255, 0, 0)));
                    item->setForeground(QBrush(QColor(255, 255, 255)));
                } else {
                    // ✅ ROUGE CLAIR
                    item->setBackground(QBrush(QColor(255, 200, 200)));
                    item->setForeground(QBrush(QColor(0, 0, 0)));
                }
            } else {
                // ✅ Réinitialiser aux couleurs par défaut
                item->setBackground(QBrush());
                item->setForeground(QBrush());
            }
        }
    }

    ui->tab_mon->blockSignals(false);

    // ✅ FORCER le rafraîchissement
    ui->tab_mon->viewport()->update();
}

// ✅ Recharger le tableau des moniteurs
void GereMoniteur::rechargerTableauMoniteurs(Ui::MainWindow* ui,
                                             int& derniereColonneModifiee, int& derniereLigneModifiee,
                                             QString& derniereValeurModifiee, QString& dernierCin)
{
    // ✅ Méthode sécurisée pour recharger le tableau
    ui->tab_mon->blockSignals(true);

    Moniteur m_temp;
    m_temp.afficher(ui->tab_mon);

    // ✅ Réinitialiser les variables de modification
    derniereColonneModifiee = -1;
    derniereLigneModifiee = -1;
    derniereValeurModifiee.clear();
    dernierCin = "";

    ui->tab_mon->blockSignals(false);

    qDebug() << "✅ Tableau moniteurs rechargé sécuritairement";
}
