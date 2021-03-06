#include "scientistrepository.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <QDebug>

ScientistRepository::ScientistRepository()
{
    createConnection();
}

ScientistRepository::~ScientistRepository()
{
}

void ScientistRepository::add(Scientist scientist)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO Scientists (Name, BirthYear, DeathYear, Gender, ImagePath) VALUES (:name,:dob,:dod,:gender,:imagePath)");
    query.bindValue(":name",    QString::fromStdString(scientist.getName()));
    query.bindValue(":dob",     QString::fromStdString(scientist.getDateOfBirth()));
    query.bindValue(":dod",     QString::fromStdString(scientist.getDateOfDeath()));
    query.bindValue(":gender",  QString::fromStdString(scientist.getGender()));
    query.bindValue(":imagePath",QString::fromStdString(scientist.getImagepath()));

    query.exec();
}

void ScientistRepository::remove(int id)
{
    QSqlQuery query(db);
    query.clear();
    query.prepare("DELETE FROM Scientists WHERE ID = :id");
    query.bindValue(":id", QString::number(id));
    query.exec();

    query.prepare("DELETE FROM Joined WHERE s_ID = :id");
    query.bindValue(":id", QString::number(id));
    query.exec();
}

std::vector<Scientist> ScientistRepository::list()
{
    return list("","");
}

std::vector<Scientist> ScientistRepository::list(std::string col, std::string mod)
{
    std::vector<Scientist> scientistList = std::vector<Scientist>();

    QSqlQuery query(db);
    std::string orderBy = "";

    if(!col.empty())
    {
        mod = mod.empty() ? "ASC" : (mod.find("desc") != std::string::npos ? "DESC" : "ASC");
        orderBy = "order by " + col + " " + mod;
    }
    query.exec("SELECT * FROM Scientists " + QString::fromStdString(orderBy));

    populateScientistList(scientistList, query);

    return scientistList;
}

void ScientistRepository::populateScientistList(std::vector<Scientist> &scientistList, QSqlQuery query)
{
    while(query.next())
    {
        Scientist s = Scientist();
        s.setId(query.value("ID").toInt());
        s.setName(query.value("Name").toString().toStdString());
        s.setDateOfBirth(query.value("BirthYear").toString().toStdString());
        s.setDateOfDeath(query.value("DeathYear").toString().toStdString());
        s.setGender(query.value("Gender").toString().toStdString());
        s.setImagepath(query.value("ImagePath").toString().toStdString());

        scientistList.push_back(s);
    }
}

void ScientistRepository::connect(int sID, int cID)
{
        scientistDB = getDatabaseConnection();
        scientistDB.open();
        QSqlQuery query(scientistDB);

        query.exec(QString("INSERT INTO Joined (s_ID, c_ID) VALUES (%1,%2);")
                        .arg(sID)
                        .arg(cID));

       scientistDB.close();
}

std::vector<Scientist> ScientistRepository::connectedScientists(int sID)
{
    std::vector<Scientist> scientist = std::vector<Scientist>();
    Scientist s = Scientist();
    scientistDB = getDatabaseConnection();
    scientistDB.open();
    QSqlQuery query(scientistDB);
    QString s_ID = QString::number(sID);

    query.exec(QString("SELECT ID, Name FROM scientists JOIN Joined ON Joined.s_ID = scientists.ID WHERE Joined.c_ID = %1")
                      .arg(sID));

    while(query.next())
    {
        s.name                    = query.value("Name").toString().toStdString();

        scientist.push_back(s);
    }
        scientistDB.close();

    return scientist;
}

