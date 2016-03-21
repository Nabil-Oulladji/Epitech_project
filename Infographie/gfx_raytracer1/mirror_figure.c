/*
** mirror_figure.c for mirror_figure in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 13 00:47:58 2016 oullad_n
** Last update Sun Mar 13 02:31:10 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

int		mirror_calcul_sphere(t_ray *st, int i)
{
  st->a = pow(st->r_x, 2) + pow(st->r_y, 2) + pow(st->r_z, 2);
  st->b = 2 * (st->r_x * (st->p_x - st->info.sphere[i].x)
	       + st->r_y * (st->p_y - st->info.sphere[i].y)
	       + st->r_z * (st->p_z - st->info.sphere[i].z));
  st->c = pow(st->p_x - st->info.sphere[i].x, 2)
    + pow(st->p_y - st->info.sphere[i].y, 2)
    + pow(st->p_z - st->info.sphere[i].z, 2)
    - pow(st->info.sphere[i].rayon, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  return (1);
}

int		mirror_check_sphere(t_ray *st, int i)
{
  if (mirror_calcul_sphere(st, i) == 0)
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
      mirror_color_sphere(st, i);
      return (1);
    }
  return (0);
}

int		mirror_calcul_cylindre(t_ray *st, int i)
{
  st->a = pow(st->r_x, 2) + pow(st->r_z, 2);
  st->b = 2 * (st->r_x * (st->p_x - st->info.cylindre[i].x)
	       + st->r_z * (st->p_z - st->info.cylindre[i].z));
  st->c = pow(st->p_x - st->info.cylindre[i].x, 2)
    + pow(st->p_z - st->info.cylindre[i].z, 2)
    - pow(st->info.cylindre[i].rayon, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  return (1);
}

int		mirror_check_cylindre(t_ray *st, int i)
{
  if (mirror_calcul_cylindre(st, i) == 0)
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
      mirror_color_cylindre(st, i);
      return (1);
    }
  return (0);
}
