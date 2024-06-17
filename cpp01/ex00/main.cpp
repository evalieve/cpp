# include "Zombie.hpp"

int main(void) {
	Zombie *heapZombie;

	std::cout << std::endl;

	heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << std::endl;

	randomChump("stackZombie");

	std::cout << std::endl;

	return (0);
}