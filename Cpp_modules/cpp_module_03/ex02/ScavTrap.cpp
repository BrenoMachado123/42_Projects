#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Initialized" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
_name = name; _hitPoints=100; _energyPoints=50; _attackDamage=20;
	std::cout << "ScavTrap Initialized" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other) {}

ScavTrap& ScavTrap::operator=(ScavTrap const& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return(*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destroyed" << std::endl;
}

void	ScavTrap::guardGate() {
	if (this->active()) {
		std::cout << "ScavCrap " << this->_name << " have enterred in Gate keeper mode!"
		<< std::endl;
		this->setDmg(0);
		this->_hitPoints += 50;
		this->_energyPoints -= 10;
		this->active();
	}
}
