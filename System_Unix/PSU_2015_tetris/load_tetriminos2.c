/*
** load_tetriminos2.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Fri Mar 18 23:04:06 2016 Youssef Mekkaoui
** Last update Sun Mar 20 17:49:18 2016 oullad_n
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tetris.h"
#include "get_next_line.h"

void	fill_file(char *file, char *d_name)
{
  int	i;
  int	j;

  i = 13;
  j = 0;
  my_strcpy(file, "./tetriminos/", 13);
  while (j < my_strlen(d_name))
    {
      file[i] = d_name[j];
      i = i + 1;
      j = j + 1;
    }
  file[i] = '\0';
}

void		init_stock(t_stock *st, char *file)
{
  st->map = NULL;
  st->color = 0;
  st->name = file;
  st->width = 0;
  st->error = 0;
  st->height = 0;
  st->i = 0;
  st->k = - 1;
  st->j = 0;
  st->max = 0;
}

void		init_checktetri(t_checktetri *ct, char *file, int fd)
{
  struct stat	st;

  if (stat(file, &st) == -1)
    exit(-1);
  if ((ct->buff = malloc(sizeof(char) * st.st_size + 1)) == NULL)
    exit(-1);
  if ((read(fd, ct->buff, st.st_size)) < 0)
    exit(-1);
  ct->buff[st.st_size] = '\0';
}

void		malloc_map(t_stock *stock)
{
  int	i;

  i = 0;
  if ((stock->map = malloc(sizeof(int *) * stock->height)) == NULL)
    exit(-1);
  while (i < stock->height)
    {
      if ((stock->map[i] = malloc(sizeof(int) * stock->width)) == NULL)
	exit(-1);
      i = i + 1;
    }
}

void	check_endpiece(char *buff, t_stock *stock)
{
  while (buff[++stock->k])
    {
      if (buff[stock->k] == '\n' && buff[stock->k + 1] != '\0')
	{
	  if (stock->max < stock->i)
	    stock->max = stock->i;
	  stock->i = 0;
	  stock->j = stock->j + 1;
	}
      else if (check_linepiece(buff, stock) == 1)
	stock->i = stock->i + 1;
    }
}
