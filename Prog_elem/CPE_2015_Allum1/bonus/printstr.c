/*
** printstr.c for printstr in /home/oullad_n/rendu/System_Unix/PSU_2015_minishell1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan 20 15:28:13 2016 nabil oulladji
** Last update Fri Jan 22 12:35:40 2016 nabil oulladji
*/

#include "struct.h"

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]) {}
  return (i);
}

int		printstr(int output, char *s, char *color)
{
  write(output, color, my_strlen(color));
  write(output, s, my_strlen(s));
  write(output, RESET, my_strlen(RESET));
  if (output == 2)
    return (-1);
  return (my_strlen(s));
}
