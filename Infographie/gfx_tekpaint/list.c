/*
** list.c for tekpaint in /home/pinta_a/rendu/INFOGRAPHIE/TEKPAINT/VRAI2/gfx_tekpaint
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Tue Jan  5 13:50:35 2016 arnaud pinta
** Last update Wed Jan 13 16:30:04 2016 nabil oulladji
*/

#include "include/my.h"

t_list		init_list(void)
{
  t_list	*list;

  list = malloc(sizeof(t_list));
  if (list != NULL)
    {
      list->next = list;
      list->prev = list;
    }
  return (list);
}

void		add_before(t_list list, t_pix pix)
{
  t_list
}

void		my_delete_in_list(t_list *list)
{
  list->prev->next = list->next;
  list->next->prev = list->prev;
  bunny_delete_clipable(&list->pix.pix->clipable);
  free(list);
}
