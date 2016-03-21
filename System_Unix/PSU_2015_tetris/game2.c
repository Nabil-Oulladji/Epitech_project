/*
** game2.c for tetris in /home/mekkao_y/mysql/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Mar 19 16:47:10 2016 Youssef Mekkaoui
** Last update Sun Mar 20 23:13:39 2016 oullad_n
*/

#include "tetris.h"

void	my_key(t_tetris *st, t_tetriminos *elem, int *x, int *y)
{
  int	key;
  int	i;
  int	j;

  i = *x;
  j = *y;
  if ((key = get_key(st)) == 1)
    {
      if (check_left(i, j, st, elem) == 0)
	*x = *x - 1;
    }
  else if (key == 2)
    {
      if (check_right(i, j, st, elem) == 0)
	*x = *x + 1;
    }
  else if (key == 3)
    check_left_rotate(i, j, st, elem);
  else if (key == 4)
    drop_tetri(y, x, st, elem);
  else if (key == 5)
    xexit(st, "See you again :)\n");
  else if (key == 6)
    while (get_key(st) != 6);
}
