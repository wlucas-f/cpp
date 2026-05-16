#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    Zombie* zombie = new Zombie(name);
    if(!zombie)
        std::cerr << "Memory allocation failed" << std::endl;
    return (zombie);
}