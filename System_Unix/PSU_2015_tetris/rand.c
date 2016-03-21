/*
** rand.c for rand in /home/oullad_n/nabil/rendu/System_Unix/youss/test1/tetris
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 20 14:16:23 2016 oullad_n
** Last update Sun Mar 20 19:02:30 2016 oullad_n
*/

#include <stdlib.h>
#include "tetris.h"

t_tetriminos		*rand_tetri(t_tetris *st, t_tetriminos *elem)
{
  int		i;
  int		rd;

  i = 0;
  rd = rand() % st->nb_tetri;
  while (i < rd)
    {
      elem = elem->next;
      if (elem == st->tetriminos)
	elem = st->tetriminos->next;
      while (elem->error == 1)
	{
	  elem = elem->next;
	  if (elem == st->tetriminos)
	    elem = st->tetriminos->next;
	}
      i = i + 1;
    }
  return (elem);
}
