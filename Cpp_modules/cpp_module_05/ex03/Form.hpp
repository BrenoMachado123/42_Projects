#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form {
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;
	public:
		Form();
		Form(const std::string& name, const int gradeSign, const int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();

		int setGradeToSign(const int grade);
		int setGradeToExec(const int grade);

		std::string 	getName() const;
		std::string 	getSign() const;
		int				getGradeToSign() const;
		int 			getGradeToExec() const;

		void			beSigned(Bureaucrat& bureau);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		void		execute(const Bureaucrat& executor) const;
		virtual void start() const = 0;

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif
