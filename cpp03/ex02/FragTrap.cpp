# include "FragTrap.hpp"
# include "Color.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_HP = 100;
    this->_EP = 100;
    this->_AD = 30;
    
	std::cout << "FragTrap named " << BLU << this->_name << NC << " called the default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->_HP = 100;
    this->_EP = 100;
    this->_AD = 30;
   
    std::cout << "FragTrap named " << BLU << this->_name << NC << " called the constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap named " << BLU << this->_name << NC << " called the copy constructor to copy " << BLU << other._name << NC << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap named " << BLU << this->_name << NC << " called the copy assignment operator to copy " << BLU << other._name << NC << std::endl;
    if (this != &other)
		ClapTrap::operator=(other);

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap named " << BLU << this->_name << NC << " called the destructor" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << BLU << this->_name << NC << " hands out high-fives to everyone!" << std::endl;
}


