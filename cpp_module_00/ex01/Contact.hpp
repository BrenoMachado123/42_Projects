#ifndef	CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	public:
		void	create();
		void	print_basic(int index);
		void	info();
	private:
		std::string	_fname;
		std::string	_lname;
		std::string	_nick;
		std::string	_nphone;
		std::string	_ds;
};

#endif
