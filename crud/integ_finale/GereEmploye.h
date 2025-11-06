#ifndef GEREEMPLOYE_H
#define GEREEMPLOYE_H

#include "employe.h"
#include "ui_mainwindow.h"
#include <QModelIndex>

class GereEmploye
{
public:
    static bool verifierEmploye(Ui::MainWindow* ui);
    static bool ajouterEmploye(Ui::MainWindow* ui);
    static bool modifierEmploye(Ui::MainWindow* ui, Employe &e, bool &isEditing, int &currentId);
    static bool supprimerEmploye(Ui::MainWindow* ui, Employe &e, bool &isEditing, int &currentId);
    static void chargerEmployePourModification(Ui::MainWindow* ui, const QModelIndex &index, bool &isEditing, int &currentId);
    static void exporterExcel(Ui::MainWindow* ui);
    static void reinitialiserFormulaire(Ui::MainWindow* ui);
};

#endif // GEREEMPLOYE_H
