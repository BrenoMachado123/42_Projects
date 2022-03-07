#include "zombie.hpp"

Zombie::Zombie() {
	std::cout << "A might Zombie stands for the brains!" << std::endl;
}

Zombie::~Zombie() {
	if (this->_name.length() == 0) { std::cout << "The might....who died for the brains?" << std::endl; }
	else
		std::cout << "The might Zombie " << this->_name << " died for the brains!" << std::endl;
}

void	Zombie::announce() {
	if (this->_name.length() == 0) {
		std::cout << "Unnamed easily forgotten zombie: BraiiiiiinnnnzzZ..." << std::endl;
	}
	else
		std::cout << this->_name << ": BraiiiiiinnnnzzZ..." << std::endl;
}

void	Zombie::setZombieName(std::string name) { this->_name = name; }
