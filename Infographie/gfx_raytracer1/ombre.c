/*
** ombre.c for ombre in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 13 04:43:01 2016 oullad_n
** Last update Sun Mar 13 06:02:25 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

void		display_ombre(t_ray *st)
{
  st->color_ref.argb[0] = st->color_ref.argb[0] / 5;
  st->color_ref.argb[1] = st->color_ref.argb[1] / 5;
  st->color_ref.argb[2] = st->color_ref.argb[2] / 5;
}

int	        ombre_check_sphere(t_ray *st, int i)
{
  st->a = pow(st->l_x, 2) + pow(st->l_y, 2) + pow(st->l_z, 2);
  st->b = 2 * (st->l_x * (st->p_x - st->info.sphere[i].x)
	       + st->l_y * (st->p_y - st->info.sphere[i].y)
	       + st->l_z * (st->p_z - st->info.sphere[i].z));
  st->c = pow(st->p_x - st->info.sphere[i].x, 2)
    + pow(st->p_y - st->info.sphere[i].y, 2)
    + pow(st->p_z - st->info.sphere[i].z, 2)
    - pow(st->info.sphere[i].rayon, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  if (check_solution(st) == 0)
    return (0);
  if (st->t < st->l)
    return (1);
  return (0);
}

int	        ombre_check_cylindre(t_ray *st, int i)
{
  st->a = pow(st->l_x, 2) + pow(st->l_z, 2);
  st->b = 2 * (st->l_x * (st->p_x - st->info.cylindre[i].x)
	       + st->l_z * (st->p_z - st->info.cylindre[i].z));
  st->c = pow(st->p_x - st->info.cylindre[i].x, 2)
    + pow(st->p_z - st->info.cylindre[i].z, 2)
    - pow(st->info.cylindre[i].rayon, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  if (check_solution(st) == 0)
    return (0);
  if (st->t < st->l)
    return (1);
  return (0);
}

int	        ombre_check_cone(t_ray *st, int i)
{
  st->a = pow(st->l_x, 2) + pow(st->l_z, 2)
    - pow(st->info.cone[i].rayon, 2) * pow(st->l_y, 2);
  st->b = 2 * (st->l_x * (st->p_x - st->info.cone[i].x)
	       + st->l_z * (st->p_z - st->info.cone[i].z)
	       - pow(st->info.cone[i].rayon, 2)
	       * (st->p_y - st->info.cone[i].y) * st->l_y);
  st->c = pow(st->p_x - st->info.cone[i].x, 2)
    + pow(st->p_z - st->info.cone[i].z, 2)
    - pow(st->info.cone[i].rayon, 2)
    * pow(st->p_y - st->info.cone[i].y, 2);
  st->d = pow(st->b, 2) - (4 * st->a * st->c);
  if (st->d <= 0)
    return (0);
  if (check_solution(st) == 0)
    return (0);
  if (st->t < st->l)
    return (1);
  return (0);
}

void		ombre_figure(t_ray *st, int i, int figure, int j)
{
  while (++j < st->info.nb_sphere)
    {
      if (i == j && figure == 1)
	i = j;
      else if (ombre_check_sphere(st, j) == 1)
	display_ombre(st);
    }
  j = -1;
  while (++j < st->info.nb_cylindre)
    {
      if (i == j && figure == 2)
	i = j;
      else if (ombre_check_cylindre(st, j) == 1)
  	display_ombre(st);
    }
  j = -1;
  while (++j < st->info.nb_cone)
    {
      if (i == j && figure == 3)
	i = j;
      else if (ombre_check_cone(st, j) == 1)
  	display_ombre(st);
    }
}
