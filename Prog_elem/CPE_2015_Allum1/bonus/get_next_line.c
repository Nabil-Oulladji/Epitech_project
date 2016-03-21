/*
** get_next_line.c for get_next_line in /home/oullad_n/rendu/Prog_elem/CPE_2015_getnextline
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan  6 15:04:11 2016 nabil oulladji
** Last update Fri Jan 22 12:38:58 2016 nabil oulladji
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char		*realloc_line(t_line *st, char buffer[READ_SIZE], int *m)
{
  while (buffer[*m] != '\n' && *m < READ_SIZE)
    *m = *m + 1;
  *m = *m + 1;
  st->l = 0;
  if ((st->tmp = malloc(sizeof(char) * (st->size + st->len + 1))) == NULL)
    return (NULL);
  st->len += st->size;
  while (st->line[st->l] != '\0')
    {
      st->tmp[st->l] = st->line[st->l];
      st->l = st->l + 1;
    }
  while (st->j < st->len)
    {
      st->tmp[st->j] = buffer[st->k];
      if (st->tmp[st->j] == '\n')
	{
	  st->tmp[st->j] = '\0';
	  return (st->tmp);
	}
      st->j = st->j + 1;
      st->k = st->k + 1;
    }
  st->tmp[st->j] = '\0';
  return (st->tmp);
}

int		check_read(t_line *st, char buffer[READ_SIZE], int *i)
{
  if ((*i) >= st->size)
    (*i) = 0;
  while ((*i) < st->size)
    {
      if (buffer[(*i)] == '\n')
	{
	  (*i) = (*i) + 1;
	  return (1);
	}
      (*i) += 1;
    }
  if (st->size != READ_SIZE)
    return (1);
  return (0);
}

int		init_value(t_line *st)
{
  st->line = NULL;
  st->r_read = 0;
  st->size = 0;
  st->len = 0;
  st->n = 0;
  st->j = 0;
  if ((st->line = malloc(sizeof(char))) == NULL)
    return (1);
  st->line[0] = '\0';
  return (0);
}

void		init_value_to_realloc(int *size, int *m, t_line *st)
{
  st->size = *size;
  st->k = *m;
}

char		*get_next_line(const int fd)
{
  t_line	st;
  static int	i;
  static char	buffer[READ_SIZE];
  static int	size;
  static int	m;

  if (init_value(&st) == 1)
    return (NULL);
  while (1)
    {
      st.a = -1;
      if (i >= size)
	{
	  while (++st.a != READ_SIZE)
	    buffer[st.a] = '\0';
	  m = 0;
	  if ((size = read(fd, buffer, READ_SIZE)) <= 0)
	    return (NULL);
	}
      init_value_to_realloc(&size, &m, &st);
      st.r_read = check_read(&st, buffer, &i);
      st.line = realloc_line(&st, buffer, &m);
      if (st.r_read == 1)
	return (st.line);
    }
}
