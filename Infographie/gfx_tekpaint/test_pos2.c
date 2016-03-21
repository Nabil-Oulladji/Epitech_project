/*
** test_pos2.c for test_pos in /home/oullad_n/rendu/Infographie/gfx_tekpaint
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan 27 16:50:03 2016 nabil oulladji
** Last update Wed Jan 27 16:50:41 2016 nabil oulladji
*/

#include "include/my.h"

int	test_pos_plus(t_loop *loop)
{
  int	test;

  test = 0;
  if (loop->mouse->x >= 113 && loop->mouse->x <= 137)
    test = test + 1;
  if (loop->mouse->y >= 48 && loop->mouse->y <= 73)
    test = test + 1;
  return (test);
}

int	test_pos_moin(t_loop *loop)
{
  int	test;

  test = 0;
  if (loop->mouse->x >= 160 && loop->mouse->x <= 185)
    test = test + 1;
  if (loop->mouse->y >= 48 && loop->mouse->y <= 73)
    test = test + 1;
  return (test);
}

int	test_pos_rond(t_loop *loop)
{
  int	test;

  test = 0;
  if (loop->mouse->x >= 115 && loop->mouse->x <= 137)
    test = test + 1;
  if (loop->mouse->y >= 83 && loop->mouse->y <= 104)
    test = test + 1;
  return (test);
}

int	test_pos_carre(t_loop *loop)
{
  int	test;

  test = 0;
  if (loop->mouse->x >= 161 && loop->mouse->x <= 186)
    test = test + 1;
  if (loop->mouse->y >= 85 && loop->mouse->y <= 106)
    test = test + 1;
  return (test);
}
