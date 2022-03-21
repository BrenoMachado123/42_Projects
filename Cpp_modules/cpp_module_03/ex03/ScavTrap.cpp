#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints=100; _energyPoints=50; _attackDamage=20; _outOfGate=true;
	std::cout << "ScavTrap class Initialized" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints=100; _energyPoints=50; _attackDamage=20; _outOfGate=true;
	std::cout << "ScavTrap class Initialized" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other) { *this = other; }

ScavTrap& ScavTrap::operator=(ScavTrap const& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return(*this);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap class Destroyed" << std::endl; }

void	ScavTrap::guardGate() {
	if (this->active()) {
		if (this->_outOfGate) {
			std::cout << "ScavTrap " << this->_name << " has enterred in Gate keeper mode!"
			<< std::endl;
			this->setDmg(0); this->_hitPoints += 50; this->_energyPoints -= 10;
			this->_outOfGate = false;
			this->active();
		} else { 
			std::cout << "ScavTrap " << this->_name << " is already guarding the gate" << std::endl;
		}
	}
}

void	ScavTrap::attack(const std::string& target) {
	if (this->active()) {
		std::cout << "ScavTrap " << this->_name << " attacks " 
		<< target << ", causing " << this->_attackDamage 
		<< " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}
