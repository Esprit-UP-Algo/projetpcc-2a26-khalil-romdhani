#ifndef GERECANDIDAT_H
#define GERECANDIDAT_H

#include <QString>
#include <QDate>
#include <QVariantMap>
#include <QWidget> // AJOUT
#include <QSqlQuery> // AJOUT
#include "mainwindow.h"
#include "ImageVer_C.h"

namespace Ui {
class MainWindow;
}

class Candidat;
class JournalCandidat;

class GereCandidat
{
public:
    struct ResultatOperation {
        bool succes;
        QString message;
        QString detailsTechniques;
        int typeErreur;

        ResultatOperation(bool s = false, const QString& msg = "",
                          const QString& details = "", int type = AUCUNE_ERREUR)
            : succes(s), message(msg), detailsTechniques(details), typeErreur(type) {}
    };

    enum TypeErreur {
        AUCUNE_ERREUR,
        ERREUR_BDD,
        ERREUR_VALIDATION,
        ERREUR_FICHIER,
        ERREUR_DOUBLON,
        ERREUR_IMAGE
    };

    // Opérations principales
    static bool ajouterCandidat(Ui::MainWindow* ui, ImageVer_C* imageVerif, bool& isEditing);
    static bool modifierCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId, ImageVer_C* imageVerif);
    static bool supprimerCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId, ImageVer_C* imageVerif);
    static void chargerCandidatPourModification(Ui::MainWindow* ui, const QModelIndex &index, bool& isEditing, int& currentId, ImageVer_C* imageVerif);

    // Recherche et filtrage
    static void exporterExcel(Ui::MainWindow* ui);
    static void filtreC(Ui::MainWindow* ui, const QString &filterText);
    static void trierC(Ui::MainWindow* ui, const QString &sortText);
    static void rechC(Ui::MainWindow* ui, const QString &searchText);

    // Progression
    static void rechercherProgression(Ui::MainWindow* ui, const QString &idText);

    // Journal
    static void viderJournal(JournalCandidat* journal, QWidget* parent);
    static void voirJournalComplet(JournalCandidat* journal, QWidget* parent);

    // Configuration
    static void setJournal(JournalCandidat *journal);

    // Validation
    static ResultatOperation validerDonneesCandidat(const QVariantMap& donnees, int ancienId = 0);
    static ResultatOperation validerImage(const QString& cheminImage);
    static QVariantMap extraireDonneesFormulaire(Ui::MainWindow* ui);
    static QString formaterMessageErreur(int type, const QString& details); // AJOUT
    static bool verifierCandidat(Ui::MainWindow* ui); // AJOUT

    // Méthodes helpers
    static int getValeurProgression(const QString &progression); // AJOUT
    static QString getTexteProgression(const QString &progression); // AJOUT

private:
    static JournalCandidat *m_journal;
    static void setupProgressBar(Ui::MainWindow* ui);
    static void updateProgressBarColor(Ui::MainWindow* ui, int valeur);
};

#endif
