# include "Brain.hpp"

Brain::Brain() : _ideaCount(0) {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) : _ideaCount(other._ideaCount) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < SIZE; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assigment operator called" << std::endl;
	if (this != &other) {
		this->_ideaCount = other._ideaCount;
		for (int i = 0; i < SIZE; i++)
			this->_ideas[i] = other._ideas[i];
	}

	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(const std::string &idea) {
	this->_ideas[this->_ideaCount] = idea;
	this->_ideaCount = (this->_ideaCount + 1) % 100;
}

void Brain::printIdeas() {
	std::cout << "Ideas in Brain:" << std::endl;
	for (int i = 0; i < this->_ideaCount; ++i)
		std::cout << "Idea " << i << ": " << this->_ideas[i] << std::endl;
}