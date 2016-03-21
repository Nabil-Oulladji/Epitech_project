/*
** init_value.c for init_value.C in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 16:26:44 2016 nabil oulladji
** Last update Tue Feb  9 17:11:00 2016 nabil oulladji
*/

#include "struct.h"

void		init_value_allum(t_all *st)
{
  st->y = 0;
  st->s = NULL;
  st->tab[0] = 1;
  st->tab[1] = 3;
  st->tab[2] = 5;
  st->tab[3] = 7;
  st->finish = 0;
  st->line = 0;
  st->allum = 0;
  st->r = 0;
}
