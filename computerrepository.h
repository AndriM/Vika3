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
    void remove(std::string id);
    std::vector<Computer> search(std::string searchTerm);
    std::vector<Computer> list();
    // Returns a list ordered by column and modifier
    std::vector<Computer> list(std::string col,std::string mod);
private:
    std::vector<Computer> computerList;
    void populateComputerList(std::vector<Computer> &computerList, QSqlQuery query);
};

#endif // COMPUTERREPOSITORY_H
