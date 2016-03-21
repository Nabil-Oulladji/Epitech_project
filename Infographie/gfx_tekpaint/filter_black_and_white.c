/*
** filter_black_and_white.c for tekpaint in /home/pinta_a/rendu/INFOGRAPHIE/TEKPAINT/gfx_tekpaint
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Tue Dec 29 15:13:11 2015 arnaud pinta
** Last update Wed Jan 13 16:29:38 2016 nabil oulladji
*/

#include "include/my.h"

void			set_to_grey(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		color;
  int			moy;

  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  color.full = tekgetpixel(pix, &pos);
	  moy = (color.argb[0] + color.argb[1] + color.argb[2]) / 3;
	  color.argb[0] = moy;
	  color.argb[1] = moy;
	  color.argb[2] = moy;
	  tekpixel(pix, &pos, &color);
	  pos.x = pos.x + 1;
	}
      pos.y = pos.y + 1;
    }
}
