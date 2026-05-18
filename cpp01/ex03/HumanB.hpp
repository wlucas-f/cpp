#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(){};
        HumanB(std::string n) : name(n){};
        void setWeapon(Weapon w){
            weapon = w;
        }
        void attack(){
            std::cout << name << " attacks with their " << weapon.getType() << std::endl;
        }
    private:
        std::string name;
        Weapon weapon;
};

#endif