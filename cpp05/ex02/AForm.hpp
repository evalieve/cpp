#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _signed;

	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		const std::string& getName() const;
		bool getSigned() const;
		const int& getSignGrade() const;
		const int& getExecGrade() const;
		void beSigned(const Bureaucrat& obj);
		
		virtual void execute(const Bureaucrat& executor) const = 0;

		class gradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class gradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class formNotSignedException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif