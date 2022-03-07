#include "zombie.hpp"

#ifndef HORDE_SIZE
# define HORDE_SIZE 8
#endif

int main() {
	Zombie	*zombiehorde;
	std::string name;

	std::cout << "|Zombies Horde name| " << std::endl;
	getline(std::cin >> std::ws, name);
	zombiehorde = Zombie::zombieHorde(HORDE_SIZE,name);
	for (int i; i < HORDE_SIZE; i++)
		zombiehorde->announce();
	delete[] zombiehorde;
	return (0);
}
