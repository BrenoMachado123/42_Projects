#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	{
		Bureaucrat bureau("Breno", 90);
		Form form("The boring big monday's paperwork", 20, 30);

		std::cout << bureau;
		std::cout << form;
		bureau.signForm(form);
		std::cout << form;
	}
	{
		Bureaucrat bureau("Onerb", 10);
		Form form("The nice small friday's paperwork", 20, 30);
		std::cout << bureau;
		std::cout << form;
		bureau.signForm(form);
		std::cout << form;
	}
	{
		try {
			Bureaucrat bureau("Bob, the All-Loser", 150);
			Form form("The whatever medium rest of days's paperwork", -1, 100);
		} catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}
	{
		try {
			Bureaucrat bureau("Dob, the other All-Loser", 150);
			Form form("The whatever medium rest of days's paperwork", 100, 3213112);
		} catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}
	return (0);
}
