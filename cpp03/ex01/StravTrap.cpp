#ifndef STRAVTRAP_CPP
#define STRAVTRAP_CPP

#include "ClapTrap.hpp"

class StravTrap : public ClapTrap{
    public:
        StravTrap(std::string name, int hp = 100, int ep = 50, int damage = 20) : name(name), hitPoints(hp), energyPoints(ep), attackDamage(damage){};
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif