/*
** filter_sepia.c for tekpaint in /home/pinta_a/rendu/INFOGRAPHIE/TEKPAINT/gfx_tekpaint
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Tue Dec 29 15:42:20 2015 arnaud pinta
** Last update Wed Jan 27 16:26:29 2016 nabil oulladji
*/

#include "include/my.h"

void			set_to_sepia(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		color;
  t_color		sepia;

  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  color.full = tekgetpixel(pix, &pos);
	  sepia.argb[0] = 0.393 * (float)color.argb[0] + 0.769
	    * (float)color.argb[1] + 0.189 * (float)color.argb[2];
	  sepia.argb[1] = 0.349 * (float)color.argb[0] + 0.686
	    * (float)color.argb[1] + 0.168 * (float)color.argb[2];
	  sepia.argb[2] = 0.272 * (float)color.argb[0] + 0.534
	    * (float)color.argb[1] + 0.131 * (float)color.argb[2];
	  sepia.argb[2] = sepia.argb[2] * 0;
	  tekpixel(pix, &pos, &sepia);
	  pos.x = pos.x + 1;
	}
      pos.y = pos.y + 1;
    }
}
