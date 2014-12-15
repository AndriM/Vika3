#include "scientistrepository.h"
#include <stdexcept>
#include <string>
#include <iostream>

ScientistRepository::ScientistRepository() {
    createConnection();
}

ScientistRepository::~ScientistRepository() {
}

void ScientistRepository::add(Scientist scientist) {

    QSqlQuery query(db);
    query.prepare("INSERT INTO Scientists (Name, BirthYear, DeathYear, Gender, ImagePath) VALUES (:name,:dob,:dod,:gender,:imagePath)");
    query.bindValue(":name",    QString::fromStdString(scientist.getName()));
    query.bindValue(":dob",     QString::fromStdString(scientist.getDateOfBirth()));
    query.bindValue(":dod",     QString::fromStdString(scientist.getDateOfDeath()));
    query.bindValue(":gender",  QString::fromStdString(scientist.getGender()));
    query.bindValue(":imagePath",QString::fromStdString(scientist.getImagepath()));

    query.exec();
}

void ScientistRepository::remove(std::string id) {
    QSqlQuery query(db);

    query.prepare("DELETE FROM Scientists WHERE id = :id");
    query.bindValue(":id", std::atoi(id.c_str()));

    query.exec();

    query.prepare("DELETE FROM ScientistComputerConnections WHERE s_ID = :id");
    query.bindValue(":id", std::atoi(id.c_str()));

    query.exec();
}

std::vector<Scientist> ScientistRepository::list() {
    return list("","");
}

std::vector<Scientist> ScientistRepository::list(std::string col, std::string mod) {

    std::vector<Scientist> scientistList = std::vector<Scientist>();

    QSqlQuery query(db);
    std::string orderBy = "";

    if(!col.empty()){
        mod = mod.empty() ? "ASC" : (mod.find("desc") != std::string::npos ? "DESC" : "ASC");
        orderBy = "order by " + col + " " + mod;

    }
    query.exec("SELECT * FROM Scientists " + QString::fromStdString(orderBy));

    populateScientistList(scientistList, query);

    return scientistList;

}

std::vector<Scientist> ScientistRepository::search(std::string searchTerm) {
    // Naive search implementation, finds a substring in the name field
    std::vector<Scientist> scientistList = std::vector<Scientist>();

    QSqlQuery query(db);

    std::string q = "SELECT * FROM Scientists WHERE Name LIKE '%"+searchTerm+"%'";

    query.exec(QString::fromStdString(q));

    populateScientistList(scientistList, query);

    return scientistList;
}

void ScientistRepository::populateScientistList(std::vector<Scientist> &scientistList, QSqlQuery query){
    while(query.next()){
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
