/*
** game_tools2.c for game_tools2 in /home/oullad_n/nabil/rendu/System_Unix/PSU_2015_tetris
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 20 23:22:17 2016 oullad_n
** Last update Sun Mar 20 23:34:53 2016 oullad_n
*/

#include "tetris.h"

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
      if (st->map[j + y - 1][i + x] != 0)
	return (1);
      j = j + 1;
    }
  return (0);
}

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
      if (st->map[j + y - 1][i + x] != 0)
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
  st->score_lines += 1;
  st->score += 15;
  wrefresh(st->wscore);
}

void	drop_tetri(int *y, int *x, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;
  int	max;
  int	down;

  j = 0;
  max = LINES;
  while (j < elem->width)
    {
      i = elem->height - 1;
      while (elem->map[i][j] != 1)
	i = i - 1;
      down = 0;
      while (st->map[i + *y + down][j + *x] == 0)
	down = down + 1;
      if (max > down)
	max = down;
      j = j + 1;
    }
  *y += max;
}  

void	check_left_rotate(int x, int y, t_tetris *st, t_tetriminos *elem)
{
  int	i;
  int	j;
  
  j = 0;
  while (j < elem->height)
    {
      i = 0;
      while (i < elem->width)
	{
	  if (st->map[i + y][j + x] == 1)
	    return ;
	  i = i + 1;
	}
      j = j + 1;
    }
}
