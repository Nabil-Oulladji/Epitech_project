/*
** my_check_error.c for my_check_error in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Thu Dec 17 22:35:40 2015 nabil oulladji
** Last update Sat Dec 19 19:20:32 2015 nabil oulladji
*/

#include <stdio.h>
#include "bsq.h"

int		error_nb(t_map *st, char *buffer, int i)
{
  int		n;

  n = 0;
  if (my_getnbr(buffer) <= 0)
    return (1);
  while (buffer[i] != '\n')
    i = i + 1;
  i = i + 1;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	n = n + 1;
      i = i + 1;
    }
  n = n + 1;
  if (st->nb_ligne != n)
    return (1);
  return (0);
}

int		error_caractere(char *buffer, int i)
{
  while (buffer[i] != '\n')
    i = i + 1;
  i = i + 1;
  while (buffer[i] != '\0')
    {
      if (buffer[i] != '\n' &&
       	  buffer[i] != '.' && buffer[i] != 'o')
       	return (1);
      i = i + 1;
    }
  return (0);
}

void		nb_1(char *buffer, int i)
{
  int		n;

  n = 0;
  while (buffer[i] != '\n')
    {
      i = i + 1;
    }
  i = i + 1;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '.' && n == 0)
	{
	  buffer[i] = 'x';
	  n = 1;
	}
      my_putchar(buffer[i]);
      i = i + 1;
    }
  my_putchar('\n');
}

void		map_o(t_map *st)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  if (st->square != 0)
    return ;
  while (y != st->nb_ligne)
    {
      x = 0;
      while (x != st->nb_colone)
	{
	  if (st->map[y][x] == '.')
	    {
	      st->map[y][x] = 'x';
	      return ;
	    }
	  x = x + 1;
	}
      y = y + 1;
    }
}

int		check_error(t_map *st, char *buffer)
{
  int		i;

  i = 0;
  if (error_nb(st, buffer, i) == 1)
    return (1);
  if (error_caractere(buffer, i) == 1)
    return (1);
  if (st->nb_ligne == 1 || st->nb_colone == 1)
    {
      nb_1(buffer, i);
      return (1);
    }
  return (0);
}

