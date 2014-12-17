#ifndef SCIENCESERVICE_H
#define SCIENCESERVICE_H

#include "Scientist.h"
#include "ScientistRepository.h"
#include "computer.h"
#include "computerrepository.h"
#include <list>


// Domain layer, services the presentation layer
class ScienceService {
public:
    ScienceService();
    ~ScienceService();

    //Scientists
    void addScientist(Scientist scientist);
    void removeScientist(int id);
    std::vector<Scientist> getAllScientists();
    std::vector<Scientist> getScientistsOrderedBy(std::string col,std::string mod);

    //Computers
    void addComputer(Computer computer);
    void removeComputer(int id);
    std::vector<Computer> getAllComputers();
    std::vector<Computer> getComputersOrderedBy(std::string col,std::string mod);

    //Connections
    void connectScientists(int sID, int cID);
    void connectComputers(int cID, int sID);
    std::vector<Scientist> connectedScientists(int sID);
    std::vector<Computer> connectedComputers(int cID);
private:
    ScientistRepository scientistRepository;
    ComputerRepository computerRepository;

};

#endif // SCIENCESERVICE_H
