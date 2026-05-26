#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        explicit ScavTrap(std::string name);
        ScavTrap(ScavTrap &other);
        ScavTrap operator=(const ScavTrap &other);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        bool chassisUp();
        ~ScavTrap();
    private:
};

#endif