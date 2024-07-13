# include "PresidentialPardonForm.hpp"
# include "Color.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
		: AForm("defaultTarget", PRES_SIGN_GRADE, PRES_EXEC_GRADE)
{
	std::cout << "PresidentialPardonForm: Default constructor called for " BLU + getName() + NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm(target, PRES_SIGN_GRADE, PRES_EXEC_GRADE)
{
	std::cout << "PresidentialPardonForm: Parameterized constructor called for " BLU + getName() + NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
		: AForm(other)
{
	std::cout << "PresidentialPardonForm: Copy constructor called for " BLU + getName() + NC << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm: Copy assignment operator called for " BLU + getName() + NC << std::endl;
	if (this != &other)
		AForm::operator=(other);

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: Destructor called for " BLU + getName() + NC << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::cout << getName() + " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}