/*
** tek_fill_circle.c for tek_fill_circle in /home/menett_a/Modules/infographie/gfx_tekpaint
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Tue Dec 29 15:32:25 2015 Nicolas Menettrier
** Last update Wed Jan 13 17:01:16 2016 nabil oulladji
*/

#include "include/my.h"

void	tek_fill_circle(t_bunny_pixelarray *pix,
			t_bunny_position *pos,
			int radius,
			t_color color)
{
  float			i;
  float			angle;
  t_bunny_position	circle;

  i = 1;
  while (i <= radius)
    {
      angle = 0;
      while (angle < 360)
	{
	  circle.x = (float)pos->x + (float)i * cos((M_PI * (float)angle) / 180);
	  circle.y = (float)pos->y + (float)i * sin((M_PI * (float)angle) / 180);
	  tekpixel(pix, &circle, &color);
	  angle = angle + 1;
	}
      i = i + 0.5;
    }
}
