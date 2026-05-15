#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name){
    Zombie* zombie = new Zombie(name);
    if(!zombie)
        std::cerr << "Memory allocation failed" << std::endl;
    return (zombie);
}

void randomChump(std::string name){
    Zombie zombie(name);
    zombie.announce();
}

int main(){
    std::string name;
    
    std::cout << "Insert zombie name: " << std::endl;
    std::cin >> name;
    //Zombie z(name);
    //z.announce();
    Zombie *z = newZombie(name);

    
}