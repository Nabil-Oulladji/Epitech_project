/*
** main.c for main in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 10:21:16 2016 nabil oulladji
** Last update Fri Feb 19 17:42:39 2016 nabil oulladji
*/

#include "struct.h"

int		main(int ac, char **av)
{
  t_all		st;

  av = av;
  if (ac != 1)
    {
      write(2, "Usage: ./allum1\n", 16);
      return (2);
    }
  if (allum1(&st) == 1)
    return (1);
  return (0);
}
