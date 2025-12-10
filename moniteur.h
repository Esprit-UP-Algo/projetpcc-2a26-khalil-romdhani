//MONITEUR_H
#ifndef MONITEUR_H
#define MONITEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QTableWidgetItem>

class Moniteur
{
private:
    // Généré automatiquement dans la base
    QString cin_m;
    QString nom_m;
    QString prenom_m;
    QString email_m;
    QString tel_m;
    QString dispo_m;
    QString specialite_m;
    int experience_m;
    int id_seance;

public:
    Moniteur();
    Moniteur(QString nom_m, QString prenom_m, QString email_m, QString tel_m,
             QString dispo_m, QString specialite_m, int experience_m, int id_seance);
    Moniteur(QString cin_m, QString nom_m, QString prenom_m, QString email_m, QString tel_m,
             QString dispo_m, QString specialite_m, int experience_m, int id_seance);

    // Getters
    QString getCin() const { return cin_m; }
    QString getNom() const { return nom_m; }
    QString getPrenom() const { return prenom_m; }
    QString getEmail() const { return email_m; }
    QString getTel() const { return tel_m; }
    QString getDispo() const { return dispo_m; }
    QString getSpecialite() const { return specialite_m; }
    int getExperience() const { return experience_m; }
    int getIdSeance() const { return id_seance; }

    // Setters

    void setNom(const QString &n) { nom_m = n; }
    void setPrenom(const QString &p) { prenom_m = p; }
    void setEmail(const QString &e) { email_m = e; }
    void setTel(const QString &t) { tel_m = t; }
    void setDispo(const QString &d) { dispo_m = d; }
    void setSpecialite(const QString &s) { specialite_m = s; }
    void setExperience(int e) { experience_m = e; }
    void setIdSeance(int id) { id_seance = id; }

    // Méthodes CRUD
    bool ajouter();
    void afficher(QTableWidget* table);
    bool modifier(QString cin_m, QString colonne, QVariant valeur);
    bool modifier(QString cin_m, QString nom, QString prenom, QString email,
                  QString tel, QString dispo, QString specialite, int experience, int id_seance);

    bool supprimer(QString cin_m);
};

#endif // MONITEUR_H

