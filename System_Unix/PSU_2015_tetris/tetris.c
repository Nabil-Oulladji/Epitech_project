/*
** tetris.c for tetris.h in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Fri Mar 18 23:59:39 2016 Youssef Mekkaoui
** Last update Sun Mar 20 23:29:13 2016 oullad_n
*/

#include <stdlib.h>
#include "tetris.h"

void	init_tetris(t_tetris *st, int ac, char **av)
{
  st->ac = ac;
  st->av = av;
  st->key.level = 1;
  if ((st->key.left = tigetstr("kcub1")) == (char *)-1)
    exit(-1);
  if ((st->key.right = tigetstr("kcuf1")) == (char *)-1)
    exit(-1);
  if ((st->key.turn = tigetstr("kcuu1")) == (char *)-1)
    exit(-1);
  if ((st->key.drop = tigetstr("kcud1")) == (char *)-1)
    exit(-1);
  st->key.quit = "q";
  st->key.pause = " ";
  st->key.row = 20;
  st->key.col = 10;
  st->key.debug = 0;
  st->key.without = 0;
  st->pause = 0;
  st->score_lines = 0;
  st->high_score = 9362;
  st->score = 0;
  st->timer = 0;
}

char		*env_name(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp2(env[i], "TERM=", 5))
	return (&env[i][5]);
      i = i + 1;
    }
  return (NULL);
}
