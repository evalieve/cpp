#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Color.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;
	
	std::cout << std::endl;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }
	std::cout << std::endl;

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }
	std::cout << std::endl;

    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }
	std::cout << std::endl;

    form = someRandomIntern.makeForm("unknown form", "Target");
    if (form) {
        delete form;
    }
	std::cout << std::endl;

    return 0;
}
