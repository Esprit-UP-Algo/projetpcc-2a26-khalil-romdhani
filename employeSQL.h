#ifndef EMPLOYESQL_H
#define EMPLOYESQL_H

#include <QObject>
#include <QLineEdit>
#include <QTableWidget>
#include <QModelIndex>

class EmployeSQL : public QObject
{
    Q_OBJECT

public:
    explicit EmployeSQL(QObject* parent = nullptr);

    // Fonctions CRUD
    void ConfE(QLineEdit* ui_id, QLineEdit* ui_nom, QLineEdit* ui_prenom,
               QLineEdit* ui_tel, QLineEdit* ui_poste, QLineEdit* ui_salaire,
               QLineEdit* ui_email, QLineEdit* ui_pass, QString& currID);

    void modifE(QLineEdit* ui_id, QLineEdit* ui_nom, QLineEdit* ui_prenom,
                QLineEdit* ui_tel, QLineEdit* ui_poste, QLineEdit* ui_salaire,
                QLineEdit* ui_email, QLineEdit* ui_pass, QString& currID);

    void suppE(QString& currID,QTableWidget* table );

    QString tabClick(const QModelIndex &index, QLineEdit* ui_id, QLineEdit* ui_nom,
                     QLineEdit* ui_prenom, QLineEdit* ui_tel, QLineEdit* ui_poste,
                     QLineEdit* ui_salaire, QLineEdit* ui_email, QLineEdit* ui_pass,
                     QTableWidget* table);



    bool chercheID(const QString& id, const QString& suppID = "");

    void rech(QTableWidget* table, const QString& nom);
    void trierTab(QTableWidget* table, const QString& critere);
    void refTab(QTableWidget* table);
};

#endif // EMPLOYESQL_H
