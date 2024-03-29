#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
_name("Clapbot Defaultmont"), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
	std::cout << "ClapTrap class Initialized" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap class Initialized" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other){*this=other;}

ClapTrap& ClapTrap::operator=(ClapTrap const& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return(*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap class Destroyed" << std::endl;
}

int		ClapTrap::getDmg() { return (this->_attackDamage); }
int		ClapTrap::getHp() { return (this->_hitPoints); }
int		ClapTrap::getEnergy() { return (this->_energyPoints); }

std::string ClapTrap::getName() { return (this->_name); }

void	ClapTrap::setHP(unsigned int amount) { this->_hitPoints = amount; }
void	ClapTrap::setEnergy(unsigned int amount) { this->_energyPoints = amount; }
void 	ClapTrap::setDmg(unsigned int amount) { this->_attackDamage = amount; }
void	ClapTrap::setName(std::string name) { this->_name = name; }

bool	ClapTrap::active(int takingDmg) {
	bool ret = true;
	if (!this->_hitPoints) {
		if (takingDmg) { std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl; }
		else { std::cout << "ClapTrap " << this->_name << " unable to do any actions because is destroyed!" << std::endl; }
		ret =  false;
	} else if (!this->_energyPoints && !takingDmg) {
		std::cout << "ClapTrap " << this->_name << " unable to do any actions because is without energy!" << std::endl;
		ret = false;
	} else {
		std::cout << "----------- STATUS --------------" << std::endl;
		std::cout << "ClapTrap: " << this->_name << std::endl;
		std::cout << "HP: " << this->_hitPoints << std::endl;
		std::cout << "Energy: " << this->_energyPoints << std::endl;
		std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << std::endl;
	}
	return ret;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->active()) {
		std::cout << "Claptrap " << this->_name << " attacks " 
		<< target << ", causing " << this->_attackDamage 
		<< " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
		if (this->_hitPoints) { this->active(1); }
		this->_hitPoints -= amount;
		int hp = this->_hitPoints;
		if (hp < 0) { this->_hitPoints = 0; }
		if (this->active(1)) {
			std::cout << "ClapTrap " << this->_name << " has taken " 
			<< amount << " of damage!" << std::endl;
		}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->active()) {
		std::cout << "ClapTrap " << this->_name << " repaired itself "
		"receiving " << amount << " of HP!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
		this->active();
	}
}
