# include "Fixed.hpp"

/**
 * @brief	Default constructor: Initializes the fixed-point number value to 0.
*/
Fixed::Fixed() : _fixedPointNumber(0) {
	// std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Integer constructor: Converts an integer to the corresponding fixed-point value.
 * @param num Integer value to be converted.
 * 
 * The integer is left-shifted by the number of fractional bits to convert it to a fixed-point representation.
 * This effectively multiplies the integer by 256 (since _fractionalBits is 8).
 */
Fixed::Fixed(const int num) {
	// std::cout << "Integer constructor called" << std::endl;
	
	this->_fixedPointNumber = num << this->_fractionalBits;
}

/**
 * @brief Float constructor: Converts a float to the corresponding fixed-point value.
 * @param num Floating-point value to be converted.
 * 
 * The float is multiplied by 256 (1 << _fractionalBits) and then rounded to the nearest integer to convert it to a fixed-point representation.
 */
Fixed::Fixed(const float num) {
	// std::cout << "Float constructor called" << std::endl;
	
	this->_fixedPointNumber = roundf(num * (1 << this->_fractionalBits));
}

/**
 * @brief Copy constructor: Initializes the fixed-point number with the value of another Fixed object.
 * @param other Reference to the Fixed object to be copied.
 */
Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

/**
 * @brief Copy assignment operator: Assigns the value of another Fixed object to this object.
 * @param other Reference to the Fixed object to be assigned.
 * @return Reference to this Fixed object.
 */
Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->_fixedPointNumber = other.getRawBits();

	return *this;
}

/**
 * @brief Destructor: Outputs a message indicating destruction of the object (commented out).
 */
Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Public member function: Returns the raw value of the fixed-point number.
 * @return The raw fixed-point value as an integer.
 */
int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	
	return this->_fixedPointNumber;
}

/**
 * @brief Public member function: Sets the raw value of the fixed-point number.
 * @param raw The raw fixed-point value to be set.
 */
void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;

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

/**
 * @brief Comparison operator: Checks if this Fixed object is greater than another Fixed object.
 * @param other Fixed object to compare against.
 * @return True if this object is greater, false otherwise.
 */
bool	Fixed::operator>(const Fixed& other) const{
	return (this->_fixedPointNumber > other._fixedPointNumber);
}

/**
 * @brief Comparison operator: Checks if this Fixed object is less than another Fixed object.
 * @param other Fixed object to compare against.
 * @return True if this object is less, false otherwise.
 */
bool	Fixed::operator<(const Fixed& other) const{
	return (this->_fixedPointNumber < other._fixedPointNumber);
}

/**
 * @brief Comparison operator: Checks if this Fixed object is greater than or equal to another Fixed object.
 * @param other Fixed object to compare against.
 * @return True if this object is greater or equal, false otherwise.
 */
bool	Fixed::operator>=(const Fixed& other) const{
	return (this->_fixedPointNumber >= other._fixedPointNumber);
}

/**
 * @brief Comparison operator: Checks if this Fixed object is less than or equal to another Fixed object.
 * @param other Fixed object to compare against.
 * @return True if this object is less or equal, false otherwise.
 */
bool	Fixed::operator<=(const Fixed& other) const{
	return (this->_fixedPointNumber <= other._fixedPointNumber);
}

/**
 * @brief Comparison operator: Checks if this Fixed object is equal to another Fixed object.
 * @param other Fixed object to compare against.
 * @return True if the objects are equal, false otherwise.
 */
bool	Fixed::operator==(const Fixed& other) const{
	return (this->_fixedPointNumber == other._fixedPointNumber);
}

/**
 * @brief Comparison operator: Checks if this Fixed object is not equal to another Fixed object.
 * @param other Fixed object to compare against.
 * @return True if the objects are not equal, false otherwise.
 */
bool	Fixed::operator!=(const Fixed& other) const{
	return (this->_fixedPointNumber != other._fixedPointNumber);
}

/**
 * @brief Arithmetic operator: Adds two Fixed objects.
 * @param other Fixed object to be added.
 * @return A new Fixed object representing the sum.
 */
Fixed	Fixed::operator+(const Fixed& other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

/**
 * @brief Arithmetic operator: Subtracts another Fixed object from this Fixed object.
 * @param other Fixed object to be subtracted.
 * @return A new Fixed object representing the difference.
 */
Fixed	Fixed::operator-(const Fixed& other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

/**
 * @brief Arithmetic operator: Multiplies two Fixed objects.
 * @param other Fixed object to be multiplied.
 * @return A new Fixed object representing the product.
 */
Fixed	Fixed::operator*(const Fixed& other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

/**
 * @brief Arithmetic operator: Divides this Fixed object by another Fixed object.
 * @param other Fixed object to divide by.
 * @return A new Fixed object representing the quotient.
 * 
 * Checks for division by zero and handles it by returning 0 and outputting an error message.
 */
Fixed	Fixed::operator/(const Fixed& other) const {
	if (other._fixedPointNumber == 0) {
		std::cout << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

/**
 * @brief Pre-increment operator: Increments the fixed-point value by 1.
 * @return Reference to this Fixed object.
 * 
 * Increments the fixed-point value and returns a reference to the modified object.
 */
Fixed&	Fixed::operator++() {
	++_fixedPointNumber;
	return *this;
}

/**
 * @brief Post-increment operator: Increments the fixed-point value by 1.
 * @param dummy Unused integer parameter to distinguish post-increment from pre-increment.
 * @return A copy of the Fixed object before the increment.
 * 
 * Creates a copy of the current object, increments the fixed-point value, and returns the copy.
 */
Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);

	_fixedPointNumber++;
	return tmp;
}

/**
 * @brief Pre-decrement operator: Decrements the fixed-point value by 1.
 * @return Reference to this Fixed object.
 * 
 * Decrements the fixed-point value and returns a reference to the modified object.
 */
Fixed&	Fixed::operator--() {
	--_fixedPointNumber;
	return *this;
}

/**
 * @brief Post-decrement operator: Decrements the fixed-point value by 1.
 * @param dummy Unused integer parameter to distinguish post-decrement from pre-decrement.
 * @return A copy of the Fixed object before the decrement.
 * 
 * Creates a copy of the current object, decrements the fixed-point value, and returns the copy.
 */
Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);

	_fixedPointNumber--;
	return tmp;
}

/**
 * @brief Static member function: Returns a reference to the smaller of two Fixed objects.
 * @param f1 First Fixed object.
 * @param f2 Second Fixed object.
 * @return Reference to the smaller Fixed object.
 */
Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1 <= f2)
		return (f1);
	return (f2);
}

/**
 * @brief Static member function: Returns a const reference to the smaller of two Fixed objects.
 * @param f1 First Fixed object.
 * @param f2 Second Fixed object.
 * @return Const reference to the smaller Fixed object.
 */
const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	if (f1 <= f2)
		return (f1);
	return (f2);
}

/**
 * @brief Static member function: Returns a reference to the larger of two Fixed objects.
 * @param f1 First Fixed object.
 * @param f2 Second Fixed object.
 * @return Reference to the larger Fixed object.
 */
Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1 >= f2)
		return (f1);
	return (f2);
}

/**
 * @brief Static member function: Returns a const reference to the larger of two Fixed objects.
 * @param f1 First Fixed object.
 * @param f2 Second Fixed object.
 * @return Const reference to the larger Fixed object.
 */
const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	if (f1 >= f2)
		return (f1);
	return (f2);
}