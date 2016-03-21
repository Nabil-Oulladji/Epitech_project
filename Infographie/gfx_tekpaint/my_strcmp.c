/*
** my_strcmp.c for tekpaint in /home/pinta
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Tue Jan 26 15:16:02 2016 pinta_a
** Last update Wed Jan 27 19:27:42 2016 nabil oulladji
*/

#include "include/my.h"

int	my_strcmp(char *str, char *stv)
{
  int	i;

  i = 0;
  while ((str[i] == stv[i]) && str[i] != '\0' && stv[i] != '\0')
    i = i + 1;
  if (str[i] == '\0' && stv[i] == '\0')
    return (1);
  return (0);
}
