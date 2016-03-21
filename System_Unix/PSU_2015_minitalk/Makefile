##
## Makefile for Makefile in /home/oullad_n/rendu/System_Unix/PSU_2015_sigcheck
## 
## Made by nabil oulladji
## Login   <oullad_n@epitech.net>
## 
## Started on  Mon Feb  1 15:19:48 2016 nabil oulladji
## Last update Sat Feb 20 18:24:37 2016 nabil oulladji
##

CC	=	gcc

RM	=	rm -rf

NAME	=	server/server

NAME2	=	client/client

CFLAGS	+=	-W -Werror -Wall -Wextra

SRC	=	server/sigcheck.c \
		server/my_put_nbr.c \
		server/converter.c

SRC2	=	client/client.c \
		client/my_getnbr.c

OBJS	=	$(SRC:.c=.o)

OBJS2	=	$(SRC2:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS2)
	$(CC) -o $(NAME) $(OBJS)
	$(CC) -o $(NAME2) $(OBJS2)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS2)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(NAME2)

re:		fclean all

.PHONY: all clean fclean re
