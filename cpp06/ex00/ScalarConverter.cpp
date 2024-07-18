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


void convertFloat(float value) {
	if (value < 0 || value > 255)
		std::cout << "Char: Impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << static_cast<char>(value) << '\'' << std::endl;
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << value << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void convertDouble(double value) {
	if (value < 0 || value > 255)
		std::cout << "Char: Impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << static_cast<char>(value) << '\'' << std::endl;
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest())
        std::cout << "float: impossible\n";
    else {
        std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
    }
    std::cout << "double: " << value << std::endl;
}

void printImpossible () {
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Float: Impossible" << std::endl;
	std::cout << "Double: Impossible" << std::endl;

}

void convertInt(const std::string& value) {
    long long num = 0;

    try {
        num = std::stoll(value);

        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
			printImpossible();
            return;
        }
    } catch (const std::exception& e) {
        printImpossible();
        return;
    }

    int intValue = static_cast<int>(num);

    if (intValue < 0 || intValue > 255) {
        std::cout << "Char: Impossible" << std::endl;
    } else if (!std::isprint(static_cast<unsigned char>(intValue))) {
        std::cout << "Char: Non displayable" << std::endl;
    } else {
        std::cout << "Char: '" << static_cast<char>(intValue) << '\'' << std::endl;
    }

    std::cout << "Int: " << intValue << std::endl;
    // std::cout << std::fixed << std::setprecision(1);
    std::cout << "Float: " << static_cast<float>(intValue) << 'f' << std::endl;
    std::cout << "Double: " << static_cast<double>(intValue) << std::endl;
}

void convertChar(char c) {
	if (!std::isprint(c))
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << c << '\'' << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<double>(c) << 'f' << std::endl;
	std::cout << "Double: " <<  static_cast<float>(c) << std::endl;
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
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    } else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    } else {
        std::cout << "Unknown literal type\n";
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
			convertChar(literal[0]);
			break ;

		case INT:
			convertInt(literal);
			break ;

		case DOUBLE:
			convertDouble(std::stod(literal));
			break ;

		case FLOAT:
			convertFloat(std::stof(literal));
			break ;
		
		default:
			printImpossible();
	}
}