//GEREMONITEUR_H
#ifndef GEREMONITEUR_H
#define GEREMONITEUR_H

#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QRegularExpression>
#include <QModelIndex>

namespace Ui {
class MainWindow;
}

class Moniteur;

class GereMoniteur
{
public:
    static bool verifierMoniteur(Ui::MainWindow* ui,
                                 const QString& nom,
                                 const QString& prenom,
                                 const QString& email,
                                 const QString& disponibilite,
                                 const QString& telephone,
                                 const QString& specialite,
                                 const QString& experience);

    static bool confirmerMoniteur(Ui::MainWindow* ui, Moniteur& m, bool& isEditing, QString& currentMoniteurcin);
    static void chargerMoniteurPourModification(Ui::MainWindow* ui, const QModelIndex& index, bool& isEditing, QString& currentMoniteurcin);
    static void reinitialiserFormulaireMoniteur(Ui::MainWindow* ui);
    static bool supprimerMoniteur(Ui::MainWindow* ui, Moniteur& m, bool& isEditing, QString& currentMoniteurcin);
    static void exporterPDFMoniteur(Ui::MainWindow* ui);
    static bool verifierChamp(const QString &champ, const QString &valeur, QString &erreur);

};

#endif // GEREMONITEUR_H
