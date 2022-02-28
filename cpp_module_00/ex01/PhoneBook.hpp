#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	public:
		void		add();
		void		search();
		void		print_phonebook();
		void		init();
	private:
		Contact		_contact_lst[8];
		static int	_index;
};

#endif

