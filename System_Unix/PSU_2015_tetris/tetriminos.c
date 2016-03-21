/*
** tetriminos.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Thu Mar 10 16:46:17 2016 Youssef Mekkaoui
** Last update Sat Mar 19 20:21:15 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"

t_tetriminos	*init_tetriminos()
{
  t_tetriminos *racine;

  if ((racine = malloc(sizeof(t_tetriminos))) == NULL)
    exit(-1);
  racine->width = 0;
  racine->height = 0;
  racine->name = NULL;
  racine->error = 0;
  racine->prev = racine;
  racine->next = racine;
  return (racine);
}

t_tetriminos	*add_next(t_tetriminos *elem, t_stock *stock)
{
  t_tetriminos	*new;

  if ((new = malloc(sizeof(t_tetriminos))) == NULL)
    exit(-1);
  new->map = stock->map;
  new->width = stock->width;
  new->height = stock->height;
  new->color = stock->color;
  new->error = stock->error;
  new->name = stock->name;
  new->prev = elem;
  new->next = elem->next;
  elem->next->prev = new;
  elem->next = new;
  return (new);
}
