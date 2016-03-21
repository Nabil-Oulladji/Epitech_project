/*
** init_value.c for init_value.C in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 16:26:44 2016 nabil oulladji
** Last update Thu Feb 11 17:13:58 2016 nabil oulladji
*/

#include "struct.h"

int		init_value_allum(t_all *st)
{
  int		i;

  i = -1;
  if ((st->tab = malloc(sizeof(int) * st->size_allum)) == NULL)
    return (1);
  while (++i < st->size_allum)
    st->tab[i] = i * 2 + 1;
  st->y = 0;
  st->s = NULL;
  st->finish = 0;
  st->line = 0;
  st->allum = 0;
  st->r = 0;
  return (0);
}
