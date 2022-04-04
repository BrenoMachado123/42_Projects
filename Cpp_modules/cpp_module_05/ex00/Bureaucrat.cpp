#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : 
_name(name) { setGrade(grade); }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		(std::string&)this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int) {
	this->_grade += 1;
	return (setGrade(this->_grade));
}

Bureaucrat Bureaucrat::operator++(int) {
	this->_grade -= 1;
	return (setGrade(this->_grade));
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) { *this = other; }

Bureaucrat::~Bureaucrat() {}

std::string		Bureaucrat::getName() const { return(this->_name); }
int	Bureaucrat::getGrade() const { return(this->_grade); }

Bureaucrat& Bureaucrat::setGrade(int grade) {
	if (grade < 1) { throw GradeTooHighException(); }
	else if (grade > 150) { throw GradeTooLowException(); }
	this->_grade = grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { 
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() { 
	return "grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}

