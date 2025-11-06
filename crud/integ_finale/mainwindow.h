#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employe.h"
#include <QMainWindow>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fermer_btn_clicked();
    void on_vehicule_btn_clicked();
    void on_candidat_btn_clicked();
    void on_seance_btn_clicked();
    void on_emp_btn_clicked();
    void on_moniteur_btn_clicked();

    void onAjouterClicked();
    void onModifierClicked();
    void onSupprimerClicked();
    void onRechercherClicked();
    void onExporterClicked();

    void on_confirmer_E_clicked();
    void on_modifier_E_clicked();
    void on_supp_E_clicked();
    void on_reinstaller_E_clicked();
    void on_tab_employes_doubleClicked(const QModelIndex &index);
    void on_expo_tab_E_clicked();

private:
    Ui::MainWindow *ui;
    Employe e;                    // objet employé
    bool isEditingEmploye = false; // vrai si on est en mode modification
    int currentIdEmploye = 0;     // ID de l’employé sélectionné pour modification/suppression
};

#endif // MAINWINDOW_H
