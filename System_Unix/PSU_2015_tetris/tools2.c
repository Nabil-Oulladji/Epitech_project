/*
** tools2.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Mar  5 23:56:54 2016 Youssef Mekkaoui
** Last update Thu Mar 17 17:56:02 2016 Youssef Mekkaoui
*/

#include "tetris.h"

int	my_strcmp2(char *av, char *str)
{
  int	j;

  j = 0;
  while (av[j] == str[j])
    {
      if (j == my_strlen(str))
	return (j);
      j = j + 1;
    }
  return (0);
}

int	my_strncmp2(char *av, char *str, int n)
{
  int	j;

  j = 0;
  while (av[j] == str[j])
    {
      j = j + 1;
      if (j == n)
	return (j);
    }
  return (0);
}

int	my_strncmp(char **av, char *str, int n)
{
  int	i;
  int	j;

  i = 0;
  while (av[i])
    {
      j = 0;
      while (av[i][j] == str[j])
	{
	  j = j + 1;
	  if (j == n)
	    return (i);
	}
      i = i + 1;
    }
  return (0);
}

char	*my_strcpy(char *str, char *txt, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      str[i] = txt[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

int	my_intlen(int nb)
{
  int	i;

  i = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      i = i + 1;
    }
  return (i);
}
