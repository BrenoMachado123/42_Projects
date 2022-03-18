#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		ScavTrap();
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& other);
		~ScavTrap();
		ScavTrap& operator=(ScavTrap const& other);

		void guardGate();


};

#endif