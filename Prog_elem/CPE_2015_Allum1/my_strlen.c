/*
** my_strlen.c for my_strlen in /home/oullad_n/rendu/System_Unix/PSU_2015_minishell1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan 20 15:28:13 2016 nabil oulladji
** Last update Fri Feb 19 20:52:24 2016 nabil oulladji
*/

#include "struct.h"

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}

int		my_dis(int i, char *str)
{
  write(1, str, my_strlen(str));
  return (i);
}
