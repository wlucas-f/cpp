#include "Character.hpp"
#include "AMateria.hpp"
#include "iostream"
#include <cstddef>

Character::Character(std::string const &name):name(name){
    for(int i = 0; i < 4; i++) slot[i] = NULL;
}

Character::Character(const Character &other):name(other.name){
    for(int i = 0; i < 4; i++)
    {
        if(other.slot[i])
            slot[i] = other.slot[i]->clone();
        else
             slot[i] = NULL;
    }
}

Character& Character::operator=(const Character &other){
    if(this == &other)
        return *this;
    for (int i = 0; i < 4; i++)
    {
        delete slot[i];
        slot[i] = NULL;
    }
    for(int i = 0; i < 4; i++)
    {
        if(other.slot[i])
            slot[i] = other.slot[i]->clone();
        else
            slot[i] = NULL;
    }

    return *this;
}

Character::~Character(){
    for(int i = 0; i < 4; i++){
            if(slot[i]){
                delete slot[i];
                slot[i] = NULL;
            }
        }
}

std::string const & Character::getName() const{
    return this->name;
}

void Character::equip(AMateria* m){
    int i = 0;
    while (slot[i] && i < 4)
        i++;
    if(i <=3)
        slot[i] = m;
}

void Character::unequip(int idx){
    if(idx < 0 || idx > 3 || !slot[idx])
        return ;
    if(slot[idx + 1])
        slot[idx] = slot[idx + 1];
    else
        slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if(idx < 0 || idx > 3 || !slot[idx])
        return ;
    slot[idx]->use(target);
}
