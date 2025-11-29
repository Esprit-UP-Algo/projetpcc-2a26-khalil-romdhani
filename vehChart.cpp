#include "vehChart.h"
#include "vehSQL.h"

vehChart::vehChart(QWidget *parent) : QWidget(parent)
{
}

QChartView* vehChart::createTypeChart()
{
    QPieSeries *series = new QPieSeries();

    int voiture = getVoitureCount();
    int moto = getMotoCount();
    int bus = getBusCount();
    int camion = getCamionCount();

    int total = voiture + moto + bus + camion;

    // Custom colors far from #0F2434 (dark blue) - using RGB values
    QColor colors[] = {
        QColor(255, 107, 107),  // Coral red
        QColor(78, 205, 196),   // Teal
        QColor(69, 183, 209),   // Light blue
        QColor(150, 206, 180)   // Sage green
    };

    int colorIndex = 0;

    if(voiture > 0) {
        QPieSlice *slice = series->append(QString("Voitures\n%1%").arg(QString::number((voiture * 100.0) / total, 'f', 1)), voiture);
        slice->setColor(colors[colorIndex++]);
        slice->setLabelColor(Qt::white);
    }
    if(moto > 0) {
        QPieSlice *slice = series->append(QString("Motos\n%1%").arg(QString::number((moto * 100.0) / total, 'f', 1)), moto);
        slice->setColor(colors[colorIndex++]);
        slice->setLabelColor(Qt::white);
    }
    if(bus > 0) {
        QPieSlice *slice = series->append(QString("Bus\n%1%").arg(QString::number((bus * 100.0) / total, 'f', 1)), bus);
        slice->setColor(colors[colorIndex++]);
        slice->setLabelColor(Qt::white);
    }
    if(camion > 0) {
        QPieSlice *slice = series->append(QString("Camions\n%1%").arg(QString::number((camion * 100.0) / total, 'f', 1)), camion);
        slice->setColor(colors[colorIndex]);
        slice->setLabelColor(Qt::white);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par Type");
    chart->setTitleBrush(QBrush(Qt::white));
    chart->setTitleFont(QFont("Arial", 10, QFont::Bold));

    // Remove background and set dark theme
    chart->setBackgroundBrush(QBrush(Qt::transparent));
    chart->setBackgroundRoundness(0);

    // Customize legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setLabelColor(Qt::white);
    chart->legend()->setBackgroundVisible(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background: transparent;");

    return chartView;
}

QChartView* vehChart::createEtatChart()
{
    QPieSeries *series = new QPieSeries();

    int bon = getBonCount();
    int entretien = getEntretienCount();
    int panne = getPanneCount();

    int total = bon + entretien + panne;

    // Custom colors far from #0F2434 (dark blue) - using RGB values
    QColor colors[] = {
        QColor(106, 255, 106),  // Bright green
        QColor(255, 255, 107),  // Yellow
        QColor(255, 140, 107)   // Orange
    };

    int colorIndex = 0;

    if(bon > 0) {
        QPieSlice *slice = series->append(QString("Bon\n%1%").arg(QString::number((bon * 100.0) / total, 'f', 1)), bon);
        slice->setColor(colors[colorIndex++]);
        slice->setLabelColor(Qt::white);
    }
    if(entretien > 0) {
        QPieSlice *slice = series->append(QString("Entretien\n%1%").arg(QString::number((entretien * 100.0) / total, 'f', 1)), entretien);
        slice->setColor(colors[colorIndex++]);
        slice->setLabelColor(Qt::white);
    }
    if(panne > 0) {
        QPieSlice *slice = series->append(QString("Panne\n%1%").arg(QString::number((panne * 100.0) / total, 'f', 1)), panne);
        slice->setColor(colors[colorIndex]);
        slice->setLabelColor(Qt::white);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par État");
    chart->setTitleBrush(QBrush(Qt::white));
    chart->setTitleFont(QFont("Arial", 10, QFont::Bold));

    // Remove background and set dark theme
    chart->setBackgroundBrush(QBrush(Qt::transparent));
    chart->setBackgroundRoundness(0);

    // Customize legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setLabelColor(Qt::white);
    chart->legend()->setBackgroundVisible(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background: transparent;");

    return chartView;
}

int vehChart::getVoitureCount()
{
    vehSQL sql;
    return sql.recVoiturenb();
}

int vehChart::getMotoCount()
{
    vehSQL sql;
    return sql.recMotonb();
}

int vehChart::getBusCount()
{
    vehSQL sql;
    return sql.recBusnb();
}

int vehChart::getCamionCount()
{
    vehSQL sql;
    return sql.recCamionnb();
}

int vehChart::getBonCount()
{
    vehSQL sql;
    return sql.recBonnb();
}

int vehChart::getEntretienCount()
{
    vehSQL sql;
    return sql.recEntrenb();
}

int vehChart::getPanneCount()
{
    vehSQL sql;
    return sql.recPannenb();
}
