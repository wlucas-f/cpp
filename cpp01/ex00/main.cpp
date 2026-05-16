#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = NULL;
	zombie = newZombie("zombie1");
	zombie->announce();
	randomChump("zombie2");
	delete zombie;
	return (0);
}
