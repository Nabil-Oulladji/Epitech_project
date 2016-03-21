/*
** my_getnbr.c for my_getnbr in /home/oullad_n/rendu/Piscine
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sun Nov 22 18:17:28 2015 nabil oulladji
** Last update Thu Mar 10 23:15:21 2016 oullad_n
*/

#include "struct.h"

int		my_number(const char *str, int nb_neg, int i)
{
  int		nb;
  int		tmp;

  nb = 0;
  tmp = 0;
  while (str[i] && str[i] >= 48 && str[i] <= 57)
    {
     tmp = nb;
      if (tmp > (nb * 10 + (str[i] - 48)))
        return (0);
      nb = nb * 10 + (str[i++] - 48);
    }
  if (nb_neg % 2 == 1)
    nb = nb * -1;
  return (nb);
}

int		my_getnbr(const char *str)
{
  int		i;
  int		nb;
  int		nb_neg;

  i = 0;
  nb_neg = 0;
  while (str[i])
    {
      if (str[i] == '-')
        nb_neg++;
      if (str[i] >= 48 && str[i] <= 57)
        {
          nb = my_number(str, nb_neg, i);
          return (nb);
        }
      i++;
    }
  return (0);
}
