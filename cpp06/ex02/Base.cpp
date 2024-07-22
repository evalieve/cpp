# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Color.hpp"

Base* generate(void)
{
	// casting time(0) from time_t which usually is a long int to unsigned int
	srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;

    if (random == 0) {
		std::cout << "Object generated of type: " YEL "A" NC << std::endl;
        return new A();
	}
    else if (random == 1) {
		std::cout << "Object generated of type: " YEL "B" NC << std::endl;
        return new B();
	}
    else {
		std::cout << "Object generated of type: " YEL "C" NC << std::endl;
        return new C();
	}
}


void identify(Base* p) {
	A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);

    if (a) std::cout << "Object is of type: " YEL "A" NC << std::endl;
    if (b) std::cout << "Object is of type: " YEL "B" NC << std::endl;
    if (c) std::cout << "Object is of type: " YEL "C" NC << std::endl;
}

void identify(Base& p) {
	 try {
		(void)dynamic_cast<A&>(p);
        std::cout << "Object is of type: " YEL "A" NC << std::endl;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Object is of type: " YEL "B" NC << std::endl;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Object is of type: " YEL "C" NC << std::endl;
    } catch (std::exception &e) {}
}