/*
** my_raytracer.c for my_raytracer in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sat Feb 27 21:25:42 2016 oullad_n
** Last update Sat Mar 12 20:54:24 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

void		vector_normalize(double *x, double *y, double *z)
{
  double	i;

  i = 1 / sqrt((*x * *x) + (*y * *y) + (*z * *z));
  *x = *x * i;
  *y = *y * i;
  *z = *z * i;
}

void		init_cam(t_ray *st)
{
  st->b_x = st->x - (WIDTH / 2);
  st->b_y = st->y - (HEIGHT / 2);
  st->b_z = -(WIDTH / (2 * tan(30 / 2)));
  st->v_x = st->b_x - st->a_x;
  st->v_y = st->b_y - st->a_y;
  st->v_z = st->b_z - st->a_z;
  vector_normalize(&st->v_x, &st->v_y, &st->v_z);
  st->save_t = 0;
  st->pos.x = st->x;
  st->pos.y = st->y;
}

void		my_ray(t_ray *st)
{
  init_cam(st);
  collision_sphere(st);
  collision_plan(st);
  collision_cylindre(st);
  collision_cone(st);
}

void		raytracer(t_ray *st)
{
  st->y = 0;
  palette_color(st);
  while (st->y < HEIGHT)
    {
      st->x = 0;
      while (st->x < WIDTH)
	{
	  my_ray(st);
	  st->x = st->x + 1;
	}
      st->y = st->y + 1;
    }
}
