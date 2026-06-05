#include "DiamondTrap.hpp"
#include <ostream>

DiamondTrap::DiamondTrap():ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default"){
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name){
	std::cout << "Constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other), FragTrap(other), ScavTrap(other){
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other){
	std::cout << "Copy assignment operator called." << std::endl;
	if(this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return *this;
}

void DiamondTrap::whoAmI(){
	std::cout << "Hello! Im " << this->name << "! And my ClapTrap's name is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Destructor called." << std::endl;
}
