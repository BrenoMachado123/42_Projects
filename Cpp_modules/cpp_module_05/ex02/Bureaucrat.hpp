#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string			_name;
		unsigned int				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const& name,  int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&		setGrade( int grade);
		Bureaucrat& operator=(const Bureaucrat& other);
		Bureaucrat operator--(int);
		Bureaucrat operator++(int);
		~Bureaucrat();

		void	signForm(Form& form);

		std::string		getName() const;
		int				getGrade() const;

		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
