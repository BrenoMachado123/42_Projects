#include "Form.hpp"

Form::Form() {}

Form::Form(const std::string name, const int grade_sign, const int grade_exec) : _name(name) {
	setGradeForm(grade_sign, grade_exec);
	_is_signed = false;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

Form::Form(const Form& other) { *this = other; }

Form::~Form() {}
