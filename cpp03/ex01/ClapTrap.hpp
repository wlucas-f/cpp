#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		bool chassisUp();
		virtual ~ClapTrap();
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
};

#endif
