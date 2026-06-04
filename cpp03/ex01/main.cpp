#include "ScavTrap.hpp"

int main()
{
  ClapTrap MachineA("Roboto");
  ClapTrap MachineB("Roboto");
  MachineA.attack(MachineB.getName());
  MachineB.takeDamage(5);
  MachineA.beRepaired(1);
  std::cout << std::endl << std::endl;

  ScavTrap ScavA("Robert");
  ScavA.guardGate();
  ScavA.attack("Pigeon");
  ScavA.takeDamage(10);
  std::cout << std::endl << std::endl;

  ScavTrap ScavB(ScavA);
  ScavB.beRepaired(5);
  ScavB.beRepaired(1);
  std::cout << std::endl << std::endl;

  ScavTrap ScavC = ScavA;
  ScavC.takeDamage(100);
  ScavC.takeDamage(100);
  ScavC.attack("Perry");
  std::cout << std::endl << std::endl;
}
