#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "moniteur.h"
#include <QMainWindow>
#include <QDate>
#include <QModelIndex>
#include "moniteur.h"
#include "geremoniteur.h"
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Navigation boutons
    void on_fermer_btn_clicked();
    void on_vehicule_btn_clicked();
    void on_candidat_btn_clicked();
    void on_seance_btn_clicked();
    void on_emp_btn_clicked();
    void on_moniteur_btn_clicked();

    // Moniteur
    void on_enregistrer_m_clicked();
    void on_reinstaller_mon_clicked();
    void on_tab_mon_doubleClicked(const QModelIndex &index);
    void on_supp_m_clicked();
    void on_expo_tab_m_clicked();
    void on_modifier_m_clicked();
    void on_tab_mon_cellChanged(int row, int column);

    void on_enregistrer_c_clicked();
    void on_modifier_c_clicked();
    void on_table_candidat_doubleClicked(const QModelIndex &index);
    void on_supp_c_clicked();
    void on_expo_tab_c_clicked();
    void on_conf_rech_c_clicked();
    void onFiltrerChanged(const QString &filterText);
    void onTrierChanged(const QString &sortText);

private:
    Ui::MainWindow *ui;
    bool isEditingMoniteur;
    QString currentMoniteurCin;
    Moniteur m;
    QString dernierCin;
    QString derniereValeurModifiee;
    int derniereColonneModifiee;
    int derniereLigneModifiee;

    Candidat c;
    int currentCandidatId;
    bool isEditingCandidat;
};

#endif // MAINWINDOW_H
