#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
  ClapTrap MachineA("Roboto");
  ClapTrap MachineB("Roboto");
  MachineA.attack(MachineB.getName());
  MachineB.takeDamage(5);
  MachineA.beRepaired(1);
  std::cout << std::endl << std::endl;

  FragTrap FragA("Robert");
  FragA.highFiveGuys();
  FragA.attack("Pigeon");
  FragA.takeDamage(10);
  std::cout << std::endl << std::endl;

  FragTrap FragB(FragA);
  FragB.beRepaired(5);
  FragB.beRepaired(1);
  std::cout << std::endl << std::endl;

  FragTrap FragC = FragA;
  FragC.takeDamage(100);
  FragC.takeDamage(100);
  FragC.attack("Perry");
  std::cout << std::endl << std::endl;
}
