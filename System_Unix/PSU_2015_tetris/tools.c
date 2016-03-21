/*
** tools.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Feb 24 09:51:00 2016 Youssef Mekkaoui
** Last update Sat Mar  5 23:55:55 2016 Youssef Mekkaoui
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_puterr(char *str)
{
  write(2, str, my_strlen(str));
  return (0);
}

int	my_strcmp(char **av, char *str)
{
  int	i;
  int	j;

  i = 0;
  while (av[i])
    {
      j = 0;
      while (av[i][j] == str[j])
	{
	  if (j == my_strlen(str))
	    return (i);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}
