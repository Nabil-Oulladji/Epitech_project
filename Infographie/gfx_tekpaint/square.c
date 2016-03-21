/*
** square.c for gfx_tekpaint in /home/mekkao_y/rendu/infographie/gfx_tekpaint
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Jan 13 16:12:23 2016 Youssef Mekkaoui
** Last update Wed Jan 27 10:58:22 2016 Youssef Mekkaoui
*/

#include <lapin.h>
#include "include/my.h"

void			square(t_bunny_pixelarray *pix,
				    t_bunny_position pos,
				    t_color color,
				    int size)

{
  t_bunny_position	counter;

  counter.x = pos.x;
  counter.y = pos.y - size;
  while (counter.y < pos.y + size)
    {
      counter.x = pos.x - size;
      while (counter.x < pos.x + size)
	{
	  tekpixel(pix, &counter, &color);
	  counter.x = counter.x + 1;
	}
      counter.y = counter.y + 1;
    }
}
