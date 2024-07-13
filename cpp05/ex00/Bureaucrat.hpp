#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define BUR_MIN_GRADE 150
# define BUR_MAX_GRADE 1

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif