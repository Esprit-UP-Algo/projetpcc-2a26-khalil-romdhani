#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChart>
#include <QMessageBox>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QDate>
#include <QModelIndex>
#include <QTimer>
#include <QPropertyAnimation>
#include <QScrollBar>
#include <QDebug>
#include "moniteur.h"
#include "Candidat.h"
#include "StatCandidat.h"
#include "chatbot.h"
#include "StatCandidat.h"
#include "JournalCandidat.h"
#include "ImageVer_C.h"
#include "groq_manager.h"
#include "veh_func.h"
#include "veh.h"
#include <QTextCursor>
#include "gereseance.h"
#include "GestionSeanceUI.h"
#include "employe.h"


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
    ImageVer_C* getImageVerif() const { return m_imageVerif; }


private slots:
    void on_fermer_btn_clicked();
    void on_acceuil_clicked();
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
    void on_enregistrer_c_clicked();
    void on_modifier_c_clicked();
    void on_supp_c_clicked();
    void on_expo_tab_c_clicked();
    void on_table_candidat_doubleClicked(const QModelIndex &index);
    void onFiltrerChanged(const QString &filterText);
    void onTrierChanged(const QString &sortText);
    void on_conf_rech_c_clicked();
    void on_prog_idcandidat_textChanged(const QString &text);
    void on_viderJournal_clicked();
    void on_voirJournalComplet_clicked();
    void on_refresh_s_clicked();
    void on_confirm_ajout_s_clicked();
    void on_confirm_s_clicked();
    void on_tab_s_clicked(const QModelIndex &index);
    void on_reins_s_clicked();
    void on_supp_s_clicked();
    void on_filtre_s_clicked();
    void on_tri_s_currentIndexChanged(int index);
    void on_exp_s_clicked();
    void on_calendar_s_clicked(const QDate &date);
    void on_calendar_s_selectionChanged();
    void on_mapType_s_currentIndexChanged(int index);
    void on_centerMap_s_clicked();
    void on_enregistrer_m_clicked();
    void on_reinstaller_mon_clicked();
    void on_tab_mon_doubleClicked(const QModelIndex &index);
    void on_supp_m_clicked();
    void on_expo_tab_m_clicked();
    void on_modifier_m_clicked();
    void on_tab_mon_cellChanged(int row, int column);
    void on_taper_mon_textChanged(const QString &text);
    void on_filtrer_mon_currentTextChanged(const QString &typePermis);
    void trierMoniteurs(const QString &critere);
     void rechargerTableauMoniteurs();


private:
    Ui::MainWindow *ui;
    GestionSeanceUI* m_gestionSeanceUI;
    bool isEditingMoniteur;
    QString currentMoniteurCin;
    Moniteur m;
    QString dernierCin;
    QString derniereValeurModifiee;
    int derniereColonneModifiee;
    int derniereLigneModifiee;
    ChatBot *assistant;
        QSqlDatabase db;
    int convertirExperience(const QString &texteExperience);
    QChart *m_chart;
    QChartView *m_chartView;
    QChart *m_chartExperience;
    QChartView *m_chartViewExperience;
    void configurerGraphique();
    void afficherStatistiquesChart();
    void configurerHistogrammeExperience();
    void afficherHistogrammeExperience();
    QTimer *timerClignotement;
    bool clignotementEtat;
    QVector<QPair<int, int>> cellulesAClignoter;
    void arreterClignotement();
    void mettreAJourClignotement();
    QString headerStyle;
    Candidat c;
    int currentCandidatId;
    bool isEditingCandidat;
    StatCandidat *m_statCandidat;
    JournalCandidat *m_journalCandidat;
    ImageVer_C *m_imageVerif;
    GroqManager* m_groqManager;
    veh_func* m_vehFunc;
    veh* m_veh;
    void initialiserInterface();
    void initialiserStatistiques();
    void initialiserJournal();
    void initialiserGestionImages();
    void connecterSignaux();
    void demarrerClignotement();
    Employe* m_employe;

};

#endif // MAINWINDOW_H
