#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const& other);
		Point& operator=(Point const &other); 
		~Point();

	static Fixed getArea(Point a, Point b, Point c);
	static bool isVertex(Point a, Point b, Point c, Point p);

	Fixed getX();
	Fixed getY();
	bool operator==(Point& other);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif