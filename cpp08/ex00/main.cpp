# include "easyfind.hpp"
# include "Color.hpp"

void testEmptyContainer() {
	std::cout << GRN ">------- Test Empty Container -------<" NC << std::endl;
	std::vector<int> vec;
	try {
		easyfind(vec, 10);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
}

void testNotInContainer() {
	std::cout << GRN ">------- Test Not In Container -------<" NC << std::endl;
	std::vector<int> vec = {10, 20, 30, 40, 50};
	try {
		easyfind(vec, 60);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void testList() {
	std::cout << GRN ">------- Test List -------<" NC << std::endl;
	try {
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(3);
		lst.push_back(17);
		lst.push_back(9);
		lst.push_back(11);
		std::list<int>::iterator lstIt = easyfind(lst, 17);
		std::cout << BLU "Found in list: " NC << *lstIt << std::endl;
	} 
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void testVector() {
	std::cout << GRN ">------- Test Vector -------<" NC << std::endl;

	try {
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(17);
		vec.push_back(9);
		vec.push_back(11);
		std::vector<int>::iterator vecIt = easyfind(vec, 17);
		std::cout << BLU "Found in vector: " NC << *vecIt << std::endl;
	} 
	catch (const std::exception& e) {
		std::cerr <<  e.what() << std::endl;
	}
}

int main() {
	std::cout << std::endl;
	testVector();
	
	std::cout << std::endl;
	testList();

	std::cout << std::endl;
	testNotInContainer();

	std::cout << std::endl;
	testEmptyContainer();

	std::cout << std::endl;
	
    return 0;
}