/*
** event.c for event in /home/menett_a/Modules/infographie/gfx_tekpaint
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Dec 30 12:55:35 2015 Nicolas Menettrier
** Last update Fri Jan 29 15:18:32 2016 arnaud pinta
*/

#include "include/my.h"

void			set_click_part2(t_loop *loop)
{
  if (loop->l_click == 1 && test_pos_plus(loop) == 2)
    loop->size = loop->size + 1;
  if (loop->l_click == 1 && test_pos_moin(loop) == 2)
    loop->size = loop->size - 1;
  if (loop->l_click == 1 && test_pos_rond(loop) == 2)
    loop->choice = 1;
  if (loop->l_click == 1 && test_pos_carre(loop) == 2)
    loop->choice = 2;
  if (loop->l_click == 1 && test_pos_save(loop) == 2)
    save_velo(loop->pix, loop->save_name);
  if (loop->l_click == 1 && test_pos_nuancier(loop) == 2)
    {
      loop->nuancier.full = tekgetpixel(loop->gui, loop->mouse);
      loop->cursor.y = loop->mouse->y;
    }
  if (loop->l_click == 1 && test_pos_square(loop) == 2)
    loop->color.full = tekgetpixel(loop->gui, loop->mouse);
}

void			set_click(t_loop *loop)
{
  t_bunny_position	draw_pos;

  loop->mouse = bunny_get_mouse_position();
  draw_pos.x = loop->mouse->x - loop->gui_pos.x;
  draw_pos.y = loop->mouse->y - loop->gui_pos.y;
  if (test_pos_mouse(loop) == 1)
    {
      if (loop->l_click == 1)
	{
	  if (loop->choice == 1)
	    tek_fill_circle(loop->pix, &draw_pos, loop->size, loop->color);
	  else if (loop->choice == 2)
	    square(loop->pix, draw_pos, loop->color, loop->size);
	}
      if (loop->r_click == 1)
	loop->color.full = tekgetpixel(loop->pix, &draw_pos);
      if (loop->pot == 1)
	paint_full(loop->pix, &draw_pos, loop->color);
    }
  else
    set_click_part2(loop);
  if (loop->size < 1)
    loop->size = 1;
  if (loop->size > 50)
    loop->size = 50;
}

void	event_key(t_bunny_event_state state,
				  t_bunny_keysym key,
				  t_loop *loop)
{
  if (state == GO_UP && key == BKS_R)
    set_to_grey(loop->pix);
  if (state == GO_UP && key == BKS_T)
    set_to_neg(loop->pix);
  if (state == GO_DOWN && key == BKS_A)
    loop->pot = 1;
  if (state == GO_UP && key == BKS_A)
    loop->pot = 0;
}
