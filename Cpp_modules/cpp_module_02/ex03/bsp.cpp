#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed At;
	At = Point::getArea(a, b, c);
	if (At == 0) { return false; }
	Fixed A1;
	A1 = Point::getArea(point, b, c);
	Fixed A2;
	A2 = Point::getArea(a, point, c);
	Fixed A3;
	A3 = Point::getArea(a, b, point);

	bool ret = Point::isVertex(a,b,c,point);
	return (ret && At == A1 + A2 + A3);
}

