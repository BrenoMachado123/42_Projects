#include "ClapTrap.hpp"

int main() {
	ClapTrap bot1("BMO");
	ClapTrap bot2;

	bot1.setDmg(10);
	bot2.setHP(20);
	bot2.setEnergy(2);
	bot1.attack(bot2.getName());
	bot2.takeDamage(bot1.getDmg());
	bot2.attack(bot1.getName());
	bot1.takeDamage(bot2.getDmg());
	bot1.beRepaired(5);
	bot1.attack(bot2.getName());
	bot2.takeDamage(bot1.getDmg());
	bot2.attack(bot1.getName());
	return (0);
}