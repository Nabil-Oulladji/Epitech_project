/*
** main.c for main in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Thu Dec 17 14:46:16 2015 nabil oulladji
** Last update Fri Dec 18 14:46:22 2015 nabil oulladji
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq.h"

int	main(int ac, char **av)
{
  t_map	*st;

  if ((st = malloc(sizeof(*st))) == NULL)
    return (1);
  init_struct(st);
  if (ac != 2)
    {
      write(2, "Error argument\n", my_strlen("Error argument\n"));
      return (1);
    }
  if (open(av[1], O_RDONLY) == -1)
   {
     write(2, "Error Open\n", my_strlen("Error Open\n"));
     return (1);
   }
  if (read_file(av[1], st) == 1)
    {
      free(st);
      return (1);
    }
  close(open(av[1], O_RDONLY));
  free(st);
  return (0);
}
