/*
** my_put_nbr.c for my_put_nbr in /home/oullad_n/rendu/Piscine_C_J03
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Thu Oct  1 09:40:27 2015 nabil oulladji
** Last update Mon Feb  1 18:28:03 2016 nabil oulladji
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
    }
  nb = nb % 10;
  my_putchar(nb + 48);
}
