# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "Color.hpp"

// ============== PRESIDENTIALPARDONFORM TESTS ============== //

void testNotSignedFormP() {
	std::cout << GRN "Not signed form:" NC << std::endl;
	try {
		Bureaucrat P("P", PRES_EXEC_GRADE);
		PresidentialPardonForm F("PresidentialF");

		std::cout << std::endl;
		P.executeForm(F);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testTooLowForExecFormP() {
	std::cout << GRN "Too low to execute form:" NC << std::endl;
	try {
		Bureaucrat P("P", PRES_EXEC_GRADE + 1);
		PresidentialPardonForm F("PresidentialF");

		std::cout << std::endl;
		P.signForm(F);

		std::cout << std::endl;
		P.executeForm(F);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testTooLowForSignFormP() {
	std::cout << GRN "Too low to sign form:" NC << std::endl;
	try {
		Bureaucrat P("P", PRES_SIGN_GRADE + 1);
		PresidentialPardonForm F("PresidentialF");

		std::cout << std::endl;
		P.signForm(F);

		std::cout << std::endl;
		P.executeForm(F);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testFormP() {
	std::cout << GRN "Normal Form:" NC << std::endl;
	try {
		Bureaucrat P("P", PRES_EXEC_GRADE);
		PresidentialPardonForm F("PresidentialF");

		std::cout << std::endl;
		P.signForm(F);

		std::cout << std::endl;
		P.executeForm(F);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testConstructorsP() {
	std::cout << GRN "Constructors:" NC << std::endl;
	PresidentialPardonForm form1;
	PresidentialPardonForm form2("targetPresidential");
	PresidentialPardonForm form3 = form2;

	form1 = form3;
	std::cout << std::endl;
}

void testPresidentialPardonForm() {
	std::cout << std::endl << GRN ">--- Tests PresidentialPardonForm ---<" NC << std::endl; 
	
	testConstructorsP();
	std::cout << std::endl;

	testFormP();
	std::cout << std::endl;

	testTooLowForSignFormP();
	std::cout << std::endl;

	testTooLowForExecFormP();
	std::cout << std::endl;

	testNotSignedFormP();
	std::cout << std::endl;
}


// ============== ROBOTOMYREQUESTFORM TESTS ============== //

void testNotSignedFormR() {
	std::cout << GRN "Not signed form:" NC << std::endl;
	try {
		Bureaucrat R("R", ROBO_EXEC_GRADE);
		RobotomyRequestForm F("RobotomyF");

		std::cout << std::endl;
		R.executeForm(F);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testTooLowForExecFormR() {
	std::cout << GRN "Too low to execute form:" NC << std::endl;
	try {
		Bureaucrat R("R", ROBO_EXEC_GRADE + 1);
		RobotomyRequestForm F("RobotomyF");

		std::cout << std::endl;
		R.signForm(F);
	
		std::cout << std::endl;
		R.executeForm(F);
		
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testTooLowForSignFormR() {
	std::cout << GRN "Too low to sign form:" NC << std::endl;
	try {
		Bureaucrat R("R", ROBO_SIGN_GRADE + 1);
		RobotomyRequestForm F("RobotomyF");
		
		std::cout << std::endl;
		R.signForm(F);

		std::cout << std::endl;
		R.executeForm(F);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testFormR() {
	std::cout << GRN "Normal Form:" NC << std::endl;
	try {
		Bureaucrat R("R", PRES_EXEC_GRADE);
		RobotomyRequestForm F("RobotomyF");
		
		std::cout << std::endl;
		R.signForm(F);
		
		std::cout << std::endl;
		R.executeForm(F);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testConstructorsR() {
	std::cout << GRN "Constructors:" NC << std::endl;
	RobotomyRequestForm form1;
	RobotomyRequestForm form2("targetRobotomy");
	RobotomyRequestForm form3 = form2;

	form1 = form3;
	std::cout << std::endl;
}

void testRobotomyRequestForm() {
	std::cout << std::endl << GRN ">--- Tests RobotomyRequestForm ---<" NC << std::endl; 
	testConstructorsR();
	std::cout << std::endl;

	testFormR();
	std::cout << std::endl;

	testTooLowForSignFormR();
	std::cout << std::endl;

	testTooLowForExecFormR();
	std::cout << std::endl;

	testNotSignedFormR();
	std::cout << std::endl;
}

// ============== SHRUBBERYCREATIONFORM TESTS ============== //

void testNotSignedFormS() {
	std::cout << GRN "Not signed form:" NC << std::endl;
	try {
		Bureaucrat S("S", SHRUB_EXEC_GRADE);
		ShrubberyCreationForm F("ShrubberyF");

		std::cout << std::endl;
		S.executeForm(F);
		
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testTooLowForExecFormS() {
	std::cout << GRN "Too low to execute form:" NC << std::endl;
	try {
		Bureaucrat S("S", SHRUB_EXEC_GRADE + 1);
		ShrubberyCreationForm F("ShrubberyF");

		std::cout << std::endl;
		S.signForm(F);

		std::cout << std::endl;
		S.executeForm(F);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testTooLowForSignFormS() {
	std::cout << GRN "Too low to sign form:" NC << std::endl;
	try {
		Bureaucrat S("S", SHRUB_SIGN_GRADE + 1);
		ShrubberyCreationForm F("ShrubberyF");

		std::cout << std::endl;
		S.signForm(F);

		std::cout << std::endl;
		S.executeForm(F);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testFormS() {
	std::cout << GRN "Normal Form:" NC << std::endl;
	try {
		Bureaucrat S("S", SHRUB_EXEC_GRADE);
		ShrubberyCreationForm F("ShrubberyF");

		std::cout << std::endl;
		S.signForm(F);

		std::cout << std::endl;
		S.executeForm(F);
		
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testConstructorsS() {
	std::cout << GRN "Constructors:" NC << std::endl;
	ShrubberyCreationForm form1;
	ShrubberyCreationForm form2("targetShrubbery");
	ShrubberyCreationForm form3 = form2;

	form1 = form3;
	std::cout << std::endl;
}

void testShrubberyCreationForm() {
	std::cout << std::endl << GRN ">--- Tests ShrubberyCreationForm ---<" NC << std::endl; 
	testConstructorsS();
	std::cout << std::endl;

	testFormS();
	std::cout << std::endl;

	testTooLowForSignFormS();
	std::cout << std::endl;

	testTooLowForExecFormS();
	std::cout << std::endl;

	testNotSignedFormS();
	std::cout << std::endl;
}

// ============== MAIN FUNCTION ============== //

int main() {
	testPresidentialPardonForm();
	std::cout << std::endl;
	
	testRobotomyRequestForm();
	std::cout << std::endl;

	testShrubberyCreationForm();
	std::cout << std::endl;

	return 0;
}