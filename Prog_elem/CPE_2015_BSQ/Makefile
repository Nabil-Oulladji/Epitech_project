##
## Makefile for makefile in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
## 
## Made by nabil oulladji
## Login   <oullad_n@epitech.net>
## 
## Started on  Thu Dec 10 16:30:49 2015 nabil oulladji
## Last update Thu Dec 17 22:54:01 2015 nabil oulladji
##

CC	=	gcc -g3

RM	=	rm -rf

NAME	=	bsq

SRC	=	main.c \
		bsq.c \
		read_file.c \
		add_display_x.c \
		malloc_free.c \
		my_getnbr.c \
		my_strlen.c \
		my_putchar.c \
		my_check_error.c

CFLAGS	=	-W -Wall -Wextra -Werror

OBJS	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
