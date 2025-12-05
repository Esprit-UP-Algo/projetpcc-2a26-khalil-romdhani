#ifndef GERESEANCE_H
#define GERESEANCE_H

#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QRegularExpression>
#include <QModelIndex>

namespace Ui {
class MainWindow;
}

class Seance;

class GereSeance
{
public:
    static bool verifierSeance(Ui::MainWindow* ui,
                               int id,
                               const QString& type,
                               const QDate& date,
                               const QString& heureDebut,
                               const QString& heureFin);

    static bool validerLongueursChamps(Ui::MainWindow* ui, const QString& salle);

    static bool confirmerSeance(Ui::MainWindow* ui, Seance& s, bool& isEditing, int& currentId);
    static void chargerSeancePourModification(Ui::MainWindow* ui, const QModelIndex& index, bool& isEditing, int& currentId);
    static void reinitialiserFormulaire(Ui::MainWindow* ui);
    static bool supprimerSeance(Ui::MainWindow* ui, Seance& s, bool& isEditing, int& currentId);
    static bool exporterSeanceExcel(Ui::MainWindow* ui);
    static void rechercherSeanceParType(Ui::MainWindow* ui, Seance& s, const QString& typeRecherche);
};

#endif // GERESEANCE_H
