#include "Form.hpp"

Form::Form() : _name("file"), _gradeToSign(100), _gradeToExec(100) { _signed = false; }

Form::Form(const std::string& name, const int grade_sign, const int grade_exec) : 
	_name(name), 
	_gradeToSign(setGradeToSign(grade_sign)), 
	_gradeToExec(setGradeToExec(grade_exec)) { 
		_signed = false; 
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		(std::string&)this->_name = other._name;
		(int&)this->_gradeToSign = other._gradeToSign;
		(int&)this->_gradeToExec = other._gradeToExec;
		this->_signed = other._signed;
	}
	return (*this);
}

Form::Form(const Form& other) :
	_name(other.getName()),
	_gradeToSign(other.getGradeToSign()),
   	_gradeToExec(other.getGradeToExec()) { 
		*this = other;
}

std::string Form::getName() const { return (this->_name); }
int Form::getGradeToSign() const { return (this->_gradeToSign); } 
int Form::getGradeToExec() const { return (this->_gradeToExec); } 
std::string Form::getSign() const { 
	if (this->_signed) { return ("Yes"); }
	return ("No");
} 


std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << "-----------------------------------" << std::endl;
	out << "Form: " << obj.getName() << std::endl;
	out << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	out << "Grade to execute: " << obj.getGradeToExec() << std::endl;
	out << "Form: " << obj.getSign() << std::endl;
	out << "-----------------------------------" << std::endl;
	return (out);
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return "<error: Form grade too high>";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "<error: Form grade too low>";
}

int Form::setGradeToSign(const int grade) {
	try {
		if (grade < 1) { throw GradeTooHighException(); }
		else if (grade > 150) { throw  GradeTooLowException(); }
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	(int&)this->_gradeToSign = grade;
	return (this->_gradeToSign);
}

int Form::setGradeToExec(const int grade) {
	try {
		if (grade < 1) { throw GradeTooHighException(); }
		else if (grade > 150) { throw  GradeTooLowException(); }
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	(int&)this->_gradeToExec = grade; 
	return (this->_gradeToExec);
}

bool	Form::beSigned(Bureaucrat& bureau) {
	if (bureau.getGrade() > 150) { throw GradeTooLowException(); }
	else if (bureau.getGrade() < 1) { throw GradeTooHighException(); } 
	else if  (bureau.getGrade() <= this->_gradeToSign) { this->_signed = true; } 
	return (this->_signed);
}

void	Form::start() const { return ; };

void	Form::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > 150) { throw GradeTooLowException(); }
	else if (executor.getGrade() < 1) { throw GradeTooHighException(); } 
	else if  (executor.getGrade() <= this->_gradeToSign && executor.getGrade() <= this->_gradeToExec) { this->start(); }  

}
