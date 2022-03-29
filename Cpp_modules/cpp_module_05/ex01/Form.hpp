#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form : public Bureaucrat {
	private:
		const std::string	_name;
		const int			_grade_sign;
		const int			_grade_exec;
		bool				_is_signed;
	public:
		Form();
		Form(const std::string& name, const int grade, bool _is_signed);
		Form(const Form& other);
		Form& setGradeForm(const int grade_sign, const int grade_exec)
		~Form();

		bool				beSigned();
		void				signForm();

};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif
