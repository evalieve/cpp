# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: evalieve <evalieve@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/04/25 15:16:08 by evalieve      #+#    #+#                  #
#    Updated: 2024/06/14 14:45:46 by evalieve      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:%.cpp=%.o)

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++11

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re