/*
** display.c for display in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 16:25:26 2016 nabil oulladji
** Last update Fri Feb 19 21:00:22 2016 nabil oulladji
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
    write(1, "|", 1);
}

void		display_tab(t_all *st)
{
  write(1, "*********\n", 10);
  st->y = 0;
  while (st->y < 4)
    {
      write(1, "*", 1);
      display_space(3 - st->y);
      display_allum(st->tab[st->y]);
      display_space(7 - st->tab[st->y] - (3 - st->y));
      st->y = st->y + 1;
      write(1, "*\n", 2);
    }
  write(1, "*********\n", 10);
  if (st->finish == 0)
    write(1, "\n", 1);
}

void		display_next(t_all *st)
{
  write(1, "Player removed ", 15);
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
