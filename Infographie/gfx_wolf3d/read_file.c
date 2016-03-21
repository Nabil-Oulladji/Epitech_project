/*
** read_file.c for read_file in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Mon Dec 21 12:35:59 2015 nabil oulladji
** Last update Sun Dec 27 10:31:37 2015 nabil oulladji
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "wolf3d.h"
#include "lapin.h"

int			read_name_tile(t_bunny_ini *ini, const char *name_s,
				       t_wolf *wolf)
{
  const char		*c_width;
  const char		*c_height;

  if ((c_width = bunny_ini_get_field(ini, name_s, "width", 0)) == NULL)
    return (1);
  wolf->width = my_getnbr(c_width);
  if ((c_height = bunny_ini_get_field(ini, name_s, "height", 0)) == NULL)
    return (1);
  wolf->height = my_getnbr(c_height);
  return (0);
}

void			read_map(t_bunny_ini *ini, const char *name_s,
				 t_wolf *wolf)
{
  const char		*buffer;
  int			x;
  int			y;
  int			i;

  i = 0;
  x = 0;
  y = 0;
  while (x < wolf->height)
    {
      y = 0;
      while (y < wolf->width)
	{
	  if ((buffer = bunny_ini_get_field(ini, name_s, "data", i)) == NULL)
	    return ;
	  wolf->map[x][y] = buffer[0] - 48;
	  i = i + 1;
	  y = y + 1;
	}
      x = x + 1;
    }
  return ;
}

int			read_start(t_bunny_ini *ini, const char *name_s,
				   t_wolf *wolf)
{
  const char		*c_start;

  if ((c_start = bunny_ini_get_field(ini, name_s, "start_position", 0))
      == NULL)
    return (1);
  wolf->pos_x = my_getnbr(c_start);
  if ((c_start = bunny_ini_get_field(ini, name_s, "start_position", 1))
      == NULL)
    return (1);
  wolf->pos_y = my_getnbr(c_start);
  wolf->dir_x = -1;
  wolf->dir_y = 0;
  wolf->plane_x = 0;
  wolf->plane_y = 0.66;
  return (0);
}

int			read_file(const char *pathname, t_wolf *wolf)
{
  t_bunny_ini		*ini;
  t_bunny_ini_scope	*scope;
  const char		*name_s;

  if ((ini = bunny_load_ini(pathname)) == NULL)
    return (1);
  if ((scope = bunny_ini_first(ini)) == NULL)
    return (1);
  if ((scope = bunny_ini_next(ini, scope)) == NULL)
    return (1);
  name_s = bunny_ini_scope_name(ini, scope);
  read_name_tile(ini, name_s, wolf);
  if (bunny_malloc_map(wolf) == 1)
    return (1);
  read_map(ini, name_s, wolf);
  if (read_start(ini, name_s, wolf) == 1)
    return (1);
  bunny_delete_ini(ini);
  if (check_map(wolf) == 1)
    return (1);
  return (0);
}
