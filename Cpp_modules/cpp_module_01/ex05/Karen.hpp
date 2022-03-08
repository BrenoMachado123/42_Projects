#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen {
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();
	public:
		Karen();
		~Karen();

		typedef void(Karen::*fcmds)(void);
		fcmds	karen_cmds[4];
		void	complain(std::string level);

};

#endif