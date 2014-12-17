#include "computer.h"

Computer::Computer()
{
}

int Computer::getId() const
{
    return id;
}

void Computer::setId(int value)
{
    id = value;
}

std::string Computer::getName() const
{
    return name;
}

void Computer::setName(const std::string &value)
{
    name = value;
}

std::string Computer::getYearBuilt() const
{
    return yearBuilt;
}

void Computer::setYearBuilt(const std::string &value)
{
    yearBuilt = value;
}

std::string Computer::getType() const
{
    return type;
}

void Computer::setType(std::string value)
{
    type = value;
}

std::string Computer::getWasBuilt() const
{
    return wasBuilt;
}

void Computer::setWasBuilt(std::string value)
{
    wasBuilt = value;
}

bool Computer::contains(std::string str)
{
    if(str == "")
    {
        return true;
    }

    std::string searchStringToLower = Computer::stringToLower(str);

    if(Computer::stringToLower(this->toString()).find(searchStringToLower) != std::string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Computer::stringToLower(std::string original)
{
    std::string result = "";

    for(unsigned int i = 0; i < original.length(); ++i)
    {
        result += std::tolower(original[i]);
    }
    return result;
}

std::string Computer::toString()
{
    return name + " " + yearBuilt + " " + type + " " /*+ wasBuilt*/;
}






