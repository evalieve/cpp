#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _signed;

	public:
		Form();
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool getSigned() const;
		const int& getSignGrade() const;
		const int& getExecGrade() const;
		void beSigned(const Bureaucrat& obj);
		
		class gradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class gradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif