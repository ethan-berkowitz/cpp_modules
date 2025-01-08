# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 11:40:14 by eberkowi          #+#    #+#              #
#    Updated: 2025/01/07 11:25:03 by eberkowi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++11
INFILES = megaphone.cpp
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