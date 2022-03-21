#include "WrongDog.hpp"

WrongDog::WrongDog(){ this->_type = "WrongDog"; }

WrongDog::WrongDog(const WrongDog& other) { *this = other; }

WrongDog& WrongDog::operator=(const WrongDog& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongDog::~WrongDog(){}

void	WrongDog::makeSound() const { std::cout << "Oof!" << std::endl; }
