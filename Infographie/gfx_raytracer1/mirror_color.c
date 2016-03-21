/*
** mirror_color.c for mirror_color in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 13 00:26:34 2016 oullad_n
** Last update Sun Mar 13 03:44:09 2016 oullad_n
*/

#include <math.h>
#include "struct.h"

void		mirror_checker_color_cone(t_ray *st)
{
  if ((st->col_x = (st->p_x + st->t * st->r_x) / 1.75) < 0)
    st->col_x = -st->col_x + 1;
  if ((st->col_y = (st->p_y + st->t * st->r_y) / 1.75) < 0)
    st->col_y = -st->col_y + 1;
  if (((int)st->col_x % 2 == 0 && (int)st->col_y % 2 == 0)
      || ((int)st->col_x % 2 == 1 && (int)st->col_y % 2 == 1))
    {
      st->color_ref.argb[0] = (st->color_ref.argb[0]) / 4;
      st->color_ref.argb[1] = (st->color_ref.argb[1]) / 4;
      st->color_ref.argb[2] = (st->color_ref.argb[2]) / 4;
    }
  else
    {
      st->color_ref.argb[0] = (3 * 255
			       + st->color_ref.argb[0]) / 4;
      st->color_ref.argb[1] = (3 * 255
			       + st->color_ref.argb[1]) / 4;
      st->color_ref.argb[2] = (3 * 255
				 + st->color_ref.argb[2]) / 4;
      }
}

void		mirror_checker_color_cone_line(t_ray *st)
{
  if ((st->col_y = (st->p_y + st->t * st->r_y) / 1.75) < 0)
    st->col_y = -st->col_y + 1;
  if ((int)st->col_y % 2 == 0)
    {
      st->color_ref.argb[0] = (st->color_ref.argb[0]) / 4;
      st->color_ref.argb[1] = (st->color_ref.argb[1]) / 4;
      st->color_ref.argb[2] = (st->color_ref.argb[2]) / 4;
    }
  /* else */
  /*   { */
  /*     st->color_ref.argb[0] = (3 * 255 */
  /* 			       + st->color_ref.argb[0]) / 4; */
  /*     st->color_ref.argb[1] = (3 * 255 */
  /* 			       + st->color_ref.argb[1]) / 4; */
  /*     st->color_ref.argb[2] = (3 * 255 */
  /* 			       + st->color_ref.argb[2]) / 4; */
  /*   } */
}

void		mirror_color_sphere(t_ray *st, int i)
{
  if (st->info.sphere[i].color == 9)
    mirror_checker_color_cone(st);
  else if (st->info.sphere[i].color == 10)
    mirror_checker_color_cone_line(st);
  else
    {
      st->color_ref.argb[0] = (3 * st->color[st->info.sphere[i].color].argb[0]
			       + st->color_ref.argb[0]) / 4;
      st->color_ref.argb[1] = (3 * st->color[st->info.sphere[i].color].argb[1]
			       + st->color_ref.argb[1]) / 4;
      st->color_ref.argb[2] = (3 * st->color[st->info.sphere[i].color].argb[2]
			       + st->color_ref.argb[2]) / 4;
    }
}

void		mirror_color_cylindre(t_ray *st, int i)
{
  if (st->info.cylindre[i].color == 9)
    mirror_checker_color_cone(st);
  else if (st->info.cylindre[i].color == 10)
    mirror_checker_color_cone_line(st);
  else
    {
      st->color_ref.argb[0] = (3 * st->color[st->info.cylindre[i].color].argb[0]
			       + st->color_ref.argb[0]) / 4;
      st->color_ref.argb[1] = (3 * st->color[st->info.cylindre[i].color].argb[1]
			       + st->color_ref.argb[1]) / 4;
      st->color_ref.argb[2] = (3 * st->color[st->info.cylindre[i].color].argb[2]
			       + st->color_ref.argb[2]) / 4;
    }
}

void		mirror_color_cone(t_ray *st, int i)
{
  if (st->info.cone[i].color == 9)
    mirror_checker_color_cone(st);
  else if (st->info.cone[i].color == 10)
    mirror_checker_color_cone_line(st);
  else
    {
      st->color_ref.argb[0] = (3 * st->color[st->info.cylindre[i].color].argb[0]
			       + st->color_ref.argb[0]) / 4;
      st->color_ref.argb[1] = (3 * st->color[st->info.cylindre[i].color].argb[1]
			       + st->color_ref.argb[1]) / 4;
      st->color_ref.argb[2] = (3 * st->color[st->info.cylindre[i].color].argb[2]
			       + st->color_ref.argb[2]) / 4;
    }
}
