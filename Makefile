#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abibyk <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 14:33:43 by abibyk            #+#    #+#              #
#    Updated: 2018/01/29 14:46:11 by abibyk           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS = fillit.c map.c parsing.c placing.c validate.c main.c tetr.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

OPTIONS = -c -I

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $< -o $@ -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
