/*
** score.c for tetris in /home/mekkao_y/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Mar 19 23:08:53 2016 Youssef Mekkaoui
** Last update Sun Mar 20 23:38:32 2016 oullad_n
*/

#include "tetris.h"

void	tetris_score(t_tetris *st)
{
  if (st->score_lines == 10)
    st->key.level += 1;
  if (st->score_lines == 20)
    st->key.level += 1;
  if (st->score_lines == 30)
    st->key.level += 1;
  if (st->score_lines == 40)
    st->key.level += 1;
  if (st->score_lines == 50)
    st->key.level += 1;
  mvwprintw(st->wscore, 2, 2, "High Score  %d", st->high_score);
  mvwprintw(st->wscore, 3, 2, "Score  %d", st->score);
  mvwprintw(st->wscore, 5, 2, "Lines  %d", st->score_lines);
  mvwprintw(st->wscore, 6, 2, "Level  %d", st->key.level);
  draw_border(st->wscore);
  wrefresh(st->wscore);
}
