# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: evalieve <evalieve@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/21 13:59:58 by evalieve      #+#    #+#                  #
#    Updated: 2024/06/14 14:45:52 by evalieve      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

HEADER = Contacts.hpp Phonebook.hpp

SRCS = PhoneBook.cpp Contacts.cpp main.cpp

OBJS = $(SRCS:%.cpp=%.o)

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++11

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re