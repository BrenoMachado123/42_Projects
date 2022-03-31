# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :  Form("ShruberryCreationFormulary", 145, 137), _target("42 Lisboa") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShruberryCreationFormulary", 145, 137), _target(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		(std::string&)this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other) {};

void	ShrubberyCreationForm::start() const {
	std::ofstream output;
	output.open(this->_target + "_shrubbery", std::ios::out);
	if (!output.is_open()) { return ; }

	output << "    ccae88oo" << std::endl;
  	output << "C8O8O8Q8PoOb#o8oo" << std::endl;
 	output <<  " dOB@9Q@8PdUOpugoO9bD" << std::endl;
	output << " C@ggbU@OU#@Op#qOdoUOdcb" << std::endl;
	output << " 6OuU@@/p@@u@@gcoUodpP " << std::endl;
	output << "  {21a12 /douUP" << std::endl;
	output <<  "     {||////}	  " << std::endl;
	output <<  "      {||//}		  " << std::endl;
	output <<  "       {|||}        " << std::endl;
	output <<  "       {|||}        " << std::endl;
	output <<  ".....//||||\\\\....  " << std::endl;
	output.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
