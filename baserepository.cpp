#include "baserepository.h"
#include <stdexcept>

bool BaseRepository::createConnection()
{
    db = getDatabaseConnection();

    if(!db.isOpen()){
       throw std::runtime_error("Failed to open database");
    }
    return true;
}

QSqlDatabase BaseRepository::getDatabaseConnection()
{
    QString connectionName = "ScienceConnection";
    QSqlDatabase database;

    if(QSqlDatabase::contains(connectionName))
    {
        database = QSqlDatabase::database(connectionName);
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        database.setDatabaseName("vika3.sqlite");
        database.open();

        //Turn foreign key check on
        QSqlQuery query(database);
        query.exec("PRAGMA FOREIGN_KEYS = ON");
    }
    return database;
}
