# include "Zombie.hpp"

int main(void) {
	Zombie	*arrayZombies;
	int		N = 6;

	arrayZombies = zombieHorde(N, "zombieHorde");
	
	std::cout << std::endl;

	for (int i = 0; i < N; i++)
		arrayZombies[i].announce();
	
	std::cout << std::endl;

	delete []arrayZombies;
	
	std::cout << std::endl;

	return 0;
}