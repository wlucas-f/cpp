#include "Zombie.hpp"

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string n){
    name = n;
}

Zombie::~Zombie(){
    std::cout << "Destructor called for " << name << std::endl;
};