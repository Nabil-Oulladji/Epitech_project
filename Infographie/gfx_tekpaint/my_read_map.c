/*
** my_read_map.c for read_map in /home/menett_a/Modules/infographie/test/read_velo
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Tue Jan 26 16:50:38 2016 Nicolas Menettrier
** Last update Wed Jan 27 19:53:44 2016 nabil oulladji
*/

#include "include/my.h"

void	norm_while(t_loop *data)
{
  int		i;
  int		j;
  int		k;
  t_color	col;

  i = 0;
  k = 0;
  j = 0;
  while (i < (data->heigth * data->width) * 4)
    {
      col.argb[j] =
	my_getnbr_const(bunny_ini_get_field(data->ini, "velo", "image_color", i));
      i = i + 1;
      j = j + 1;
      if (j == 4)
	{
	  ((t_color *)data->pix->pixels)[k] = col;
	  j = 0;
	  k = k + 1;
	}
    }
}

char		*read_velo(t_loop *data, char *name)
{
  if ((data->ini = bunny_load_ini(name)) == NULL)
    return ("Error load ini\n");
  data->heigth =
    my_getnbr_const(bunny_ini_get_field(data->ini, "velo", "width", 0));
  data->width =
    my_getnbr_const(bunny_ini_get_field(data->ini, "velo", "heigth", 0));
  data->pix = bunny_new_pixelarray(data->heigth, data->width);
  norm_while(data);
  return (NULL);
}
