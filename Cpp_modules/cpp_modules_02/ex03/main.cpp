#include "Point.hpp"
#include <iostream>

int main() {
	Point const a;
	Point const b(20, 0);
	Point const c(10.20f, 30);
	Point const p(10, 15.30f);

	if (bsp(a, b, c, p)) { 
		std::cout << "Point inside" << std::endl; 
	} else { std::cout << "Point not inside" << std::endl; } 
	return (0);
}