/*
** check_allum.c for check_allum in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 16:27:24 2016 nabil oulladji
** Last update Thu Feb 11 18:03:28 2016 nabil oulladji
*/

#include "struct.h"

int		display_if_win(t_all *st)
{
  st->finish = 1;
  display_next(st);
  display_tab(st);
  if (st->player != 0)
    {
      printstr(1, "Player ", GREENST);
      if (st->player == 2)
	st->player = 1;
      else
	st->player = 2;
      my_put_nbr(st->player);
      printstr(1, " WIN !!!\n", GREENST);
    }
  else
    write(1, "You lost, too bad..\n", 20);
  return (1);
}

int		check_allum(t_all *st)
{
  int		i;
  int		j;

  j = 0;
  i = -1;
  while (++i < st->size_allum)
    if (st->tab[i] == 0)
      j = j + 1;
  if (j == st->size_allum)
    return (display_if_win(st));
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
  while (++i < st->size_allum)
    if (st->tab[i] == 0)
      j = j + 1;
  if (j == st->size_allum)
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
