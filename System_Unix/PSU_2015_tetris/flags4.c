/*
** flags4.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Mar  5 23:43:54 2016 Youssef Mekkaoui
** Last update Sat Mar 19 23:20:45 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"

void	fill_flag2size(char *_row, char *_col, char *str, char *av)
{
  int	j;
  int	col;

  j = 0;
  col = 0;
  while (str[j] != ',')
    {
      _row[j] = str[j];
      j = j + 1;
    }
  _row[j] = '\0';
  j = j + 1;
  if (str[j] == '\0')
    help(av);
  while (str[j])
    {
      _col[col] = str[j];
      col = col + 1;
      j = j + 1;
    }
  _col[col] = '\0';
}
