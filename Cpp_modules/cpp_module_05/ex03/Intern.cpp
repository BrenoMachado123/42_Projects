#include "Intern.hpp"

Intern::Intern() {
	_form[0] = &Intern::makeShruberry;
	_form[1] = &Intern::makeRobotomy;
	_form[2] = &Intern::makePardon;
}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		this->_form[0] = other._form[0];
		this->_form[1] = other._form[1];
		this->_form[2] = other._form[2];
	}
	return (*this);
}

Form*	Intern::makeForm(const std::string& request, const std::string& target) {
	std::string requestsList[3] = {
		"shrubbery request", "robotomy request", "pardon request"
	};
	for (int i = 0; i < 3; i++) {
		if (request == requestsList[i]) {
			Form* requestedForm = (this->*_form[i])(target);
			std::cout << "Intern creates " << requestedForm->getName() << std::endl;
			return (requestedForm);
 		}
	}
	std::cout << "Intern had one job and failed..." << std::endl;
	return (NULL);
}

Form* Intern::makeShruberry(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

Form* Intern::makePardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

Intern::~Intern() {}
