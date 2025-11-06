#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

class Connection
{
private:
    static Connection* p_instance;
    QSqlDatabase db;

    Connection();

public:
    static Connection* instance();
    bool createconnect();
    ~Connection();

    // ✅ méthode publique pour accéder à la base
    QSqlDatabase& getDatabase();
};

#endif // CONNECTION_H
