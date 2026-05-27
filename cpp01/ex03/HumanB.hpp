#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(const std::string name);
        HumanB(const std::string &name, Weapon *weapon);
        void attack() const;
        void setWeapon(Weapon &weapon);
    private:
        std::string name;
        Weapon *weapon;
};

#endif