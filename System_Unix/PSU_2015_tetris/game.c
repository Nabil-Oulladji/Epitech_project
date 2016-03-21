/*
** game.c for tetris in /home/mekkao_y/mysql/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Sat Mar 19 15:29:35 2016 Youssef Mekkaoui
** Last update Sun Mar 20 23:35:44 2016 oullad_n
*/

#include <time.h>
#include <stdlib.h>
#include "tetris.h"

void	init_game(t_tetris *st)
{
  char	*roo;

  st->wtetris = initscr();
  if ((st->wnext = newwin(10, 12, 0, 0)) == NULL)
    exit(-1);
  if ((st->wscore = newwin(11, 20, 10, 19)) == NULL)
    exit(-1);
  if ((wresize(st->wtetris, st->key.row + 1, st->key.col + 1)) == ERR)
    exit(-1);
  if ((mvwin(st->wtetris, LINES / 2, COLS / 2)) == ERR)
    exit(-1);
  draw_border(st->wtetris);
  draw_border(st->wnext);
  roo = tigetstr("smkx");
  if (roo != 0)
    my_putstr(roo);
  wrefresh(st->wnext);
  noecho();
  curs_set(0);
  if ((st->buff = malloc(sizeof(char) * get_maxsequence(st))) == NULL)
    exit(1);
}

int		add_figure(t_tetris *st, t_tetriminos *elem)
{
  static int	x;
  static int	y;

  if (y == 0)
    x = (st->key.col - elem->width) / 2;
  if (check_down_map(x, y, st, elem) == 1)
    {
      y = 0;
      return (1);
    }
  else
    {
      if (y != 0)
	res_tetri_in_map(x, y, st, elem);
      y = y + 1;
    }
  my_key(st, elem, &x, &y);
  stock_tetri_in_map(x, y, st, elem);
  return (0);
}

void		display_game_tetri(t_tetris *st)
{
  t_tetriminos	*elem;
  t_tetriminos	*tmp;
  
  if (check_tetri_error(st) == 1)
    return ;
  tmp = st->tetriminos->next;
  elem = st->tetriminos->next;
  elem = rand_tetri(st, elem);
  tmp = rand_tetri(st, tmp);
  while (1)
    {
      if (add_figure(st, elem) == 1)
	{
	  check_line(st);
	  if (check_finish(st, elem) == 1)
	    return ;
	  elem = tmp;
	  tmp = rand_tetri(st, tmp);
	}
      display_tetrimap(st, tmp);
      display_game(st);
      draw_border(st->wtetris);
      draw_border(st->wnext);
      wrefresh(st->wnext);
      wrefresh(st->wtetris);
      tetris_score(st);
    }
}

void		game(t_tetris *st)
{
  srand(time(NULL));
  init_game(st);
  tetris_score(st);
  mode(st, 0);
  get_key(st);
  display_game_tetri(st);
  mode(st, 1);
  delwin(st->wtetris);
  delwin(st->wscore);
  endwin();
}
