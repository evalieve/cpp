# include "Cat.hpp"

Cat::Cat() : _brain(new Brain()) {
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) : _brain(new Brain(*other._brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}

	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(const std::string& idea) {
	_brain->setIdea(idea);
}

void Cat::printIdeas() const {
	_brain->printIdeas();
}