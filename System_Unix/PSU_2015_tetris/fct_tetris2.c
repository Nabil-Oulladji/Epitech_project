/*
** fct_tetris2.c for tetris in /home/mekkao_y/mysql/PSU_2015_tetris
** 
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
** 
** Started on  Sat Mar 19 16:29:47 2016 Youssef Mekkaoui
** Last update Sat Mar 19 17:15:13 2016 Youssef Mekkaoui
*/

#include "tetris.h"

int	check_left(int x, int y, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;

  j = 0;
  while (j < elem->height)
    {
      i = 0;
      while (elem->map[j][i] != 1)
	i = i + 1;
      i = i - 1;
      if (st->map[j + y][i + x] == 1)
	return (1);
      j = j + 1;
    }
  return (0);
}

void	del_line(int j, t_tetris *st)
{
  int	i;

  i = 1;
  while (i < st->key.col - 1)
    {
      st->map[j][i] = 0;
      i = i + 1;
    }
  while (j > 0)
    {
      i = 1;
      while (i < st->key.col - 1)
	{
	  st->map[j][i] = st->map[j - 1][i];
	  i = i + 1;
	}
      j = j - 1;
    }
}

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
	  if (st->map[j][i] == 1)
	    x = x + 1;
	  i = i + 1;
	}
      if (x == st->key.col)
	del_line(j, st);
      j = j + 1;
    }
}

int	check_left_rotate(int x, int y, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;

  j = 0;
  while (j < elem->height)
    {
      i = 0;
      while (i < elem->width)
	{
	  if (st->map[j + y][1 + x] == 1)
	    return (1);
	  i = i + 1;
	}
      j = j + 1;
    }
  return (0);
}
