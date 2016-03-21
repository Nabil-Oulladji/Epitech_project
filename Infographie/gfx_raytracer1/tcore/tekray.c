/*
** tekray.c for tekray in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb 23 10:59:38 2016 nabil oulladji
** Last update Sat Mar 12 18:56:59 2016 oullad_n
*/

#include "../struct.h"

void		tekray(const t_bunny_position *screen_info,
		       int *x,
		       int *y,
		       int *z)
{
  *x = screen_info[1].x - (screen_info[0].x / 2);
  *y = screen_info[1].y - (screen_info[0].y / 2);
  *z = 100;
}
