/*
** tekpixel.c for tekpixel in /home/oullad_n/rendu/Infographie
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Nov 25 14:55:16 2015 nabil oulladji
** Last update Mon Dec 28 16:37:08 2015 nabil oulladji
*/

#include "lapin.h"

void		tekpixel(t_bunny_pixelarray *pix,
			  t_bunny_position *pos, t_color *color)
{
  unsigned int	calc;

  calc = ((pos->y * pix->clipable.buffer.width) + pos->x);
  ((unsigned int*)(pix)->pixels)[calc] = color->full;
}
