/*
** init_value.c for init_value in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sat Dec 26 22:27:34 2015 nabil oulladji
** Last update Sun Dec 27 10:19:54 2015 nabil oulladji
*/

#include "wolf3d.h"
#include "lapin.h"

void		init_all_values(t_wolf *wolf)
{
  wolf->step_y = 0;
  wolf->hit = 0;
  wolf->move = 0;
}

void		init_all_value2(t_wolf *wolf)
{
  wolf->side = 0;
  wolf->line_height = 0;
  wolf->draw_start = 0;
  wolf->draw_end = 0;
  wolf->c_x = 0;
  wolf->old_dir_x = 0;
  wolf->old_plane_x = 0;
  wolf->old_dir_y = 0;
  wolf->old_plane_y = 0;
  wolf->state_up = 0;
  wolf->state_down = 0;
  wolf->state_left = 0;
  wolf->state_right = 0;
  wolf->speed_move = 0;
  wolf->mode = 1;
  wolf->i = 0;
  wolf->max = 0;
  wolf->pixel = 0;
  wolf->a = 0;
  wolf->music_next = 0;
  wolf->i_c = 0;
  wolf->x_colorize = 0;
  wolf->y_colorize = 0;
  init_all_values(wolf);
}

void		init_all_value(t_wolf *wolf)
 {
  wolf->tile_size = 0;
  wolf->width = 0;
  wolf->height = 0;
  wolf->map = NULL;
  wolf->pos_x = 0;
  wolf->pos_y = 0;
  wolf->start_position_a = 0;
  wolf->dir_x = 0;
  wolf->dir_y = 0;
  wolf->plane_x = 0;
  wolf->plane_y = 0;
  wolf->camera_x = 0;
  wolf->ray_pos_x = 0;
  wolf->ray_pos_y = 0;
  wolf->ray_dir_x = 0;
  wolf->ray_dir_y = 0;
  wolf->map_x = 0;
  wolf->map_y = 0;
  wolf->side_dist_x = 0;
  wolf->side_dist_y = 0;
  wolf->delta_dist_x = 0;
  wolf->delta_dist_y = 0;
  wolf->perp_dist = 0;
  wolf->step_x = 0;
  init_all_value2(wolf);
}
