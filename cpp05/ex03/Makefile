NAME = intern

HEADER =	Bureaucrat.hpp				\
			AForm.hpp					\
			ShrubberyCreationForm.hpp	\
			RobotomyRequestForm.hpp 	\
			PresidentialPardonForm.hpp	\
			Intern.hpp					\

SRC =		main.cpp 					\
			Bureaucrat.cpp 				\
			AForm.cpp					\
			ShrubberyCreationForm.cpp	\
			RobotomyRequestForm.cpp		\
			PresidentialPardonForm.cpp	\
			Intern.cpp					\
			
OBJ = $(SRC:%.cpp=%.o)

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++11

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
