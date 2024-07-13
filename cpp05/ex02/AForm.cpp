# include "AForm.hpp"
# include "Color.hpp"

AForm::AForm() : _name("DefaultForm"), _signGrade(BUR_MIN_GRADE), _execGrade(BUR_MIN_GRADE), _signed(false) {
	std::cout << "AForm: Default constructor called, attributes: " << *this << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) 
		: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	std::cout << "AForm: Parameterized constructor called, attributes: " << *this << std::endl;
	if (signGrade < BUR_MAX_GRADE)
		throw gradeTooHighException();
	if (signGrade > BUR_MIN_GRADE)
		throw gradeTooLowException();
	if (execGrade < BUR_MAX_GRADE)
		throw gradeTooHighException();
	if (execGrade > BUR_MIN_GRADE)
		throw gradeTooHighException();
}

AForm::AForm(const AForm& other) 
		: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed) {
	std::cout << "AForm: Copy constructor called copying " << *this << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm: Copy assignment operator called for copying the signed state of Aform attributes: " << other << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}

	return *this;
}

AForm::~AForm() {
	std::cout << "AForm: Destructor called, attributes: " << *this << std::endl;
}

const std::string& AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

const int& AForm::getSignGrade() const {
	return this->_signGrade;
}

const int& AForm::getExecGrade() const {
	return this->_execGrade;
}

void AForm::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > this->_signGrade)
		throw gradeTooHighException();
	this->_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!this->_signed)
		throw formNotSignedException();
	if (this->_execGrade < executor.getGrade())
		throw gradeTooHighException();
}

const char* AForm::gradeTooHighException::what() const noexcept {
	return RED "Form exception: Grade too high!" NC;
}

const char* AForm::gradeTooLowException::what() const noexcept {
	return RED "Form exception: Grade too low!" NC;
}

const char* AForm::formNotSignedException::what() const noexcept {
	return RED "Form exception: Form is not signed!" NC;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "Form: " BLU + obj.getName() + NC ", Sign grade: " YEL << obj.getSignGrade() << NC
		<< ", Execute grade: " YEL << obj.getExecGrade() << NC ", Signed: " YEL << (obj.getSigned() ? "True" : "False") << NC;

	return os;
}
