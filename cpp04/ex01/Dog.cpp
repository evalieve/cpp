# include "Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other) : _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}

	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(const std::string& idea) {
	_brain->setIdea(idea);
}

void Dog::printIdeas() const {
	_brain->printIdeas();
}