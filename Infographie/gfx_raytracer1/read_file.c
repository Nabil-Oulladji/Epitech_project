/*
** read_file.c for read_file in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb 23 21:09:25 2016 nabil oulladji
** Last update Sun Mar 13 06:04:44 2016 oullad_n
*/

#include "struct.h"

int			malloc_struct(t_ray *st)
{
  if (st->info.nb_sphere > 0)
    if ((st->info.sphere = bunny_malloc(sizeof(t_geo)
					* (st->info.nb_sphere))) == NULL)
      return (1);
  if (st->info.nb_plan > 0)
    if ((st->info.plan = bunny_malloc(sizeof(t_geo)
				      * (st->info.nb_plan))) == NULL)
      return (1);
  if (st->info.nb_cylindre > 0)
    if ((st->info.cylindre = bunny_malloc(sizeof(t_geo)
					  * (st->info.nb_cylindre))) == NULL)
      return (1);
  if (st->info.nb_cone > 0)
    if ((st->info.cone = bunny_malloc(sizeof(t_geo)
				      * (st->info.nb_cone))) == NULL)
      return (1);
  if (st->info.nb_light > 0)
    if ((st->info.light = bunny_malloc(sizeof(t_geo)
				       * (st->info.nb_light))) == NULL)
      return (1);
  return (0);
}

int			read_nb(t_bunny_ini *ini, t_ray *st)
{
  const char		*nb;
  
  if ((nb = bunny_ini_get_field(ini, "Raytracer", "sphere", 0)) == NULL
      || (st->info.nb_sphere = my_getnbr(nb)) < 0)
    return (1);
  if ((nb = bunny_ini_get_field(ini, "Raytracer", "plan", 0)) == NULL
      || (st->info.nb_plan = my_getnbr(nb)) < 0)
    return (1);
  if ((nb = bunny_ini_get_field(ini, "Raytracer", "cylindre", 0)) == NULL
      || (st->info.nb_cylindre = my_getnbr(nb)) < 0)
    return (1);
  if ((nb = bunny_ini_get_field(ini, "Raytracer", "cone", 0)) == NULL
      || (st->info.nb_cone = my_getnbr(nb)) < 0)
    return (1);
  if ((nb = bunny_ini_get_field(ini, "Raytracer", "light", 0)) == NULL
      || (st->info.nb_light = my_getnbr(nb)) < 0)
    return (1);
  return (malloc_struct(st));
}

int			read_figure(t_bunny_ini *ini, t_ray *st)
{
  if (read_sphere(ini, st) == 1)
    return (1);
  if (read_plan(ini, st) == 1)
    return (1);
  if (read_cylindre(ini, st) == 1)
    return (1);
  if (read_cone(ini, st) == 1)
    return (1);
  if (read_light(ini, st) == 1)
    return (1);
  if (read_start(ini, st) == 1)
    return (1);
  return (0);
}

int                     read_file(const char *pathname, t_ray *st)
{
  t_bunny_ini           *ini;

  if ((ini = bunny_load_ini(pathname)) == NULL)
    return (1);
  if (read_nb(ini, st) == 1)
    {
      write(1, "Error: Size of figure invalide\n", 31);
      return (1);
    }
  if (read_figure(ini, st) == 1)
    {
      write(1, "Error: Figure invalid\n", 22);
      return (1);
    }
  return (0);
}
