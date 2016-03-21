/*
** plan.c for plan in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Mon Mar  7 19:26:57 2016 oullad_n
** Last update Sun Mar 13 05:45:23 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

void		check_ombre_plan(t_ray *st, int i)
{
  st->l_x = st->info.light[0].x - st->p_x;
  st->l_y = st->info.light[0].y - st->p_y;
  st->l_z = st->info.light[0].z - st->p_z;
  st->l = sqrt(pow(st->l_x, 2) + pow(st->l_y, 2) + pow(st->l_z, 2));
  vector_normalize(&st->l_x, &st->l_y, &st->l_z);
  ombre_figure(st, i, 0, -1);
  st->n_x = st->info.plan[i].vx;
  st->n_y = st->info.plan[i].vy;
  st->n_z = st->info.plan[i].vz;
  vector_normalize(&st->n_x, &st->n_y, &st->n_z);
  st->angle = fabs(st->l_x * st->n_x + st->l_y * st->n_y + st->l_z * st->n_z);
  if (mirror_plan(st, i) == 0)
    {
      st->color_ref.argb[0] = st->angle * st->color_ref.argb[0];
      st->color_ref.argb[1] = st->angle * st->color_ref.argb[1];
      st->color_ref.argb[2] = st->angle * st->color_ref.argb[2];
      tekpixel(st->pix, &st->pos, &st->color_ref);
    }
}

int		check_plan(t_ray *st, int i)
{
  st->t0 = st->info.plan[i].vx * (st->a_x - st->info.plan[i].x)
    + st->info.plan[i].vy * (st->a_y - st->info.plan[i].y)
    + st->info.plan[i].vz * (st->a_z - st->info.plan[i].z);
  st->t1 = st->info.plan[i].vx * st->v_x
    + st->info.plan[i].vy * st->v_y
    + st->info.plan[i].vz * st->v_z;
  if (st->t1 != 0 && (st->t = -(st->t0 / st->t1)) > 0.01)
    {
      if (st->t <= st->save_t || st->save_t == 0)
	{
	  if (st->info.plan[i].color == 9)
	    checker_color(st);
	  else if (st->info.plan[i].color == 10)
	    checker_color_plan_line(st);
	  else
	    st->color_ref.full = st->color[st->info.plan[i].color].full;
	  st->p_x = st->a_x + st->t * st->v_x;
	  st->p_y = st->a_y + st->t * st->v_y;
	  st->p_z = st->a_z + st->t * st->v_z;
	  st->save_t = st->t;
	  return (1);
	}
    }
  return (0);
}

void		collision_plan(t_ray *st)
{
  int		i;
  
  i = 0;
  while (i < st->info.nb_plan)
    {
      if (check_plan(st, i) == 1)
	check_ombre_plan(st, i);
      i = i + 1;
    }
}
