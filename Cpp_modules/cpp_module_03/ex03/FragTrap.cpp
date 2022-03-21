#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	_hitPoints=100; _energyPoints=100; _attackDamage=30;
	std::cout << "FragTrap class Initialized" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints=100; _energyPoints=100; _attackDamage=30;
	std::cout << "FragTrap class Initialized" << std::endl;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other) {}

FragTrap& FragTrap::operator=(FragTrap const& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return(*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap class Destroyed" << std::endl;
}

void	FragTrap::highFivesGuys() {
	if (this->active()) {
		std::cout << "FlagCrap " << this->_name << " requests a high five! "
		<< std::endl;
		this->_attackDamage += 15;
		this->_energyPoints -= 30;
		this->active();
	}
}
