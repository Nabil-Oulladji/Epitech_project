/*
** read_position.c for read_position in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sat Mar 12 19:43:27 2016 oullad_n
** Last update Sat Mar 12 19:43:59 2016 oullad_n
*/

#include "struct.h"

int			read_light(t_bunny_ini *ini, t_ray *st)
{
  const char		*nb[3];
  int			i;
  int			k;
  int			l;

  k = -1;
  i = 0;
  while (++k < st->info.nb_light)
    {
      l = -1;
      while (++l < 3)
	if ((nb[l] = bunny_ini_get_field(ini, "Raytracer", "light", ++i)) == NULL)
	  return (1);
      st->info.light[k].x = my_getnbr(nb[0]);
      st->info.light[k].y = my_getnbr(nb[1]);
      st->info.light[k].z = my_getnbr(nb[2]);
    }
  return (0);
}

int			read_start(t_bunny_ini *ini, t_ray *st)
{
  const char		*nb;

  if ((nb = bunny_ini_get_field(ini, "Raytracer", "start", 0)) == NULL)
    return (1);
  st->a_x = my_getnbr(nb);
  if ((nb = bunny_ini_get_field(ini, "Raytracer", "start", 1)) == NULL)
    return (1);
  st->a_y = my_getnbr(nb);
  if ((nb = bunny_ini_get_field(ini, "Raytracer", "start", 2)) == NULL)
    return (1);
  st->a_z = my_getnbr(nb);
  return (0);
}
