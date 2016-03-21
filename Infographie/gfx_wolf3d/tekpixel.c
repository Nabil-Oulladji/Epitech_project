/*
** tekpixel.c for tekpixel in /home/oullad_n/rendu/Infographie
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Nov 25 14:55:16 2015 nabil oulladji
** Last update Sat Dec 26 20:30:56 2015 nabil oulladji
*/

#include "lapin.h"

void		tekpixel(t_bunny_pixelarray *pix,
			  t_bunny_position *pos, unsigned int color)
{
  unsigned int	calc;

  calc = ((pos[0].y * pix->clipable.buffer.width) + pos[0].x);
  ((unsigned int*)(pix)->pixels)[calc] = color;
}
