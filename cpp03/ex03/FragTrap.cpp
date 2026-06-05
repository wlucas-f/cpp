#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap():ClapTrap("Default"){
	std::cout << "FragTrap constructor called\n";
	hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap (const std::string name) : ClapTrap(name){
    std::cout << "FragTrap constructor called\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other){
    std::cout << "FragTrap copy assignment operator called\n";
    if (this == &other)
        return *this;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return *this;
}

void FragTrap::highFiveGuys(void){
    std::cout << "FragTrap high-fives you!\n";
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called\n";
}
