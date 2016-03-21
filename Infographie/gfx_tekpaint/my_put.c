/*
** my_put.c for tekpaint in /home/mekkao_y/rendu/infographie/gfx_tekpaint
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Jan 27 17:38:36 2016 Youssef Mekkaoui
** Last update Wed Jan 27 19:25:55 2016 nabil oulladji
*/

#include "include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_putstr_ret(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

void	my_putstr_err(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_err(str[i]);
      i = i + 1;
    }
}
