/*
** sphere.c for sphere in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Mon Mar  7 19:24:59 2016 oullad_n
** Last update Sun Mar 13 05:44:50 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

void		check_ombre_sphere(t_ray *st, int i)
{
  st->l_x = st->info.light[0].x - st->p_x;
  st->l_y = st->info.light[0].y - st->p_y;
  st->l_z = st->info.light[0].z - st->p_z;
  st->l = sqrt(pow(st->l_x, 2) + pow(st->l_y, 2) + pow(st->l_z, 2));
  vector_normalize(&st->l_x, &st->l_y, &st->l_z);
  ombre_figure(st, i, 1, -1);
  st->n_x = st->p_x - st->info.sphere[i].x;
  st->n_y = st->p_y - st->info.sphere[i].y;
  st->n_z = st->p_z - st->info.sphere[i].z;
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

int		calcul_sphere(t_ray *st, int i)
{
  st->a = pow(st->v_x, 2) + pow(st->v_y, 2) + pow(st->v_z, 2);
  st->b = 2 * (st->v_x * (st->a_x - st->info.sphere[i].x)
	       + st->v_y * (st->a_y - st->info.sphere[i].y)
	       + st->v_z * (st->a_z - st->info.sphere[i].z));
  st->c = pow(st->a_x - st->info.sphere[i].x, 2)
    + pow(st->a_y - st->info.sphere[i].y, 2)
    + pow(st->a_z - st->info.sphere[i].z, 2)
    - pow(st->info.sphere[i].rayon, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  return (1);
}

int		check_sphere(t_ray *st, int i)
{
  if (calcul_sphere(st, i) == 0)
    return (0);
  if (st->d > 0)
    {
      if (check_solution(st) == 0)
	return (0);
      if (st->t <= st->save_t || st->save_t == 0)
	{
	  if (st->info.sphere[i].color == 9)
	    checker_color_cone(st);
	  else if (st->info.sphere[i].color == 10)
	    checker_color_cone_line(st);
	  else
	    st->color_ref.full = st->color[st->info.sphere[i].color].full;
	  st->save_t = st->t;
	  st->p_x = st->a_x + st->t * st->v_x;
	  st->p_y = st->a_y + st->t * st->v_y;
	  st->p_z = st->a_z + st->t * st->v_z;
	  return (1);
	}
    }
  return (0);
}

void		collision_sphere(t_ray *st)
{
  int		i;
  
  i = 0;
  while (i < st->info.nb_sphere)
    {
      if (check_sphere(st, i) == 1)
	check_ombre_sphere(st, i);
      i = i + 1;
    }
}
