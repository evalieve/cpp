# include <string>
# include <iostream>

int main(void) {
	std::string string = "HI THIS IS BRAIN";
	
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << std::endl;
	std::cout << "address of string:    " << &string << std::endl;
	std::cout << "address in stringPTR: " << stringPTR << std::endl;
	std::cout << "address in stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "value of string:      " << string << std::endl;
	std::cout << "value in stringPTR:   " << *stringPTR << std::endl;
	std::cout << "value in stringREF:   " << stringREF << std::endl;

	std::cout << std::endl;

	return (0);
}