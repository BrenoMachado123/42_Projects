#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bureau1("Breno", 1);
	for (int i = 0; i < 150; i++) {std::cout << bureau1; bureau1++; }
	std::cout << "*********************************************************" << std::endl;
	for (int i = 150; i >= 0; i--) {std::cout << bureau1; bureau1--; }
	return (0);
}
