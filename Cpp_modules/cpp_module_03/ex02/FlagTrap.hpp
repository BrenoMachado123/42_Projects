#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap: public ClapTrap {
	private:
		FlagTrap();
	public:
		FlagTrap(std::string name);
		FlagTrap(FlagTrap const& other);
		~FlagTrap();
		FlagTrap& operator=(FlagTrap const& other);

		void highFivesGuys();


};

#endif