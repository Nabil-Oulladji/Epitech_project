/*
** main.c for main in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb 23 10:54:01 2016 nabil oulladji
** Last update Thu Mar 10 22:22:03 2016 oullad_n
*/

#include <unistd.h>
#include "struct.h"

int		main(int ac, char **av)
{
  t_ray		st;

  if (ac != 2)
    {
      write(2, "Usage: ./raytracer1 [fichier.ini]\n", 34);
      return (1);
    }
  if (read_file(av[1], &st) == 1)
    return (1);
  init_value(&st);
  st.win = bunny_start(WIDTH, HEIGHT, 0, "Raytracer");
  st.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_loop(st.win, 60, &st);
  bunny_delete_clipable(&st.pix->clipable);
  bunny_stop(st.win);
  return (0);
}
