# include "Bureaucrat.hpp"
# include "Color.hpp"

void testGradeMods(void (Bureaucrat::*func)(), Bureaucrat& obj) {
	try {
		std::cout << obj << " trying to " << (func == &Bureaucrat::incrementGrade ? "increment grade" : "decrement grade") << std::endl;
		(obj.*func)();
		std::cout << BLU + obj.getName() + NC + " has now a grade of " + YEL << obj.getGrade() << NC << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testInstances(const std::string& name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testConstructors() {
	Bureaucrat John;
	Bureaucrat Jack("Jack", 140);
	Bureaucrat Josh = Jack;

	John = Jack;
	std::cout << std::endl;
}

int main() {
	std::cout << std::endl << GRN ">--- Test Constructors ---<" NC << std::endl; 
	{
		testConstructors();
		std::cout << std::endl;
	}

	std::cout << std::endl << GRN ">--- Test Instances ---<" NC << std::endl;
	{
		testInstances("James", 1);
		std::cout << std::endl;
		
		testInstances("Jace", 150);
		std::cout << std::endl;
		
		testInstances("Jonah", 75);
		std::cout << std::endl;

		testInstances("Jacob", 0);
		std::cout << std::endl;

		testInstances("Jordan", 151);
		std::cout << std::endl;
	}

	std::cout << std::endl << GRN ">--- Test Grade Modifications ---<" NC << std::endl;
	{
		Bureaucrat TooHighJason("TooHighJason", 1);
		Bureaucrat TooLowJason("TooLowJason", 150);
		Bureaucrat OkJason("OkJason", 75);

		std::cout << std::endl;

		testGradeMods(&Bureaucrat::incrementGrade, TooHighJason);
		std::cout << std::endl;

		testGradeMods(&Bureaucrat::decrementGrade, TooLowJason);
		std::cout << std::endl;

		testGradeMods(&Bureaucrat::incrementGrade, OkJason);
		std::cout << std::endl;

		testGradeMods(&Bureaucrat::decrementGrade, OkJason);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}