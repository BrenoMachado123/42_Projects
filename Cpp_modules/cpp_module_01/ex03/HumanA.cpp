#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
	_name(name),
	_weapon(weapon) {
	std::cout << "Human " << this->_name 
		<< " joins the battle with a " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA() { 
	std::cout << "Human " << this->_name << " fell in battle" << std::endl;
}

void	HumanA::attack() const {
	std::cout << "Human " << this->_name << " attacks using " 
	<< this->_weapon.getType() << std::endl; 
}
