#include "connection.h"
#include <QDebug>
#include <QSettings>  // Pour password sécurisé (optionnel)

Connection* Connection::p_instance = nullptr;
QMutex Connection::mutex;  // Implémentation static

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    // Options ODBC pour Oracle (perf + pooling)
    db.setConnectOptions("SQL_ATTR_CONNECTION_POOLING=1;ODBC;DRIVER={Oracle in instantclient_21_3};");
}

Connection* Connection::instance()
{
    QMutexLocker locker(&mutex);  // Thread-safe
    if (p_instance == nullptr) {
        p_instance = new Connection();
    }
    return p_instance;
}

bool Connection::createconnect()
{
    bool test = false;

    db.setDatabaseName("source_projet2A");  // DSN ODBC – Vérifie s'il existe !
    db.setUserName("SmartSchool");
    // Password sécurisé (optionnel: lis de QSettings ou env)
    db.setPassword("esprit25");  // Ou: QSettings settings; db.setPassword(settings.value("db/password").toString());

    if (db.open()) {
        test = true;
        qDebug() << "✅ Connexion réussie à la base de données Oracle (DSN:" << db.databaseName() << ")";
    } else {
        QString err = db.lastError().text();
        qDebug() << "❌ Erreur de connexion:" << err;
        QMessageBox::critical(nullptr, "Erreur DB", "Connexion échouée: " + err + "\nVérifiez DSN 'source_projet2A' et pilote Oracle ODBC.");
    }

    return test;
}

bool Connection::reconnect()  // Nouveau: Pour retry si fermé
{
    if (db.isOpen()) return true;
    db.close();  // Nettoie
    return createconnect();
}

Connection::~Connection()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "DB fermée proprement.";
    }
    delete p_instance;  // Cleanup singleton
    p_instance = nullptr;
}
