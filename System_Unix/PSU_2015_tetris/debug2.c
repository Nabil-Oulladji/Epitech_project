/*
** debug2.c for debug in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Fri Mar 18 23:18:48 2016 Youssef Mekkaoui
** Last update Fri Mar 18 23:38:49 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"

void	display_key(t_tetris *st)
{
  my_putstr("Key Left : ");
  my_putstr2(st->key.left);
  my_putchar(10);
  my_putstr("Key Right : ");
  my_putstr2(st->key.right);
  my_putchar(10);
  my_putstr("Key Turn : ");
  my_putstr2(st->key.turn);
  my_putchar(10);
  my_putstr("Key Drop : ");
  my_putstr2(st->key.drop);
  my_putchar(10);
  my_putstr("Key Quit : ");
  my_putstr2(st->key.quit);
  my_putchar(10);
  my_putstr("Key Pause : ");
  my_putstr2(st->key.pause);
  my_putchar(10);
}

int		tetri_nb(t_tetris *st)
{
  int		i;
  t_tetriminos	*elem;

  elem = st->tetriminos->next;
  i = 0;
  while (elem != st->tetriminos)
    {
      i = i + 1;
      elem = elem->next;
    }
  my_putstr("Tetriminos : ");
  my_put_nbr(i);
  my_putchar(10);
  return (i);
}

char	*only_tetriname(char *name)
{
  int	i;
  int	j;
  int	k;
  char	*s;

  i = my_strlen(name) - 1;
  j = my_strlen(name) - 1;
  k = 0;
  if ((s = malloc(sizeof(char) * my_strlen(name))) == NULL)
    exit(-1);
  while (i != 0 && name[i] != '/')
    i = i - 1;
  i = i + 1;
  while (name[j] != '.' && j > i)
    j = j - 1;
  while (i < j)
    {
      s[k] = name[i];
      i = i + 1;
      k = k + 1;
    }
  s[k] = '\0';
  return (s);
}

void	debug_tetrimap(t_tetriminos *elem)
{
  int	i;
  int	j;
  int	_j;

  i = 0;
  while (i < elem->height)
    {
      _j = 0;
      j = elem->width - 1;
      while (elem->map[i][j] != 1)
	j = j - 1;
      while (_j <= j)
	{
	  if (elem->map[i][_j] == 2)
	    my_putchar(' ');
	  else if (elem->map[i][_j] == 1)
	    my_putchar('*');
	  _j = _j + 1;
	}
      my_putchar('\n');
      i = i + 1;
    }
}
