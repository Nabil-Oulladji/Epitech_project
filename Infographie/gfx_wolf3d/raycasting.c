/*
** raycasting.c for raycasting in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sat Dec 26 21:49:18 2015 nabil oulladji
** Last update Sat Dec 26 22:00:06 2015 nabil oulladji
*/

#include <math.h>
#include "wolf3d.h"
#include "lapin.h"

void		        calcul_height(t_wolf *wolf)
{
  wolf->line_height = abs(HEIGHT / wolf->perp_dist);
  wolf->draw_start = (-(wolf->line_height) / 2) + (HEIGHT / 2);
  if (wolf->draw_start < 0)
    wolf->draw_start = 0;
  wolf->draw_end = (wolf->line_height / 2) + (HEIGHT / 2);
  if (wolf->draw_end >= HEIGHT)
    wolf->draw_end = HEIGHT - 1;
}

void			side_hit(t_wolf *wolf)
{
  while (wolf->hit == 0)
    {
      if (wolf->side_dist_x < wolf->side_dist_y)
	{
	  wolf->side_dist_x += wolf->delta_dist_x;
	  wolf->map_x += wolf->step_x;
	  wolf->side = 0;
	}
      else
	{
	  wolf->side_dist_y += wolf->delta_dist_y;
	  wolf->map_y += wolf->step_y;
	  wolf->side = 1;
	}
      if (wolf->map[wolf->map_x][wolf->map_y] > 0)
	wolf->hit = 1;
    }
  if (wolf->side == 0)
    wolf->perp_dist = fabs((wolf->map_x - wolf->ray_pos_x
			     + (1 - wolf->step_x) / 2) / wolf->ray_dir_x);
  else
    wolf->perp_dist = fabs((wolf->map_y - wolf->ray_pos_y
			     + (1 - wolf->step_y) / 2) / wolf->ray_dir_y);
}

void			side_dist(t_wolf *wolf)
{
  wolf->hit = 0;
  if (wolf->ray_dir_x < 0)
    {
      wolf->step_x = -1;
      wolf->side_dist_x = (wolf->ray_pos_x - wolf->map_x)
	* wolf->delta_dist_x;
    }
  else
    {
      wolf->step_x = 1;
      wolf->side_dist_x = (wolf->map_x + 1.0 - wolf->ray_pos_x)
	* wolf->delta_dist_x;
    }
  if (wolf->ray_dir_y < 0)
    {
      wolf->step_y = -1;
      wolf->side_dist_y = (wolf->ray_pos_y - wolf->map_y)
	* wolf->delta_dist_y;
    }
  else
    {
      wolf->step_y = 1;
      wolf->side_dist_y = (wolf->map_y + 1.0 - wolf->ray_pos_y)
	* wolf->delta_dist_y;
    }
}

void			raycasting(t_wolf *wolf)
{
  wolf->c_x = 0;
  while (wolf->c_x < WIDTH)
    {
      wolf->camera_x = 2 * wolf->c_x / (double)WIDTH - 1;
      wolf->ray_pos_x = wolf->pos_x;
      wolf->ray_pos_y = wolf->pos_y;
      wolf->ray_dir_x = wolf->dir_x + wolf->plane_x * wolf->camera_x;
      wolf->ray_dir_y = wolf->dir_y + wolf->plane_y * wolf->camera_x;
      wolf->map_x = (int)wolf->ray_pos_x;
      wolf->map_y = (int)wolf->ray_pos_y;
      wolf->delta_dist_x = sqrt(1 + (wolf->ray_dir_y * wolf->ray_dir_y)
				/ (wolf->ray_dir_x * wolf->ray_dir_x));
      wolf->delta_dist_y = sqrt(1 + (wolf->ray_dir_x * wolf->ray_dir_x)
				/ (wolf->ray_dir_y * wolf->ray_dir_y));
      side_dist(wolf);
      side_hit(wolf);
      calcul_height(wolf);
      draw_line(wolf);
      wolf->c_x = wolf->c_x + 1;
    }
}
