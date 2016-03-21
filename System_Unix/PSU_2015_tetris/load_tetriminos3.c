/*
** load_tetriminos3.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Fri Mar 18 23:17:19 2016 Youssef Mekkaoui
** Last update Sat Mar 19 23:15:35 2016 Youssef Mekkaoui
*/

#include "tetris.h"

void	check_endpiece2(char *buff, t_stock *stock)
{
  if (buff[stock->k] == '\0')
    {
      if (buff[stock->k - 1] == '*')
	{
	  if (stock->max < stock->i)
	    stock->max = stock->i;
	  stock->i = 0;
	  stock->j = stock->j + 1;
	}
      else if (buff[stock->k - 1] == '\n')
	{
	  if (stock->max < stock->i)
	    stock->max = stock->i;
	  stock->i = 0;
	  stock->j = stock->j + 1;
	}
    }
}

int	check_linepiece(char *buff, t_stock *stock)
{
  int	i;

  i = stock->k;
  while (buff[i] != '\n' && buff[i] != '\0')
    {
      if (buff[i] == '*')
	return (1);
      i = i + 1;
    }
  return (0);
}
