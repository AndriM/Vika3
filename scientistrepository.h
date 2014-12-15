#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include "Scientist.h"
#include "baserepository.h"
#include <stdexcept>
#include <iostream>
#include <vector>

class ScientistRepository : public BaseRepository{
public:
    ScientistRepository();
    ~ScientistRepository();

    void add(Scientist);
    void remove(std::string id);
    std::vector<Scientist> search(std::string searchTerm);
    std::vector<Scientist> list();
    // Returns a list ordered by column and modifier
    std::vector<Scientist> list(std::string col,std::string mod);
private:
    std::vector<Scientist> scientistList;
    void populateScientistList(std::vector<Scientist> &scientistList, QSqlQuery query);
};

#endif // SCIENTISTREPOSITORY_H
