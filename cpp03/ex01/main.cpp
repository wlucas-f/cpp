#include "ClapTrap.hpp"

int main(){
    ClapTrap robot1("Bob");
    ClapTrap robot2("Jimmy");
    robot1.attack(robot2.getName());
    robot2.takeDamage(1000);
    robot2.attack("Tests");
}