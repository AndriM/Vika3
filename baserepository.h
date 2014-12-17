#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

#include <QtSql>
//Handles to open the database if it isn't open
class BaseRepository{
    protected:
        QSqlDatabase db;

        bool createConnection();
        QSqlDatabase getDatabaseConnection();

};

#endif // BASEREPOSITORY_H
