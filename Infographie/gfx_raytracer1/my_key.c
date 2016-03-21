/*
** my_key.c for my_key in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Thu Mar 10 22:07:50 2016 oullad_n
** Last update Fri Mar 11 17:30:48 2016 oullad_n
*/

#include "struct.h"

void			key_go_up2(t_bunny_keysym key,
				   t_ray *st)
{
  if (key == BKS_Z)
    st->event.go = 0;
  if (key == BKS_S)
    st->event.back = 0;
  if (key == BKS_Q)
    st->event.left = 0;
  if (key == BKS_D)
    st->event.right = 0;
  if (key == BKS_E)
    st->event.down = 0;
  if (key == BKS_A)
    st->event.up = 0;
  if (key == BKS_R)
    st->event.add_light = 0;
  if (key == BKS_T)
    st->event.del_light = 0;  
}

void			key_go_up(t_bunny_event_state state,
				  t_bunny_keysym key, t_ray *st)
{
  if (state == GO_UP)
    {
      key_go_up2(key, st);
      if (key == BKS_UP)
	st->event.up_light = 0;
      if (key == BKS_DOWN)
	st->event.down_light = 0;
      if (key == BKS_LEFT)
	st->event.left_light = 0;
      if (key == BKS_RIGHT)
	st->event.right_light = 0;
      if (key == BKS_F)
	st->event.go_light = 0;
      if (key == BKS_G)
	st->event.back_light = 0;
    }
}

void			key_go_down(t_bunny_keysym key,
				    t_ray *st)
{
  if (key == BKS_Z)
    st->event.go = 1;
  if (key == BKS_S)
    st->event.back = 1;
  if (key == BKS_Q)
    st->event.left = 1;
  if (key == BKS_D)
    st->event.right = 1;
  if (key == BKS_E)
    st->event.down = 1;
  if (key == BKS_A)
    st->event.up = 1;
  if (key == BKS_R)
    st->event.add_light = 1;
  if (key == BKS_T)
    st->event.del_light = 1;
  if (key == BKS_UP)
    st->event.up_light = 1;
  if (key == BKS_DOWN)
    st->event.down_light = 1;
  if (key == BKS_LEFT)
    st->event.left_light = 1;
  if (key == BKS_RIGHT)
    st->event.right_light = 1;
}

void			use_key_2(t_ray *st)
{
  if (st->event.go == 1)
    st->a_z += 5;
  if (st->event.back == 1)
    st->a_z -= 5;
  if (st->event.left == 1)
    st->a_x -= 5;
  if (st->event.right == 1)
    st->a_x += 5;
  if (st->event.up == 1)
    st->a_y -= 5;
  if (st->event.down == 1)
    st->a_y += 5;  
}

void			use_key(t_ray *st)
{
  use_key_2(st);
  if (st->event.add_light == 1)
    st->info.light[0].intensity += 5;
  if (st->event.del_light == 1)
    st->info.light[0].intensity -= 5;
  if (st->event.up_light == 1)
    st->info.light[0].y -= 5;
  if (st->event.down_light == 1)
    st->info.light[0].y += 5;
  if (st->event.left_light == 1)
    st->info.light[0].x -= 5;
  if (st->event.right_light == 1)
    st->info.light[0].x += 5;
  if (st->event.go_light == 1)
    st->info.light[0].z += 5;
  if (st->event.back_light == 1)
    st->info.light[0].z -= 5;
}
