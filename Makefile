# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: draynor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 16:26:51 by draynor           #+#    #+#              #
#    Updated: 2018/12/25 16:40:50 by draynor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
INCL_FOLD = .
NAME =  libftprintf.a

all: $(NAME)

$(NAME):
	gcc -I$(INCL_FOLD) $(FLAGS) -c -Ofast	src/*.c
	ar rc $(NAME)							*.o
	ranlib $(NAME)

clean:
	rm -f									*.o 

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	gcc $(FLAGS) tests.c -L. -lft
	./a.out

dele:
	rm -f $(NAME)
