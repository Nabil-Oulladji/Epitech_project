/*
** fct_deplacement.c for fct_deplacement in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sat Dec 26 20:43:58 2015 nabil oulladji
** Last update Sat Dec 26 20:46:56 2015 nabil oulladji
*/

#include <math.h>
#include "wolf3d.h"
#include "lapin.h"

void			up(t_wolf *wolf)
{
  if (wolf->map[(int)(wolf->pos_x + wolf->dir_x * (0.025 + wolf->speed_move))]
      [(int)(wolf->pos_y)] == 0)
    wolf->pos_x += wolf->dir_x * (0.025 + wolf->speed_move);
  if (wolf->map[(int)(wolf->pos_x)]
      [(int)(wolf->pos_y + wolf->dir_y * (0.025 + wolf->speed_move))] == 0)
    wolf->pos_y += wolf->dir_y * (0.025 + wolf->speed_move);
}

void			down(t_wolf *wolf)
{
  if (wolf->map[(int)(wolf->pos_x - wolf->dir_x * (0.025 + wolf->speed_move))]
      [(int)(wolf->pos_y)] == 0)
    wolf->pos_x -= wolf->dir_x * (0.025 + wolf->speed_move);
  if (wolf->map[(int)(wolf->pos_x)]
      [(int)(wolf->pos_y - wolf->dir_y * (0.025 + wolf->speed_move))] == 0)
    wolf->pos_y -= wolf->dir_y * (0.025 + wolf->speed_move);
}

void			right(t_wolf *wolf)
{
  wolf->old_dir_x = wolf->dir_x;
  wolf->old_plane_x = wolf->plane_x;
  wolf->dir_x = wolf->dir_x * cos(-0.04) - wolf->dir_y * sin(-0.04);
  wolf->dir_y = wolf->old_dir_x * sin(-0.04) + wolf->dir_y * cos(-0.04);
  wolf->plane_x = wolf->plane_x * cos(-0.04) - wolf->plane_y * sin(-0.04);
  wolf->plane_y = wolf->old_plane_x * sin(-0.04) +  wolf->plane_y * cos(-0.04);
}

void			left(t_wolf *wolf)
{
  wolf->old_dir_x = wolf->dir_x;
  wolf->old_plane_x = wolf->plane_x;
  wolf->dir_x = wolf->dir_x * cos(0.04) - wolf->dir_y * sin(0.04);
  wolf->dir_y = wolf->old_dir_x * sin(0.04) + wolf->dir_y * cos(0.04);
  wolf->plane_x = wolf->plane_x * cos(0.04) - wolf->plane_y * sin(0.04);
  wolf->plane_y = wolf->old_plane_x * sin(0.04) +  wolf->plane_y * cos(0.04);
}
