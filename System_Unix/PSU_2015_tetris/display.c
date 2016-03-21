/*
** display.c for display in /home/oullad_n/nabil/rendu/System_Unix/PSU_2015_tetris
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 20 14:32:09 2016 oullad_n
** Last update Sun Mar 20 18:49:51 2016 oullad_n
*/

#include "tetris.h"

void	display_tetrimap(t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;

  i = 0;
  werase(st->wnext);
  draw_border(st->wnext);
  mvwprintw(st->wnext, 0, 1, "Next:");
  while (i < elem->height)
    {
      j = 0;
      while (j < elem->width)
	{
	  if (elem->map[i][j] == 1)
	    {
	      palette_color();
	      wattron(st->wnext, COLOR_PAIR(elem->color));
	      mvwprintw(st->wnext, i + 1, j + 1, "*");
	      wattroff(st->wnext, COLOR_PAIR(elem->color));
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

void		palette_color()
{
  init_pair(1, COLOR_RED, 1);
  init_pair(2, COLOR_GREEN, 2);
  init_pair(3, COLOR_YELLOW, 3);
  init_pair(4, COLOR_BLUE, 4);
  init_pair(5, COLOR_MAGENTA, 5);
  init_pair(6, COLOR_CYAN, 6);
  init_pair(7, COLOR_WHITE, 7);
}

void		display_game(t_tetris *st)
{
  int		i;
  int		j;

  i = 0;
  start_color();
  while (i < st->key.row - 1)
    {
      j = 1;
      while (j < st->key.col - 1)
  	{
	  if (st->map[i][j] != 0)
	    {
	      palette_color();
	      wattron(st->wtetris, COLOR_PAIR(st->map[i][j]));
	      mvwprintw(st->wtetris, i + 1, j, "*");
	      wattroff(st->wtetris, COLOR_PAIR(st->map[i][j]));
	      wrefresh(st->wtetris);
	    }
	  else
	    mvwprintw(st->wtetris, i + 1, j, " ");
  	  j = j + 1;
  	}
      i = i + 1;
    }
}
