/*
** draw_line.c for draw_line in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sat Dec 26 21:59:43 2015 nabil oulladji
** Last update Sun Dec 27 20:04:11 2015 nabil oulladji
*/

#include "wolf3d.h"
#include "lapin.h"

void                    background(t_bunny_pixelarray *pix, t_wolf *wolf)
{
  wolf->i = 0;
  wolf->max = pix->clipable.clip_width * pix->clipable.clip_height;
  wolf->pixel = pix->pixels;
  while (wolf->i < (wolf->max / 2))
    {
      if (wolf->mode == 1)
	wolf->pixel[wolf->i] = 0xFF330000;
      if (wolf->mode == 2)
        wolf->pixel[wolf->i] = 0xFF330000;
      if (wolf->mode == 3)
	wolf->pixel[wolf->i] = BLACK;
      wolf->i = wolf->i + 1;
    }
  while (wolf->i < wolf->max)
    {
      if (wolf->mode == 1)
	wolf->pixel[wolf->i] = WHITE;
      if (wolf->mode == 2)
	wolf->pixel[wolf->i] = 0xFF330000;
      if (wolf->mode == 3)
	wolf->pixel[wolf->i] = GREEN;
      wolf->i = wolf->i + 1;
    }
}

void	draw_mode_3(t_bunny_position pos[1], int y,
		     t_color color[1], t_wolf *wolf)
{
  while (y <= wolf->draw_end)
    {
      pos[0].y = y;
      tekpixel(wolf->pix, pos, wolf->draw_end);
      y = y + 1;
    }
  color[0].argb[0] = 255;
  color[0].argb[1] = 0;
  color[0].argb[2] = 0;
  while (y <= wolf->draw_end + 50)
    {
      pos[0].y = y;
      color[0].argb[0] -= 5;
      color[0].argb[1] += 5;
      tekpixel(wolf->pix, pos, color[0].full);
      y = y + 1;
    }
}

void	draw_mode_2(t_bunny_position pos[1], int y,
		     t_color color[1], t_wolf *wolf)
{
  color[0].argb[0] = 51;
  color[0].argb[1] = 204;
  color[0].argb[2] = 255;
  pos[0].y = y;
  tekpixel(wolf->pix, pos, color[0].full);
  pos[0].y = wolf->draw_end;
  tekpixel(wolf->pix, pos, color[0].full);
}

void	draw_mode_1(t_bunny_position pos[1], int y,
		     t_color color[1], t_wolf *wolf)
{
  color[0].argb[0] = 50;
  color[0].argb[1] = 50;
  color[0].argb[2] = 50;
  color[1].argb[0] = 100;
  color[1].argb[1] = 100;
  color[1].argb[2] = 100;
  pos[0].y = y;
  if (y == wolf->draw_start && y != 0)
    tekpixel(wolf->pix, pos, WHITE);
  y = y + 1;
  while (y <= wolf->draw_end)
    {
      pos[0].y = y;
      if (wolf->side == 0)
	tekpixel(wolf->pix, pos, color[0].full);
      else
	tekpixel(wolf->pix, pos, color[1].full);
      y = y + 1;
    }
}

void			draw_line(t_wolf *wolf)
{
  t_bunny_position	pos[1];
  int			y;
  t_color		color[1];

  color[0].argb[0] = 255;
  color[0].argb[1] = 255;
  color[0].argb[2] = 255;
  y = wolf->draw_start;
  pos[0].x = wolf->c_x;
  if (wolf->mode == 1)
    draw_mode_1(pos, y, color, wolf);
  if (wolf->mode == 2)
    draw_mode_2(pos, y, color, wolf);
  if (wolf->mode == 3)
    draw_mode_3(pos, y, color, wolf);
}
