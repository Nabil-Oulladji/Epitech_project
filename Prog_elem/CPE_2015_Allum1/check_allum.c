/*
** check_allum.c for check_allum in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 16:27:24 2016 nabil oulladji
** Last update Tue Feb  9 19:29:54 2016 nabil oulladji
*/

#include "struct.h"

int		check_allum(t_all *st)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (i < 4)
    {
      if (st->tab[i] == 0)
	j = j + 1;
      i = i + 1;
    }
  if (j == 4)
    {
      st->finish = 1;
      display_next(st);
      display_tab(st);
      write(1, "You lost, too bad..\n", 20);
      return (1);
    }
  else
    {
      display_next(st);
      display_tab(st);
    }
  return (0);
}

int		check_allum_IA(t_all *st)
{
  int		i;
  int		j;

  j = 0;
  i = -1;
  while (++i < 4)
    if (st->tab[i] == 0)
      j = j + 1;
  if (j == 4)
    {
      st->finish = 1;
      display_next_IA(st);
      display_tab(st);
      write(1, "I lost.. snif.. but I'll get you next time!!\n", 45);
      return (1);
    }
  else
    {
      display_next_IA(st);
      display_tab(st);
    }
  return (0);
}
