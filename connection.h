#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QMutex>  // Pour thread-safety

class Connection
{
public:
    static Connection* instance();
    bool createconnect();
    QSqlDatabase getDb() const { return db; }
    bool isConnected() const { return db.isOpen() && !db.lastError().isValid(); }  // Nouveau: Statut rapide
    bool reconnect();  // Nouveau: Retry connexion

private:
    Connection();
    ~Connection();
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
    static Connection* p_instance;
    static QMutex mutex;  // Nouveau: Lock pour singleton
    QSqlDatabase db;
};

#endif // CONNECTION_H
