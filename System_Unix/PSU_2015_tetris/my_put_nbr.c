/*
** my_put_nbr.c for putnbr in /home/mekkao_y/rendu/PSU_2015_my_printf_bootstrap
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Nov  4 15:34:22 2015 Youssef Mekkaoui
** Last update Fri Mar 18 23:43:52 2016 Youssef Mekkaoui
*/

#include <unistd.h>
#include "tetris.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb / 10 != 0)
    my_put_nbr(nb / 10);
  my_putchar((nb % 10) + '0');
}
