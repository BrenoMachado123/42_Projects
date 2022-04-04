# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :  Form("RobotomyRequestFormulary", 72, 45), _target("42 Lisboa") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestFormulary", 72, 45), _target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		(std::string&)this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other) { *this = other; }

void	RobotomyRequestForm::start() const {
	std::cout << "brzzzzz brzzzz brzzzzzZZZZ" << std::endl;
	srand((unsigned int)time(NULL));
	if (rand() % 2) { 
		std::cout << "< " << this->_target << " was robotomized with success >" << std::endl;
	} else {
		std::cout << "<" << this->_target << " robotomize process failed > " << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {}
