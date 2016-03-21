/*
** add_display_x.c for add_display_x in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Thu Dec 17 15:00:41 2015 nabil oulladji
** Last update Sun Dec 20 19:27:03 2015 nabil oulladji
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void		add_x(t_map *st)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y != st->square)
    {
      st->map[st->y_square + y][st->x_square + x] = 'x';
      if (x == (st->square - 1))
	{
	  x = 0;
	  y = y + 1;
	}
      else
	x = x + 1;
    }
  map_o(st);
  display_x(st);
}

void		display_x(t_map *st)
{
  int		x;
  int		y;
  char		*buffer;
  int		i;

  i = 0;
  x = 0;
  y = 0;
  buffer = malloc(sizeof(char) * ((st->nb_colone + 1)
				  * st->nb_ligne));
  while (y != st->nb_ligne)
    {
      while (x != st->nb_colone)
	{
	  buffer[i] = st->map[y][x];
	  i = i + 1;
	  x = x + 1;
	}
      buffer[i] = '\n';
      x = 0;
      y = y + 1;
      i = i + 1;
    }
  write(1, buffer, ((st->nb_colone + 1) * st->nb_ligne));
  free(buffer);
}
