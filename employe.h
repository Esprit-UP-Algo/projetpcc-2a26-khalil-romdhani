#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QMainWindow>
#include <QString>
#include <QDate>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QFrame>
#include <QPushButton>
#include <QMap>
#include <algorithm>
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>

class EmployeSQL;

class Employe : public QMainWindow
{
    Q_OBJECT

public:
    Employe();
    bool verifE(const QString& id, const QString& nom, const QString& prenom,
                const QString& tel, const QDate& dateEmbauche,
                const QString& poste, const QString& salaire,
                const QString& email, const QString& pass);

    bool verifId(const QString& id);
    bool verifNomPrenom(const QString& nom, const QString& prenom);
    bool verifTel(const QString& tel);
    bool verifDate(const QDate& dateEmbauche);
    bool verifPoste(const QString& poste);
    bool verifPass(const QString& pass, const QString& currentId = "");
    bool verifSalaire(const QString& salaire);
    bool verifEmail(const QString& email);
    void initE(QLineEdit* id, QLineEdit* nom, QLineEdit* prenom,
               QLineEdit* telephone, QLineEdit* salaire, QComboBox* poste,
               QLineEdit* email, QDateEdit* date_embauche, QLineEdit* pass);

    void affTab(QTableWidget* table);
    void initTab(QTableWidget *tab_employes);
    void initTrier(QComboBox* trier_e);
    void initRech(QLineEdit* taper_e);
    void afficherStatistiquesGraphique(QTabWidget *tabWidget);

public slots:

    void ConfE();
    void modifE();
    void suppE();
    void reinitE();
    void rechE();
    void rechParIdOuNom();
    void expoE();
    void tabClick(int row, int column);
    void trierE();
    void refTab();

private:
    QLineEdit* ui_id;
    QLineEdit* ui_nom;
    QLineEdit* ui_prenom;
    QLineEdit* ui_telephone;
    QLineEdit* ui_salaire;
    QComboBox* ui_poste;
    QLineEdit* ui_email;
    QDateEdit* ui_date_embauche;
    QLineEdit* ui_pass;
    QTableWidget *table; // pointeur vers le tableau affiché

    QTableWidget *ui_table_ajout_E;
    QTableWidget *ui_tab_employes;
    QComboBox* ui_trier_e;
    QLineEdit* ui_taper_e;

    QString currId;
    EmployeSQL* sqli;
};

#endif // EMPLOYE_H
