# include "Span.hpp"
# include "Color.hpp"

void testFullSpan() {
	Span sp = Span(5);
	std::cout << GRN ">------ Test Full Span ------<" NC << std::endl;

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printVec();

	std::cout << std::endl << BLU "Try to add a number to a full Span: " NC << std::endl;
	try {
		sp.addNumber(42);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testEmptySpan() {
	Span sp = Span(5);
	std::cout << GRN ">------ Test Empty Span ------<" NC << std::endl;

	sp.printVec();
	
	std::cout << std::endl << BLU "Shortest span: " NC << std::endl;
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << BLU "Longest span: " NC << std::endl;
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}

void testNormalSpan() {
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << GRN ">------ Test Normal Span ------<" NC << std::endl;
	
	sp.printVec();
	
	std::cout << std::endl << BLU "Shortest span: " NC << std::endl;
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << BLU "Longest span: " NC << std::endl;
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	std::cout << std::endl;
	testNormalSpan();

	std::cout << std::endl;
	testEmptySpan();

	std::cout << std::endl;
	testFullSpan();

	std::cout << std::endl;
	return 0;
}