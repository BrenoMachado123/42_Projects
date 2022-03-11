#include "Fixed.hpp"

Fixed::Fixed() {
	this->_Integer = 0;
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int Constructor called" << std::endl;
	this->_Integer = n << this->_cInteger;
}

Fixed::Fixed(const float n) {
	std::cout << "Float Constructor called" << std::endl;
	this->_Integer = (int)(roundf(n * (1 << this->_cInteger)));
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

int Fixed::toInt() const {return(this->_Integer >> this->_cInteger);}

float Fixed::toFloat() const {
	return ((float)this->_Integer / (float)(1 << this->_cInteger));
}

std::ostream &operator<<(std::ostream& os, const Fixed& construct){
	os << construct.toFloat();
	return (os);
}