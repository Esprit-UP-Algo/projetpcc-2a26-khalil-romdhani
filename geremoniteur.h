//GEREMONITEUR_H
#ifndef GEREMONITEUR_H
#define GEREMONITEUR_H

#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QRegularExpression>
#include <QModelIndex>
#include <QChart>
#include <QMessageBox>
#include <QChartView>
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
     static QVector<int> statistiquesSpecialites();
    static void rechercherMoniteur(Ui::MainWindow* ui, const QString& text);
    static void filtrerMoniteurs(Ui::MainWindow* ui, const QString& typePermis);
    static void trierMoniteurs(Ui::MainWindow* ui, const QString& critere);
    static void gererDoubleClicTableau(Ui::MainWindow* ui, const QModelIndex &index,
                                       int& derniereColonneModifiee, int& derniereLigneModifiee,
                                       QString& derniereValeurModifiee, QString& dernierCin);
    static void gererChangementCellule(Ui::MainWindow* ui, int row, int column,
                                       int& derniereColonneModifiee, int& derniereLigneModifiee,
                                       QString& derniereValeurModifiee, QString& dernierCin);
    static bool modifierMoniteurDirect(Ui::MainWindow* ui,
                                       int derniereColonneModifiee, int derniereLigneModifiee,
                                       QString dernierCin, QString derniereValeurModifiee);
    static void configurerGraphique(Ui::MainWindow* ui, QChart*& m_chart, QChartView*& m_chartView);
    static void afficherStatistiquesChart(Ui::MainWindow* ui, QChart* m_chart);
    static void configurerHistogrammeExperience(Ui::MainWindow* ui, QChart*& m_chartExperience, QChartView*& m_chartViewExperience);
    static void afficherHistogrammeExperience(Ui::MainWindow* ui, QChart* m_chartExperience);
    static void demarrerClignotement(Ui::MainWindow* ui, QTimer* timerClignotement, bool& clignotementEtat);
    static void arreterClignotement(Ui::MainWindow* ui, QTimer* timerClignotement);
    static void mettreAJourClignotement(Ui::MainWindow* ui, QTimer* timerClignotement, bool& clignotementEtat,
                                        int derniereColonneModifiee, int derniereLigneModifiee);
    static void rechargerTableauMoniteurs(Ui::MainWindow* ui,
                                          int& derniereColonneModifiee, int& derniereLigneModifiee,
                                          QString& derniereValeurModifiee, QString& dernierCin);
};

#endif // GEREMONITEUR_H
