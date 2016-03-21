/*
** flags.c for flags in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Feb 24 17:44:12 2016 Youssef Mekkaoui
** Last update Sat Mar 19 01:45:05 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"

int	flag_newl(int *i, char **av, t_tetris *st)
{
  *i = *i + 1;
  if ((st->key.level = my_getnbr(av[*i])) <= 0)
    {
      help(av[0]);
    }
  return (0);
}

int	flag_newkl(int *i, char **av, t_tetris *st)
{
  *i = *i + 1;
  if (av[*i] == NULL)
    {
      help(av[0]);
    }
  st->key.left = av[*i];
  return (0);
}

int	flag_newkr(int *i, char **av, t_tetris *st)
{
  *i = *i + 1;
  if (av[*i] == NULL)
    {
      help(av[0]);
    }
  st->key.right = av[*i];
  return (0);
}

int	flag_newkt(int *i, char **av, t_tetris *st)
{
  *i = *i + 1;
  if (av[*i] == NULL)
    {
      help(av[0]);
    }
  st->key.turn = av[*i];
  return (0);
}

int	flag_newkd(int *i, char **av, t_tetris *st)
{
  *i = *i + 1;
  if (av[*i] == NULL)
    {
      help(av[0]);
    }
  st->key.drop = av[*i];
  return (0);
}
