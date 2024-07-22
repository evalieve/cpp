# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Color.hpp"
// # include <unistd.h>

int main() {
    // Generate a random instance of A, B, or C and get it as a Base pointer
	std::cout << GRN ">----- Generating random object: -----<" NC << std::endl;
    Base* basePtr = generate();
	std::cout << std::endl;
	
    // Identify the type using the pointer
    std::cout << GRN ">----- Identifying using pointer: -----<" NC << std::endl;
    identify(basePtr);
	std::cout << std::endl;

    // Identify the type using the reference
    std::cout << GRN ">----- Identifying using reference: -----<" NC << std::endl;
    identify(*basePtr);

	std::cout << std::endl;
    // Clean up
    delete basePtr;

    return 0;
}