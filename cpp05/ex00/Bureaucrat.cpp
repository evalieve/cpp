# include "Bureaucrat.hpp"
# include "Color.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(BUR_MIN_GRADE) {
	std::cout << "Default constructor called for " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Parameterized constructor called for " << *this << std::endl;
	if (grade < BUR_MAX_GRADE)
		throw GradeTooHighException();
	if (grade > BUR_MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Copy constructor called copying " << *this << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Copy assignment operator called for copying the grade of " << other << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}

	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called for " << *this << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade <= BUR_MAX_GRADE)
		throw GradeTooHighException();
	--this->_grade;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= BUR_MIN_GRADE)
		throw GradeTooLowException();
	++this->_grade;
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return RED "Bureaucrat exception: Grade too low!" NC;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return RED "Bureaucrat exception: Grade too high!" NC;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << BLU + obj.getName() + NC + " with a bureaucrat grade of " + YEL << obj.getGrade() << NC;

	return os;
}