# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 12:08:41 by eberkowi          #+#    #+#              #
#    Updated: 2025/03/24 10:56:13 by eberkowi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
FLAGS = -Wall -Wextra -Werror -std=c++11
INFILES = 	main.cpp \
			Bureaucrat.cpp \
			Form.cpp
OBJFILES = $(INFILES:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJFILES)
	c++ $(FLAGS) $(OBJFILES) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re