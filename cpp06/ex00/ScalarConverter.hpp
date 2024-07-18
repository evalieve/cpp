#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <climits>
# include <cmath>
# include <iomanip>
# include <string>

typedef enum {
	UNTYPED,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
}		t_type;

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(std::string n);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};

#endif