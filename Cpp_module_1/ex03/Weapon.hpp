#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	private:
		std::string _type;
	public:
					Weapon(std::string weapon_name);
					~Weapon();

		const std::string&	getType() const;
		void				setType(std::string type);
};

#endif
