/*
** bsq.c for bsq in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Thu Dec 10 16:47:50 2015 nabil oulladji
** Last update Thu Dec 17 22:10:09 2015 nabil oulladji
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"

void		init_dem(t_map *st)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y <= st->nb_ligne - 1)
    {
      while (x <= st->nb_colone - 1)
	{
	  if (st->map[y][x] == '.')
	    st->dem[y][x] = 1;
	  else if (st->map[y][x] == 'o')
	    st->dem[y][x] = 0;
	  x = x + 1;
	}
      y = y + 1;
      x = 0;
    }
}

int		count(t_map *st, int x, int y)
{
  int		a;
  int		b;
  int		c;

  a = st->dem[y][x + 1];
  b = st->dem[y + 1][x];
  c = st->dem[y + 1][x + 1];
  if (a > b)
    a = b;
  if (a > c)
    a = c;
  return (a + 1);
}

void		algo_bsq(t_map *st, int x, int y)
{
  y = st->nb_ligne - 2;
  x = st->nb_colone - 2;
  init_dem(st);
  while (y != -1)
    {
      while (x != -1)
	{
	  st->r_count = 0;
	  if (st->dem[y][x] != 0)
	    {
	      st->r_count = count(st, x, y);
	      st->dem[y][x] = st->r_count;
	    }
	  if (st->r_count >= st->square)
	    {
	      st->square = st->r_count;
	      st->x_square = x;
	      st->y_square = y;
	    }
	  x = x - 1;
	}
      x = st->nb_colone - 2;
      y = y - 1;
    }
}

void		stock_map(char *buffer, t_map *st)
{
  int		x;
  int		y;
  int		i;

  y = 0;
  i = 0;
  while (buffer[i] != '\n')
    i = i + 1;
  i = i + 1;
  while (y < st->nb_ligne)
    {
      x = 0;
      while (x < st->nb_colone)
	{
	  if (buffer[i] != '\n')
	    {
	      st->map[y][x] = buffer[i];
	      x = x + 1;
	    }
	  i = i + 1;
	}
      y = y + 1;
    }
  algo_bsq(st, x, y);
  add_x(st);
}
