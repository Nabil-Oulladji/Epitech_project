/*

** cone.c for cone in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sat Mar 12 19:59:59 2016 oullad_n
** Last update Sun Mar 13 05:44:37 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

int		check_solution(t_ray *st)
{
  st->t0 = (-st->b + sqrt(st->d)) / (2 * st->a);
  st->t1 = (-st->b - sqrt(st->d)) / (2 * st->a);
  if (st->t0 <= 0 && st->t1 <= 0)
    return (0);
  if ((st->t0 > 0 && st->t0 <= st->t1) || (st->t1 < st->t0 && st->t1 <= 0))
    st->t = st->t0;
  if ((st->t1 > 0 && st->t1 < st->t0) || (st->t0 < st->t1 && st->t0 <= 0))
    st->t = st->t1;
  return (1);
}

void		check_ombre_cone(t_ray *st, int i)
{
  st->l_x = st->info.light[0].x - st->p_x;
  st->l_y = st->info.light[0].y - st->p_y;
  st->l_z = st->info.light[0].z - st->p_z;
  st->l = sqrt(pow(st->l_x, 2) + pow(st->l_y, 2) + pow(st->l_z, 2));
  vector_normalize(&st->l_x, &st->l_y, &st->l_z);
  ombre_figure(st, i, 3, -1);
  st->n_x = st->p_x - st->info.cone[i].x;
  st->n_y = st->p_y - st->info.cone[i].y * tan(pow(st->info.cone[i].rayon, 2));
  st->n_z = st->p_z - st->info.cone[i].z;
  vector_normalize(&st->n_x, &st->n_y, &st->n_z);
  st->angle = st->n_x * st->l_x + st->n_y * st->l_y + st->n_z * st->l_z;
  if (st->angle > 0.2)
    {
      st->color_ref.argb[0] = st->color_ref.argb[0] * st->angle;
      st->color_ref.argb[1] = st->color_ref.argb[1] * st->angle;
      st->color_ref.argb[2] = st->color_ref.argb[2] * st->angle;
    }
  if (st->angle <= 0.2)
    {
      st->color_ref.argb[0] *= 0.2;
      st->color_ref.argb[1] *= 0.2;
      st->color_ref.argb[2] *= 0.2;
    }
  tekpixel(st->pix, &st->pos, &st->color_ref);
}


int		calcul_cone(t_ray *st, int i)
{
  st->a = pow(st->v_x, 2) + pow(st->v_z, 2)
    - pow(st->info.cone[i].rayon, 2) * pow(st->v_y, 2);
  st->b = 2 * (st->v_x * (st->a_x - st->info.cone[i].x)
	       + st->v_z * (st->a_z - st->info.cone[i].z)
	       - pow(st->info.cone[i].rayon, 2)
	       * (st->a_y - st->info.cone[i].y) * st->v_y);
  st->c = pow(st->a_x - st->info.cone[i].x, 2)
    + pow(st->a_z - st->info.cone[i].z, 2)
    - pow(st->info.cone[i].rayon, 2)
    * pow(st->a_y - st->info.cone[i].y, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  return (1);
}

int		check_cone(t_ray *st, int i)
{
  if (calcul_cone(st, i) == 0)
    return (0);
  if (st->d > 0)
    {
      if (check_solution(st) == 0)
      	return (0);
      if (st->t <= st->save_t || st->save_t == 0)
	{
	  if (color_cone_line(st, i) == 0)
	    return (0);
	  st->save_t = st->t;
	  st->p_x = st->a_x + st->t * st->v_x;
	  st->p_y = st->a_y + st->t * st->v_y;
	  st->p_z = st->a_z + st->t * st->v_z;
	  return (1);
	}
    }
  return (0);
}

void		collision_cone(t_ray *st)
{
  int		i;
  
  i = 0;
  while (i < st->info.nb_cone)
    {
      if (check_cone(st, i) == 1)
	check_ombre_cone(st, i);
      i = i + 1;
    }
}
