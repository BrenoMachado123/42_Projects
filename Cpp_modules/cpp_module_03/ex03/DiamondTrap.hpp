#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FlagTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap {

private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string const name);
	~DiamondTrap();
    DiamondTrap (const DiamondTrap &diamondTrap);
    DiamondTrap & operator= (const DiamondTrap &diamondTrap);

	void WhoAmI();
	void attack(std::string const& target);
};

#endif
