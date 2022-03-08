#include "Fixed.hpp"

Fixed::Fixed() {
	this->_Integer = 0;
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& Construct) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = Construct;
}

Fixed &Fixed::operator=(Fixed const &Construct) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_Integer = Construct.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_Integer);
}

void	Fixed::setRawBits(int const raw) { this->_Integer = raw; }