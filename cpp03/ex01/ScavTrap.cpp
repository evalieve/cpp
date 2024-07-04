# include "ScavTrap.hpp"
# include "Color.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_HP = 100;
    this->_EP = 50;
    this->_AD = 20;
    std::cout << "ScavTrap named " << BLU << this->_name << NC << " called the default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->_HP = 100;
    this->_EP = 50;
    this->_AD = 20;
    std::cout << "ScavTrap named " << BLU << this->_name << NC << " called the constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap named " << BLU << this->_name << NC << " called the copy constructor to copy " << BLU << other._name << NC << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap named " << BLU << this->_name << NC << " called the copy assignment operator to copy " << BLU << other._name << NC << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	
	return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap named " << BLU << this->_name << NC << " called the destructor" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (!this->canPerformAction("attack"))
		return ;
	
	this->_EP--;

    std::cout << "ScavTrap " << BLU << this->_name << NC << " attacks " << YEL << target << NC << " causing it to lose " << RED << this->_AD << NC << " hit points!" << std::endl;
    std::cout << "ScavTrap " << BLU << this->_name << NC << " has " << RED << this->_EP << NC << " energy points left" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << BLU << this->_name << NC << " is now in Gate keeper mode!" << std::endl;
}
