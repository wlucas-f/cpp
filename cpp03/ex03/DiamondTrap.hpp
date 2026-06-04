#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap{
    public:
        DiamondTrap();
        DiamondTrap(DiamondTrap &other);
        DiamondTrap& operator=(DiamondTrap &other);
        ~DiamondTrap();

    private:
        std::string name;
};

#endif
