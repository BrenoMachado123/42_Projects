# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :  Form("PresidentialPardonFormulary", 25, 5), _target("42 Lisboa") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("PresidentialPardonFormulary", 72, 45), _target(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		(std::string&)this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other) { *this = other; };

void	PresidentialPardonForm::start() const { std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm() {}
