##
## Makefile for Makefile in /home/oullad_n/rendu/Infographie/WOLF3D
## 
## Made by nabil oulladji
## Login   <oullad_n@epitech.net>
## 
## Started on  Sun Dec 20 18:12:00 2015 nabil oulladji
## Last update Sun Mar 13 06:02:33 2016 oullad_n
##

CC	=	gcc

RM	=	rm -rf

NAME	=	raytracer1

SRC	=	main.c \
		tcore/tekpixel.c \
		main_loop.c \
		read_file.c \
		read_figure.c \
		read_position.c \
		my_getnbr.c \
		my_raytracer.c \
		palette_color.c \
		plan.c \
		sphere.c \
		cylindre.c \
		cone.c \
		color.c \
		mirror_color.c \
		fct_mirror.c \
		mirror_figure.c \
		mirror_figure2.c \
		ombre.c \
		my_key.c \
		init_value.c

CFLAGS	+=	-W -Wall -Werror -ansi -pedantic

CCLIB   +=	-I/home/${USER}/.froot/include -L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
		-lsfml-system -lstdc++ -ldl -lm

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
