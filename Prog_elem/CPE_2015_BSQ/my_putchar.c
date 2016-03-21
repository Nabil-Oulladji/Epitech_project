/*
** my_putchar.c for my_putchar in /home/oullad_n/work
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Fri Oct  2 23:01:04 2015 nabil oulladji
** Last update Wed Dec  9 19:17:02 2015 nabil oulladji
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
