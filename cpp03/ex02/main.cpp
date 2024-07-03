#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    ClapTrap Clap("Clap");
    ClapTrap Trap("Trap");
    ClapTrap copyTrap;

    copyTrap = Trap;

    std::cout << std::endl;

    Clap.attack("Trap");
    std::cout << std::endl;

    Trap.takeDamage(0);
    std::cout << std::endl;

    Trap.takeDamage(8);
    std::cout << std::endl;

    Trap.beRepaired(410);
    std::cout << std::endl;

    Trap.takeDamage(10);
    std::cout << std::endl;

    Trap.attack("Clap");
    std::cout << std::endl;

    copyTrap.attack("Clap");
    std::cout << std::endl;

    Clap.takeDamage(5);
    std::cout << std::endl;

    std::cout << std::endl;

    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);
    Clap.beRepaired(1);

    std::cout << std::endl;

    ScavTrap scav("Scav");
    scav.attack("Clap"); // This will call ScavTrap::attack
    scav.guardGate();
    scav.takeDamage(50);
    scav.beRepaired(30);

    std::cout << std::endl;

    FragTrap frag("Frag");
    frag.attack("Clap"); // This will call FragTrap::attack
    frag.highFivesGuys();
    frag.takeDamage(70);
    frag.beRepaired(40);

    std::cout << std::endl;

    return 0;
}
