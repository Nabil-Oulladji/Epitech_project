/*
** game_tools3.c for game_tools3 in /home/oullad_n/nabil/rendu/System_Unix/PSU_2015_tetris
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 20 23:23:22 2016 oullad_n
** Last update Sun Mar 20 23:23:37 2016 oullad_n
*/

#include "tetris.h"

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
      if (st->map[i + y][j + x] != 0)
	return (1);
      j = j + 1;
    }
  return (0);
}
