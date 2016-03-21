/*
** get_next_line.c for get_next_line in /home/mekkao_y/rendu/cprogelem/CPE_2015_getnextline
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Mon Jan  4 12:48:53 2016 Youssef Mekkaoui
** Last update Fri Mar 18 23:24:01 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "get_next_line.h"

int	isreturn(char *str, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (str[i] == '\n')
	return (i);
      i = i + 1;
    }
  return (i);
}

char	*before(char *save, int save_size)
{
  char	*str;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (i < save_size && save[i] != '\n')
    i = i + 1;
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  while (j < i)
  {
    str[j] = save[j];
    j = j + 1;
  }
  str[j] = '\0';
  return (str);
}

char	*after(char *save, int *save_size)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < *save_size && save[i] != '\n')
    i = i + 1;
  i = i + 1;
  str = &save[i];
  while (str[j])
    {
      j = j + 1;
    }
  *save_size = j;
  return (str);
}

char	*my_realloc(char *str, char *buff, int str_size, int size)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(char) * (str_size + size + 1))) == NULL)
    return (NULL);
  while (i < str_size)
    {
      new[i] = str[i];
      i = i + 1;
    }
  while (j < size)
    {
      new[i] = buff[j];
      j = j + 1;
      i = i + 1;
    }
  new[i] = '\0';
  return (new);
}

char		*get_next_line(const int fd)
{
  static char	*save;
  static int	save_size;
  static char	buff[READ_SIZE];
  t_gnl		gnl;

  if (save == NULL)
    save = "\0";
  while ((gnl.size = read(fd, buff, READ_SIZE)) > 0 &&
	 (gnl.next = isreturn(buff, gnl.size)) == gnl.size)
    {
      if ((save = my_realloc(save, buff, save_size, gnl.size)) == NULL)
	return (NULL);
      save_size = save_size + gnl.size;
    }
  if ((save = my_realloc(save, buff, save_size, gnl.size)) == NULL)
    return (NULL);
  gnl.next = isreturn(buff, gnl.size);
  save_size = save_size + gnl.size;
  if (save_size <= 0 || save_size == 0)
    return (NULL);
  if ((gnl.str = before(save, save_size)) == NULL)
    return (NULL);
  gnl.str = before(save, save_size);
  save = after(save , &save_size);
  return (gnl.str);
}
