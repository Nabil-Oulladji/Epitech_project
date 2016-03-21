/*
** tekpaint.c for tekpaint in /home/pinta
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Jan 27 12:01:34 2016 pinta_a
** Last update Fri Jan 29 15:10:59 2016 arnaud pinta
*/

#include <lapin.h>
#include "include/my.h"

int			my_is(t_bunny_pixelarray *pix,
			      t_bunny_position *pos,
			      unsigned int color)
{
  t_bunny_position	posi[4];

  posi[0].x = pos->x;
  posi[0].y = pos->y - 1;
  posi[1].x = pos->x + 1;
  posi[1].y = pos->y;
  posi[2].x = pos->x;
  posi[2].y = pos->y + 1;
  posi[3].x = pos->x - 1;
  posi[3].y = pos->y;
  if (posi[0].y >= 0 && tekgetpixel(pix, &posi[0]) == color)
    return (1);
  if (posi[1].x < pix->clipable.clip_width
      && tekgetpixel(pix, &posi[1]) == color)
    return (2);
  if (posi[2].y < pix->clipable.clip_height
      && tekgetpixel(pix, &posi[2]) == color)
    return (3);
  if (posi[3].x >= 0 && tekgetpixel(pix, &posi[3]) == color)
    return (4);
  return (0);
}

void			my_move(t_bunny_position *pos2,
				t_bunny_position pos1,
				int move)
{
  if (move == 1)
    {
      pos2->x = pos1.x;
      pos2->y = pos1.y - 1;
    }
  if (move == 2)
    {
      pos2->x = pos1.x + 1;
      pos2->y = pos1.y;
    }
  if (move == 3)
    {
      pos2->x = pos1.x;
      pos2->y = pos1.y + 1;
    }
  if (move == 4)
    {
      pos2->x = pos1.x - 1;
      pos2->y = pos1.y;
    }
}

void			paint_full(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color color)
{
  t_bunny_position	*pile;
  unsigned int		col;
  int			move;
  int			i;
  int			size;

  i = 0;
  col = tekgetpixel(pix, pos);
  if (color.full != tekgetpixel(pix, pos))
    {
      size = pix->clipable.clip_height * pix->clipable.clip_width;
      if ((pile = bunny_malloc(sizeof(t_bunny_position) * size)) != NULL)
	{
	  pile[0] = *pos;
	  while (my_is(pix, &pile[0], col) || i >= 0)
	    {
	      while ((move = my_is(pix, &pile[i], col)) != 0 && i < size)
		{
		  tekpixel(pix, &pile[i], &color);
		  i = i + 1;
		  my_move(&pile[i], pile[i - 1], move);
		}
	      tekpixel(pix, &pile[i], &color);
	      while (i >= 0 && my_is(pix, &pile[i], col) == 0)
		i = i - 1;
	    }
	}
      bunny_free(pile);
    }
}
