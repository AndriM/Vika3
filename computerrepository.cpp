#include "computerrepository.h"

ComputerRepository::ComputerRepository() {
    createConnection();
}

ComputerRepository::~ComputerRepository() {
}

void ComputerRepository::add(Computer computer) {

    QSqlQuery query(db);
    query.prepare("INSERT INTO Computers (Name, Type, Constructed, ConstructionYear) VALUES (:name,:type,:wb,:yb)");
    query.bindValue(":name",    QString::fromStdString(computer.getName()));
    query.bindValue(":type",      QString::fromStdString(computer.getType()));
    query.bindValue(":wb",    QString::fromStdString(computer.getWasBuilt()));
    query.bindValue(":yb",      QString::fromStdString(computer.getYearBuilt()));

    query.exec();
}

void ComputerRepository::remove(int id) {

    QSqlQuery query(db);
    query.clear();
    query.prepare("DELETE FROM Computers WHERE ID = :id");
    query.bindValue(":id", QString::number(id));
    query.exec();


    query.prepare("DELETE FROM Joined WHERE c_ID = :id");
    query.bindValue(":id", QString::number(id));
    query.exec();

}

std::vector<Computer> ComputerRepository::list() {
    return list("","");
}

std::vector<Computer> ComputerRepository::list(std::string col, std::string mod) {
    std::vector<Computer> computerList = std::vector<Computer>();

    QSqlQuery query(db);
    std::string orderBy = "";

    if(!col.empty()){
        mod = mod.empty() ? "ASC" : (mod.find("desc") != std::string::npos ? "DESC" : "ASC");
        orderBy = "order by " + col + " " + mod;

    }
    query.exec("SELECT * FROM Computers " + QString::fromStdString(orderBy));

    populateComputerList(computerList, query);

    return computerList;

}

/*std::vector<Computer> ComputerRepository::search(std::string searchTerm) {
    // Naive search implementation, finds a substring in the name field
    std::vector<Computer> computerList = std::vector<Computer>();

    QSqlQuery query(db);

    std::string q = "SELECT * FROM Computers WHERE Name LIKE '%"+searchTerm+"%'";

    query.exec(QString::fromStdString(q));

    populateComputerList(computerList, query);

    return computerList;
}*/

void ComputerRepository::populateComputerList(std::vector<Computer> &computerList, QSqlQuery query){
    while(query.next()){
        Computer c = Computer();
        c.setId(query.value("ID").toInt());
        c.setName(query.value("Name").toString().toStdString());
        c.setType(query.value("Type").toString().toStdString());
        c.setWasBuilt(query.value("Constructed").toString().toStdString());
        c.setYearBuilt(query.value("ConstructionYear").toString().toStdString());

        computerList.push_back(c);
    }
}
void ComputerRepository::connect(int cID, int sID) {

            computerDB = getDatabaseConnection();
            computerDB.open();
            QSqlQuery query(computerDB);

            query.exec(QString("INSERT INTO Joined (c_ID, s_ID) VALUES (%1,%2);")
                            .arg(cID)
                            .arg(sID));

           computerDB.close();
}

std::list<Computer> ComputerRepository::connectedComputers(int cID) {

    std::list<Computer> comp = std::list<Computer>();
    Computer c = Computer();
    computerDB = getDatabaseConnection();
    computerDB.open();
    QSqlQuery query(computerDB);
    QString c_ID = QString::number(cID);

    query.exec(QString("SELECT ID, Name FROM Computers JOIN Joined ON Joined.c_ID = Computers.ID WHERE Joined.s_ID = %1")
                      .arg(cID));

    while(query.next()){
        c.name                    = query.value("Name").toString().toStdString();

        comp.push_back(c);
    }
        computerDB.close();

    return comp;
}


