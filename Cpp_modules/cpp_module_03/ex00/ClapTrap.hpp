#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& other);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap const& other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int			getDmg();
		std::string	getName();
		bool		active();
		void		setHP(unsigned int amount);
		void		setEnergy(unsigned int amount);
		void		setDmg(unsigned int amount);
		void		setName(std::string name);
};

#endif