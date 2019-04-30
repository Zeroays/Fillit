# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 10:35:36 by vrabaib           #+#    #+#              #
#    Updated: 2019/04/03 23:55:13 by vrabaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = fillit.h

SRC = process.c data.c helper.c main.c fillit.c utils.c

SRCO = process.o data.o helper.o main.o fillit.o utils.o

LIB = libft/libft.a

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Werror -Wextra -c $(SRC) -I libft/includes
	clang $(SRCO) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(SRCO)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean
