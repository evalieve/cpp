#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
	
	public:
		virtual ~Animal();

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif