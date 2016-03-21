/*
** tools4.c for tetris in /home/mekkao_y/mysql/PSU_2015_tetris
** 
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
** 
** Started on  Sat Mar 19 16:07:32 2016 Youssef Mekkaoui
** Last update Sat Mar 19 16:07:37 2016 Youssef Mekkaoui
*/

#include "tetris.h"

int	found(char *av, char s[10][12])
{
  int	j;

  j = 0;
  while (s[j] && j < 10)
    {
      if (my_strcmp2(av, s[j]))
      	return (j);
      j = j + 1;
    }
  return (-1);
}
