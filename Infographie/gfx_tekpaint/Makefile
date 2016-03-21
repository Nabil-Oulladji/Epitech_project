##
## Makefile for tekpaint in /home/pinta_a/rendu/INFOGRAPHIE/TEKPAINT
## 
## Made by arnaud pinta
## Login   <pinta_a@epitech.net>
## 
## Started on  Mon Dec 28 13:15:03 2015 arnaud pinta
## Last update Wed Jan 27 20:13:30 2016 nabil oulladji
## Last update Tue Dec 29 15:40:19 2015 Nicolas Menettrier
##

CC		= gcc -g3

NAME		= tekpaint

LIB		= -L/home/${USER}/.froot/lib 		\
		  -I/home/${USER}/.froot/include	\
		  -llapin 				\
		  -lsfml-audio 				\
		  -lsfml-graphics 			\
		  -lsfml-window 			\
		  -lsfml-system 			\
		  -lstdc++ 				\
		  -ldl 					\
		  -lm

CFLAGS		+= -W		\
		  -Wall		\
		  -Werror

SRC		= gui.c				\
		  gui2.c			\
		  my_put.c			\
		  main.c			\
		  event.c			\
		  bitmap.c			\
		  square.c			\
		  pochon.c			\
		  nuancier.c			\
		  test_pos.c			\
		  test_pos2.c			\
		  tekpixel.c			\
		  my_getint.c			\
		  get_nbr.c			\
		  tekcircle.c			\
		  paint_full.c			\
		  my_strcmp.c			\
		  tekgetpixel.c			\
		  filter_sepia.c		\
		  init_all_value.c		\
		  filter_negatif.c		\
		  tek_fill_circle.c		\
		  noise_color_full.c		\
		  filter_black_and_white.c	\
		  save.c			\
		  my_read_map.c

OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME) $(FLAG)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
