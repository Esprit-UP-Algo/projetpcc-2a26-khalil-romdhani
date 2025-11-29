#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QModelIndex>

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
    void on_fermer_btn_clicked();
    void on_vehicule_btn_clicked();
    void on_candidat_btn_clicked();
    void on_seance_btn_clicked();
    void on_emp_btn_clicked();
    void on_moniteur_btn_clicked();
    void on_accueil_clicked();
    void on_vehicule_clicked();
    void on_candidat_clicked();
    void on_seance_clicked();
    void on_emp_clicked();
    void on_moniteur_clicked();

    void on_confirm_ajout_s_clicked();
    void on_confirm_s_clicked();
    void on_tab_s_clicked(const QModelIndex &index);
    void on_filtre_s_clicked();
    void on_tri_s_currentIndexChanged(int index);
    void on_exp_s_clicked();
    void on_supp_s_clicked();
    void on_reins_s_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
