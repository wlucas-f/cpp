#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        explicit FragTrap(const std::string name);
        FragTrap(FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        void attack(const std::string &target);
        //void takeDamage(unsigned int amount);
        //void beRepaired(unsigned int amount);
        void highFiveGuys(void);
        //std::string getName() const;
        //int getHitPoints() const;
        //int getEnergyPoints() const;
        //int getAttackDamage() const;
        bool chassisUp();
        ~FragTrap();
};

#endif