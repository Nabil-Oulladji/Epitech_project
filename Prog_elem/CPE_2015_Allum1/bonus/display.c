/*
** display.c for display in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 16:25:26 2016 nabil oulladji
** Last update Sat Feb 20 01:20:25 2016 nabil oulladji
*/

#include "struct.h"

void		display_space(int i)
{
  int		y;

  y = -1;
  while (++y < i)
    write(1, " ", 1);
}

void		display_allum(int i)
{
  int		y;

  y = -1;
  while (++y < i)
    printstr(1, "|", GREENST);
}

void		display_tab(t_all *st)
{
  st->y = -1;
  while (++st->y < st->size_allum * 2 + 1)
    printstr(1, "*", BLUEST);
  write(1, "\n", 1);
  st->y = -1;
  while (++st->y < st->size_allum)
    {
      printstr(1, "*", BLUEST);
      display_space(st->size_allum - st->y - 1);
      display_allum(st->tab[st->y]);
      display_space((st->size_allum * 2) -
		    st->tab[st->y] - (st->size_allum - st->y));
      printstr(1, "* (", BLUEST);
      my_put_nbr(st->y + 1);
      printstr(1, ")", BLUEST);
      printstr(1, " (", REDST);
      my_put_nbr(st->tab[st->y]);
      printstr(1, ")\n", REDST);
    }
  st->y = -1;
  while (++st->y < st->size_allum * 2 + 1)
    printstr(1, "*", BLUEST);
  write(1, "\n", 1);
  if (st->finish == 0)
    write(1, "\n", 1);
}

void		display_next(t_all *st)
{
  write(1, "Player ", 7);
  if (st->player != 0)
    {
      my_put_nbr(st->player);
      write(1, " removed ", 9);
    }
  else
    write(1, "removed ", 8);
  my_put_nbr(st->allum);
  write(1, " match(es) from line ", 21);
  my_put_nbr(st->line);
  write(1, "\n", 1);
}

void		display_next_IA(t_all *st)
{
  write(1, "AI's turn...", 12);
  write(1, "\nAI removed ", 12);
  my_put_nbr(st->allum);
  write(1, " match(es) from line ", 21);
  my_put_nbr(st->line);
  write(1, "\n", 1);
}
