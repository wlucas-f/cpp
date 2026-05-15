#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
        Zombie(){};
        Zombie(std::string n):name(n){};
        void announce(void){
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
    private:
        std::string name;
};

#endif