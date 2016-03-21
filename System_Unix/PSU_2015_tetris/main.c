/*
** main.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Feb 24 09:48:00 2016 Youssef Mekkaoui
** Last update Sun Mar 20 19:24:19 2016 oullad_n
*/

#include <term.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"

void	malloc_newmap(t_tetris *st)
{
  int	i;

  i = 0;
  if ((st->map = malloc(sizeof(int *) * st->key.row)) == NULL)
    exit(-1);
  while (i < st->key.row)
    {
      if ((st->map[i] = malloc(sizeof(int) * st->key.col)) == NULL)
	exit(-1);
      i = i + 1;
    }
}

int	map(t_tetris *st)
{
  int	i;
  int	j;

  i = 0;
  st->key.row += 1;
  st->key.col += 2;
  malloc_newmap(st);
  while (i < st->key.row)
    {
      st->map[i][0] = -1;
      j = 1;
      while (j < st->key.col - 1)
	{
	  if (i == st->key.row - 1)
	    st->map[i][j] = -1;
	  else
	    st->map[i][j] = 0;
	  j = j + 1;
	}
      st->map[i][j] = -1;
      i = i + 1;
    }
  return (1);
}

int		main(int ac, char **av, char **env)
{
  
  t_tetris	st;
  int		erreur;

  if ((env_name(env) == NULL) || (setupterm(env_name(env), 1, &erreur) == -1))
    exit(-1);
  init_tetris(&st, ac, av);
  if (checker2(av, &st) == 1)
    return (1);
  st.tetriminos = init_tetriminos();
  map(&st);
  load_tetriminos(&st);
  if (st.key.debug == 1)
    debug(&st);
  if (COLS < st.key.col || LINES < st.key.row)
    return (1 + my_puterr("Resize your terminal\n"));
  game(&st);
  return (0);
}
