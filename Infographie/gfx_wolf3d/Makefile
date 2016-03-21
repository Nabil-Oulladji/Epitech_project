##
## Makefile for Makefile in /home/oullad_n/rendu/Infographie/WOLF3D
## 
## Made by nabil oulladji
## Login   <oullad_n@epitech.net>
## 
## Started on  Sun Dec 20 18:12:00 2015 nabil oulladji
## Last update Sun Dec 27 20:19:24 2015 nabil oulladji
##

CC	=	gcc -g3

RM	=	rm -rf

NAME	=	wolf3d

SRC	=	main.c \
		read_file.c \
		raycasting.c \
		init_value.c \
		main_loop.c \
		draw_line.c \
		fct_deplacement.c \
		snow.c \
		music.c \
		malloc_free.c \
		check_map.c \
		my_getnbr.c \
		tekpixel.c

#CFLAGS	=	-W -Wall -Werror -ansi -pedantic

CCLIB   +=	-L/home/${USER}/.froot/lib/ -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

OBJS	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CCLIB) 

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
