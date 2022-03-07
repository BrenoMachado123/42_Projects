#include "zombie.hpp"

void	Zombie::randomChump(std::string name) {
	Zombie randomZombie;
	randomZombie.setZombieName(name);
	randomZombie.announce();
}
