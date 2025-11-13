#include "employeSQL.h"
#include "connection.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QSqlError>
#include <QLineEdit>

EmployeSQL::EmployeSQL(QObject* parent) : QObject(parent) {}

void EmployeSQL::ConfE(QLineEdit* ui_id, QLineEdit* ui_nom, QLineEdit* ui_prenom,
                       QLineEdit* ui_telephone, QLineEdit* ui_poste, QLineEdit* ui_salaire,
                       QLineEdit* ui_email, QLineEdit* ui_pass, QString& currID)
{
    QString id = ui_id->text();
    QString nom = ui_nom->text();
    QString prenom = ui_prenom->text();
    QString tel = ui_telephone->text();
    QString poste = ui_poste->text();
    QString salaire = ui_salaire->text();
    QString email = ui_email->text();
    QString pass = ui_pass->text();

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "erreur", "connexion echouee");
        return;
    }

    if(chercheID(id)) {
        QMessageBox::warning(nullptr, "erreur", "ID existe deja");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (ID_EMPLOYE, NOM_EMP, PRENOM_EMP, TEL_EMP, POSTE_EMP, SALAIRE_EMP, EMAIL_EMP, PASS_EMP) "
                  "VALUES (:id, :nom, :prenom, :tel, :poste, :salaire, :email, :pass)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire.toDouble());
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);

    if(query.exec()) {
        QMessageBox::information(nullptr, "success", "employe cree avec succes");
        currID = "";
        ui_id->clear(); ui_nom->clear(); ui_prenom->clear();
        ui_telephone->clear(); ui_poste->clear(); ui_salaire->clear();
        ui_email->clear(); ui_pass->clear();
    } else {
        QMessageBox::warning(nullptr, "erreur", "erreur insertion: " + query.lastError().text());
    }
}

void EmployeSQL::modifE(QLineEdit* ui_id, QLineEdit* ui_nom, QLineEdit* ui_prenom,
                        QLineEdit* ui_telephone, QLineEdit* ui_poste, QLineEdit* ui_salaire,
                        QLineEdit* ui_email, QLineEdit* ui_pass, QString& currID)
{
    QString id = ui_id->text();
    QString nom = ui_nom->text();
    QString prenom = ui_prenom->text();
    QString tel = ui_telephone->text();
    QString poste = ui_poste->text();
    QString salaire = ui_salaire->text();
    QString email = ui_email->text();
    QString pass = ui_pass->text();

    if(id != currID) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID ne peut pas être modifié");
        return;
    }

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) {
        QMessageBox::warning(nullptr, "Erreur", "Connexion échouée");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE EMPLOYES SET NOM_EMP=:nom, PRENOM_EMP=:prenom, TEL_EMP=:tel, POSTE_EMP=:poste, "
                  "SALAIRE_EMP=:salaire, EMAIL_EMP=:email, PASS_EMP=:pass WHERE ID_EMPLOYE=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire.toDouble());
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);

    if(!query.exec()) {
        QMessageBox::warning(nullptr, "Erreur", "Erreur modification: " + query.lastError().text());
        return;
    }

    currID = "";
}


void EmployeSQL::suppE(QString& currID, QTableWidget* table)
{
    if(currID.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Sélectionnez un employé à supprimer");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Confirmation",
                                                              "Voulez-vous supprimer " + currID + "?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Connection* conn = Connection::instance();
        if(!conn->createconnect()) {
            QMessageBox::warning(nullptr, "Erreur", "Connexion échouée");
            return;
        }

        QSqlQuery query;
        query.prepare("DELETE FROM EMPLOYES WHERE ID_EMPLOYE=:id");
        query.bindValue(":id", currID);

        if(query.exec()) {
            QMessageBox::information(nullptr, "Succès", "Employé supprimé avec succès");
            currID = "";

            // Rafraîchir le tableau
            if(table) {
                table->setRowCount(0);
                QSqlQuery selectQuery("SELECT ID_EMPLOYE, NOM_EMP, PRENOM_EMP, TEL_EMP, POSTE_EMP, SALAIRE_EMP, EMAIL_EMP, PASS_EMP FROM EMPLOYES");
                int row = 0;
                while(selectQuery.next()) {
                    table->insertRow(row);
                    for(int col = 0; col < 8; ++col)
                        table->setItem(row, col, new QTableWidgetItem(selectQuery.value(col).toString()));
                    row++;
                }
            }
        } else {
            QMessageBox::warning(nullptr, "Erreur", "Erreur suppression: " + query.lastError().text());
        }
    }
}


QString EmployeSQL::tabClick(const QModelIndex &index, QLineEdit* ui_id, QLineEdit* ui_nom, QLineEdit* ui_prenom,
                             QLineEdit* ui_telephone, QLineEdit* ui_poste, QLineEdit* ui_salaire,
                             QLineEdit* ui_email, QLineEdit* ui_pass, QTableWidget* table)
{
    if(!table) return "";

    int row = index.row();
    if(row < 0 || row >= table->rowCount()) return "";

    QString id = table->item(row, 0)->text();
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return "";

    QSqlQuery query;
    query.prepare("SELECT ID_EMPLOYE, NOM_EMP, PRENOM_EMP, TEL_EMP, POSTE_EMP, SALAIRE_EMP, EMAI_EMPL, PASS_EMP FROM EMPLOYES WHERE ID_EMP=:id");
    query.bindValue(":id", id);

    if(query.exec() && query.next()) {
        ui_id->setText(query.value(0).toString());
        ui_nom->setText(query.value(1).toString());
        ui_prenom->setText(query.value(2).toString());
        ui_telephone->setText(query.value(3).toString());
        ui_poste->setText(query.value(4).toString());
        ui_salaire->setText(query.value(5).toString());
        ui_email->setText(query.value(6).toString());
        ui_pass->setText(query.value(7).toString());
    }

    return id;
}

void EmployeSQL::refTab(QTableWidget* table)
{
    if(!table) return;

    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return;

    table->setRowCount(0);
    QSqlQuery query("SELECT ID_EMPLOYE, NOM_EMP, PRENOM_EMP, TEL_EMP, DATE_EMBAUCHE_EMP, POSTE_EMP, SALAIRE_EMP, EMAIL_EMP, PASS_EMP FROM EMPLOYES");

    int row = 0;
    while(query.next()) {
        table->insertRow(row);
        for(int col = 0; col < 9; ++col)
            table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        row++;
    }
}


bool EmployeSQL::chercheID(const QString& id, const QString& suppID)
{
    Connection* conn = Connection::instance();
    if(!conn->createconnect()) return false;

    QSqlQuery checkQuery;
    if(suppID.isEmpty()) {
        checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE ID_EMPLOYE=:id");
        checkQuery.bindValue(":id", id);
    } else {
        checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE ID_EMPLOYE=:id AND ID_EMPLOYE!=:old_id");
        checkQuery.bindValue(":id", id);
        checkQuery.bindValue(":old_id", suppID);
    }

    if(checkQuery.exec() && checkQuery.next()) return checkQuery.value(0).toInt() > 0;
    return false;
}
void EmployeSQL::trierTab(QTableWidget* table, const QString& critere)
{
    Q_UNUSED(table);
    Q_UNUSED(critere);
}

void EmployeSQL::rech(QTableWidget* table, const QString& nom)
{
    for(int i=0; i<table->rowCount(); i++) {
        bool match = table->item(i, 1)->text().contains(nom, Qt::CaseInsensitive); // colonne Nom = 1
        table->setRowHidden(i, !match);
    }
}
