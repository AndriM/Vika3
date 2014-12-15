#include "scientist.h"

Scientist::Scientist() {
    name = "";
    dateOfBirth = "";
    dateOfDeath = "";
    gender = "";
}

std::string Scientist::getName() const
{
    return name;
}

void Scientist::setName(const std::string &value)
{
    name = value;
}
std::string Scientist::getDateOfBirth() const
{
    return dateOfBirth;
}

void Scientist::setDateOfBirth(const std::string &value)
{
    dateOfBirth = value;
}
std::string Scientist::getDateOfDeath() const
{
    return dateOfDeath;
}

void Scientist::setDateOfDeath(const std::string &value)
{
    dateOfDeath = value;
}
std::string Scientist::getGender() const
{
    return gender;
}

void Scientist::setGender(const std::string &value)
{
    gender = value;
}
std::string Scientist::getImagepath() const
{
    return imagePath;
}
void Scientist::setImagepath(const std::string &value)
{
    imagePath = value;
}

int Scientist::getId() const
{
    return id;
}

void Scientist::setId(int value)
{
    id = value;
}

bool Scientist::contains(std::string str)
{
    if(str == "")
    {
        return true;
    }

    std::string searchStringToLower = Scientist::stringToLower(str);

    if(Scientist::stringToLower(this->toString()).find(searchStringToLower) != std::string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Scientist::stringToLower(std::string original)
{
    std::string result = "";

    for(unsigned int i = 0; i < original.length(); ++i)
    {
        result += std::tolower(original[i]);
    }

    return result;
}

std::string Scientist::toString()
{
    return name + " " + dateOfBirth + " " + dateOfDeath + " " + gender;
}
