#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(const std::string name):name(name){};
        HumanB(const std::string &name, Weapon *weapon) : name(name), weapon(weapon){};
        void attack() const {
            if (weapon != NULL)
                std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
            else
                std::cout << this->name << " tried to attack, but has no weapon" << std::endl;
        }
        void setWeapon(Weapon &weapon){
            this->weapon = &weapon;
        }
    private:
        std::string name;
        Weapon *weapon;
};

#endif