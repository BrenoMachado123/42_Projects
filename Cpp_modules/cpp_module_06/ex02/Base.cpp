#include "Base.hpp"
#include "Childs.hpp"
#include <cstdlib>

//identify a reference to a type of Base (A, B or C)
void identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Reference to A found" << std::endl;
		return ;
	} catch (std::exception & e) {
		std::cout << e.what() << " : No reference to A" << std::endl;
	} try {
		(void)dynamic_cast<B &>(p);
		std::cout << "Reference to B found" << std::endl;
		return ;
	} catch (std::exception & e) {
		std::cout << e.what() << " : No reference to B" << std::endl;
	} try {
		(void)dynamic_cast<C &>(p);
		std::cout << "Reference to C found" << std::endl;
		return ;
	} catch (std::exception & e) {
		std::cout << e.what() << " : No reference to C" << std::endl;
	}
	//if it reached at this point, that means that wasn't able to identify the type
	std::cout << "No able to identify <reference>" << std::endl;
}

//identify the type of Base(A, B or C) using dynamic cast:
void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) { std::cout << "A found" << std::endl; }
	else if (dynamic_cast<B*>(p)) { std::cout << "B found" << std::endl; }
	else if (dynamic_cast<C*>(p)) { std::cout << "C found" << std::endl; }
	else { std::cout << "Not able to idenitfy <type>" << std::endl; }
}

Base* generate() {
	Base *ptr = NULL;
	srand((unsigned int)time(NULL));
	int n = rand() % 3; // create a random number between 0 and 3
	switch (n) {
		case 0: ptr = new A();
			break ; // create a class pointer;
		case 1: ptr = new B();
			break ;
		case 2: ptr = new C();
			break;
	}
	return (ptr); // return the pointer;
}
