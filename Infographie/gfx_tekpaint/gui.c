/*
** gui.c for tekpaint in /home/mekkao_y/rendu/infographie/gfx_tekpaint
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Tue Dec 29 15:31:12 2015 Youssef Mekkaoui
** Last update Wed Jan 27 16:31:18 2016 nabil oulladji
*/

#include "include/my.h"

void			gui_square(t_bunny_pixelarray *pix,
			     t_color color)
{
  t_bunny_position	pos;

  pos.y = 100;
  pos.x = 172;
  square(pix, pos, color, 10);
}

void			nuancier(t_bunny_pixelarray *pix,
				 t_color *color,
				 t_color col)
{
  t_bunny_position	pos;
  t_bunny_position	pos_save;

  pos.y = 680;
  pos.x = 0;
  pos_save = pos;
  while (pos.x < pos_save.x + 396)
    {
      tekpixel(pix, &pos, color);
      pos.x = pos.x + 1;
    }
  pos.x = 20;
  while (pos.x < 40)
    {
      draw_nuancier(pix, pos);
      pos.x = pos.x + 1;
    }
  draw_square(pix, col);
}

void			save(t_bunny_pixelarray *pix,
			     t_color color)
{
  t_bunny_position	pos;

  pos.y = 300;
  pos.x = 172;
  square(pix, pos, color, 100);
}

void			gui(t_bunny_pixelarray *pix,
			    t_color col)
{
  t_color		color[4];

  color[0].full = 0xFFB5BECB;
  color[1].full = BLACK;
  set_rightgui(pix, color[0]);
  plus(pix, color[1]);
  moin(pix, color[1]);
  circle(pix, color[1]);
  gui_square(pix, color[1]);
  save(pix, color[1]);
  nuancier(pix, &color[1], col);
}
