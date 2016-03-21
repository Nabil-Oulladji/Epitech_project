/*
** check_map.c for check_map in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sat Dec 26 23:52:22 2015 nabil oulladji
** Last update Sun Dec 27 21:15:12 2015 nabil oulladji
*/

#include <unistd.h>
#include "wolf3d.h"
#include "lapin.h"

int		check_value_map(t_wolf *wolf)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (x < wolf->height)
    {
      y = 0;
      while (y < wolf->width)
	{
	  if (wolf->map[x][y] != 0 && wolf->map[x][y] != 1)
	    return (1);
	  y = y + 1;
	}
      x = x + 1;
    }
  return (0);
}

int		check_start_pos(t_wolf *wolf)
{
  if ((int)wolf->pos_y <= 0 || (int)wolf->pos_x <= 0)
    {
      write(2, "Error: Player spawn out map\n", 28);
      return (1);
    }
  if ((int)wolf->pos_y >= wolf->width || (int)wolf->pos_x >= wolf->height)
    {
      write(2, "Error: Player spawn out map\n", 28);
      return (1);
    }
  wolf->pos_x = wolf->pos_x + 0.5;
  wolf->pos_y = wolf->pos_y + 0.5;
  if (wolf->map[(int)wolf->pos_x][(int)wolf->pos_y] != 0)
    {
      write(2, "Error: Player spawn in wall\n", 28);
      return (1);
    }
  return (0);
}

void		check_wall(t_wolf *wolf)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y < wolf->width)
    {
      wolf->map[0][y] = 1;
      wolf->map[wolf->height - 1][y] = 1;
      y = y + 1;
    }
  while (x < wolf->height)
    {
      wolf->map[x][0] = 1;
      wolf->map[x][wolf->width - 1] = 1;
      x = x + 1;
    }
}

int		check_map(t_wolf *wolf)
{
  check_wall(wolf);
  if (check_value_map(wolf) == 1)
    {
      write(2, "Error: map is invalid\n", 28);
      return (1);
    }
  if (check_start_pos(wolf) == 1)
    {
      return (1);
    }
  return (0);
}
