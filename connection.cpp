#include "connection.h"
#include <QDebug>

Connection* Connection::p_instance = nullptr;

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

Connection* Connection::instance()
{
    if (p_instance == nullptr) {
        p_instance = new Connection();
    }
    return p_instance;
}

bool Connection::createconnect()
{
    bool test = false;

    db.setDatabaseName("smartelectronique");
    db.setUserName("elyes");
    db.setPassword("esprit18");

    if (db.open()) {
        test = true;
        qDebug() << "Connexion réussie à la base de données Oracle";
    } else {
        qDebug() << "Erreur de connexion:" << db.lastError().text();
    }

    return test;
}

Connection::~Connection()
{
    if (db.isOpen()) {
        db.close();
    }
}
