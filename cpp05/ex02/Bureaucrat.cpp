# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "Color.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(BUR_MIN_GRADE) {
	std::cout << "Bureaucrat: Default constructor called for " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat: Parameterized constructor called for " << *this << std::endl;
	if (grade < BUR_MAX_GRADE)
		throw GradeTooHighException();
	if (grade > BUR_MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat: Copy constructor called copying " << *this << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat: Copy assignment operator called for copying the grade of " << other << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}

	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor called for " << *this << std::endl;
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

void Bureaucrat::signForm(AForm& form) const {
	if (form.getSigned()) {
		std::cout << BLU + this->_name + NC " could not sign " BLU + form.getName() + NC " because it was already signed!" << std::endl;
		return ;
	}
	form.beSigned(*this);
	std::cout << BLU + this->_name + NC " signed " BLU + form.getName() + NC "!" << std::endl;
}

void Bureaucrat::executeForm(const AForm& form) {
	form.execute(*this);
	std::cout << BLU + this->_name + NC " executed " BLU << form.getName() + NC "!" << std::endl;
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