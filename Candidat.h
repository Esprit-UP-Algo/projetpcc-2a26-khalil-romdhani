#ifndef CANDIDAT_H
#define CANDIDAT_H

#include "GereCandidat.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidget>

class Candidat
{
private:
    int id_candidat;
    QString nom_c;
    QString prenom_c;
    QDate date_n_c;
    QString adresse_c;
    QString telephone_c;
    QString email;
    QString nv_permis;
    QString progression;
    int id_seance;

public:
    Candidat();
    Candidat(int id_candidat, QString nom_c, QString prenom_c, QDate date_n_c,
             QString adresse_c, QString telephone_c, QString email,
             QString nv_permis, QString progression, int id_seance = 0);

    bool ajouter();
    void afficher(QTableWidget* table);
    bool modifier(int ancienId, int nouveauId, QString nom, QString prenom, QDate date_n,
                  QString adresse, QString telephone, QString email, QString nv_permis,
                  QString progression);
    bool supprimer(int id_candidat);
};

#endif
