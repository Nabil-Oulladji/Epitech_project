##
## Makefile for Makefile in /home/oullad_n/rendu/System_Unix/PSU_2015_minishell1
## 
## Made by nabil oulladji
## Login   <oullad_n@epitech.net>
## 
## Started on  Mon Jan 18 12:01:42 2016 nabil oulladji
## Last update Tue Feb  9 19:39:38 2016 nabil oulladji
##

CC	=	gcc -g3

RM	=	rm -rf

NAME	=	allum1

CFLAGS	+=	-W -Wall -Werror -ansi -pedantic

SRC	=	main.c \
		allum1.c \
		check_allum.c \
		init_value.c \
		display.c \
		get_next_line.c \
		my_getnbr.c \
		printstr.c \
		my_put_nbr.c

OBJS	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
