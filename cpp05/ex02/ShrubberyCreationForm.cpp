# include "ShrubberyCreationForm.hpp"
# include "Color.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("defaultTarget", SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE)
{
	std::cout << "ShrubberyCreationForm: Default constructor called for " BLU + getName() + NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm(target, SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE)
{
	std::cout << "ShrubberyCreationForm: Parameterized constructor called for " BLU + getName() + NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
		: AForm(other)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called for " BLU + getName() + NC << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm: Copy assignment operator called for " BLU + getName() + NC << std::endl;
	if (this != &other)
		AForm::operator=(other);

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor called for " BLU + getName() + NC << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::ofstream file;
	// error checks met creeeren en openen files? checken
	file.open(this->getName() + "_shrubbery");
	file << "           &&& &&  & &&" << std::endl;
	file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "     &&     \\|||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "      , -=-~  .-^- _" << std::endl;
	file.close();
}