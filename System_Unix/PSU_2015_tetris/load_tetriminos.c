/*
** load_tetriminos.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Thu Mar 10 21:51:52 2016 Youssef Mekkaoui
** Last update Sat Mar 19 20:19:08 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tetris.h"
#include "get_next_line.h"

int		get_fill(t_stock *stock, char *buff, int i)
{
  char	*s;
  int	r;

  if ((r = my_backn(buff)) == -1)
    {
      stock->width = 0;
      stock->height = 0;
      stock->color = 0;
      return (1);
    }
  if ((s = malloc(sizeof(char) * r)) == NULL)
    exit(-1);
  while (i < r)
    {
      s[i] = buff[i];
      i = i + 1;
    }
  i = 0;
  stock->width = my_getnbr_good(buff);
  i = 1 + my_intlen(stock->width);
  stock->height = my_getnbr_good(&buff[i]);
  i = i + my_intlen(stock->height);
  stock->color = my_getnbr_good(&buff[i+1]);
  return (0);
}

int		check_validpiece(t_tetris *tetris, t_stock *stock, char *buff)
{
  check_endpiece(buff, stock);
  check_endpiece2(buff, stock);
  if (stock->width != stock->max || stock->height != stock->j
      || tetris->key.col < stock->max || tetris->key.row < stock->j)
    stock->error = 1;
  return (0);
}

void	fill_tetrimap(t_checktetri *ct, t_stock *stock, int i, int k)
{
  int	j;

  j = -1;
  while (ct->buff2[++j])
    {
      if (ct->buff2[j] == '\n' && ct->buff2[j + 1] != '\0')
  	{
  	  while (k < stock->width)
  	    stock->map[i][k++] = 2;
  	  k = 0;
  	  i = i + 1;
  	}
      else if (ct->buff2[j] == ' ')
  	stock->map[i][k++] = 2;
      else if (ct->buff2[j] == '*')
  	stock->map[i][k++] = 1;
      else if (ct->buff2[j + 1] == '\0' && ct->buff2[j] == '\n')
	i = i;
      else
	stock->error = 1;
    }
  while (k < stock->width)
    stock->map[i][k++] = 2;
}

int		check_tetriminos(int fd, char *file, t_tetris *tetris)
{
  t_checktetri	ct;
  t_stock	stock;

  init_stock(&stock, file);
  init_checktetri(&ct, file, fd);
  get_fill(&stock, ct.buff, 0);
  if (stock.width == 0 || stock.height == 0 || stock.color == 0)
    {
      stock.error = 1;
      add_next(tetris->tetriminos, &stock);
      return (1);
    }
  malloc_map(&stock);
  ct.buff2 = &ct.buff[my_backn(ct.buff) + 1];
  check_validpiece(tetris, &stock, ct.buff2);
  if (stock.error == 1)
    {
      add_next(tetris->tetriminos, &stock);
      return (1);
    }
  fill_tetrimap(&ct, &stock, 0, 0);
  add_next(tetris->tetriminos, &stock);
  return (0);
}

int		load_tetriminos(t_tetris *st)
{
  DIR		*dir;
  struct dirent	*readed;
  char		*file;
  int		fd;

  if ((dir = opendir("./tetriminos/")) == NULL)
    exit(-1);
  while ((readed = readdir(dir)) != NULL)
    {
      if (my_strcompare(readed->d_name, ".tetrimino"))
	{
	  if ((file = malloc(sizeof(char) * (14 + my_strlen(readed->d_name)))) == NULL)
	    return (-1);
	  fill_file(file, readed->d_name);
	  if ((fd = open(file, O_RDONLY)) != -1)
	    check_tetriminos(fd, file, st);
	  else
	    exit(-1);
      	}
    }
  closedir(dir);
  return (1);
}
