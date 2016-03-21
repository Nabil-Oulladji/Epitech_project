/*
** noise_color_full.c for noise_color_full in /home/pinta_a/rendu/lightning_2020
** 
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
** 
** Started on  Tue Nov 17 17:03:52 2015 arnaud pinta
** Last update Wed Jan 13 16:31:49 2016 nabil oulladji
*/

#include "include/my.h"

void	noise_color_full(t_bunny_pixelarray *pix,
			 unsigned int color)
{
  int	i;

  i = 0;
  while (i != pix->clipable.clip_height * pix->clipable.clip_width)
    {
      ((int *)pix->pixels)[i] = color;
      i = i + 1;
    }
}
