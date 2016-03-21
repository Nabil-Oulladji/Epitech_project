/*
** main.c for main.c in /home/oullad_n/rendu/Infographie/WOLF3D
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sun Dec 20 16:44:59 2015 nabil oulladji
** Last update Sun Dec 27 10:27:07 2015 nabil oulladji
*/

#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"
#include "lapin.h"

int		main(int ac, char **av)
{
  t_wolf	*wolf;

  if ((wolf = bunny_malloc(sizeof(*wolf))) == NULL)
    return (1);
  if (ac != 2)
    {
      write(2, "Usage: ./wolf3d [map_path]\n", 27);
      return (1);
    }
  init_all_value(wolf);
  if (read_file(av[1], wolf) == 1
      || (wolf->music = bunny_load_music("ressources/Reine.ogg")) == NULL)
    return (1);
  loop(wolf);
  wolf->win = bunny_start(WIDTH, HEIGHT, 0, "Wolf3d");
  wolf->pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_loop(wolf->win, 60, wolf);
  bunny_delete_clipable(&wolf->pix->clipable);
  bunny_sound_stop(wolf->music);
  bunny_delete_sound(wolf->music);
  bunny_stop(wolf->win);
  bunny_free_map(wolf);
  return (0);
}
