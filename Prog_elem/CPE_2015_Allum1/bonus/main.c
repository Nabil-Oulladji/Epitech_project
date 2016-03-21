/*
** main.c for main in /home/oullad_n/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb  9 10:21:16 2016 nabil oulladji
** Last update Mon Feb 15 15:56:41 2016 nabil oulladji
*/

#include "struct.h"

int		main(int ac, char **av)
{
  t_all		st;

  if (ac == 1)
    {
      st.size_allum = 4;
      st.player = 0;
    }
  else if (ac == 2)
    {
      st.player = 0;
      if ((st.size_allum = my_getnbr(av[1])) <= 0 || st.size_allum > 85)
	return (printstr(2, "Usage: ./allum1 [0 < size < 86]\n", REDST));
    }
  else if (ac == 3)
    {
      if ((st.size_allum = my_getnbr(av[1])) <= 0 || st.size_allum > 100)
	return (printstr(2, "Usage: ./allum1 [0 < size < 101]\n", REDST));
      if ((st.player = my_getnbr(av[2])) != 2)
	return (printstr(2, "Usage: ./allum1 [0 < size < 101] [2]\n", REDST));
    }
  else
    return (printstr(2, "Usage: ./allum1 [size]\n", REDST));
  if (allum1(&st) == 1)
    return (1);
  return (0);
}
