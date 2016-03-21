/*
** my_getnbr.c for my_getnbr in /home/oullad_n/rendu/Piscine
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sun Nov 22 18:17:28 2015 nabil oulladji
** Last update Sat Feb 20 01:03:51 2016 nabil oulladji
*/

#include "struct.h"

int		my_getnbr(char *str)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  if (str[i] == '\0')
    return (-2);
  i = 0;
  while (str[i])
    {
      if (str[i] < 48 || str[i] > 57)
	return (-1);
      nb = nb * 10 + (str[i] - 48);
      i = i + 1;
    }
  return (nb);
}
