#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        explicit ScavTrap(const std::string name);
        ScavTrap(ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        void attack(const std::string &target);
        //void takeDamage(unsigned int amount);
        //void beRepaired(unsigned int amount);
        void guardGate();
        //std::string getName() const;
        //int getHitPoints() const;
        //int getEnergyPoints() const;
        //int getAttackDamage() const;
        bool chassisUp();
        ~ScavTrap();
};

#endif