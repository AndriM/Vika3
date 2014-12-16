#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include "baserepository.h"
#include "computer.h"

#include <stdexcept>
#include <iostream>
#include <vector>

class ComputerRepository : public BaseRepository
{
public:
    ComputerRepository();
    ~ComputerRepository();

    void add(Computer);
    void remove(int id);
    //std::vector<Computer> search(std::string searchTerm);
    std::vector<Computer> list();
    // Returns a list ordered by column and modifier
    std::vector<Computer> list(std::string col,std::string mod);
    void connect(int cID, int sID);
    std::list<Computer> connectedComputers(int cID);
private:
    std::vector<Computer> computerList;
    void populateComputerList(std::vector<Computer> &computerList, QSqlQuery query);
    QSqlDatabase computerDB;
};

#endif // COMPUTERREPOSITORY_H
