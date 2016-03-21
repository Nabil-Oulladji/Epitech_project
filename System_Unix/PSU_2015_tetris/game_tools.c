/*
** game_tools.c for game_tools in /home/oullad_n/nabil/rendu/System_Unix/youss/test1/tetris
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 20 12:56:40 2016 oullad_n
** Last update Sun Mar 20 23:23:38 2016 oullad_n
*/

#include "tetris.h"

void	check_line(t_tetris *st)
{
  int	i;
  int	j;
  int	x;

  j = 0;
  while (j < st->key.row - 1)
    {
      i = 0;
      x = 0;
      while (i < st->key.col)
	{
	  if (st->map[j][i] != 0)
	    x = x + 1;
	  i = i + 1;
	}
      if (x == st->key.col)
	  del_line(j, st);
      j = j + 1;
    }
}

int	check_finish(t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;
  int	x;

  j = 0;
  x = (st->key.col - elem->width) / 2;
  while (j < elem->height)
    {
      i = 0;
      while (i < elem->width)
	{
	  if (elem->map[j][i] == 1 && st->map[j][i + x] != 0)
	    return (1);
	  i = i + 1;
	}
      j = j + 1;
    }
  return (0);
}

int	check_tetri_error(t_tetris *st)
{
  t_tetriminos *tmp;

  tmp = st->tetriminos->next;
  st->nb_tetri = 0;
  while (tmp != st->tetriminos)
    {
      if (tmp->error == 0)
	st->nb_tetri += 1;
      tmp = tmp->next;
    }
  tmp = st->tetriminos->next;
  while (tmp != st->tetriminos)
    {
      if (tmp->error == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

void	 res_tetri_in_map(int x, int y, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;

  i = 0;
  while (i < elem->height)
    {
      j = 0;
      while (j < elem->width)
	{
	  if (elem->map[i][j] == 1)
	    st->map[i + y - 1][j + x] = 0;
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	 stock_tetri_in_map(int x, int y, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;

  i = 0;
  while (i < elem->height)
    {
      j = 0;
      while (j < elem->width)
	{
	  if (elem->map[i][j] == 1)
	    st->map[i + y - 1][j + x] = elem->color;
	  j = j + 1;
	}
      i = i + 1;
    }
}
