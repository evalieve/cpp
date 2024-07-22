# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter: Default constructor called" << std::endl;
}
		
ScalarConverter::ScalarConverter(std::string n) {
	(void)n;
	std::cout << "ScalarConverter: Parameterized constructor called" << std::endl;
}
		
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "ScalarConverter: Copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter: Destructor called" << std::endl;
}


void printImpossible () {
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Float: Impossible" << std::endl;
	std::cout << "Double: Impossible" << std::endl;

}

template <typename T>
void printFloat (T value, t_type type) {
	if (type == FLOAT)
		std::cout << "Float: " << value;
	else
		std::cout << "Float: " << static_cast<float>(value);
	if (value - static_cast<int>(value) == 0)
		std::cout << ".0";
	std::cout << 'f' << std::endl;
}

template <typename T>
void printDouble (T value, t_type type) {
	if (type == DOUBLE)
		std::cout << "Double: " << value;
	else
		std::cout << "Double: " << static_cast<double>(value);
	if (value - static_cast<int>(value) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

template <typename T>
void printInt (T value, t_type type) {
	if (type == INT)
		std::cout << "Int: " << value << std::endl;
	else if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(value) << std::endl;
}

template <typename T>
void printChar (T value, t_type type) {
	if (value < 0 || value > 255)
		std::cout << "Char: Impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << "Char: Non displayable" << std::endl;
	else if (type == CHAR)
		std::cout << "Char: '" << value << '\'' << std::endl;
	else
		std::cout << "Char: '" << static_cast<char>(value) << '\'' << std::endl;
}

template <typename T>
void convertType(T value, t_type type) {
	void (*print[4])(T value, t_type type) = {
		&printChar,
		&printInt,
		&printFloat,
		&printDouble
	};

	for (int i = 0; i < 4; i++)
		print[i](value, type);
}

t_type getType(const std::string& literal) {
	size_t i = 0;
	size_t sizeLiteral = literal.length();
	bool isDigit = false;

	if (sizeLiteral == 1 && !std::isdigit(literal[0]))
		return CHAR;
	
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	
	while (literal[i] && std::isdigit(literal[i])) 
	{
		if (isDigit == false)
			isDigit = true;
		i++;
	}
	
	if (i == sizeLiteral)
		return INT;

	if (literal[i] == '.') {
		i++;
		while (literal[i] && std::isdigit(literal[i])) {
			if (isDigit == false)
				isDigit = true;
			i++;
		}
		if (i == sizeLiteral)
			return DOUBLE;

		if (i == sizeLiteral - 1 && literal[i] == 'f' && isDigit == true)
			return FLOAT;
	}
	return UNTYPED;
}

void handleSpecialCases(const std::string& literal) {
	if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } 
	else if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } 
	else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

bool isPseudoLiteral(const std::string& literal) {
    return literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff";
}

void ScalarConverter::convert(const std::string &literal) {
	if (isPseudoLiteral(literal)) {
        handleSpecialCases(literal);
        return ;
    }
	
	t_type type = getType(literal);
	switch (type) {
		case CHAR:
			convertType(literal[0], type);
			break ;

		case INT:
			try {
				convertType(std::stoi(literal), type);
			} catch (std::exception& e) {
				printImpossible();
			}
			break ;

		case FLOAT:
			try {
				convertType(std::stof(literal), type);
			} catch (std::exception& e) {
				printImpossible();
			}
			break ;

		case DOUBLE:
			try {
				convertType(std::stod(literal), type);
			} catch (std::exception& e) {
				printImpossible();
			}
			break ;
		
		default:
			printImpossible();
	}
}