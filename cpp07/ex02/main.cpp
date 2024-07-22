#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> defaultArray;
        std::cout << "Default array size: " << defaultArray.getSize() << std::endl;

        // Test constructor with size parameter
        Array<int> sizeArray(5);
        std::cout << "Size array size: " << sizeArray.getSize() << std::endl;

        // Test copy constructor
        Array<int> copyArray(sizeArray);
        std::cout << "Copy array size: " << copyArray.getSize() << std::endl;

		// Test array data
		std::cout << std::endl << "Array data before accessing and changes:" << std::endl;
		for (unsigned int i = 0; i < sizeArray.getSize(); ++i) {
			std::cout << "sizeArray[" << i << "] = " << sizeArray[i] << std::endl;
		}

        // Test element access
		std::cout << std::endl << "Array data after accessing and changing values:" << std::endl;
		for (unsigned int i = 0; i < sizeArray.getSize(); ++i) {
            sizeArray[i] = i * 2;
            std::cout << "sizeArray[" << i << "] = " << sizeArray[i] << std::endl;
        }

        // Test assignment operator
        Array<int> assignArray;
        assignArray = sizeArray;

		// Test array data after assignment
		std::cout << std::endl << "Array data after assignment:" << std::endl;
        std::cout << "Assigned array size: " << assignArray.getSize() << std::endl;
		for (unsigned int i = 0; i < assignArray.getSize(); ++i) {
			std::cout << "assignArray[" << i << "] = " << assignArray[i] << std::endl;
		}

        // Test out of bounds access
		std::cout << std::endl << "Trying to access out of bounds element:" << std::endl;
        try {
            std::cout << sizeArray[10] << std::endl;
        } 
		catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } 
	catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
