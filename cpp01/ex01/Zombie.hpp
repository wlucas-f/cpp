#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
        Zombie(){};
        Zombie(std::string n):name(n){};
        void announce(void);
        void setName(std::string n);
        ~Zombie();
    private:
        std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif