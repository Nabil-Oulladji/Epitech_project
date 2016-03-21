/*
** malloc_free.c for malloc_free in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sat Dec 26 23:08:10 2015 nabil oulladji
** Last update Sun Dec 27 20:23:36 2015 nabil oulladji
*/

#include "wolf3d.h"
#include "lapin.h"

int		bunny_malloc_map(t_wolf *wolf)
{
int		y;

  y = 0;
  wolf->map = bunny_malloc(sizeof(int *) * wolf->height);
  while (y < wolf->height)
    {
      if ((wolf->map[y] = bunny_malloc(sizeof(int) * wolf->width)) == NULL)
	return (1);
      y = y + 1;
    }
return (0);
}

void		bunny_free_map(t_wolf *wolf)
{
  int		y;

  y = wolf->height - 1;
  while (y <= 0)
    {
      bunny_free(wolf->map[y]);
      y = y - 1;
    }
  bunny_free(wolf->map);
}
