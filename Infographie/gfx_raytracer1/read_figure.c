/*
** read_file.c for read_file in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
**
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
**
** Started on  Tue Feb 23 21:09:25 2016 nabil oulladji
** Last update Sun Mar 13 00:12:24 2016 oullad_n
*/

#include "struct.h"

int			read_sphere(t_bunny_ini *ini, t_ray *st)
{
  const char		*nb[5];
  int			i;
  int			k;
  int			l;
  
  k = -1;
  i = 1;
  while (++k < st->info.nb_sphere)
    {
      l = -1;
      while (++l < 5)
	if ((nb[l] = bunny_ini_get_field(ini, "Raytracer", "sphere", i++))
	    == NULL)
	  return (1);
      st->info.sphere[k].x = my_getnbr(nb[0]);
      st->info.sphere[k].y = my_getnbr(nb[1]);
      st->info.sphere[k].z = my_getnbr(nb[2]);
      st->info.sphere[k].rayon = my_getnbr(nb[3]);
      if ((st->info.sphere[k].color = my_getnbr(nb[4])) > 10
      	  || st->info.sphere[k].color < 0)
      	return (1);
    }
  return (0);
}

int			read_plan(t_bunny_ini *ini, t_ray *st)
{
  const char		*nb[8];
  int			i;
  int			k;
  int			l;

  k = -1;
  i = 0;
  while (++k < st->info.nb_plan)
    {
      l = -1;
      while (++l < 8)
	if ((nb[l] = bunny_ini_get_field(ini, "Raytracer", "plan", ++i)) == NULL)
	  return (1);
      st->info.plan[k].x = my_getnbr(nb[0]);
      st->info.plan[k].y = my_getnbr(nb[1]);
      st->info.plan[k].z = my_getnbr(nb[2]);
      st->info.plan[k].vx = my_getnbr(nb[3]);
      st->info.plan[k].vy = my_getnbr(nb[4]);
      st->info.plan[k].vz = my_getnbr(nb[5]);
      if ((st->info.plan[k].color = my_getnbr(nb[6])) > 10
      	  || st->info.plan[k].color < 0)
      	return (1);
      st->info.plan[k].mirror = my_getnbr(nb[7]);
    }
  return (0);
}

int			read_cylindre(t_bunny_ini *ini, t_ray *st)
{
  const char		*nb[5];
  int			i;
  int			k;
  int			l;

  k = -1;
  i = 1;
  while (++k < st->info.nb_cylindre)
    {
      l = -1;
      while (++l < 5)
	if ((nb[l] = bunny_ini_get_field(ini, "Raytracer", "cylindre", i++))
	    == NULL)
	  return (1);
      st->info.cylindre[k].x = my_getnbr(nb[0]);
      st->info.cylindre[k].y = my_getnbr(nb[1]);
      st->info.cylindre[k].z = my_getnbr(nb[2]);
      st->info.cylindre[k].rayon = my_getnbr(nb[3]);
      if ((st->info.cylindre[k].color = my_getnbr(nb[4])) > 10
      	  || st->info.cylindre[k].color < 0)
      	return (1);
    }
  return (0);
}

int			read_cone(t_bunny_ini *ini, t_ray *st)
{
  const char		*nb[5];
  int			i;
  int			k;
  int			l;

  k = -1;
  i = 1;
  while (++k < st->info.nb_cone)
    {
      l = -1;
      while (++l < 5)
	if ((nb[l] = bunny_ini_get_field(ini, "Raytracer", "cone", i++)) == NULL)
	  return (1);
      st->info.cone[k].x = my_getnbr(nb[0]);
      st->info.cone[k].y = my_getnbr(nb[1]);
      st->info.cone[k].z = my_getnbr(nb[2]);
      st->info.cone[k].rayon = my_getnbr(nb[3]);
      if ((st->info.cone[k].color = my_getnbr(nb[4])) > 10
      	  || st->info.cone[k].color < 0)
      	return (1);
    }
  return (0);
}
