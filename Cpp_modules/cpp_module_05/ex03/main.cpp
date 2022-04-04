#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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
		ShrubberyCreationForm test("Evil guy");

		breno.signForm(test);
		breno.executeForm(test);
		std::cout << "-----------------------------" << std:: endl;
		std::cout << std::endl;
	}
	{
		std::cout << "------------- TEST 3 ----------------" << std:: endl;
		Bureaucrat breno("Breno", 1);
		RobotomyRequestForm test("ClapTrap");

		breno.signForm(test);
		breno.executeForm(test);
		std::cout << "-----------------------------" << std:: endl;
		std::cout << std::endl;

	}
	{
		std::cout << "------------- TEST 3 ----------------" << std:: endl;
		Intern Jimmy;
		Form* Formulary;

		Formulary = Jimmy.makeForm("robotomy request", "Bender");

		Bureaucrat breno("Breno", 1);
		breno.signForm(*Formulary);
		breno.executeForm(*Formulary);

		delete Formulary;
		std::cout << "-----------------------------" << std:: endl;
	}
	return (0);
}
