#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon) :
_name(name), _weapon(weapon) {
	std::cout << "Human " << this->_name 
	<< " joins the battle using ";
	if (this->_weapon) { std::cout << this->_weapon << std::endl; }
	else { std::cout << " their... fists? lol" << std::endl; }
}

HumanB::~HumanB() {
	if (this->_weapon) {
		std::cout << "Human " << this->_name 
		<< " fell in battle" << std::endl; 
	} else {
		std::cout << "Human " << this->_name 
		<< " didn't last one second in battle. Bring a weapon next time!"
		<< std::endl;
	}
}

void	HumanB::setWeapon(Weapon *weapon) { this->_weapon = weapon; }

void	HumanB::attack() const {
	if (this->_weapon) {
		std::cout << this->_name 
		<< " attacks with their weapon " << this->_weapon->getType() 
		<< std::endl;
	} else {
		std::cout << this->_name 
		<< " runs beserk with their might barefists..." << std::endl;
	}
}
