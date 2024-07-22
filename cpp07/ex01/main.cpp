# include "iter.hpp"


int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	::iter(intArray, 5, print_element);
	std::cout << std::endl;

	std::string strArray[] = {"one", "two", "three", "four", "five"};
	::iter(strArray, 5, print_element);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(doubleArray, 5, print_element);

	return 0;
}