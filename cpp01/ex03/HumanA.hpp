#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    public:
        HumanA(){};
        HumanA(std::string n, Weapon w) : name(n), weapon(w){};
        void attack(){
            std::cout << name << " attacks with their " << weapon.getType() << std::endl;
        }
    private:
        std::string name;
        Weapon weapon;
};

#endif