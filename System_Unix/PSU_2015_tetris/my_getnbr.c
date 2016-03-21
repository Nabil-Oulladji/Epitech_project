/*
** my_getnbr.c for bsq in /home/mekkao_y/rendu/CPE_2015_BSQ
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Dec 12 21:39:22 2015 Youssef Mekkaoui
** Last update Fri Mar 18 23:50:47 2016 Youssef Mekkaoui
*/

#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

int	is_neg(char *str)
{
  int	i;
  int	counter;

  i = 0;
  counter = 0;
  while ((str[i] > '9' || str[i] < '0') && str[i])
    {
      if (str[i] == '-')
	counter++;
      i++;
    }

  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}

int	is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else
    return (0);
}

int	full_check(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i = i + 1;
    }
  return (1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  if (full_check(str) == 0)
    return (-29);
  else if (full_check(str) == -1)
    return (-1);
  if (str[i] == '\0')
    return (-29);
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}

int	my_getnbr_good(char *str)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
