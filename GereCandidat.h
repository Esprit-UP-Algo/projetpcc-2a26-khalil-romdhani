#ifndef GERECANDIDAT_H
#define GERECANDIDAT_H

#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QRegularExpression>

namespace Ui {
class MainWindow;
}

class Candidat;

class GereCandidat
{
public:

    static bool verifierCandidat(Ui::MainWindow* ui);
    static bool ajouterCandidat(Ui::MainWindow* ui);
    static bool modifierCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId);
    static void chargerCandidatPourModification(Ui::MainWindow* ui, const QModelIndex &index, bool& isEditing, int& currentId);
    static bool supprimerCandidat(Ui::MainWindow* ui, Candidat& c, bool& isEditing, int& currentId);
    static void exporterExcel(Ui::MainWindow* ui);
    static void filtreC(Ui::MainWindow* ui, const QString &filterText);
    static void trierC(Ui::MainWindow* ui, const QString &sortText);
    static void rechC(Ui::MainWindow* ui, const QString &searchText);
};

#endif
