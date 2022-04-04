#include "Bureaucrat.hpp"

int main() {
	{
		Bureaucrat bureau1("Breno", 1);
		std::cout << bureau1;
	}
	{
		try {
			Bureaucrat bureau1("Breno", 723897139);
		} catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}
	{
		try {
			Bureaucrat bureau1("Breno", -313);
		} catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}
	return (0);
}
