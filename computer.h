#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

class Computer
{
public:
    Computer();
    int getId() const;
    void setId(int value);

    std::string getName() const;
    void setName(const std::string &value);

    std::string getYearBuilt() const;
    void setYearBuilt(const std::string &value);

    std::string getType() const;
    void setType(std::string value);

    std::string getWasBuilt() const;
    void setWasBuilt(std::string value);

    int id;
    std::string name;
    std::string yearBuilt;
    std::string type;
    std::string wasBuilt;
    std::string stringToLower(std::string original);
    std::string toString();
    bool contains(std::string str);
};

#endif // COMPUTER_H
