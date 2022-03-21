#include "ClapTrap.hpp"

int main() {
	ClapTrap bot1("BMO");
	ClapTrap bot2;

	//settings
	bot1.setDmg(10);
	bot2.setHP(20);
	bot2.setDmg(1);
	bot2.setEnergy(0); // setting energy as 0 for the energy test
	//bot1 turn
	bot1.attack(bot2.getName()); // <- bot1 has energy and it's active, so it can attack. Lose 1 energy point.
	bot2.takeDamage(bot1.getDmg()); // <- bot2 will take the damage from bot1 attack.
	//bot2 turn
	bot2.attack(bot1.getName()); //<- bot2 without energy to attack.
	bot2.beRepaired(5); //<- bot2 without energy to repair.
	//bot1 turn
	bot1.beRepaired(5); // <- bot1 will gain 5 of health. Lose 1 energy point
	bot1.attack(bot2.getName()); // bot1 should have 8 of energy here and will attack again.
	bot2.takeDamage(bot1.getDmg()); // <- bot2 will be destroyed here.
	bot2.attack(bot1.getName()); // <- bot2 will try attack but it's already destroyed.
	bot2.takeDamage(bot1.getDmg()); // <- bot2 won't show damage message because is already destroyed.
	bot2.beRepaired(5); // <- bot2 won't repair itself because it's already destroyed.
	return (0);
}
