/*
** save.c for save in /home/menett_a/Modules/infographie/gfx_tekpaint
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Jan 13 16:33:57 2016 Nicolas Menettrier
** Last update Wed Jan 27 16:48:55 2016 nabil oulladji
*/

#include "include/my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

void	init_header(t_bunny_pixelarray *daw,
		    char *name,
		    int fd)
{
  char	*str;

  write(fd, "[velo]\n", 7);
  write(fd, "name=", 5);
  write(fd, name, my_strlen(name));
  write(fd, "\n", 1);
  str = my_getint(daw->clipable.clip_width);
  write(fd, "width=", 6);
  write(fd, str, my_strlen(str));
  write(fd, "\n", 1);
  str = my_getint(daw->clipable.clip_height);
  write(fd, "heigth=", 7);
  write(fd, str, my_strlen(str));
  write(fd, "\n", 1);
  write(fd, "image_color=", 12);
  free(str);
}

int		save_velo(t_bunny_pixelarray *daw,
			  char *name)
{
  t_save	st;

  if ((st.fd = open(name, O_CREAT | O_RDWR, S_IRWXU)) < 0)
    return (1);
  st.x[0] = 0;
  st.x[1] = daw->clipable.clip_width * daw->clipable.clip_height;
  init_header(daw, name, st.fd);
  while (st.x[0] < st.x[1])
    {
      st.color.full = ((int *)daw->pixels)[st.x[0]];
      st.i = 0;
      while (st.i < 4)
	{
	  st.str = my_getint(st.color.argb[st.i]);
	  write(st.fd, st.str, my_strlen(st.str));
	  if (st.x[0] + 1 != st.x[1] || st.i < 3)
	    write(st.fd, ",", 1);
	  st.i = st.i + 1;
	}
      st.x[0] = st.x[0] + 1;
    }
  close(st.fd);
  return (0);
}
