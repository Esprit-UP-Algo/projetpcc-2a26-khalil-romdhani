#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "seance.h"
#include "gereseance.h"

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


    void on_confirm_ajout_s_clicked();
    void on_confirm_s_clicked();  // Recherche par ID
    void on_tab_s_clicked(const QModelIndex &index);
    void on_filtre_s_clicked();
    void on_tri_s_currentIndexChanged(int index);
    void on_exp_s_clicked();
    void on_supp_s_clicked();
    void on_reins_s_clicked();


    void on_conf_v_clicked();
    void on_reins_v_clicked();
    void on_supp_v_clicked();
    void on_expo_v_clicked();
    void on_enregistrer_c_clicked();
    void on_modifier_c_clicked();
    void on_supp_c_clicked();
    void on_expo_tab_c_clicked();

private:
    Ui::MainWindow *ui;
    Seance s;
    bool isEditingSeance;
    int currentSeanceId;
    void afficherSeances();
};

#endif // MAINWINDOW_H
