/*
** mirror_figure2.c for mirror_figure2 in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 13 02:28:18 2016 oullad_n
** Last update Sun Mar 13 02:43:42 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

int		mirror_calcul_cone(t_ray *st, int i)
{
  st->a = pow(st->r_x, 2) + pow(st->r_z, 2)
    - pow(st->info.cone[i].rayon, 2) * pow(st->r_y, 2);
  st->b = 2 * (st->r_x * (st->p_x - st->info.cone[i].x)
	       + st->r_z * (st->p_z - st->info.cone[i].z)
	       - pow(st->info.cone[i].rayon, 2)
	       * (st->p_y - st->info.cone[i].y) * st->r_y);
  st->c = pow(st->p_x - st->info.cone[i].x, 2)
    + pow(st->p_z - st->info.cone[i].z, 2)
    - pow(st->info.cone[i].rayon, 2)
    * pow(st->p_y - st->info.cone[i].y, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  return (1);
}

int		mirror_check_cone(t_ray *st, int i)
{
  if (mirror_calcul_cone(st, i) == 0)
    return (0);
  if (st->d > 0)
    {
      st->t0 = (-st->b + sqrt(st->d)) / (2 * st->a);
      st->t1 = (-st->b - sqrt(st->d)) / (2 * st->a);
      if (st->t0 <= 0 && st->t1 <= 0)
      	return (0);
      if ((st->t0 > 0 && st->t0 <= st->t1) || (st->t1 < st->t0 && st->t1 <= 0))
	st->t = st->t0;
      if ((st->t1 > 0 && st->t1 < st->t0) || (st->t0 < st->t1 && st->t0 <= 0))
	st->t = st->t1;
      st->p_x = st->p_x + st->t * st->r_x;
      st->p_y = st->p_y + st->t * st->r_y;
      st->p_z = st->p_z + st->t * st->r_z;
      mirror_color_cone(st, i);
      return (1);
    }
  return (0);
}
