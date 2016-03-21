/*
** allum1.c for allum1 in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 10:30:03 2016 nabil oulladji
** Last update Sat Feb 20 19:06:40 2016 nabil oulladji
*/

#include <time.h>
#include "struct.h"

int		wait_turn_matches(t_all *st)
{
  while (st->tab[st->line - 1] < st->allum || st->allum <= 0)
    {
      write(1, "Matches: ", 9);
      if ((st->s = get_next_line(0)) == NULL)
	return (1);
      st->allum = my_getnbr(st->s);
      free(st->s);
      if (st->allum == 0)
	return (my_dis(2, "Error: you have to remove at least one match\n"));
      else if (st->allum == -1 || st->allum == -2)
	return (my_dis(2, "Error: invalid input (positive number expected)\n"));
      else if (st->tab[st->line - 1] < st->allum)
	return (my_dis(2, "Error: not enough matches on this line\n"));
      else
	{
	  st->tab[st->line - 1] = st->tab[st->line - 1] - st->allum;
	  return (0);
	}
    }
  return (0);
}

int		wait_turn_line(t_all *st)
{
  while (st->line <= 0 || st->line >= 5 || st->tab[st->line - 1] == 0)
    {
      write(1, "Line: ", 6);
      if ((st->s = get_next_line(0)) == NULL)
	return (1);
      st->line = my_getnbr(st->s);
      free(st->s);
      if (st->line == -1 || st->line == -2)
	write(1, "Error: invalid input (positive number expected)\n", 48);
      else if (st->line == 0 || st->line >= 5)
	write(1, "Error: this line is out of range\n", 33);
      else if (st->tab[st->line - 1] == 0)
        write(1, "Error: this line is empty\n", 26);
      else
	{
	  if ((st->r = wait_turn_matches(st)) == 1)
	    return (1);
	  else if (st->r == 0)
	    return (0);
	  st->line = 0;
	}
    }
  return (0);
}

void		wait_IA_turn(t_all *st)
{
  int		i;
  int		retest;
  int		j;

  retest = 0;
  st->line = 0;
  st->allum = 0;
  while (retest == 0)
    {
      srand(time(NULL));
      if (st->tab[(j = (i = rand()) % 4)] > 1)
	{
	  st->line = j + 1;
	  st->allum = st->tab[j] - 1;
	  st->tab[j] = 1;
	  retest = 1;
	}
      else if (st->tab[(j = i % 4)] > 0)
	{
	  st->line = j + 1;
	  st->allum = st->tab[j];
	  st->tab[j] = 0;
	  retest = 1;
	}
    }
}

int		allum1(t_all *st)
{
  init_value_allum(st);
  display_tab(st);
  while (st->finish != 1)
    {
      write(1, "Your turn:\n", 11);
      st->line = 0;
      st->allum = 0;
      if (wait_turn_line(st) == 1)
	return (1);
      if (check_allum(st) == 1)
	return (0);
      wait_IA_turn(st);
      if (check_allum_IA(st) == 1)
	return (0);
    }
  return (0);
}
