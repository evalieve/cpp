# include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);

	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongMeow!" << std::endl;
}
