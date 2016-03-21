/*
** read_file.c for read_file in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Thu Dec 17 14:50:19 2015 nabil oulladji
** Last update Sat Dec 19 19:22:51 2015 nabil oulladji
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq.h"

int		my_nb_colone(char *buffer)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (buffer[i] != '\n')
    i = i + 1;
  i = i + 1;
  j = i;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    i = i + 1;
  return (i - j);
}

int		read_file(char *pathname, t_map *st)
{
  struct stat	sb;
  char		*buffer;
  int		size_oct;

  if (stat(pathname, &sb) == -1)
    return (1);
  if ((size_oct = sb.st_size) == 0)
    return (1);
  if (((buffer = malloc(sizeof(char) * size_oct)) == NULL) ||
      (read(open(pathname, O_RDONLY), buffer, size_oct) <= 3))
    return (1);
  if (buffer[size_oct - 1] != '\n')
    return (1);
  buffer[size_oct - 1] = '\0';
  st->nb_ligne = my_getnbr(buffer);
  st->nb_colone = my_nb_colone(buffer);
  if (check_error(st, buffer) == 1)
    return (1);
  if (malloc_map(st) == 1 || malloc_dem(st) == 1)
    return (1);
  stock_map(buffer, st);
  free(buffer);
  free_dem(st);
  free_map(st);
  return (0);
}
