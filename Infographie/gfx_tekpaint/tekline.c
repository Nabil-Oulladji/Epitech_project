/*
** tekline.c for tekline in /home/menett_a/Modules/infographie/fil_de_fer
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Dec 21 15:25:33 2015 Nicolas Menettrier
** Last update Wed Jan 13 16:32:19 2016 nabil oulladji
*/

#include "include/my.h"

void	tekswap(t_bunny_position *pos,
		t_bunny_position *pos1)
{
  int	swap;

  swap = pos->x;
  pos->x = pos1->x;
  pos1->x = swap;
  swap = pos->y;
  pos->y = pos1->y;
  pos1->y = swap;
}

void	tekline_2(t_bunny_pixelarray *pix,
		  t_bunny_position *pos,
		  unsigned int color)
{
  float	coef;
  float	b;

  coef = ((float)(pos[1].y - pos[0].y)) / ((float)(pos[1].x - pos[0].x));
  coef = 1 / coef;
  b = (float)(pos[0].x - (coef * pos[0].y));
  if (pos[0].y > pos[1].y)
    tekswap(&pos[0], &pos[1]);
  while (pos[0].y <= pos[1].y)
    {
      tekpixel(pix, pos, color);
      pos[0].y = pos[0].y + 1;
      pos[0].x = coef * pos[0].y + b;
    }
}

void	tekline_1(t_bunny_pixelarray *pix,
		  t_bunny_position *pos,
		  unsigned int color)
{
  float	coef;
  float	b;

  coef = ((float)(pos[1].y - pos[0].y)) / ((float)(pos[1].x - pos[0].x));
  b = (float)(pos[0].y - (coef * pos[0].x));
  if (pos[0].x > pos[1].x)
    tekswap(&pos[0], &pos[1]);
  while (pos[0].x != pos[1].x)
    {
      tekpixel(pix, pos, color);
      pos[0].x = pos[0].x + 1;
      pos[0].y = coef * pos[0].x + b;
      color = color - 100;
    }
}

void	tekline(t_bunny_pixelarray *pix,
		t_bunny_position *pos,
		unsigned int color)
{
  float	coef;
  float	b;

  coef = ((float)(pos[1].y - pos[0].y)) / ((float)(pos[1].x - pos[0].x));
  b = (float)(pos[0].y - (coef * pos[0].x));
  if (coef <= 1 && coef >= -1)
    tekline_1(pix, pos, color);
  else if (coef > 1 || coef < -1)
    tekline_2(pix, pos, color);
}
