#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {
	private:
		std::string	_ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
};


#endif
