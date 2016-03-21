/*
** tekpixel.c for tekpixel in /home/pinta_a/rendu/lightning_2020
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Tue Nov 17 17:15:08 2015 arnaud pinta
** Last update Wed Jan 27 16:49:33 2016 nabil oulladji
*/

#include "include/my.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int	position;

  position = pix->clipable.clip_width * pos->y + pos->x;
  if (pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y >= 0 && pos->y < pix->clipable.clip_height)
    ((int*)pix->pixels)[position] = color->full;
}
