#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    public:
        ClapTrap(std::string name, int HP = 10, int energy = 10, int damage = 0) : name(name), hitPoints(HP),  energyPoints(energy), attackDamage(damage){
            std::cout << "Constructor called" << std::endl;
        };
        void attack(const std::string &target){
            if(this->energyPoints){
                std::cout << "ClapTrap" << this->name << "attacks" << target << ", causing" << this->attackDamage << "points of damage!" << std::endl;
                this->energyPoints--;
                return ;
            }
            std::cout << "ClapTrap" << this->name << "tried to attack" << target << "but it doesn't have enought Energy Points!" << std::endl;
        };
        void takeDamage(unsigned int amount){
            std::cout << "ClapTrap" << this->name << "was attacked. Loosing" << amount << "points of damage!" << std::endl;
            this->hitPoints -= amount;
        };
        void beRepaired(unsigned int amount){
            if(this->energyPoints){
                std::cout << "ClapTrap" << this->name << "repairs itself. Regaining" << amount << "hit points!" << std::endl;
                this->energyPoints--;
                return ;
            }
            std::cout << "ClapTrap" << this->name << "tried to repair itself, but it doesn't have enought Energy Points!" << std::endl;
        };

    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif