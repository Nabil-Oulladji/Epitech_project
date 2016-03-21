/*
** color.c for color in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Mon Mar  7 19:38:24 2016 oullad_n
** Last update Sun Mar 13 04:21:43 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

void		checker_color(t_ray *st)
{
  if ((st->col_x = (st->a_x + st->t * st->v_x) / 1.75) < 0)
    st->col_x = -st->col_x + 1;
  if ((st->col_y = (st->a_y + st->t * st->v_y) / 1.75) < 0)
    st->col_y = -st->col_y + 1;
  if ((st->col_z = (st->a_z + st->t * st->v_z) / 1.75) < 0)
    st->col_z = -st->col_z + 1;
  if ((int)st->col_z % 2 == 0)
    {
      if (((int)st->col_x % 2 == 0 && (int)st->col_y % 2 == 0)
	|| ((int)st->col_x % 2 == 1 && (int)st->col_y % 2 == 1))
	st->color_ref.full = WHITE;	
      else
	st->color_ref.full = BLACK;
    }
  else
    {
      if (((int)st->col_x % 2 == 0 && (int)st->col_y % 2 == 0)
	  || ((int)st->col_x % 2 == 1 && (int)st->col_y % 2 == 1))
	st->color_ref.full = BLACK;	
      else
	st->color_ref.full = WHITE;	
    }
}

void		checker_color_cone(t_ray *st)
{
  if ((st->col_x = (st->a_x + st->t * st->v_x) / 1.75) < 0)
    st->col_x = -st->col_x + 1;
  if ((st->col_y = (st->a_y + st->t * st->v_y) / 1.75) < 0)
    st->col_y = -st->col_y + 1;
  if (((int)st->col_x % 2 == 0 && (int)st->col_y % 2 == 0)
      || ((int)st->col_x % 2 == 1 && (int)st->col_y % 2 == 1))
    st->color_ref.full = BLACK;
  else
    st->color_ref.full = WHITE;
}

int		checker_color_cone_line(t_ray *st)
{
  if ((st->col_y = (st->a_y + st->t * st->v_y) / 1.75) < 0)
    st->col_y = -st->col_y + 1;
  if ((int)st->col_y % 2 == 0)
    st->color_ref.full = WHITE;
  else
    return (0);
  return (1);
}

void		checker_color_plan_line(t_ray *st)
{
  if ((st->col_z = (st->a_z + st->t * st->v_z) / 1.75) < 0)
    st->col_z = -st->col_z + 1;
  if ((int)st->col_z % 2 == 0)
    st->color_ref.full = BLACK;
  else
    st->color_ref.full = WHITE;
}

int		color_cone_line(t_ray *st, int i)
{
  if (st->info.cone[i].color == 9)
    checker_color_cone(st);
  else if (st->info.cone[i].color == 10)
    {
      if (checker_color_cone_line(st) == 0 && st->save_t != 0)
	return (0);
      st->t = st->t1;
      if (checker_color_cone_line(st) == 0)
	st->t = st->t0;
      if (checker_color_cone_line(st) == 0)
	return (0);
    }
  else
    st->color_ref.full = st->color[st->info.cone[i].color].full;
  return (1);
}
