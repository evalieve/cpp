# include "ClapTrap.hpp"
# include "Color.hpp"

ClapTrap::ClapTrap() : _name("DefaultClap"), _HP(10), _EP(10), _AD(0) {
	std::cout << "ClapTrap named " << BLU << this->_name << NC << " called the default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AD(0) {
	std::cout << "ClapTrap named " << BLU << this->_name << NC << " called the constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _HP(other._HP), _EP(other._EP), _AD(other._AD) {
		std::cout << "ClapTrap named " << BLU << this->_name << NC << " called the copy constructor to copy " << BLU << other._name << NC << std::endl;

}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap named " << BLU << this->_name << NC << " called the copy assignment operator to copy " << BLU << other._name << NC << std::endl;

	if (this != &other) {
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_AD = other._AD;
	}

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap named " << BLU << this->_name << NC << " called the destructor" << std::endl;
}

bool ClapTrap::canPerformAction(const std::string action) const {
	if (this->_EP == 0) {
		std::cout << BLU << this->_name << MAG << " is too tired to " << action << "!" << NC << std::endl;
		return false;
	}
	if (this->_HP == 0) {
		std::cout << BLU <<this->_name << MAG << " is dead and cannot " << action << "!" << NC << std::endl;
		return false;
	}

	return true;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->canPerformAction("attack"))
		return ;

	this->_EP--;

	std::cout << BLU << this->_name << NC << " attacks " << YEL << target << NC <<" causing it to lose " << RED << this->_AD << NC << " hit points!" << std::endl;
	std::cout << BLU << this->_name << NC << " has " << RED << this->_EP << NC << " energy points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->canPerformAction("take damage"))
		return ;
	
	this->_HP = (this->_HP < (int)amount) ? 0 : this->_HP - amount;

	std::cout << BLU << this->_name << NC << " took " << RED << amount << NC << " hit points damage" << std::endl;
	
	if (this->_HP == 0)
		std::cout << BLU << this->_name << MAG << " died!" << NC << std::endl;
	else
		std::cout << BLU << this->_name << NC << " has " << RED << this->_HP << NC << " hit points left" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->canPerformAction("be repaired"))
			return ;

	this->_EP--;
	
	this->_HP = (this->_HP + amount > 10) ? 10 : this->_HP + amount;

	std::cout << BLU << this->_name << NC << " repaired itself with " << RED << amount << NC << " hit points ";
	if (this->_HP == 10)
		std::cout << "back to his maximum health of " << RED << "10" << NC << " hit points!" << std::endl;
	else
		std::cout << "to a total of " << RED << this->_HP << NC << " hit points!" << std::endl;
	
	std::cout << BLU << this->_name << NC << " has " << RED << this->_EP << NC << " energy points left" << std::endl;
}