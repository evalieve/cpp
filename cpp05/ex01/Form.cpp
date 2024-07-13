# include "Form.hpp"
# include "Color.hpp"

Form::Form() : _name("DefaultForm"), _signGrade(BUR_MIN_GRADE), _execGrade(BUR_MIN_GRADE), _signed(false) {
	std::cout << "Form: Default constructor called, attributes: " << *this << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) 
		: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	std::cout << "Form: Parameterized constructor called, attributes: " << *this << std::endl;
	if (signGrade < BUR_MAX_GRADE)
		throw gradeTooHighException();
	if (signGrade > BUR_MIN_GRADE)
		throw gradeTooLowException();
	if (execGrade < BUR_MAX_GRADE)
		throw gradeTooHighException();
	if (execGrade > BUR_MIN_GRADE)
		throw gradeTooLowException();
}

Form::Form(const Form& other) 
		: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed) {
	std::cout << "Form: Copy constructor called copying " << *this << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form: Copy assignment operator called for copying the signed state of form attributes: " << other << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}

	return *this;
}

Form::~Form() {
	std::cout << "Form: Destructor called, attributes: " << *this << std::endl;
}

const std::string& Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

const int& Form::getSignGrade() const {
	return this->_signGrade;
}

const int& Form::getExecGrade() const {
	return this->_execGrade;
}

void Form::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > this->_signGrade)
		throw gradeTooHighException();
	this->_signed = true;
}

const char* Form::gradeTooHighException::what() const noexcept {
	return RED "Form exception: Grade too high!" NC;
}

const char* Form::gradeTooLowException::what() const noexcept {
	return RED "Form exception: Grade too low!" NC;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form: " BLU + obj.getName() + NC ", Sign grade: " YEL << obj.getSignGrade() << NC
		<< ", Execute grade: " YEL << obj.getExecGrade() << NC ", Signed: " YEL << (obj.getSigned() ? "True" : "False") << NC;

	return os;
}
