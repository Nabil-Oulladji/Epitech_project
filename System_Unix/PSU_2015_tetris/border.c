/*
** border.c for tetris in /home/mekkao_y/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Mar 19 23:10:51 2016 Youssef Mekkaoui
** Last update Sun Mar 20 22:47:00 2016 oullad_n
*/

#include "tetris.h"

void	draw_border(WINDOW *win)
{
  int	i;
  int	y;
  int	x;

  i = 1;
  getmaxyx(win, y, x);
  mvwprintw(win, 0, 0, "+");
  mvwprintw(win, y - 1, 0, "+");
  mvwprintw(win, 0, x - 2, "+");
  mvwprintw(win, y - 1, x - 2, "+");
  while (i < (y - 1))
    {
      mvwprintw(win, i, 0, "|");
      mvwprintw(win, i, x - 2, "|");
      i = i + 1;
    }
  i = 1;
  while (i < (x - 2))
    {
      mvwprintw(win, 0, i, "-");
      mvwprintw(win, y - 1, i, "-");
      i = i + 1;
    }
}
