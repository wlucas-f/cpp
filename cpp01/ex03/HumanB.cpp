#include "HumanB.hpp"

HumanB::HumanB(const std::string name):name(name){};

HumanB::HumanB(const std::string &name, Weapon *weapon) : name(name), weapon(weapon){};

void HumanB::attack() const {
    if (weapon != NULL)
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " tried to attack, but has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}