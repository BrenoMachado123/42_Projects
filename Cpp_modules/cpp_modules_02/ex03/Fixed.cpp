#include "Fixed.hpp"

Fixed::Fixed() {
	this->_Bits = 0;
}

Fixed::Fixed(const int n) {
	this->_Bits = n << this->_cBits;
}

Fixed::Fixed(const float n) {
	this->_Bits = (int)(roundf(n * (1 << this->_cBits)));
}

Fixed::Fixed(Fixed const &other) {
	*this = other;
}

Fixed &Fixed::operator=(Fixed const &other) {
	this->_Bits = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &other) {
	return (this->_Bits > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) {
	return (this->_Bits < other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) {
	return (this->_Bits <= other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) {
	return (this->_Bits >= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) {
	return (this->_Bits == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) {
	return (this->_Bits != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other) {
	Fixed res = Fixed();
	res.setRawBits(this->_Bits + other.getRawBits());
	return (res);
}

Fixed Fixed::operator-(Fixed const &other) {
	Fixed res = Fixed();
	res.setRawBits(this->_Bits - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(Fixed const &other) {
	Fixed res = Fixed(this->toFloat() * other.toFloat());
	return (res);
}

Fixed Fixed::operator/(Fixed const &other) {
	Fixed res = Fixed(this->toFloat() / other.toFloat());
	return (res);
}

Fixed Fixed::operator++() {
	Fixed res;
	res.setRawBits(++this->_Bits);
	return (res);
}

Fixed Fixed::operator++(int) {
	Fixed res;
	res.setRawBits(this->_Bits++);
	return (res);
}

Fixed Fixed::operator--() {
	Fixed res;
	res.setRawBits(--this->_Bits);
	return (res);
}

Fixed Fixed::operator--(int) {
	Fixed res;
	res.setRawBits(this->_Bits--);
	return (res);
}

Fixed& Fixed::min(Fixed& objA, Fixed& objB) {
	if (objA < objB) { return objA; }
	return (objB);
}

Fixed const& Fixed::min(Fixed const& objA, Fixed const& objB) {
	if ((Fixed&)objA < objB) { return objA; }
	return (objB);
}

Fixed& Fixed::max(Fixed& objA, Fixed& objB) {
	if (objA > objB) { return objA; }
	return (objB);
}

Fixed const& Fixed::max(Fixed const& objA, Fixed const& objB) {
	if ((Fixed&)objA > objB) { return objA; }
	return (objB);
}

Fixed::~Fixed() {
}

int	Fixed::getRawBits() const {
	return (this->_Bits);
}

void	Fixed::setRawBits(int const raw) { this->_Bits = raw; }

int Fixed::toInt() const {return(this->_Bits >> this->_cBits);}

float Fixed::toFloat() const {
	return ((float)this->_Bits / (float)(1 << this->_cBits));
}

std::ostream &operator<<(std::ostream& os, const Fixed& construct){
	os << construct.toFloat();
	return (os);
}