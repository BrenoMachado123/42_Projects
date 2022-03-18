#include "FlagTrap.hpp"

FlagTrap::FlagTrap() {
	_name = "Flagbot Defaultmont";
	std::cout << "FlagTrap Initialized" << std::endl;
}

FlagTrap::FlagTrap(std::string name) {
_name = name; _hitPoints=100; _energyPoints=100; _attackDamage=30;
	std::cout << "FlagTrap Initialized" << std::endl;
}

FlagTrap::FlagTrap(FlagTrap const& other) : ClapTrap(other) {}

FlagTrap& FlagTrap::operator=(FlagTrap const& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return(*this);
}

FlagTrap::~FlagTrap() {
	std::cout << "FlagTrap destroyed" << std::endl;
}

void	FlagTrap::highFivesGuys() {
	if (this->active()) {
		std::cout << "FlagCrap " << this->_name << " requests a high five! "
		<< std::endl;
		this->_attackDamage += 10;
		this->_energyPoints -= 20;
		this->active();
	}
}