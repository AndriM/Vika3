#include "scienceservice.h"

ScienceService::ScienceService() {
    scientistRepository = ScientistRepository();
}

ScienceService::~ScienceService() {
}

void ScienceService::addScientist(Scientist scientist) {
    scientistRepository.add(scientist);
}

void ScienceService::removeScientist(std::string id) {
    scientistRepository.remove(id);
}

std::vector<Scientist> ScienceService::getAllScientists() {
    return scientistRepository.list();
}

std::vector<Scientist> ScienceService::getScientistsOrderedBy(std::string col, std::string mod) {
    return scientistRepository.list(col,mod);
}

std::vector<Scientist> ScienceService::searchScientist(std::string searchTerm) {
    return scientistRepository.search(searchTerm);
}

void ScienceService::addComputer(Computer computer)
{
    computerRepository.add(computer);
}

void ScienceService::removeComputer(std::string id)
{
    computerRepository.remove(id);
}

std::vector<Computer> ScienceService::searchComputer(std::string searchTerm)
{
    return computerRepository.search(searchTerm);
}

std::vector<Computer> ScienceService::getAllComputers()
{
    return computerRepository.list();
}

std::vector<Computer> ScienceService::getComputersOrderedBy(std::string col, std::string mod)
{
    return computerRepository.list(col, mod);
}

std::vector<Computer> ScienceService::getAllComputersByScientistId(std::string id)
{
    return scientistComputerConnectionsRepository.getAllComputersByScientistId(id);
}

std::vector<Scientist> ScienceService::getAllScientistsByComputerId(std::string id)
{
    return scientistComputerConnectionsRepository.getAllScientistsByComputerId(id);
}

bool ScienceService::addConnection(std::string sid, std::string cid)
{
    return scientistComputerConnectionsRepository.addConnection(sid, cid);
}

bool ScienceService::removeConnection(std::string sid, std::string cid)
{
    return scientistComputerConnectionsRepository.removeConnection(sid, cid);
}
