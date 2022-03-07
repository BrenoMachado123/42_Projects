#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

static bool	cruel_fate(std::string w_name, std::string name) {
		std::string decision;
		std::cout << "Give  " << w_name << " to " << name << "? [Y]/[N]" << std::endl;
		while (1) { 
			getline(std::cin >> std::ws, decision);
			if (decision == "Y") { 
				return (false); 
			} else if (decision == "N") {
				return (true);
			}
		}
		return (false);
}

static std::string name_choice() {
	std::string name;
	std::cout << "|Choose your name|" << std::endl;
	getline(std::cin >> std::ws, name);
	return name;
}

static std::string weapon_choice() {
	std::string w_name;
	std::cout << "|Choose/Change weapon|" << std::endl;
	getline(std::cin >> std::ws, w_name);
	return w_name;
}

int	main(void) {
	{
		std::cout << "--- PLAYER 1 --- " << std::endl;
		std::string w_name = weapon_choice();
		Weapon weapon = Weapon(w_name);
		std::string name = name_choice();
		HumanA player1(name, weapon);
		player1.attack();
		w_name = weapon_choice();
		weapon.setType(w_name);
		player1.attack();
		std::cout << "---------------- " << std::endl;
	}
	{
		std::cout << "--- PLAYER 2 --- " << std::endl;
		std::string w_name = weapon_choice();
		Weapon	weapon = Weapon(w_name);
		std::string name = name_choice();
		HumanB player2(name);
		if (cruel_fate(w_name, name) == false) { player2.setWeapon(&weapon); };
		player2.attack();
		w_name = weapon_choice();
		if (cruel_fate(w_name, name) == false) { weapon.setType(w_name); };
		player2.attack();
		std::cout << "---------------- " << std::endl;
	}
	return (0);
}
