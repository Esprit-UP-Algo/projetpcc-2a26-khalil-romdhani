#ifndef VEHSQL_H
#define VEHSQL_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class QLineEdit;
class QComboBox;
class QRadioButton;
class QDateEdit;
class QTableWidget;

class vehSQL : public QObject
{
    Q_OBJECT

public:
    vehSQL(QObject* parent = nullptr);
    void ConfV(QLineEdit* ui_matricule, QComboBox* ui_type_v, QLineEdit* ui_marque_v,
               QLineEdit* ui_modele_v, QLineEdit* ui_kilometrage_v, QRadioButton* ui_bon,
               QRadioButton* ui_entretien, QRadioButton* ui_panne, QDateEdit* ui_date_achat_v,
               QDateEdit* ui_date_maint_v, QString& currM);

    void suppV(QString& currM);
    void modifV(QLineEdit* ui_matricule, QComboBox* ui_type_v, QLineEdit* ui_marque_v,
                QLineEdit* ui_modele_v, QLineEdit* ui_kilometrage_v, QRadioButton* ui_bon,
                QRadioButton* ui_entretien, QRadioButton* ui_panne, QDateEdit* ui_date_achat_v,
                QDateEdit* ui_date_maint_v, QString& currM);
    QString tabClick(const QModelIndex &index, QLineEdit* ui_matricule, QComboBox* ui_type_v,
                     QLineEdit* ui_marque_v, QLineEdit* ui_modele_v, QLineEdit* ui_kilometrage_v,
                     QRadioButton* ui_bon, QRadioButton* ui_entretien, QRadioButton* ui_panne,
                     QDateEdit* ui_date_achat_v, QDateEdit* ui_date_maint_v, QTableWidget* table);

    void refTab(QTableWidget* ui_table_ajout_v);
    int recBonnb();
    int recEntrenb();
    int recPannenb();
    int recVoiturenb();
    int recMotonb();
    int recBusnb();
    int recCamionnb();
    QMap<QString, QVariant> fetchVehicleForCarteGrise(const QString& matricule);
    bool chercheMat(const QString& matricule, const QString& suppMat = "");

    //---------------------teb3a seance
    QSqlQueryModel* getVehiculesDisponibles();
    QSqlQueryModel* getVehiculesDisponibles(const QDate& date, const QString& heureDebut, const QString& heureFin, int idSeanceExclue );
    //---------------------

};

#endif // VEHSQL_H
