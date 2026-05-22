#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    public:
        HumanA(const std::string name, Weapon &weapon) : name(name), weapon(weapon){};
        void attack() const {
            std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
        }
    private:
        std::string name;
        Weapon &weapon;
};
#endif