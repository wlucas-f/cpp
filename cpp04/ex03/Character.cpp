#include "Character.hpp"
#include "AMateria.hpp"
#include <cstddef>

Character::Character(std::string const &name):name(name){}

Character::Character(const Character &other):name(other.name){}

Character& Character::operator=(const Character &other){
    if(this != &other)
        *this = other;
    return *this;
}

Character::~Character(){};

std::string const & Character::getName() const{
    return this->name;
}

void Character::equip(AMateria* m){
    int i = 0;
    while (*slot && i < 4)
        i++;
    if(i <=3)
        slot[i] = m;
}

//void Character::unequip(int idx){};

void Character::use(int idx, ICharacter& target){
    slot[idx]->use(target);
}
