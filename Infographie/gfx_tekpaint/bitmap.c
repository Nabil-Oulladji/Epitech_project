/*
** bitmap.c for tekpaint in /home/pinta_a/rendu/INFOGRAPHIE/TEKPAINT
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Mon Dec 28 16:02:58 2015 arnaud pinta
** Last update Fri Jan 29 15:25:02 2016 arnaud pinta
*/

#include "include/my.h"

void			x_read(int fd, int size)
{
  int			buff[1];
  int			i;

  i = 0;
  while (i < size && read(fd, buff, 1) > 0)
    i = i + 1;
}

void			my_bmp_dim(t_bmp *bmp, int fd)
{
  if (read(fd, bmp->buff, 4) == 4)
    bmp->width = bmp->buff[0];
  if (read(fd, bmp->buff, 4) == 4)
    bmp->height = bmp->buff[0];
  bmp->pix = bunny_new_pixelarray(bmp->width, bmp->height);
  bmp->pix->clipable.clip_x_position = 0;
  bmp->i = 2;
  bmp->pos.y = bmp->height - 1;
  bmp->pos.x = 0;
}

t_bunny_pixelarray	*my_load_bitmap(const char *file)
{
  t_bmp			bmp;

  if ((bmp.fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  x_read(bmp.fd, 18);
  my_bmp_dim(&bmp, bmp.fd);
  while (read(bmp.fd, bmp.buff, 1) > 0 && bmp.pos.y >= 0)
    {
      bmp.color.argb[bmp.i] = bmp.buff[0];
      bmp.i = bmp.i - 1;
      if (bmp.i < 0)
	bmp.i = 3;
      if (bmp.i == 2)
	{
	  tekpixel(bmp.pix, &bmp.pos, &bmp.color);
	  bmp.pos.x = bmp.pos.x + 1;
	  if (bmp.pos.x == bmp.width)
	    {
	      bmp.pos.x = 0;
	      bmp.pos.y = bmp.pos.y - 1;
	    }
	}
    }
  close(bmp.fd);
  return (bmp.pix);
}
