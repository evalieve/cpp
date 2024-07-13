# include "Intern.hpp"
# include "Color.hpp"

Intern::Intern() {
	std::cout << "Intern: Default constructor called for " BLU << this << NC << std::endl;
}
 
Intern::Intern(const Intern& other) {
	std::cout << "Intern: Copy constructor called for " BLU << this << NC << std::endl;
	(void)other;
}
 
Intern&	Intern::operator=(const Intern& other ) {
	std::cout << "Intern: Copy assignment operator called for " BLU << this << NC << std::endl;
	(void) other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern: Destructor called for " BLU << this << NC << std::endl;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
    const std::string formNames[3] = {
        "robotomy request", 
        "presidential pardon", 
        "shrubbery creation"
    };

    AForm* (Intern::*formCreators[])(const std::string&) = {
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createShrubberyCreationForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formNames[i] == name) {
            std::cout << "Intern creates " BLU << name << NC << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cout << "Form name " << BLU << name << NC << " does not exist." << std::endl;
    return NULL;
}