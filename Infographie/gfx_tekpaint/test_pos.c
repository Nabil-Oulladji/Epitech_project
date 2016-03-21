/*
** test_pos.c for test_pos in /home/menett_a/Modules/infographie/gfx_tekpaint
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Dec 30 13:11:00 2015 Nicolas Menettrier
** Last update Wed Jan 27 19:44:28 2016 nabil oulladji
*/

#include "include/my.h"

int     test_pos_save(t_loop *loop)
{
  int   test;

  test = 0;
  if (loop->mouse->x >= 71 && loop->mouse->x < 276)
    test = test + 1;
  if (loop->mouse->y >= 189 && loop->mouse->y < 381)
    test = test + 1;
  return (test);
}

int	test_pos_nuancier(t_loop *loop)
{
  int	test;

  test = 0;
  if (loop->mouse->x >= 20 && loop->mouse->x < 40)
    test = test + 1;
  if (loop->mouse->y > 680 && loop->mouse->y < 1040)
    test = test + 1;
  return (test);
}

int	test_pos_square(t_loop *loop)
{
  int	test;

  test = 0;
  if (loop->mouse->x >= 80 && loop->mouse->x < 380)
    test = test + 1;
  if (loop->mouse->y >= 680 && loop->mouse->y < 980)
    test = test + 1;
  return (test);
}

int	test_pos_mouse(t_loop *loop)
{
  if (loop->mouse->x >= 396)
    return (1);
  return (0);
}
