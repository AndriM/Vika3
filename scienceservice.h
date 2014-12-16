#ifndef SCIENCESERVICE_H
#define SCIENCESERVICE_H

#include "Scientist.h"
#include "ScientistRepository.h"
#include "computer.h"
#include "computerrepository.h"
#include "scientistcomputerconnections.h"
#include "scientistcomputerconnectionsrepository.h"
#include <list>


// Domain layer, services the presentation layer
class ScienceService {
public:
    ScienceService();
    ~ScienceService();

    //Scientists
    void addScientist(Scientist scientist);
    void removeScientist(int id);
    //std::vector<Scientist> searchScientist(std::string searchTerm);
    std::vector<Scientist> getAllScientists();
    std::vector<Scientist> getScientistsOrderedBy(std::string col,std::string mod);

    //Computers
    void addComputer(Computer computer);
    void removeComputer(int id);
    //std::vector<Computer> searchComputer(std::string searchTerm);
    std::vector<Computer> getAllComputers();
    std::vector<Computer> getComputersOrderedBy(std::string col,std::string mod);

    //Connections
    /*std::vector<Computer> getAllComputersByScientistId(std::string id);
    std::vector<Scientist> getAllScientistsByComputerId(std::string id);
    bool addConnection(std::string sid, std::string cid);
    bool removeConnection(std::string sid, std::string cid);*/

    //Connections
    void connectScientists(int sID, int cID);
    void connectComputers(int cID, int sID);
    std::vector<Scientist> connectedScientists(int sID);
    std::vector<Computer> connectedComputers(int cID);
private:
    ScientistRepository scientistRepository;
    ComputerRepository computerRepository;
    //ScientistComputerConnectionsRepository scientistComputerConnectionsRepository;
};

#endif // SCIENCESERVICE_H
