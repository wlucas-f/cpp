#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = NULL;
	zombie = newZombie("zombie1");
	if (!zombie)
		return (1);
	zombie->announce();
	randomChump("zombie2");
	delete zombie;
	return (0);
}
