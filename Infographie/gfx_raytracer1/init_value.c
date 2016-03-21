/*
** init_value.c for init_value in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Thu Mar 10 22:04:37 2016 oullad_n
** Last update Thu Mar 10 22:27:03 2016 oullad_n
*/

#include "struct.h"

void		init_value(t_ray *st)
{
  st->event.go = 0;
  st->event.back = 0;
  st->event.left = 0;
  st->event.right = 0;
  st->event.up = 0;
  st->event.down = 0;
  st->event.add_light = 0;
  st->event.del_light = 0;
  st->event.up_light = 0;
  st->event.down_light = 0;
  st->event.left_light = 0;
  st->event.right_light = 0;
  st->event.go_light = 0;
  st->event.back_light = 0;
}
