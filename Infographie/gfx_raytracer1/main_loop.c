/*
** main_loop.c for main_loop in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb 23 20:49:19 2016 nabil oulladji
** Last update Thu Mar 10 22:30:25 2016 oullad_n
*/

#include "struct.h"

void		background(t_bunny_pixelarray *pix,
			   unsigned int color)
{
  int		i;
  int		max;
  int		*pixel;

  i = 0;
  max = pix->clipable.clip_width * pix->clipable.clip_height;
  pixel = pix->pixels;
  while (i < max)
    {
      pixel[i] = color;
      i = i + 1;
    }
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *my_data)
{
  t_ray			*st;

  st = (t_ray *)my_data;
  st = st;
  if (state == GO_DOWN)
    {
      key_go_down(key, st);
      if (key == BKS_F)
	st->event.go_light = 1;
      if (key == BKS_G)
	st->event.back_light = 1;
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
    }
  key_go_up(state, key, st);
  return (GO_ON);
}

t_bunny_response	mainloop(void *my_data)
{
  t_ray			*st;

  st = (t_ray *)my_data;
  use_key(st);
  background(st->pix, BLACK);
  raytracer(st);
  bunny_blit(&st->win->buffer, &st->pix->clipable, NULL);
  bunny_display(st->win);
  return (GO_ON);
}
