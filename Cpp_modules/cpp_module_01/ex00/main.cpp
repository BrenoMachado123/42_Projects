#include "zombie.hpp"

int main() {
	Zombie	*alloc_zombie;
	Zombie	normalZombie;
	std::string name;

	std::cout << "|Heap Zombie name| " << std::endl;
	getline(std::cin >> std::ws, name);
	alloc_zombie = Zombie::newZombie(name);
	alloc_zombie->announce();
	//empty zombie test:
	normalZombie.announce();
	std::cout << "|Stack Zombie name| " << std::endl;
	getline(std::cin >> std::ws, name);
	Zombie::randomChump(name);
	delete alloc_zombie;
	return (0);
}
