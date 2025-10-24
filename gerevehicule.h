#ifndef GEREVEHICULE_H
#define GEREVEHICULE_H
#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QRegularExpression>
#include <QModelIndex>
namespace Ui {
class MainWindow;
}

class Vehicule;

class GereVehicule
{
public:
    static bool verifierVehicule(Ui::MainWindow* ui,
                                 const QString& matricule,
                                 const QString& type,
                                 const QString& marque,
                                 const QString& modele,
                                 const QString& annee,
                                 const QDate& date_maintenance);

    static bool confirmerVehicule(Ui::MainWindow* ui, Vehicule& v, bool& isEditing, QString& currentMatricule);
    static void chargerVehiculePourModification(Ui::MainWindow* ui, const QModelIndex& index, bool& isEditing, QString& currentMatricule);
    static void reinitialiserFormulaire(Ui::MainWindow* ui);
    static bool supprimerVehicule(Ui::MainWindow* ui, Vehicule& v, bool& isEditing, QString& currentMatricule);
    static void exporterPDF(Ui::MainWindow* ui);
};

#endif // GEREVEHICULE_H
