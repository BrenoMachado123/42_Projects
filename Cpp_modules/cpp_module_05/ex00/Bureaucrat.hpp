#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
	private:
		std::string			_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const& name,  int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		Bureaucrat operator--(int);
		Bureaucrat operator++(int);
		~Bureaucrat();

		std::string		getName() const;
		int				getGrade() const;
		void			setGrade( int grade);

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
