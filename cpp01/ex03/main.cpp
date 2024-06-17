# include "HumanA.hpp"
# include "HumanB.hpp"

int main(void) {

	Weapon club = Weapon("crude spiked club");

	std::cout << std::endl;

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	club.setType("crude spiked club");
	std::cout << std::endl;

	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

	std::cout << std::endl;

	return 0; 
}