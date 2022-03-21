#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){}

WrongAnimal::WrongAnimal(const WrongAnimal& other) { *this = other; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(){}

void	WrongAnimal::makeSound() const { std::cout << "BrainzzzZZZ" << std::endl; }

std::string	WrongAnimal::getType() const { return(this->_type); }

