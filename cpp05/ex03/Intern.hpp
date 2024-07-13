#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public: 
		Intern(); 
		Intern(const Intern& other); 
		Intern& operator=(const Intern& other);
		~Intern(); 

		AForm* makeForm(std::string form, std::string target);

	private:
		AForm* createShrubberyCreationForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);
}; 
 
#endif