#ifndef STATISTICS_H
#define STATISTICS_H

#include <QObject>
#include <QMap>
#include <QVector>
#include <QDate>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QSet>

class Statistics : public QObject
{
    Q_OBJECT

public:
    explicit Statistics(QObject *parent = nullptr);

    // Méthodes principales
    int getTotalSeances();
    double getHeuresTotales();
    QMap<QString, int> getSeancesParType();
    QMap<QString, int> getSeancesParMois();
    QMap<QString, int> getSeancesParMoniteur();
    QVector<QPair<QString, int>> getTopMoniteurs(int limit = 5);
    double getMoyenneHeuresParSeance();
    int getSeancesCeMois();
    int getSeancesCetteSemaine();

    // Tableau statistiques PAR TYPE
    QSqlQueryModel* getTableauStatsParType();

    // Méthodes de calcul
    double calculerDureeSeance(const QString& debut, const QString& fin);

private:
    double convertirHeuresEnDecimal(const QString& heure);
    QSqlQueryModel* getTableauStatsParTypeFallback();
    void calculerEtMettreAJourHeuresTotales(QSqlQueryModel* model);
};

#endif // STATISTICS_H
