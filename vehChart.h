#ifndef VEHCHART_H
#define VEHCHART_H

#include <QWidget>
#include <QtCharts>

class vehChart : public QWidget
{
    Q_OBJECT

public:
    explicit vehChart(QWidget *parent = nullptr);
    QChartView* createTypeChart();
    QChartView* createEtatChart();

private:
    int getVoitureCount();
    int getMotoCount();
    int getBusCount();
    int getCamionCount();
    int getBonCount();
    int getEntretienCount();
    int getPanneCount();
};

#endif
