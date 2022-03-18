#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap {
	protected:
		ScavTrap();
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& other);
		~ScavTrap();
		ScavTrap& operator=(ScavTrap const& other);

		void guardGate();
		void attack(std::string const& target);


};

#endif