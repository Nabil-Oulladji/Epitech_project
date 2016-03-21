/*
** malloc_free.c for malloc_free in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Thu Dec 17 14:40:03 2015 nabil oulladji
** Last update Thu Dec 17 18:00:23 2015 nabil oulladji
*/

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void		init_struct(t_map *st)
{
  st->nb_ligne = 0;
  st->nb_colone = 0;
  st->x_square = 0;
  st->y_square = 0;
  st->r_count = 0;
  st->square = 0;
}

int		malloc_dem(t_map *st)
{
  int		y;

  y = 0;
  if ((st->dem = malloc(sizeof(int *) * (st->nb_ligne))) == NULL)
    return (1);
  while (y < st->nb_ligne)
    {
      if ((st->dem[y] = malloc(sizeof(int) * (st->nb_colone))) == NULL)
	{
	  write(2, "Error malloc\n", my_strlen("Error malloc\n"));
	  return (1);
	}
      y = y + 1;
    }
  return (0);
}

void		free_dem(t_map *st)
{
  int		y;

  y = st->nb_ligne - 1;
  while (y >= 0)
    {
      free(st->dem[y]);
      y = y - 1;
    }
  free(st->dem);
}

int		malloc_map(t_map *st)
{
  int		y;

  y = 0;
  if ((st->map = malloc(sizeof(char *) * (st->nb_ligne + 1))) == NULL)
    return (1);
  while (y < st->nb_ligne)
    {
      if ((st->map[y] = malloc(sizeof(char) * (st->nb_colone))) == NULL)
	{
	  write(2, "Error malloc\n", my_strlen("Error malloc\n"));
	  return (1);
	}
      y = y + 1;
    }
  return (0);
}

void		free_map(t_map *st)
{
  int		y;

  y = st->nb_ligne - 1;
  while (y >= 0)
    {
      free(st->map[y]);
      y = y - 1;
    }
  free(st->map);
}
