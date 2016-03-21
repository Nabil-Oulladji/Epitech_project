/*
** nuancier.c for nuancier in /home/menett_a/Modules/infographie/gfx_tekpaint
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Dec 30 13:35:03 2015 Nicolas Menettrier
** Last update Wed Jan 27 17:01:54 2016 nabil oulladji
*/

#include "include/my.h"

void		draw_nuancier(t_bunny_pixelarray *pix,
			      t_bunny_position pos)
{
  int		y;
  t_color	color;

  color.full = RED;
  y = pos.y + 360;
  while (pos.y < y)
    {
      if (pos.y < y - 300)
	color.argb[2] = color.argb[2] + 4;
      if (pos.y > y - 300 && pos.y < y - 240)
	color.argb[0] = color.argb[0] - 4;
      if (pos.y > y - 240 && pos.y < y - 180)
	color.argb[1] = color.argb[1] + 4;
      if (pos.y > y - 180 && pos.y < y - 120)
	color.argb[2] = color.argb[2] - 4;
      if (pos.y > y - 120 && pos.y < y - 60)
	color.argb[0] = color.argb[0] + 4;
      if (pos.y > y - 60 && pos.y < y)
	color.argb[1] = color.argb[1] - 4;
      pos.y = pos.y + 1;
      tekpixel(pix, &pos, &color);
    }
}

void			draw_line_square(t_bunny_pixelarray *pix,
					 t_bunny_position pos,
					 t_color color)
{
  float			r[2];
  float			g[2];
  float			b[2];

  r[0] = (float)color.argb[0] / 300;
  g[0] = (float)color.argb[1] / 300;
  b[0] = (float)color.argb[2] / 300;
  r[1] = color.argb[0];
  g[1] = color.argb[1];
  b[1] = color.argb[2];
  while (pos.x >= 80)
    {
      tekpixel(pix, &pos, &color);
      r[1] = r[1] - r[0];
      g[1] = g[1] - g[0];
      b[1] = b[1] - b[0];
      color.argb[0] = r[1];
      color.argb[1] = g[1];
      color.argb[2] = b[1];
      pos.x = pos.x - 1;
    }
}

void			init_draw_square(t_draw *st, t_color *color)
{
  st->pos.x = 379;
  st->pos.y = 680;
  st->r[0] = (255 - (float)color->argb[0]) / 300;
  st->g[0] = (255 - (float)color->argb[1]) / 300;
  st->b[0] = (255 - (float)color->argb[2]) / 300;
  st->r[1] = color->argb[0];
  st->g[1] = color->argb[1];
  st->b[1] = color->argb[2];
}

void			draw_square(t_bunny_pixelarray *pix,
				    t_color color)
{
  t_draw		st;

  init_draw_square(&st, &color);
  while (st.pos.y < 980)
    {
      draw_line_square(pix, st.pos, color);
      st.r[1] = st.r[1] + st.r[0];
      st.g[1] = st.g[1] + st.g[0];
      st.b[1] = st.b[1] + st.b[0];
      if (st.r[1] > 255)
	st.r[1] = 255;
      if (st.g[1] > 255)
	st.g[1] = 255;
      if (st.b[1] > 255)
	st.b[1] = 255;
      color.argb[0] = st.r[1];
      color.argb[1] = st.g[1];
      color.argb[2] = st.b[1];
      st.pos.y = st.pos.y + 1;
    }
}
