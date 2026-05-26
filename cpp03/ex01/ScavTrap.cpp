#include "ScavTrap.hpp"

ScavTrap::ScavTrap (std::string name) : ClapTrap(name), hitPoints(100), energyPoints(50), attackDamage(20) {
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(ScavTrap &other){
    std::cout << "ScavTrap copy constructor called\n";
    *this = other;
}

ScavTrap ScavTrap::operator=(const ScavTrap &other){
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
    if (!this->chassisUp())
    {
        std::cout << "ScavTrap " << this->name << " can't attack\n";
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
    this->energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount){
    int hp = this->hitPoints - static_cast<int>(amount);
    if (hp <= 0)
    {
        this->hitPoints = 0;
        std::cout << "ScavTrap " << this->name << " has 0 HP!\n";
        return ;
    }
    std::cout << "ScavTrap " << this->name << " was attacked. Loosing " << amount << " HP!\n";
    this->hitPoints -= static_cast<int>(amount);
}

void ScavTrap::beRepaired(unsigned int amount){
    if (!this->chassisUp())
    {
        std::cout << "ScavTrap " << this->name << " can't repair itself!\n";
        return;
    }
    std::cout << "ScavTrap " << this->name << " repairs itself. Regaining " << amount << " Hit Points!\n";
    this->hitPoints += static_cast<int>(amount);
    this->energyPoints--;
}

std::string ScavTrap::getName() const{
    return(this->name);
}

int ScavTrap::getHitPoints() const{
    return(this->hitPoints);
}

int ScavTrap::getEnergyPoints() const{
    return(this->energyPoints);
}

int ScavTrap::getAttackDamage() const{
    return(this->attackDamage);
}

bool ScavTrap::chassisUp()
{
    if(this->hitPoints > 0 && this->energyPoints > 0)
        return true;
    return false;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}