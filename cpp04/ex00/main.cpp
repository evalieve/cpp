# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main() {
	const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrongcat = new WrongCat();

	std::cout << std::endl;
    std::cout << animal->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wrongcat->getType() << " " << std::endl;

	std::cout << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    wrongcat->makeSound();
	
	std::cout << std::endl;
    delete animal;
    delete dog;
    delete cat;
    delete wrongcat;

	return 0;
}