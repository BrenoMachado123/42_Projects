#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_name) :  
_type(weapon_name) { std::cout << "Weapon class initialized" << std::endl; }
Weapon::~Weapon() { std::cout << "Weapon class destroyed" << std::endl; };

const std::string&	Weapon::getType() const { return (_type); }
void			Weapon::setType(std::string type) { this->_type = type; }
