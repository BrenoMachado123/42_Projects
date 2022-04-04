#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	{
		std::cout << "------------- TEST 1 ----------------" << std:: endl;
		Bureaucrat breno("Breno", 1);
		PresidentialPardonForm test("House");

		breno.signForm(test);
		breno.executeForm(test);
		std::cout << "-----------------------------" << std:: endl;
		std::cout << std::endl;
	}
	{
		std::cout << "------------- TEST 2 ----------------" << std:: endl;
		Bureaucrat breno("Breno", 150);
		ShrubberyCreationForm test("Evil City");

		breno.signForm(test);
		breno.executeForm(test);
		std::cout << "-----------------------------" << std:: endl;
		std::cout << std::endl;

	}
	{
		std::cout << "------------- TEST 3 ----------------" << std:: endl;
		Bureaucrat breno("Breno", 1);
		RobotomyRequestForm test("Factory");

		breno.signForm(test);
		breno.executeForm(test);
		std::cout << "-----------------------------" << std:: endl;
	}
	return (0);
}
