#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "vehicule.h"
#include "Candidat.h"

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

    void on_conf_v_clicked();
    void on_reins_v_clicked();
    void on_table_ajout_v_doubleClicked(const QModelIndex &index);
    void on_supp_v_clicked();
    void on_expo_v_clicked();

    void on_enregistrer_c_clicked();
    void on_modifier_c_clicked();
    void on_table_candidat_doubleClicked(const QModelIndex &index);
    void on_supp_c_clicked();
    void on_expo_tab_c_clicked();  // ADD THIS LINE

private:
    Ui::MainWindow *ui;
    Vehicule v;
    Candidat c;
    bool verifier_vehicule(QString matricule, QString type, QString marque, QString modele, QString annee, QDate date_maintenance);
    QString currentMatricule;
    bool isEditing;
    int currentCandidatId;
    bool isEditingCandidat;
};

#endif // MAINWINDOW_H
