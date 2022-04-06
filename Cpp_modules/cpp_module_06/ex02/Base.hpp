#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <ctime>
#include <stdexcept>

class Base {
	public:
		virtual ~Base() {}
	private:
};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif
