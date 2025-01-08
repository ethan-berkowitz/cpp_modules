# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 12:08:41 by eberkowi          #+#    #+#              #
#    Updated: 2024/12/31 12:07:51 by eberkowi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_first_class
FLAGS = -Wall -Wextra -Werror -std=c++11
INFILES = 	main.cpp \
			Fixed.cpp

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
