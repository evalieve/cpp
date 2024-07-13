# include "Form.hpp"
# include "Color.hpp"

void testSigningForm(void (Bureaucrat::*func)(Form&) const, Bureaucrat& bureaucrat, Form& form) {
    try {
		std::cout << BLU + bureaucrat.getName() + NC "(" YEL << bureaucrat.getGrade() << NC ")" " is trying to sign " BLU + form.getName() + NC "(" YEL << form.getSignGrade() << ", " << (form.getSigned() ? "True" : "False") << NC ")" << std::endl;
        (bureaucrat.*func)(form);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testInstances(const std::string& name, const int signGrade, const int execGrade) {
	try {
		Form form(name, signGrade, execGrade);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testConstructors() {
	Form form1;
	Form form2("Paper", BUR_MAX_GRADE, BUR_MAX_GRADE);
	Form form3 = form2;

	form1 = form3;
	std::cout << std::endl;
}

int main() {
	std::cout << std::endl << GRN ">--- Test Constructors ---<" NC << std::endl; 
	{
		testConstructors();
		std::cout << std::endl;
	}

	std::cout << std::endl << GRN ">--- Test Instances ---<" NC << std::endl;
	{
		testInstances("Exam", 150, 150);
		std::cout << std::endl;
		
		testInstances("EvalSheet", 1, 1);
		std::cout << std::endl;
		
		testInstances("Checklist", 75, 151);
		std::cout << std::endl;

		testInstances("SomeForm", 0, 1);
		std::cout << std::endl;

		testInstances("Gradelist", 151, 0);
		std::cout << std::endl;
	}

	std::cout << std::endl << GRN ">--- Test Signing Forms ---<" NC << std::endl;
	  {
        Bureaucrat tooLowForForm("tooLowForForm", 150);
        Bureaucrat higherThanForm("higherThanForm", 1);
        Bureaucrat sameAsForm("sameAsForm", 75);
        Form form1("form1", 75, 75);
		Form form2("form2", 75, 75);

        std::cout << std::endl;

        testSigningForm(&Bureaucrat::signForm, tooLowForForm, form1);
        std::cout << std::endl;

        testSigningForm(&Bureaucrat::signForm, higherThanForm, form1);
        std::cout << std::endl;

        testSigningForm(&Bureaucrat::signForm, sameAsForm, form1);
        std::cout << std::endl;

		testSigningForm(&Bureaucrat::signForm, sameAsForm, form2);
        std::cout << std::endl;
    }

	std::cout << std::endl;

	return 0;
}