/*
** tools3.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Fri Mar 11 00:03:27 2016 Youssef Mekkaoui
** Last update Sun Mar 20 20:57:53 2016 oullad_n
*/

#include <stdlib.h>
#include "tetris.h"

int	my_backn(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n' && str[i] != '\0')
    i = i + 1;
  if (str[i] == '\0')
    return (-1);
  return (i);
}

int	my_strcompare(char *str, char *dest)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      j = 0;
      while (str[i] == dest[j] && dest[j] && str[i])
	{
	  j = j + 1;
	  i = i + 1;
	  if (j == my_strlen(dest))
	    return (1);
	}
      i = i + 1;
    }
  return (0);
}

void	xexit(t_tetris *tetris, char *msg)
{
  mode(tetris, 1);
  delwin(tetris->wtetris);
  delwin(tetris->wscore);
  delwin(tetris->wnext);
  endwin();
  exit(-1 + my_puterr(msg));
}

int	my_strbiggest(char *str1, char *str2)
{
  int	j;

  j = 0;
  while (str1[j] == str2[j] && str1[j] && str2[j])
    j = j + 1;
  return (str1[j] - str2[j]);
}

void	my_putstr2(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 27)
	my_putstr("^E");
      else if (str[i] == 32)
	my_putstr("(space)");
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}
