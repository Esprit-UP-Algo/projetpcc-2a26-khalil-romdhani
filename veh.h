#ifndef VEH_H
#define VEH_H

#include <QMainWindow>
#include <QString>
#include <QDate>
#include <QLineEdit>
#include <QComboBox>
#include <QRadioButton>
#include <QDateEdit>
#include <QTableWidget>
#include <QProgressBar>
#include <QGroupBox>

class vehSQL;
class vehChart;

class veh : public QMainWindow
{
    Q_OBJECT

public:
    veh();
    bool verifV(const QString& matricule, const QString& type, const QString& marque,
                const QString& modele, const QString& etat, const QString& kilometrage,
                const QDate& dateAchat, const QDate& dateMaint);
    bool verifMat(const QString& matricule);
    bool verifMarq(const QString& typeV, const QString& marqueV);
    bool verifDate(const QDate& dateAchat, const QDate& dateRevision);
    bool verifKm(const QString& kilometrage);

    void initV(QLineEdit* matricule, QComboBox* type_v, QLineEdit* marque_v,
               QLineEdit* modele_v, QLineEdit* kilometrage_v, QRadioButton* bon,
               QRadioButton* entretien, QRadioButton* panne, QDateEdit* date_achat_v,
               QDateEdit* date_maint_v, QGroupBox* type_stat, QGroupBox* etat_stat);  // Updated

    void affTab(QTableWidget* table);
    void refTab();
    void initFiltrer(QComboBox* filtrer_v);
    void initTrier(QComboBox* trier_v);
    void initRech(QLineEdit* taper_v);
    void initCarteGrise(QLineEdit* matricule_carte);
    void confCarteGrise();
    void reinsCarteGrise();

public slots:
    void ConfV();
    void reinitV();
    void suppV();
    void modifV();
    void tabClick(const QModelIndex &i);
    void filtrerV();
    void trierV();
    void rechV();
    void expoV();
    void refreshCharts();

private:
    QLineEdit* ui_matricule;
    QComboBox* ui_type_v;
    QLineEdit* ui_marque_v;
    QLineEdit* ui_modele_v;
    QLineEdit* ui_kilometrage_v;
    QRadioButton* ui_bon;
    QRadioButton* ui_entretien;
    QRadioButton* ui_panne;
    QDateEdit* ui_date_achat_v;
    QDateEdit* ui_date_maint_v;
    QTableWidget* ui_table_ajout_v;
    QComboBox* ui_filtrer_v;
    QComboBox* ui_trier_v;
    QLineEdit* ui_taper_v;
    QGroupBox* ui_type_stat;  // Add this
    QGroupBox* ui_etat_stat;  // Add this
    QString currM;
    vehSQL* sqli;
    QLineEdit* ui_matricule_carte;
};

#endif
