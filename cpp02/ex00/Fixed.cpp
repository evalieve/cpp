# include "Fixed.hpp"

/**
 * @brief	Default constructor: Initializes the fixed-point number value to 0.
*/
Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Copy constructor: Initializes the fixed-point number with the value of another Fixed object.
 * @param other Reference to the Fixed object to be copied.
 */
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

/**
 * @brief Copy assignment operator: Assigns the value of another Fixed object to this object.
 * @param other Reference to the Fixed object to be assigned.
 * @return Reference to this Fixed object.
 */
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->_fixedPointNumber = other.getRawBits();

	return *this;
}

/**
 * @brief Destructor: Outputs a message indicating destruction of the object (commented out).
 */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Public member function: Returns the raw value of the fixed-point number.
 * @return The raw fixed-point value as an integer.
 */
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	
	return this->_fixedPointNumber;
}

/**
 * @brief Public member function: Sets the raw value of the fixed-point number.
 * @param raw The raw fixed-point value to be set.
 */
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	
	this->_fixedPointNumber = raw;
}