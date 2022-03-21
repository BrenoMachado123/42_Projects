#include "ScavTrap.hpp"

int main() {
	ClapTrap bot("BMO");
	ClapTrap poor_bot;
	ScavTrap guardian("Goliath");

	std::string scav_name = guardian.getName();
	std::string bot_name = bot.getName();
	std::string pb_name = poor_bot.getName();

	//settings
	poor_bot.setHP(20);
	bot.setDmg(20);

	// poor bot turn
	poor_bot.attack(scav_name); //<- without energy to attack
	//guardian turn
	guardian.attack(pb_name);
	poor_bot.takeDamage(guardian.getDmg()); // <- poor bot will be destroyed
	//bot turn
	bot.attack(scav_name);
	guardian.takeDamage(bot.getDmg());
	//guardian turn
	guardian.guardGate(); // guardian will enter in guardian gate mode
	//bot turn
	bot.beRepaired(40);
	//guardian turn
	guardian.attack(bot_name);
	bot.takeDamage(guardian.getDmg());
	//bot turn
	bot.attack(scav_name);
	guardian.takeDamage(bot.getDmg());
	//guardian turn
	guardian.guardGate(); //<- already in guardian gate mode, nothing happens
	return (0);
}
