/*
** main_loop.c for main_loop in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sat Dec 26 21:52:50 2015 nabil oulladji
** Last update Sun Dec 27 20:16:22 2015 nabil oulladji
*/

#include "lapin.h"
#include "wolf3d.h"

void		key_go_up(t_bunny_event_state state,
			  t_bunny_keysym key, t_wolf *wolf)
{
  if (state == GO_UP)
    {
      if (key == BKS_UP)
	wolf->state_up = 0;
      if (key == BKS_DOWN)
	wolf->state_down = 0;
      if (key == BKS_RIGHT)
	wolf->state_right = 0;
      if (key == BKS_LEFT)
	wolf->state_left = 0;
      if (key == BKS_LSHIFT)
	wolf->speed_move = 0;
    }
}

void			key_part_2(t_bunny_keysym key, t_wolf *wolf)
{
  if (key == BKS_F1)
    {
      wolf->mode = 1;
      wolf->a = 0;
    }
  if (key == BKS_F2)
    {
      wolf->mode = 2;
      wolf->a = 0;
    }
  if (key == BKS_F3)
    {
      wolf->mode = 3;
      wolf->a = 0;
    }
}

t_bunny_response        key(t_bunny_event_state state, t_bunny_keysym key,
                            void *my_data)
{
  t_wolf		*wolf;

  wolf = (t_wolf *)my_data;
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (key == BKS_UP)
	wolf->state_up = 1;
      if (key == BKS_DOWN)
	wolf->state_down = 1;
      if (key == BKS_RIGHT)
	wolf->state_right = 1;
      if (key == BKS_LEFT)
	wolf->state_left = 1;
      if (key == BKS_LSHIFT)
	wolf->speed_move = 0.025;
      key_part_2(key, wolf);
    }
  key_go_up(state, key, wolf);
  return (GO_ON);
}

t_bunny_response        mainloop(void *my_data)
{
  t_wolf               *wolf;

  wolf = (t_wolf *)my_data;
  if (wolf->state_up == 1)
    up(wolf);
  if (wolf->state_down == 1)
    down(wolf);
  if (wolf->state_left == 1)
    left(wolf);
  if (wolf->state_right == 1)
    right(wolf);
  background(wolf->pix, wolf);
  raycasting(wolf);
  if (wolf->a == 0)
    {
      if (add_music(wolf) == 1)
	return (-1);
      wolf->a = 1;
    }
  if (wolf->mode == 1)
    snow(wolf->pix, wolf);
  bunny_blit(&wolf->win->buffer, &wolf->pix->clipable, NULL);
  bunny_display(wolf->win);
  return (GO_ON);
}
