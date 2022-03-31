#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat breno("Breno", 1);
	ShrubberyCreationForm test;
	test.execute(breno);
	return (0);
}
