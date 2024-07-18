# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base* generate(void)
{
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "A"  << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout <<  "B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "C" << std::endl;
		return (new C);
	}
}

void identify(Base* p) {
 // prints the actual type of the object pointed to by p: "A", "B" or "C".
}

void identify(Base& p) {
 // prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden
}