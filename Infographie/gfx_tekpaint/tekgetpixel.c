/*
** tekgetpixel.c for tekgetpixel in /home/pinta_a/rendu/xorshape_2020
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Thu Dec  3 14:22:35 2015 arnaud pinta
** Last update Wed Jan 13 16:46:59 2016 nabil oulladji
*/

#include "include/my.h"

unsigned int	tekgetpixel(t_bunny_pixelarray *pix,
			    const t_bunny_position *pos)
{
  int	position;

  position = pix->clipable.clip_width * pos->y + pos->x;
  return (((unsigned int *)pix->pixels)[position]);
}
