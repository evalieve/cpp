# include "RobotomyRequestForm.hpp"
# include "Color.hpp"

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("defaulTarget", ROBO_SIGN_GRADE, ROBO_EXEC_GRADE)
{
	std::cout << "RobotomyRequestForm: Default constructor called for " BLU + getName() + NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm(target, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE)
{
	std::cout << "RobotomyRequestForm: Parameterized constructor called for " BLU + getName() + NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
		: AForm(other)
{
	std::cout << "RobotomyRequestForm: Copy constructor called for " BLU + getName() + NC << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm: Copy assignment operator called for " BLU + getName() + NC << std::endl;
	if (this != &other)
		AForm::operator=(other);

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
		std::cout << "RobotomyRequestForm: Destructor called for " BLU + getName() + NC << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::cout << "* Some drilling noises... *" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << getName() << " has been robotomized succesfully!" << std::endl;
	else
		std::cout << getName() << " has been robotomized unsuccesfully!" << std::endl;
}