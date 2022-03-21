#include "DiamondTrap.hpp"

int main() {
	ClapTrap bot1("BMO");
	FragTrap buddy("Barney");
	ScavTrap guardian("Goliath");
	DiamondTrap traitor("CrazyDiamond");

	//buddy turn
	buddy.highFivesGuys();
	//bot turn
	bot1.attack(guardian.getName());
	guardian.takeDamage(bot1.getDmg());
	//guardian turn
	guardian.guardGate();
	//buddy turn
	buddy.attack(guardian.getName());
	guardian.takeDamage(buddy.getDmg());
	//guardian turn
	guardian.guardGate();
	//traitor turn
	traitor.attack(buddy.getName()); //<- it will attack with ScavTrap::attack() and showing it's claptrap name.
	buddy.takeDamage(traitor.getDmg());
	traitor.WhoAmI(); //<- will show it's name and it's claptrap name;
	return (0);
}
