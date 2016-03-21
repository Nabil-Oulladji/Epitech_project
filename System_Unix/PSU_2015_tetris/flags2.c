/*
** flags2.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Fri Feb 26 15:36:41 2016 Youssef Mekkaoui
** Last update Sat Mar 19 01:47:53 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"

int	flag_newkq(int *i, char **av, t_tetris *st)
{
  *i = *i + 1;
  if (av[*i] == NULL)
    {
      help(av[0]);
    }
  st->key.quit = av[*i];
  return (0);
}

int	flag_newkp(int *i, char **av, t_tetris *st)
{
  *i = *i + 1;
  if (av[*i] == NULL)
    {
      help(av[0]);
    }
  st->key.pause = av[*i];
  return (0);
}

int	flag_2l(int i, char **av, t_tetris *st)
{
  int	j;
  char	*str;

  j = 0;
  while (av[i - 1][j] != '=')
      j = j + 1;
  j = j + 1;
  str = &av[i - 1][j];
  if (str[0] == '\0')
    help(av[0]);
  if ((st->key.level = my_getnbr(str)) <= 0)
    st->key.level = 1;
  return (0);
}

int	flag_2kl(int i, char **av, t_tetris *st)
{
  int	j;
  char	*str;

  j = 0;
  while (av[i - 1][j] != '=')
    j = j + 1;
  j = j + 1;
  str = &av[i - 1][j];
  if (str[0] == '\0')
    help(av[0]);
  st->key.left = str;
  return (0);
}

int	flag_2kr(int i, char **av, t_tetris *st)
{
  int	j;
  char	*str;

  j = 0;
  while (av[i - 1][j] != '=')
    j = j + 1;
  j = j + 1;
  str = &av[i - 1][j];
  if (str[0] == '\0')
    help(av[0]);
  st->key.right = str;
  return (0);
}
