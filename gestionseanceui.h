#ifndef GESTIONSEANCEUI_H
#define GESTIONSEANCEUI_H

#include <QObject>
#include <QDate>
#include <QMap>
#include <QSet>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include "ui_mainwindow.h"
#include "seance.h"

class GestionSeanceUI : public QObject
{
    Q_OBJECT

public:
    explicit GestionSeanceUI(Ui::MainWindow *ui, QObject *parent = nullptr);
    ~GestionSeanceUI();

    void initialiserUI();

public slots:
    // Slots pour les boutons et interactions
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

private slots:
    void mettreAJourCarte();
    void initialiserComboboxSeances();

private:
    // Méthodes privées
    void afficherSeances();
    void afficherStatistiques();
    void initialiserCercleStatistiques();
    void mettreAJourCercleStatistiques(const QMap<QString, int> &statsParType);
    void chargerSeancesCalendrier();
    void mettreEnEvidenceDatesSeances();
    void afficherSeancesPourDate(const QDate &date);
    void initialiserCarte();

    // Membres
    Ui::MainWindow *m_ui;
    Seance m_seance;
    bool m_isEditingSeance;
    int m_currentSeanceId;
    QChartView *m_statsChartView;
    QPieSeries *m_statsSeries;
    QMap<QDate, QStringList> m_seancesCalendrier;
    QSet<QDate> m_datesMarquees;
};

#endif // GESTIONSEANCEUI_H
