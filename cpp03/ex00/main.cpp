#include "ClapTrap.hpp"

int main(){
    ClapTrap robot1("Bob");
    ClapTrap robot2("Jimmy");
    robot1.attack(robot2.getName());
    robot2.takeDamage(9);
    robot2.beRepaired(10);
    robot2.attack(robot1.getName());
    robot1.takeDamage(1000);
    robot1.attack("Tests");
}
