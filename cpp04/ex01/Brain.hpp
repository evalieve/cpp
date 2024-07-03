#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define SIZE 100

class Brain {
	private:
		std::string _ideas[SIZE];
		int _ideaCount;

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void setIdea(const std::string& idea);
		void printIdeas();
};

#endif