/*
** pochon.c for tekpaint in /home/oullad_n/rendu/Infographie/pute/gfx_tekpaint
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan 27 20:11:48 2016 nabil oulladji
** Last update Wed Jan 27 20:15:31 2016 nabil oulladji
*/

#include "include/my.h"

void            my_puthow(void)
{
  my_putstr("./tekpaint\n");
  my_putstr("\t\t-l [file] [name] (load 'file.velo' and save it as 'name')\n");
  my_putstr("\t\t-n [name] [width] [height] (create a new");
  my_putstr("file and save it as 'name white 'width' and");
  my_putstr("'height' size)\n");
  my_putstr("\t\t-b [file] [name] (load 'file.bmp'");
  my_putstr("and save it it as 'name')\n\n");
}

int		my_test(t_loop *loop, char **argv, int argc)
{
  if (argc == 2 && my_strcmp(argv[1], "--help"))
    {
      my_puthow();
      return (1);
    }
  if (argc == 4 && my_strcmp(argv[1], "-l"))
    {
      if (init_all_load(loop, argv))
	return (2);
    }
  else if (argc == 4 && my_strcmp(argv[1], "-b"))
    {
      if (init_all_bmp(loop, argv))
	return (my_putstr_ret("Failed to open .bmp file\n"));
    }
  else if (argc == 5 && my_strcmp(argv[1], "-n"))
    {
      if (init_all_create(loop, argv) != NULL)
        return (1 + my_putstr_ret(init_all_create(loop, argv)));
    }
  else
    return (1 + my_putstr_ret("Type ./tekpaint --help\n"));
  return (0);
}
