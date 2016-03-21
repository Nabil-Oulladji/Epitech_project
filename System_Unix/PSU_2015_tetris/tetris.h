/*
** tetris.h for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Feb 24 10:35:35 2016 Youssef Mekkaoui
** Last update Sun Mar 20 23:08:45 2016 oullad_n
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#include <curses.h>
#include <termios.h>

typedef struct	s_key
{
  int		level;
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
  int		row;
  int		col;
  int		debug;
  int		without;
}		t_key;

typedef struct		s_tetriminos
{
  int			**map;
  int			color;
  int			height;
  int			width;
  int			error;
  char			*name;
  struct s_tetriminos	*next;
  struct s_tetriminos	*prev;
}			t_tetriminos;

typedef struct	s_stock
{
  int		**map;
  int		color;
  char		*name;
  int		width;
  int		error;
  int		height;
  int		i;
  int		j;
  int		k;
  int		max;
}		t_stock;

typedef struct		s_tetris
{
  int			ac;
  char			**av;
  int			i;
  int			tetris;
  int			**map;
  t_key			key;
  t_tetriminos		*tetriminos;
  t_tetriminos		*tmp;
  int			high_score;
  int			score;
  int			score_lines;
  int			timer;
  int			nb_tetri;
  WINDOW		*wtetris;
  WINDOW		*wnext;
  WINDOW		*wscore;
  int			pause;
  int			readed;
  char			*buff;
  struct termios	old;
  struct termios	new;
}			t_tetris;

typedef struct	s_checktetri
{
  char		*buff;
  char		*buff2;
}		t_checktetri;

int		checker(int ac, char **av, t_tetris *st);
int		my_strcmp(char **av, char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_puterr(char *str);
void		my_putstr(char *str);
void		my_putchar(char c);
int		flag_newl(int *i, char **av, t_tetris *st);
int		flag_newkl(int *i, char **av, t_tetris *st);
int		flag_newkl(int *i, char **av, t_tetris *st);
int		flag_newkr(int *i, char **av, t_tetris *st);
int		flag_newkt(int *i, char **av, t_tetris *st);
int		flag_newkd(int *i, char **av, t_tetris *st);
int		flag_newkp(int *i, char **av, t_tetris *st);
int		flag_newkq(int *i, char **av, t_tetris *st);
int		flag_2l(int i, char **av, t_tetris *st);
int		flag_2kl(int i, char **av, t_tetris *st);
int		flag_2kt(int i, char **av, t_tetris *st);
int		flag_2kd(int i, char **av, t_tetris *st);
int		flag_2kp(int i, char **av, t_tetris *st);
int		flag_2kr(int i, char **av, t_tetris *st);
int		flag_2kq(int i, char **av, t_tetris *st);
int		flag_2size(int i, char **av, t_tetris *st, int j);
int		checker2(char **av, t_tetris *st);
int		help();
int		my_getnbr_good(char *str);
int		letter_counter(char c, char *str);
int		my_strncmp(char **av, char *str, int n);
char		*my_strcpy(char *str, char *txt, int n);
t_tetriminos	*init_tetriminos();
int		my_intlen(int nb);
int		my_backn(char *str);
int		add_figure(t_tetris *st, t_tetriminos *elem);
t_tetriminos	*add_next(t_tetriminos *elem, t_stock *stock);
void		display_game_tetri(t_tetris *st);
void		display_nextetri(t_tetris *st, t_tetriminos *elem);
void		fill_file(char *file, char *d_name);
int		tetri_nb(t_tetris *st);
char		*only_tetriname(char *name);
void		xexit(t_tetris *tetris, char *msg);
int		check_down_map(int x, int y,
			       t_tetris *st, t_tetriminos *elem);
void		res_tetri_in_map(int x, int y,
				 t_tetris *st, t_tetriminos *elem);
void		stock_tetri_in_map(int x, int y,
				   t_tetris *st, t_tetriminos *elem);
int		my_strcmp2(char *av, char *str);
int		my_strncmp2(char *av, char *str, int n);
int		load_tetriminos(t_tetris *st);
void		debug(t_tetris *st);
int		my_strbiggest(char *str1, char *str2);
void		display_tetriminos(t_tetris *st, t_tetriminos *elem);
void		my_put_nbr(int nb);
void		debug_tetrimap(t_tetriminos *elem);
void		display_key(t_tetris *st);
void		my_putstr2(char *str);
void		check_endpiece2(char *buff, t_stock *stock);
void		check_endpiece(char *buff, t_stock *stock);
void		init_stock(t_stock *stock, char *file);
void		init_checktetri(t_checktetri *ct, char *file, int fd);
void		malloc_map(t_stock *stock);
int		my_strcompare(char *file, char *src);
void		display_tetrimap(t_tetris *st, t_tetriminos *elem);
char		*env_name(char **env);
void		init_tetris(t_tetris *st, int ac, char **av);
int		found(char *av, char s[10][12]);
int		check_linepiece(char *buff, t_stock *stock);
int		check_right(int x, int y, t_tetris *st, t_tetriminos *elem);
int		check_left(int x, int y, t_tetris *st, t_tetriminos *elem);
void		check_left_rotate(int x, int y, t_tetris *st,
				  t_tetriminos *elem);
int		check_finish(t_tetris *st, t_tetriminos *elem);
void		draw_border(WINDOW *win);
void		game(t_tetris *st);
void		init_game(t_tetris *st);
void		tetris_score(t_tetris *st);
void		fill_flag2size(char *_row, char *_col, char *str, char *av);
void		my_key(t_tetris *st, t_tetriminos *elem, int *x, int *y);
int		add_figure(t_tetris *st, t_tetriminos *elem);
void		check_line(t_tetris *st);
int		check_finish(t_tetris *st, t_tetriminos *elem);
int		check_tetri_error(t_tetris *st);
void		res_tetri_in_map(int x, int y, t_tetris *st,
				 t_tetriminos *elem);
void		stock_tetri_in_map(int x, int y, t_tetris *st,
				   t_tetriminos *elem);
int		check_down_map(int x, int y, t_tetris *st, t_tetriminos *elem);
int		check_right(int x, int y, t_tetris *st, t_tetriminos *elem);
int		check_left(int x, int y, t_tetris *st, t_tetriminos *elem);
void		del_line(int j, t_tetris *st);
void		check_line(t_tetris *st);
t_tetriminos	*turn_tetri(t_tetris *st, t_tetriminos *elem);
t_tetriminos		*rand_tetri(t_tetris *st, t_tetriminos *elem);
void		display_game(t_tetris *st);
void		palette_color();
void		mode(t_tetris *st, int i);
int		get_maxsequence(t_tetris *st);
int		get_key(t_tetris *st);
void		drop_tetri(int *y, int *x, t_tetris *st, t_tetriminos *elem);
  
#endif /* !TETRIS_H_ */
