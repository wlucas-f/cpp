#include "Zombie.hpp"

int main()
{
    Zombie *horde = NULL;
    horde = zombieHorde(5, "zombieeee");
    for(int i = 0; i < 5; i++)
        horde[i].announce();

    delete[] horde;
}
