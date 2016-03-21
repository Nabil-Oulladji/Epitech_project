##
## Makefile for makefile in /home/mekkao_y/.bin
## 
## Made by Youssef Mekkaoui
## Login   <mekkao_y@epitech.net>
## 
## Started on  Sun Jan 10 14:09:06 2016 Youssef Mekkaoui
## Last update Sun Mar 20 23:38:40 2016 oullad_n
##

NAME	= tetris

SRC	= main.c \
	  game.c	\
	  game_tools.c	\
	  game_tools2.c	\
	  game_tools3.c	\
	  display.c	\
	  rand.c	\
	  border.c	\
	  score.c	\
	  game2.c	\
	  tools.c \
	  tetris.c	\
	  input.c	\
	  debug.c	\
	  debug2.c	\
	  load_tetriminos2.c \
	  load_tetriminos3.c \
	  my_getnbr.c \
	  help.c  \
	  flags.c	\
	  load_tetriminos.c \
	  get_next_line.c	\
	  tetriminos.c \
	  tools3.c	\
	  tools4.c	\
	  flags2.c	\
	  flags3.c	\
	  my_put_nbr.c	\
	  flags4.c	\
	  checker.c \
	  tools2.c\

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS	+= -Wall -Wextra -Werror -W # -pedantic -ansi

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)  -lncurses
	@echo -e "[032mCompiled successfully[0m"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
