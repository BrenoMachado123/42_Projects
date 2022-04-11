#include "Easyfind.hpp"
#include <iostream>
#include <vector>

int 	main() {
	std::vector<int> v1;

	for (int x = 0; x < 10; x+=2) { v1.push_back(x); }
	try {
		std::vector<int>::iterator x = ::easyfind(v1, 7);
		std::cout << "Ocurrence found : "<< *x << std::endl;
	} catch(int err) {
		std::cout << "easyfind::error  <" << err << ">::elementNotFound" << std::endl;
	}
	return (0);
}
