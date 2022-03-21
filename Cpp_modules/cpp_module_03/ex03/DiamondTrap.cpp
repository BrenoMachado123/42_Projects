#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Notton Claptrapiton") {
	std::cout << "DiamondTrap class Initialized" << std::endl;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name) {
	ClapTrap::_name = name + "_clap_trap";

	ScavTrap tmp_scav;
	FragTrap tmp_flag;

	_hitPoints= tmp_flag.getHp();
	_energyPoints= tmp_scav.getEnergy();
	_attackDamage = tmp_flag.getDmg();
	std::cout << "DiamondTrap class Initialized" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other) :
ClapTrap(other), ScavTrap(other), FragTrap(other) { *this=other;} 

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other) {
	ClapTrap::_name = other._name + "_clap_trap";
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return(*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap class Destroyed" << std::endl;
}

void	DiamondTrap::WhoAmI() {
	if (this->active()) {
		std::cout << "DiamondTrap " << this->_name << " reveals itself as " << ClapTrap::_name
		<< std::endl;
		this->_hitPoints -= 20;
		this->_energyPoints -= 1;
		this->_attackDamage += 20;
		this->active();
	}
}

void	DiamondTrap::attack(std::string const& target) { ScavTrap::attack(target); }
