/*
** fct_tetris.c for tetris in /home/mekkao_y/mysql/PSU_2015_tetris
** 
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
** 
** Started on  Sat Mar 19 16:07:59 2016 Youssef Mekkaoui
** Last update Sat Mar 19 17:42:46 2016 Youssef Mekkaoui
*/

#include "tetris.h"

void	res_tetri_in_map(int x, int y, t_tetris *st, t_tetriminos *elem)
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

void	stock_tetri_in_map(int x, int y, t_tetris *st, t_tetriminos *elem)
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
	    st->map[i + y - 1][j + x] = elem->map[i][j];
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	check_down_map(int x, int y, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;

  j = 0;
  while (j < elem->width)
    {
      i = elem->height - 1;
      while (elem->map[i][j] != 1)
	i = i - 1;
      if (st->map[i + y][j + x] == 1)
	return (1);
      j = j + 1;
    }
  return (0);
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
	  if (elem->map[j][i] == 1 && st->map[j][i + x] == 1)
	    return (1);
	  i = i + 1;
	}
      j = j + 1;
    }
  return (0);
}

int	check_right(int x, int y, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;

  j = 0;
  while (j < elem->height)
    {
      i = elem->width - 1;
      while (elem->map[j][i] != 1)
	i = i - 1;
      i = i + 1;
      if (st->map[j + y][i + x] == 1)
	return (1);
      j = j + 1;
    }
  return (0);
}
