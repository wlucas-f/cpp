#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other){
    std::cout << "ClapTrap copy constructor called\n";
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
    std::cout << "ClapTrap copy assignment operator called\n";
    if (this == &other)
        return *this;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string &target){
    if (!this->chassisUp())
    {
        std::cout << "ClapTrap " << this->name << " can't attack\n";
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
    int hp = this->hitPoints - static_cast<int>(amount);
    if (hp <= 0)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " has 0 HP!\n";
        return ;
    }
    std::cout << "ClapTrap " << this->name << " was attacked. Loosing " << amount << " HP!\n";
    this->hitPoints -= static_cast<int>(amount);
}

void ClapTrap::beRepaired(unsigned int amount){
    if (!this->chassisUp())
    {
        std::cout << "ClapTrap " << this->name << " can't repair itself!\n";
        return;
    }
    std::cout << "ClapTrap " << this->name << " repairs itself. Regaining " << amount << " Hit Points!\n";
    this->hitPoints += static_cast<int>(amount);
    this->energyPoints--;
}

std::string ClapTrap::getName() const{
    return(this->name);
}

int ClapTrap::getHitPoints() const{
    return(this->hitPoints);
}

int ClapTrap::getEnergyPoints() const{
    return(this->energyPoints);
}

int ClapTrap::getAttackDamage() const{
    return(this->attackDamage);
}

bool ClapTrap::chassisUp()
{
    if(this->hitPoints > 0 && this->energyPoints > 0)
        return true;
    return false;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called\n";
}
