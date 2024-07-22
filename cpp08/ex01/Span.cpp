# include "Span.hpp"
# include "Color.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_vec = other._vec;
		_N = other._N;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_vec.size() < _N)
		_vec.push_back(num);
	else
		throw Span::alreadyFullException();
}

int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw Span::notEnoughNumbersException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan() {
	if (_vec.size() < 2)
		throw Span::notEnoughNumbersException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}

const char* Span::alreadyFullException::what() const throw() {
	return RED "Span exception: The Span is already full!" NC;
}

const char* Span::notEnoughNumbersException::what() const throw() {
	return RED "Span exception: Not enough numbers to calculate the span!" NC;
}

void Span::printVec() {
	std::cout << YEL "Numbers inside vector: " NC;
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout <<  _vec[i] << " ";
	std::cout << std::endl;
}
