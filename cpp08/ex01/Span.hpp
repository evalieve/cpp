#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
	private:
		std::vector<int> _vec;
		unsigned int _N;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		class alreadyFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class notEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		void fillWithRandomNumbers(int minValue, int maxValue);
		void printVec();
};

#endif