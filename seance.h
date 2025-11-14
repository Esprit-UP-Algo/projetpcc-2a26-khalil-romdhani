#ifndef SEANCE_H
#define SEANCE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Seance
{
private:
    int id;
    QString type;
    QDate date;
    QString debut_h;
    QString fin_h;
    QString salle;
    QString circuit_dep;
    QString longitude;
    QString circuit_dep_latitude;
    QString circuit_arrive_longitude;
    QString circuit_arrive_latitude;
    int id_moniteur;

public:
    Seance();
    Seance(int id, QString type, QDate date, QString debut_h, QString fin_h,
           QString salle = "", QString circuit_dep = "", QString longitude = "",
           QString circuit_dep_latitude = "", QString circuit_arrive_longitude = "",
           QString circuit_arrive_latitude = "", int id_moniteur = 0);

    int getId() { return id; }
    QString getType() { return type; }
    QDate getDate() { return date; }
    QString getHeureDebut() { return debut_h; }
    QString getHeureFin() { return fin_h; }
    QString getSalle() { return salle; }
    QString getCircuitDep() { return circuit_dep; }
    QString getLongitude() { return longitude; }
    QString getCircuitDepLatitude() { return circuit_dep_latitude; }
    QString getCircuitArriveLongitude() { return circuit_arrive_longitude; }
    QString getCircuitArriveLatitude() { return circuit_arrive_latitude; }
    int getIdMoniteur() { return id_moniteur; }

    void setId(int i) { id = i; }
    void setType(QString t) { type = t; }
    void setDate(QDate d) { date = d; }
    void setHeureDebut(QString h) { debut_h = h; }
    void setHeureFin(QString h) { fin_h = h; }
    void setSalle(QString s) { salle = s; }
    void setCircuitDep(QString c) { circuit_dep = c; }
    void setLongitude(QString l) { longitude = l; }
    void setCircuitDepLatitude(QString l) { circuit_dep_latitude = l; }
    void setCircuitArriveLongitude(QString l) { circuit_arrive_longitude = l; }
    void setCircuitArriveLatitude(QString l) { circuit_arrive_latitude = l; }
    void setIdMoniteur(int id) { id_moniteur = id; }

    bool ajouter();
    bool modifier(int id);
    bool supprimer(int id);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString critere, QString valeur);
    QSqlQueryModel* trier(QString colonne, QString ordre);
    bool exporterExcel();
};

#endif // SEANCE_H
