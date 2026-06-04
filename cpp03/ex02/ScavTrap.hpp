#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        explicit ScavTrap(const std::string name);
        ScavTrap(ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        void attack(const std::string &target);
        void guardGate();
        bool chassisUp();
        ~ScavTrap();
};

#endif
