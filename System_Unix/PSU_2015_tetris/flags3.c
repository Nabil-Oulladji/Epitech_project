/*
** flags3.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Mar  5 23:43:14 2016 Youssef Mekkaoui
** Last update Sat Mar 19 23:23:00 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"

int	flag_2kt(int i, char **av, t_tetris *st)
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
  st->key.turn = str;
  return (0);
}

int	flag_2kd(int i, char **av, t_tetris *st)
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
  st->key.drop = str;
  return (0);
}

int	flag_2kp(int i, char **av, t_tetris *st)
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
  st->key.pause = str;
  return (0);
}

int	flag_2kq(int i, char **av, t_tetris *st)
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
  st->key.quit = str;
  return (0);
}

int	flag_2size(int i, char **av, t_tetris *st, int j)
{
  char	*_row;
  char	*_col;
  char	*str;

  if ((_row = malloc(sizeof(char) * my_strlen(av[i - 1]))) == NULL)
    exit(1);
  if ((_col = malloc(sizeof(char) * my_strlen(av[i - 1]))) == NULL)
    exit(1);
  while (av[i - 1][j] != '=')
    j = j + 1;
  j = j + 1;
  str = &av[i - 1][j];
  if (str[0] == '\0')
    help(av[0]);
  if (letter_counter(',', str) == 1)
    fill_flag2size(_row, _col, str, av[0]);
  else
    help(av[0]);
  if (((st->key.row = my_getnbr_good(_row)) < 0) ||
      ((st->key.col = my_getnbr_good(_col)) < 0))
    {
      st->key.col = 1;
      st->key.row = 1;
    }
  return (0);
}
