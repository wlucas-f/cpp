#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap("Default"){
	std::cout << "ScavTrap constructor called\n";
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap (const std::string name) : ClapTrap(name){
    std::cout << "ScavTrap constructor called\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other){
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
    std::cout << "ScavTrap copy assignment operator called\n";
    if (this == &other)
        return *this;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return *this;
}

void ScavTrap::attack(const std::string &target){
    if (!this->chassisUp()){
        std::cout << "ScavTrap " << this->name << " can't attack\n";
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
    this->energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}
