/*
** fct_mirror.c for fct_mirror in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Thu Mar 10 21:58:48 2016 oullad_n
** Last update Sun Mar 13 04:59:19 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

int		mirror_figure_2(t_ray *st)
{
  int		j;

  j = -1;
  while (++j < st->info.nb_cone)
    {
      if (mirror_check_cone(st, j) == 1)
	{
	  check_ombre_cone(st, j);
	  return (1);
	}
    }  
  return (0);
}

int		mirror_figure(t_ray *st, int i)
{
  int		j;
  
  j = -1;
  if (st->info.plan[i].mirror != 1)
    return (0);
  while (++j < st->info.nb_sphere)
    {
      if (mirror_check_sphere(st, j) == 1)
	{
	  check_ombre_sphere(st, j);
	  return (1);
	}
    }
  j = -1;
  while (++j < st->info.nb_cylindre)
    {
      if (mirror_check_cylindre(st, j) == 1)
	{
	  check_ombre_cylindre(st, j);
	  return (1);
	}
    }
  if (mirror_figure_2(st) == 1)
    return (1);
  return (0);
}

int		mirror_plan(t_ray *st, int i)
{
  st->r_x = st->v_x - 2 * (st->n_x * st->v_x) * st->n_x;
  st->r_y = st->v_y - 2 * (st->n_y * st->v_y) * st->n_y;
  st->r_z = st->v_z - 2 * (st->n_z * st->v_z) * st->n_z;
  vector_normalize(&st->r_x, &st->r_y, &st->r_z);
  if (mirror_figure(st, i) == 1)
    return (1);
  return (0);
}
