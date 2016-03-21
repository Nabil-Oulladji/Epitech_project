/*
** filter_negatif.c for tekpaint in /home/pinta_a/rendu/INFOGRAPHIE/TEKPAINT/gfx_tekpaint
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Tue Dec 29 16:44:48 2015 arnaud pinta
** Last update Wed Jan 13 17:01:02 2016 nabil oulladji
*/

#include "include/my.h"

void			set_to_neg(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		color;

  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  color.full = tekgetpixel(pix, &pos);
	  color.argb[0] = 255 - color.argb[0];
	  color.argb[1] = 255 - color.argb[1];
	  color.argb[2] = 255 - color.argb[2];
	  tekpixel(pix, &pos, &color);
	  pos.x = pos.x + 1;
	}
      pos.y = pos.y + 1;
    }
}
