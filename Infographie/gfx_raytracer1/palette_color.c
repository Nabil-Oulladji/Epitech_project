/*
** palette_color.c for palette_color in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Feb 28 19:08:55 2016 oullad_n
** Last update Thu Mar 10 22:21:54 2016 oullad_n
*/

#include "struct.h"

void		palette_color(t_ray *st)
{
  st->color[0].full = WHITE;
  st->color[1].full = YELLOW;
  st->color[2].full = TEAL;
  st->color[3].full = RED;
  st->color[4].full = PINK;
  st->color[5].full = PURPLE;
  st->color[6].full = GREEN;
  st->color[7].full = BLUE;
  st->color[8].full = BLACK;
}
