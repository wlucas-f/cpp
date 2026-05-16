#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    Zombie *zH = new Zombie[N];
    for(int i = 0; i < N; i++)
        zH[i].setName(name);
    return (zH);
}