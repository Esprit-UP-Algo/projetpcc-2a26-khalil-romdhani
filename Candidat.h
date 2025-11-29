#ifndef CANDIDAT_H
#define CANDIDAT_H

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
    QString photo_path;

public:
    Candidat();
    Candidat(int id_candidat, QString nom_c, QString prenom_c, QDate date_n_c,
             QString adresse_c, QString telephone_c, QString email,
             QString nv_permis, QString progression, QString photo_path = "", int id_seance = 0);

    bool ajouter();
    void afficher(QTableWidget* table);
    bool modifier(int ancienId, int nouveauId, QString nom, QString prenom, QDate date_n,
                  QString adresse, QString telephone, QString email, QString nv_permis,
                  QString progression, QString photo_path = "");
    bool supprimer(int id_candidat);

    int getId() const { return id_candidat; }
    QString getNom() const { return nom_c; }
    QString getPrenom() const { return prenom_c; }
    QString getPhotoPath() const { return photo_path; } // NOUVEAU
};

#endif
