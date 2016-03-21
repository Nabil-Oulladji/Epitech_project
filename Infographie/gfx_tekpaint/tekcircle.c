/*
** tekcircle.c for tekcirlce in /home/pinta_a/rendu/xorshape_2020
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Thu Dec  3 14:31:10 2015 arnaud pinta
** Last update Wed Jan 27 16:49:19 2016 nabil oulladji
*/

#include "include/my.h"

void	tekcircle(t_bunny_pixelarray *pix,
		  t_bunny_position *pos,
		  int radius,
		  t_color color)
{
  float			angle;
  t_bunny_position	circle;

  angle = 0;
  while (angle < 360)
    {
      circle.x = (float)pos->x + (float)radius
	* cos((M_PI * (float)angle) / 180);
      circle.y = (float)pos->y + (float)radius
	* sin((M_PI * (float)angle) / 180);
      tekpixel(pix, &circle, &color);
      angle = angle + 1;
    }
}
