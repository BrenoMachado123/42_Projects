#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : 
_name(name) {
	try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw  GradeTooLowException();
		else
			_grade = grade;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int) {
	this->_grade -= 1;
	this->setGrade(this->_grade);
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int) {
	this->_grade += 1;
	this->setGrade(this->_grade);
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) { *this = other; }

Bureaucrat::~Bureaucrat() {}

std::string		Bureaucrat::getName() const { return(this->_name); }
int	Bureaucrat::getGrade() const { return(this->_grade); }

void Bureaucrat::setGrade(int grade) { 
		try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw  GradeTooLowException();
		else
			this->_grade = grade;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { 
	return "<error: Grade too high>";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() { 
	return "<error: Grade too low>";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}

