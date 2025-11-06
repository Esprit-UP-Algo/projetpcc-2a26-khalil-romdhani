#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QTableWidget>

// employe.h
class Employe {
public:
    Employe(); // constructeur par défaut
    Employe(int id, QString nom, QString prenom, QString tel, QDate date, QString poste, double salaire);
    bool ajouter();
    bool modifier(int ancienId, int nouveauId, QString nom, QString prenom,
                  QString telephone, QDate dateEmbauche, QString poste, double salaire);
    bool supprimer(int id);
    void afficher(QTableWidget* table);
    bool idExiste(int id);
private:
    int id_employe;
    QString nom;
    QString prenom;
    QString telephone;
    QDate date_embauche;
    QString poste;
    double salaire;
};


#endif // EMPLOYE_H
