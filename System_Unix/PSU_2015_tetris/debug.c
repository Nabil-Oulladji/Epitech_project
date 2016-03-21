/*
** debug.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Mar 16 15:32:53 2016 Youssef Mekkaoui
** Last update Fri Mar 18 23:48:16 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"
#include "get_next_line.h"

void		my_swap(t_tetriminos *elem, t_tetriminos *next)
{
  t_tetriminos	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit(-1);
  tmp->color = elem->color;
  tmp->map = elem->map;
  tmp->name = elem->name;
  tmp->width = elem->width;
  tmp->error = elem->error;
  tmp->height = elem->height;
  elem->color = next->color;
  elem->map = next->map;
  elem->name = next->name;
  elem->width = next->width;
  elem->error = next->error;
  elem->height = next->height;
  next->color = tmp->color;
  next->map = tmp->map;
  next->name = tmp->name;
  next->width = tmp->width;
  next->error = tmp->error;
  next->height = tmp->height;
}

int		check_order(t_tetris *st, t_tetriminos *elem)
{
  while (elem->next != st->tetriminos)
    {
      if (my_strbiggest(elem->name, elem->next->name) > 0)
	return (0);
      elem = elem->next;
    }
  return (1);
}

void		bubble_sort(t_tetris *st, int a)
{
  t_tetriminos	*elem;
  int		finish;

  finish = 0;
  elem = st->tetriminos->next;
  while (finish == 0 && a != 1)
    {
      if (my_strbiggest(elem->name, elem->next->name) > 0)
	my_swap(elem, elem->next);
      elem = elem->next;
      if (elem->next == st->tetriminos)
	{
	  st->tetriminos->next = elem->next->next;
	  elem = st->tetriminos->next;
	  if (check_order(st, elem) == 1)
	    finish = 1;
	}
    }
  display_tetriminos(st, elem);
}

void		display_tetriminos(t_tetris *st, t_tetriminos *elem)
{
  while (elem != st->tetriminos)
    {
      my_putstr("Tetriminos : Name ");
      my_putstr(only_tetriname(elem->name));
      if (elem->error == 1)
      	my_putstr(" : Error\n");
      else
      	{
      	  my_putstr(" : Size ");
      	  my_put_nbr(elem->width);
      	  my_putchar('*');
      	  my_put_nbr(elem->height);
      	  my_putstr(" : Color ");
      	  my_put_nbr(elem->color);
      	  my_putstr(" :\n");
      	  debug_tetrimap(elem);
      	}
      elem = elem->next;
    }
}

void	debug(t_tetris *st)
{
  int	i;

  my_putstr("*** DEBUG MODE ***\n");
  display_key(st);
  my_putstr("Next : ");
  my_putstr(((st->key.without == 0) ? "Yes" : "No"));
  my_putchar(10);
  my_putstr("Level : ");
  my_put_nbr(st->key.level);
  my_putchar(10);
  my_putstr("Size : ");
  my_put_nbr(st->key.row - 1);
  my_putchar('*');
  my_put_nbr(st->key.col - 2);
  my_putchar(10);
  if ((i = tetri_nb(st)) > 0)
    bubble_sort(st, i);
  my_putstr("Press a key to start Tetris\n");
  get_next_line(0);
}
