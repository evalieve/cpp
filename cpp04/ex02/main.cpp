# include "Cat.hpp"
# include "Dog.hpp"


int main() {
	const int numAnimals = 4;
    Animal* animals[numAnimals];

    // Fill half of the array with Dog objects and the other half with Cat objects
    std::cout << std::endl;
	for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
		std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
		std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test deep copy
    Dog dog1;
    dog1.setIdea("Chase the mailman");
    dog1.setIdea("Bark at strangers");
    dog1.setIdea("Dig a hole");

    Dog dog2 = dog1; // Copy constructor
    std::cout << std::endl;
    dog2.printIdeas(); // Should print "Chase the mailman", "Bark at strangers", "Dig a hole"
    std::cout << std::endl;

    Cat cat1;
    cat1.setIdea("Catch the mouse");
    cat1.setIdea("Climb the tree");
    cat1.setIdea("Scratch the sofa");

    Cat cat2 = cat1; // Copy constructor
    std::cout << std::endl;
    cat2.printIdeas(); // Should print "Catch the mouse", "Climb the tree", "Scratch the sofa"
    std::cout << std::endl;

    // Call makeSound for each animal
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }
    std::cout << std::endl;

    // Delete animals
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
		std::cout << std::endl;
    }

    return 0;
}