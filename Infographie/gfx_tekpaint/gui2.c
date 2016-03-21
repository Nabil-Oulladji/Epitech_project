/*
** gui2.c for gui2 in /home/oullad_n/rendu/Infographie/gfx_tekpaint
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan 27 16:28:47 2016 nabil oulladji
** Last update Wed Jan 27 16:31:05 2016 nabil oulladji
*/

#include "include/my.h"

void			set_rightgui(t_bunny_pixelarray *pix,
				     t_color color)
{
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y <= pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  tekpixel(pix, &pos, &color);
	  pos.x = pos.x + 1;
	}
      pos.y = pos.y + 1;
    }
}

void			plus(t_bunny_pixelarray *pix,
			     t_color color)
{
  t_bunny_position	pos;
  t_bunny_position	pos_save;

  pos.y = 48;
  pos.x = 125;
  pos_save = pos;
  while (pos.y < pos_save.y + 25)
    {
      tekpixel(pix, &pos, &color);
      pos.y = pos.y + 1;
    }
  pos.y = 60;
  pos.x = 113;
  while (pos.x < pos_save.x + 12)
    {
      tekpixel(pix, &pos, &color);
      pos.x = pos.x + 1;
    }
}

void			moin(t_bunny_pixelarray *pix,
			     t_color color)
{
  t_bunny_position	pos;
  t_bunny_position	pos_save;

  pos.y = 60;
  pos.x = 160;
  pos_save = pos;
  while (pos.x < pos_save.x + 25)
    {
      tekpixel(pix, &pos, &color);
      pos.x = pos.x + 1;
    }
}

void			circle(t_bunny_pixelarray *pix,
			     t_color color)
{
  t_bunny_position	pos;

  pos.y = 100;
  pos.x = 125;
  tek_fill_circle(pix, &pos, 10, color);
}
