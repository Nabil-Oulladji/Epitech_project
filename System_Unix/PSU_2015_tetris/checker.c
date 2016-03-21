/*
** checker.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Feb 24 09:50:12 2016 Youssef Mekkaoui
** Last update Sat Mar 19 23:23:18 2016 Youssef Mekkaoui
*/

#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

int	letter_counter(char counter, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == counter)
	j = j + 1;
      i = i + 1;
    }
  return (j);
}

void	my_double(int i, char **av, t_tetris *st)
{
  if (my_strncmp2(av[i], "--help", 6))
    help(av[0]);
  if (my_strncmp2(av[i], "--level=", 8))
    flag_2l(i + 1, av, st);
  else if (my_strncmp2(av[i], "--key-left=", 11))
    flag_2kl(i + 1, av, st);
  else if (my_strncmp2(av[i], "--key-right=", 12))
    flag_2kr(i + 1, av, st);
  else if (my_strncmp2(av[i], "--key-turn=", 11))
    flag_2kt(i + 1, av, st);
  else if (my_strncmp2(av[i], "--key-drop=", 11))
    flag_2kd(i + 1, av, st);
  else if (my_strncmp2(av[i], "--key-pause=", 12))
    flag_2kp(i + 1, av, st);
  else if (my_strncmp2(av[i], "--key-quit=", 11))
    flag_2kq(i + 1, av, st);
  else if (my_strncmp2(av[i], "--debug", 7))
    st->key.debug = 1;
  else if (my_strncmp2(av[i], "--without-next", 14))
    st->key.without = 1;
  else if (my_strncmp2(av[i], "--map-size=", 11))
    flag_2size(i + 1, av, st, 0);
  else
    help(av[0]);
}

void	fill_tab_opt(char s[10][12])
{
  my_strcpy(s[0], "--help", 6);
  my_strcpy(s[1], "-l", 2);
  my_strcpy(s[2], "-kl", 3);
  my_strcpy(s[3], "-kr", 3);
  my_strcpy(s[4], "-kt", 3);
  my_strcpy(s[5], "-kd", 3);
  my_strcpy(s[6], "-kq", 3);
  my_strcpy(s[7], "-kp", 3);
  my_strcpy(s[8], "-w", 2);
  my_strcpy(s[9], "-d", 2);
}

int	my_cmd2(int *i, int j, char **av, t_tetris *st)
{
  if (j == 0)
    help(av[0]);
  else if (j == 1)
    flag_newl(i, av, st);
  else if (j == 2)
    flag_newkl(i, av, st);
  else if (j == 3)
    flag_newkr(i, av, st);
  else if (j == 4)
    flag_newkt(i, av, st);
  else if (j == 5)
    flag_newkd(i, av, st);
  else if (j == 6)
    flag_newkq(i, av, st);
  else if (j == 7)
    flag_newkp(i, av, st);
  else if (j == 8)
    st->key.without = 1;
  else if (j == 9)
    st->key.debug = 1;
  return (0);
}

int	checker2(char **av, t_tetris *st)
{
  int	i;
  int	j;
  char	s[10][12];

  i = 1;
  fill_tab_opt(s);
  while (av[i])
    {
      if (letter_counter('-', av[i]) == 1)
	{
	  if ((j = found(av[i], s)) >= 0)
	    my_cmd2(&i, j, av, st);
	  else
	    help(av[0]);
	}
      else
	my_double(i, av, st);
      i = i + 1;
    }
  return (0);
}
