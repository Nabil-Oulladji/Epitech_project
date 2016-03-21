/*
** vecnorm.c for vecnorm in /home/oullad_n/rendu/Infographie/gfx_wolf3d/tcore
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Dec 22 17:34:52 2015 nabil oulladji
** Last update Sun Dec 27 18:38:47 2015 nabil oulladji
*/

#include <math.h>
#include "lapin.h"

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	x2;
  double	y2;

  x2 = coord1->x - coord0->x;
  y2 = coord1->y - coord0->y;
  return (sqrt((x2 * x2) + (y2 * y2)));
}
