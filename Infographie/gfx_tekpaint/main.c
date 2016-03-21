/*
** main.c for main in /home/menett_a/Modules/infographie/gfx_tekpaint/nicolas
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Tue Dec 29 18:07:09 2015 Nicolas Menettrier
** Last update Fri Jan 29 15:13:51 2016 arnaud pinta
*/

#include "include/my.h"

t_bunny_response		key_rsp(t_bunny_event_state state,
					t_bunny_keysym key,
					void *data)
{
  t_loop			*loop;

  loop = data;
  event_key(state, key, loop);
  if (state == GO_UP && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && key == BKS_V)
    loop->move = 1;
  if (state == GO_UP && key == BKS_V)
    loop->move = 0;
  return (GO_ON);
}

t_bunny_response		click_rsp(t_bunny_event_state state,
					  t_bunny_mousebutton key,
					  void *data)
{
  t_loop			*loop;

  loop = data;
  if (state == GO_DOWN && key == BMB_RIGHT)
    loop->r_click = 1;
  if (state == GO_UP && key == BMB_RIGHT)
    loop->r_click = 0;
  if (state == GO_DOWN && key == BMB_LEFT)
    loop->l_click = 1;
  if (state == GO_UP && key == BMB_LEFT)
    loop->l_click = 0;
  if (loop->r_click == 1)
    loop->l_click = 0;
  return (GO_ON);
}

t_bunny_response		main_loop(t_loop *loop)
{
  t_bunny_position		pos;

  pos.x = 50;
  pos.y = 50;
  loop->gui_pos.x = 397;
  loop->gui_pos.y = 0;
  gui(loop->gui, loop->nuancier);
  bunny_set_key_response(key_rsp);
  bunny_set_click_response(click_rsp);
  set_click(loop);
  if (loop->choice == 1)
    tek_fill_circle(loop->gui, &pos, loop->size, loop->color);
  else if (loop->choice == 2)
    square(loop->gui, pos, loop->color, loop->size);
  bunny_blit(&loop->win->buffer, &loop->background->clipable, 0);
  bunny_blit(&loop->win->buffer, &loop->gui->clipable, 0);
  bunny_blit(&loop->win->buffer, &loop->pix->clipable, &loop->gui_pos);
  bunny_display(loop->win);
  return (GO_ON);
}

int		main(int argc, char **argv)
{
  t_loop	loop;

  set_max_heap_size(30);
  if (my_test(&loop, argv, argc))
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_loop(loop.win, 80, &loop);
  bunny_delete_clipable(&loop.pix->clipable);
  bunny_stop(loop.win);
  return (0);
}
