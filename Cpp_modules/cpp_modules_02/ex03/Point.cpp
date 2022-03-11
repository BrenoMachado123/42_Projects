#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : 
_x(x), _y(y) {}

Point& Point::operator=(Point const &other) {
	_x = other._x;
	_y = other._y;
	return (*this);
}

Point::Point(Point const& other) {*this = other;}

Fixed Point::getX() { return (this->_x); }
Fixed Point::getY() { return (this->_y); }

bool Point::operator==(Point& other) {
	return (this->_x == other._x && this->_y == other._y);
}

Point::~Point(){}

bool Point::isVertex(Point a, Point b, Point c, Point p) {
	if (p == a || p == b || p == c) { return false; }
	return (true);
}

Fixed Point::getArea(Point a, Point b, Point c) {
	Fixed side1;
	Fixed side2;
	Fixed side3;
	Fixed res;

	side1 = a.getX() * (b.getY() - c.getY());
	side2 = b.getX() * (c.getY() - a.getY());
	side3 = c.getX() * (a.getY() - b.getY());
	res = (side1 + side2 + side3)/2;
	if (res < 0) { res = res * -1; }
	return (res);
}