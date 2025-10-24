#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QTableWidgetItem>

class Vehicule
{
private:
    QString matricule;
    QString type;
    QString marque;
    QString modele;
    QString annee;
    QString etat;
    int kilometrage;
    QDate date_maintenance;

public:
    Vehicule();
    Vehicule(QString matricule, QString type, QString marque, QString modele,
             QString annee, QString etat, int kilometrage, QDate date_maintenance);
    QString getMatricule() { return matricule; }
    QString getType() { return type; }
    QString getMarque() { return marque; }
    QString getModele() { return modele; }
    QString getAnnee() { return annee; }
    QString getEtat() { return etat; }
    int getKilometrage() { return kilometrage; }
    QDate getDateMaintenance() { return date_maintenance; }

    void setMatricule(QString m) { matricule = m; }
    void setType(QString t) { type = t; }
    void setMarque(QString m) { marque = m; }
    void setModele(QString m) { modele = m; }
    void setAnnee(QString a) { annee = a; }
    void setEtat(QString e) { etat = e; }
    void setKilometrage(int k) { kilometrage = k; }
    void setDateMaintenance(QDate d) { date_maintenance = d; }

    bool ajouter();
    void afficher(QTableWidget* table);
    bool modifier(QString ancienMatricule, QString nouveauMatricule, QString type, QString marque, QString modele,
                  QString annee, QString etat, int kilometrage, QDate date_maintenance);
    bool supprimer(QString matricule);
};

#endif // VEHICULE_H
