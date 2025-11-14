#include "gereseance.h"
#include "ui_mainwindow.h"
#include "seance.h"
#include <QDebug>
#include <QMessageBox>
#include <QTableWidget>
#include <QTime>
#include <QDoubleValidator>

bool GereSeance::verifierSeance(Ui::MainWindow* ui,
                                int id,
                                const QString& type,
                                const QDate& date,
                                const QString& heureDebut,
                                const QString& heureFin)
{


    if (ui->ID_s->text().trimmed().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Champ obligatoire");
        msgBox.setText("L'ID est obligatoire !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->ID_s->setFocus();
        ui->ID_s->selectAll();
        return false;
    }

    if (id <= 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("ID invalide");
        msgBox.setText("L'ID doit être un nombre positif!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->ID_s->setFocus();
        ui->ID_s->selectAll();
        return false;
    }


    if (type == "Choisir" || type.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Type manquant");
        msgBox.setText("Veuillez choisir un type de séance !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->type_s->setFocus();
        return false;
    }


    if (!date.isValid()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Date invalide");
        msgBox.setText("La date est invalide!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->date_s->setFocus();
        return false;
    }


    if (heureDebut.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Heure manquante");
        msgBox.setText("L'heure de début est obligatoire!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->deb_s->setFocus();
        return false;
    }


    if (heureFin.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Heure manquante");
        msgBox.setText("L'heure de fin est obligatoire!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->fin_s->setFocus();
        return false;
    }


    QTime debut = QTime::fromString(heureDebut, "hh:mm AP");
    QTime fin = QTime::fromString(heureFin, "hh:mm AP");

    if (debut.isValid() && fin.isValid() && fin <= debut) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Heures incohérentes");
        msgBox.setText("L'heure de fin doit être après l'heure de début!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->fin_s->setFocus();
        return false;
    }

    return true;
}

bool GereSeance::validerLongueursChamps(Ui::MainWindow* ui, const QString& salle)
{

    if (salle.length() > 10) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Salle trop longue");
        msgBox.setText(QString("Le nom de la salle ne peut pas dépasser 10 caractères !\n"
                               "Valeur actuelle: \"%1\" (%2 caractères)\n\n"
                               "Veuillez utiliser un nom plus court.").arg(salle).arg(salle.length()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->salle_s->setFocus();
        ui->salle_s->selectAll();
        return false;
    }

    return true;
}

bool GereSeance::confirmerSeance(Ui::MainWindow* ui, Seance& s, bool& isEditing, int& currentId)
{

    QString idText = ui->ID_s->text().trimmed();
    QString type = ui->type_s->currentText();
    QDate date = ui->date_s->date();
    QString heureDebut = ui->deb_s->time().toString("hh:mm AP");
    QString heureFin = ui->fin_s->time().toString("hh:mm AP");
    QString salle = ui->salle_s->text().trimmed();
    QString longitude = ui->lon_dep->text().trimmed();
    QString circuit_dep_latitude = ui->lat_ar->text().trimmed();
    QString circuit_arrive_longitude = ui->lon_ariv->text().trimmed();
    QString circuit_arrive_latitude = ui->lat_arriv->text().trimmed();

    int id = 0;
    if (!idText.isEmpty()) {
        id = idText.toInt();
    }

    // Vérification supplémentaire : empêcher la modification d'ID en mode édition
    if (isEditing) {
        QString newIdText = ui->ID_s->text().trimmed();
        int newId = newIdText.toInt();

        if (newId != currentId) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Modification interdite");
            msgBox.setText("La modification de l'ID n'est pas autorisée car il est unique !\nL'ID original a été restauré.");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
            msgBox.exec();

            // Restaurer l'ID original
            ui->ID_s->setText(QString::number(currentId));
            ui->ID_s->setFocus();
            ui->ID_s->selectAll();
            return false;
        }
    }

    // VALEURS PAR DÉFAUT SEULEMENT SI VIDE
    if (salle.isEmpty()) salle = "Salle Principale";
    if (longitude.isEmpty()) longitude = "10.1650";
    if (circuit_dep_latitude.isEmpty()) circuit_dep_latitude = "36.8065";
    if (circuit_arrive_longitude.isEmpty()) circuit_arrive_longitude = "10.1750";
    if (circuit_arrive_latitude.isEmpty()) circuit_arrive_latitude = "36.8165";

    QString circuit_dep = "Point départ"; // Réduit pour respecter la limite
    int id_moniteur = 1;



    if (idText.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Champ obligatoire");
        msgBox.setText("L'ID est obligatoire !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->ID_s->setFocus();
        ui->ID_s->selectAll();
        return false;
    }

    if (id <= 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("ID invalide");
        msgBox.setText("L'ID doit être un nombre positif!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->ID_s->setFocus();
        ui->ID_s->selectAll();
        return false;
    }


    if (type == "Choisir" || type.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Type manquant");
        msgBox.setText("Veuillez choisir un type de séance !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->type_s->setFocus();
        return false;
    }


    if (!date.isValid()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Date invalide");
        msgBox.setText("La date est invalide!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->date_s->setFocus();
        return false;
    }


    if (heureDebut.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Heure manquante");
        msgBox.setText("L'heure de début est obligatoire!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->deb_s->setFocus();
        return false;
    }


    if (heureFin.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Heure manquante");
        msgBox.setText("L'heure de fin est obligatoire!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->fin_s->setFocus();
        return false;
    }


    QTime debut = QTime::fromString(heureDebut, "hh:mm AP");
    QTime fin = QTime::fromString(heureFin, "hh:mm AP");

    if (debut.isValid() && fin.isValid() && fin <= debut) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Heures incohérentes");
        msgBox.setText("L'heure de fin doit être après l'heure de début!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->fin_s->setFocus();
        return false;
    }



    if (salle.length() > 10) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Salle trop longue");
        msgBox.setText(QString("Le nom de la salle ne peut pas dépasser 10 caractères !\n"
                               "Valeur actuelle: \"%1\" (%2 caractères)\n\n"
                               "Veuillez utiliser un nom plus court.").arg(salle).arg(salle.length()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->salle_s->setFocus();
        ui->salle_s->selectAll();
        return false;
    }


    if (ui->lon_dep->text().trimmed().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Champ obligatoire");
        msgBox.setText("La longitude départ est obligatoire !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lon_dep->setFocus();
        ui->lon_dep->selectAll();
        return false;
    }

    bool okLongitude;
    double lonDep = ui->lon_dep->text().toDouble(&okLongitude);
    if (!okLongitude) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Longitude invalide");
        msgBox.setText("La longitude départ doit être un nombre valide !\nExemple: 10.1650");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lon_dep->setFocus();
        ui->lon_dep->selectAll();
        return false;
    }


    if (ui->lat_ar->text().trimmed().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Champ obligatoire");
        msgBox.setText("La latitude départ est obligatoire !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lat_ar->setFocus();
        ui->lat_ar->selectAll();
        return false;
    }

    bool okLatitudeDep;
    double latDep = ui->lat_ar->text().toDouble(&okLatitudeDep);
    if (!okLatitudeDep) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Latitude invalide");
        msgBox.setText("La latitude départ doit être un nombre valide !\nExemple: 36.8065");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lat_ar->setFocus();
        ui->lat_ar->selectAll();
        return false;
    }


    if (ui->lon_ariv->text().trimmed().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Champ obligatoire");
        msgBox.setText("La longitude arrivée est obligatoire !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lon_ariv->setFocus();
        ui->lon_ariv->selectAll();
        return false;
    }

    bool okLongitudeArr;
    double lonArr = ui->lon_ariv->text().toDouble(&okLongitudeArr);
    if (!okLongitudeArr) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Longitude invalide");
        msgBox.setText("La longitude arrivée doit être un nombre valide !\nExemple: 10.1750");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lon_ariv->setFocus();
        ui->lon_ariv->selectAll();
        return false;
    }


    if (ui->lat_arriv->text().trimmed().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Champ obligatoire");
        msgBox.setText("La latitude arrivée est obligatoire !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lat_arriv->setFocus();
        ui->lat_arriv->selectAll();
        return false;
    }

    bool okLatitudeArr;
    double latArr = ui->lat_arriv->text().toDouble(&okLatitudeArr);
    if (!okLatitudeArr) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Latitude invalide");
        msgBox.setText("La latitude arrivée doit être un nombre valide !\nExemple: 36.8165");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lat_arriv->setFocus();
        ui->lat_arriv->selectAll();
        return false;
    }


    if (lonDep < -180 || lonDep > 180) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Longitude invalide");
        msgBox.setText("La longitude départ doit être entre -180 et 180 !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lon_dep->setFocus();
        ui->lon_dep->selectAll();
        return false;
    }

    if (latDep < -90 || latDep > 90) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Latitude invalide");
        msgBox.setText("La latitude départ doit être entre -90 et 90 !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lat_ar->setFocus();
        ui->lat_ar->selectAll();
        return false;
    }

    if (lonArr < -180 || lonArr > 180) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Longitude invalide");
        msgBox.setText("La longitude arrivée doit être entre -180 et 180 !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lon_ariv->setFocus();
        ui->lon_ariv->selectAll();
        return false;
    }

    if (latArr < -90 || latArr > 90) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Latitude invalide");
        msgBox.setText("La latitude arrivée doit être entre -90 et 90 !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        ui->lat_arriv->setFocus();
        ui->lat_arriv->selectAll();
        return false;
    }


    qDebug() << "📋 Données à envoyer:";
    qDebug() << "  ID:" << id;
    qDebug() << "  Type:" << type;
    qDebug() << "  Date:" << date.toString("dd/MM/yyyy");
    qDebug() << "  Heure début:" << heureDebut;
    qDebug() << "  Heure fin:" << heureFin;
    qDebug() << "  Salle:" << salle << "(" << salle.length() << "caractères)";
    qDebug() << "  Circuit départ:" << circuit_dep << "(" << circuit_dep.length() << "caractères)";
    qDebug() << "  Longitude départ:" << longitude << "(" << lonDep << ")";
    qDebug() << "  Latitude départ:" << circuit_dep_latitude << "(" << latDep << ")";
    qDebug() << "  Longitude arrivée:" << circuit_arrive_longitude << "(" << lonArr << ")";
    qDebug() << "  Latitude arrivée:" << circuit_arrive_latitude << "(" << latArr << ")";

    bool success = false;
    QString message;
    QString titre;

    Seance tempSeance(id, type, date, heureDebut, heureFin,
                      salle, circuit_dep, longitude,
                      circuit_dep_latitude, circuit_arrive_longitude,
                      circuit_arrive_latitude, id_moniteur);

    if (isEditing) {
        qDebug() << "✏️ Modification de la séance ID:" << currentId;
        success = tempSeance.modifier(currentId);
        titre = "Modification";
        message = success ? "Séance modifiée avec succès!" : "Erreur lors de la modification!";
    } else {
        qDebug() << "➕ Ajout d'une nouvelle séance";
        success = tempSeance.ajouter();
        titre = "Ajout";
        message = success ? "Séance ajoutée avec succès!" : "Erreur lors de l'ajout! Vérifiez l'ID.";
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle(titre);
    msgBox.setText(message);

    if (success) {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();

        s = tempSeance;
        reinitialiserFormulaire(ui);
        isEditing = false;
        currentId = -1;
        return true;
    } else {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        return false;
    }
}

void GereSeance::chargerSeancePourModification(Ui::MainWindow* ui, const QModelIndex& index, bool& isEditing, int& currentId)
{
    int row = index.row();

    if (row < 0 || row >= ui->tab_s->rowCount()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Ligne invalide sélectionnée!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        return;
    }

    QString idStr = ui->tab_s->item(row, 0)->text();
    QString type = ui->tab_s->item(row, 1)->text();
    QString dateStr = ui->tab_s->item(row, 2)->text();
    QString heureDebut = ui->tab_s->item(row, 3)->text();
    QString heureFin = ui->tab_s->item(row, 4)->text();
    QString salle = ui->tab_s->item(row, 5)->text();

    QString longitude = ui->tab_s->item(row, 7)->text();
    QString latitude_dep = ui->tab_s->item(row, 8)->text();
    QString longitude_arr = ui->tab_s->item(row, 9)->text();
    QString latitude_arr = ui->tab_s->item(row, 10)->text();

    currentId = idStr.toInt();
    isEditing = true;

    // Rendre le champ ID en lecture seule et désactivé visuellement
    ui->ID_s->setText(idStr);
    ui->ID_s->setReadOnly(true);
    ui->ID_s->setStyleSheet("background-color: #f0f0f0; color: #666; border: 1px solid #ccc;"); // Style grisé pour indiquer qu'il est désactivé

    int typeIndex = ui->type_s->findText(type);
    if (typeIndex != -1) {
        ui->type_s->setCurrentIndex(typeIndex);
    }

    QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
    if (!date.isValid()) {
        date = QDate::fromString(dateStr, "yyyy-MM-dd");
    }
    if (date.isValid()) {
        ui->date_s->setDate(date);
    }

    QTime debut = QTime::fromString(heureDebut, "hh:mm AP");
    if (!debut.isValid()) {
        debut = QTime::fromString(heureDebut, "hh:mm");
    }
    if (debut.isValid()) {
        ui->deb_s->setTime(debut);
    }

    QTime fin = QTime::fromString(heureFin, "hh:mm AP");
    if (!fin.isValid()) {
        fin = QTime::fromString(heureFin, "hh:mm");
    }
    if (fin.isValid()) {
        ui->fin_s->setTime(fin);
    }

    ui->salle_s->setText(salle);
    ui->lon_dep->setText(longitude);
    ui->lat_ar->setText(latitude_dep);
    ui->lon_ariv->setText(longitude_arr);
    ui->lat_arriv->setText(latitude_arr);

    QMessageBox msgBox;
    msgBox.setWindowTitle("Modification");
    msgBox.setText("Séance chargée pour modification!\nL'ID ne peut pas être modifié car il est unique.");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
    msgBox.exec();
}

void GereSeance::reinitialiserFormulaire(Ui::MainWindow* ui)
{
    ui->ID_s->clear();
    ui->ID_s->setReadOnly(false); // Réactiver l'édition
    ui->ID_s->setStyleSheet(""); // Réinitialiser le style
    ui->type_s->setCurrentIndex(0);
    ui->date_s->setDate(QDate::currentDate());
    ui->deb_s->setTime(QTime(8, 0));
    ui->fin_s->setTime(QTime(9, 0));

    ui->salle_s->clear();
    ui->lon_dep->clear();
    ui->lat_ar->clear();
    ui->lon_ariv->clear();
    ui->lat_arriv->clear();

    ui->ID_s->setFocus();
}

bool GereSeance::supprimerSeance(Ui::MainWindow* ui, Seance& s, bool& isEditing, int& currentId)
{
    QModelIndexList selectedIndexes = ui->tab_s->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Aucune sélection");
        msgBox.setText("Veuillez sélectionner une séance à supprimer dans le tableau!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
        msgBox.exec();
        return false;
    }

    int row = selectedIndexes.first().row();
    QString idStr = ui->tab_s->item(row, 0)->text();
    int id = idStr.toInt();
    QString type = ui->tab_s->item(row, 1)->text();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirmation de suppression");
    msgBox.setText(QString("Êtes-vous sûr de vouloir supprimer la séance :\nID: %1\nType: %2").arg(idStr).arg(type));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");

    if (msgBox.exec() == QMessageBox::Yes) {
        bool success = s.supprimer(id);

        if (success) {
            QMessageBox successBox;
            successBox.setWindowTitle("Succès");
            successBox.setText("Séance supprimée avec succès!");
            successBox.setIcon(QMessageBox::Information);
            successBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
            successBox.exec();

            if (currentId == id) {
                reinitialiserFormulaire(ui);
                isEditing = false;
                currentId = -1;
            }
            return true;
        } else {
            QMessageBox errorBox;
            errorBox.setWindowTitle("Erreur");
            errorBox.setText("Erreur lors de la suppression de la séance!");
            errorBox.setIcon(QMessageBox::Critical);
            errorBox.setStyleSheet("QLabel{color: black;} QPushButton{color: black;}");
            errorBox.exec();
            return false;
        }
    }
    return false;
}

bool GereSeance::exporterSeanceExcel(Ui::MainWindow* ui)
{
    Q_UNUSED(ui)

    Seance s;
    bool success = s.exporterExcel();


    if (success) {
        QMessageBox::information(nullptr, "Exportation Excel", "Séances exportées avec succès vers Excel !");
    }

    return success;
}
