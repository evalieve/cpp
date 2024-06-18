# include "Fixed.hpp"


/**
 * @brief	Default constructor: Initializes the fixed-point number value to 0.
*/
Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Integer constructor: Converts an integer to the corresponding fixed-point value.
 * @param num Integer value to be converted.
 * 
 * The integer is left-shifted by the number of fractional bits to convert it to a fixed-point representation.
 * This effectively multiplies the integer by 256 (since _fractionalBits is 8).
 */
Fixed::Fixed(const int num) {
	std::cout << "Integer constructor called" << std::endl;
	
	this->_fixedPointNumber = num << this->_fractionalBits;
}

/**
 * @brief Float constructor: Converts a float to the corresponding fixed-point value.
 * @param num Floating-point value to be converted.
 * 
 * The float is multiplied by 256 (1 << _fractionalBits) and then rounded to the nearest integer to convert it to a fixed-point representation.
 */
Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	
	this->_fixedPointNumber = roundf(num * (1 << this->_fractionalBits));
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
 * @brief Destructor: Outputs a message indicating destruction of the object.
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

/**
 * @brief Public member function: Converts the fixed-point value to a floating-point value.
 * @return The floating-point representation of the fixed-point value.
 * 
 * The raw fixed-point value is divided by 256 (1 << _fractionalBits) to convert it back to a float.
 */
float Fixed::toFloat(void) const {
	return ((float)this->_fixedPointNumber / (1 << this->_fractionalBits));
}

/**
 * @brief Public member function: Converts the fixed-point value to an integer value.
 * @return The integer representation of the fixed-point value.
 * 
 * The raw fixed-point value is right-shifted by 8 bits (_fractionalBits) to convert it back to an integer.
 */
int Fixed::toInt(void) const {
	return (this->_fixedPointNumber >> this->_fractionalBits);
}

/**
 * @brief Overload operator: Overloads the insertion operator to output the floating-point representation of the fixed-point number.
 * @param os Output stream object.
 * @param other Fixed object to be output.
 * @return Reference to the output stream object.
 * 
 * The insertion operator is overloaded to allow easy output of Fixed objects using the stream insertion syntax (e.g., std::cout << fixedObject).
 * The function converts the Fixed object to a float and inserts it into the output stream.
 * 
 * Returning a reference to the output stream object allows for chaining of output operations. 
 * This means you can output multiple values in a single statement (e.g., std::cout << fixed1 << " " << fixed2).
 */
std::ostream& operator<<(std::ostream& os, const Fixed& other) {
	os << other.toFloat();

	return os;
}