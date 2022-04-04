#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		typedef Form* (Intern::*formularies)(const std::string& target);
		formularies	_form[3];
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		Form* makeForm(const std::string& request, const std::string& target);
		Form* makeShruberry(const std::string& target);
		Form* makeRobotomy(const std::string& target);
		Form* makePardon(const std::string& target);
};

#endif
