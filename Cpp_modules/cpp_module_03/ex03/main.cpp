#include "FlagTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	ClapTrap bot1("BMO");
	ClapTrap bot2("Norm");
	ScavTrap guardian("Goliath");
	FlagTrap buddy("Astolfo");
	DiamondTrap TwoFaces("Benjamim");

	bot1.setDmg(10);
	bot2.setHP(30);
	bot2.setEnergy(2);
	bot2.setDmg(2);
	bot1.attack(bot2.getName());
	bot2.takeDamage(bot1.getDmg());
	bot2.attack(bot1.getName());
	bot1.takeDamage(bot2.getDmg());
	bot1.beRepaired(5);
	bot1.attack(bot2.getName());
	bot2.takeDamage(bot1.getDmg());
	bot2.attack(bot1.getName());
	bot1.takeDamage(bot2.getDmg());
	guardian.attack(bot2.getName());
	bot2.takeDamage(guardian.getDmg());
	bot2.beRepaired(10);
	bot1.attack(guardian.getName());
	guardian.takeDamage(bot1.getDmg());
	guardian.guardGate();	
	bot1.attack(guardian.getName());
	guardian.takeDamage(bot1.getDmg());
	buddy.highFivesGuys();
	buddy.attack(guardian.getName());
	guardian.takeDamage(buddy.getDmg());
	TwoFaces.WhoAmI();
	TwoFaces.attack(guardian.getName());
	guardian.takeDamage(TwoFaces.getDmg());
	return (0);
}