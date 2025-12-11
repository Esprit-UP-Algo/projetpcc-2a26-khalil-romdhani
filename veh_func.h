#ifndef VEH_FUNC_H
#define VEH_FUNC_H

#include <QObject>
#include <QString>

class QComboBox;
class QLineEdit;
class QTableWidget;

class veh_func : public QObject
{
    Q_OBJECT

public:
    veh_func(QObject* parent = nullptr);

    void initUI(QComboBox* trier_v, QComboBox* filtrer_v, QLineEdit* taper_v, QTableWidget* table_v);
    void refTab();
    void trierV();
    void filtrerV();
    void rechercherV();
    void exporterPDF();

private:
    QComboBox* ui_trier_v;
    QComboBox* ui_filtrer_v;
    QLineEdit* ui_taper_v;
    QTableWidget* ui_table_v;
};

#endif // VEH_FUNC_H
