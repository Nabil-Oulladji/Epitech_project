/*
** my.h for include in /home/oullad_n/rendu/Infographie/gfx_tekpaint/include
**
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
**
** Started on  Wed Jan 13 15:23:43 2016 nabil oulladji
** Last update Fri Jan 29 15:15:27 2016 arnaud pinta
*/

#ifndef MY_H_
#define MY_H_

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <lapin.h>
#include "struct.h"

void				set_max_heap_size(size_t size);
int				my_test(t_loop *loop, char **argv, int argc);
int				main(int argc, char **argv);
void				my_putchar(char c);
void				my_putchar_err(char c);
void				my_putstr(char *str);
int				my_putstr_ret(char *str);
void				my_putstr_err(char *str);
int				my_strcmp(char *str, char *stv);
char				*init_all_create(t_loop *loop, char **argv);
int				init_all_load(t_loop *loop, char **argv);
int				init_all_bmp(t_loop *loop, char **argv);
t_bunny_response		main_loop(t_loop *loop);
t_bunny_response		click_rsp(t_bunny_event_state state,
					  t_bunny_mousebutton key,
					  void *data);
t_bunny_response		key_rsp(t_bunny_event_state state,
					t_bunny_keysym key,
					void *data);
void				x_read(int fd, int size);
void				my_bmp_dim(t_bmp *bmp, int fd);
t_bunny_pixelarray		*my_load_bitmap(const char *file);
void				set_click(t_loop *loop);
void				event_key(t_bunny_event_state state,
					t_bunny_keysym key,
					t_loop *loop);
void				square(t_bunny_pixelarray *pix, t_bunny_position pos,
				       t_color color, int size);
void				set_to_grey(t_bunny_pixelarray *pix);
void				set_to_neg(t_bunny_pixelarray *pix);
void				set_to_sepia(t_bunny_pixelarray *pix);
void				set_rightgui(t_bunny_pixelarray *pix,
					     t_color color);
void				plus(t_bunny_pixelarray *pix,
				     t_color color);
void				moin(t_bunny_pixelarray *pix,
				     t_color color);
void				nuancier(t_bunny_pixelarray *pix,
					 t_color *color,
					 t_color col);
void				circle(t_bunny_pixelarray *pix,
				       t_color color);
void				gui(t_bunny_pixelarray *pix,
				    t_color col);
void				noise_color_full(t_bunny_pixelarray *pix,
						 unsigned int color);
void				draw_nuancier(t_bunny_pixelarray *pix,
					      t_bunny_position pos);
void				draw_line_square(t_bunny_pixelarray *pix,
						 t_bunny_position pos,
						 t_color color);
void				draw_square(t_bunny_pixelarray *pix,
				    t_color color);
int				check_pos(t_bunny_pixelarray *pix,
					  t_bunny_position pos);
void				paint_full(t_bunny_pixelarray *pix,
					   t_bunny_position *pos,
					   t_color color);
void				tek_fill_circle(t_bunny_pixelarray *pix,
						t_bunny_position *pos,
						int radius,
						t_color color);
void				tekcircle(t_bunny_pixelarray *pix,
					  t_bunny_position *pos,
					  int radius,
					  t_color color);
unsigned int			tekgetpixel(t_bunny_pixelarray *pix,
					    const t_bunny_position *pos);
void				tekswap(t_bunny_position *pos,
					t_bunny_position *pos1);
void				tekline_2(t_bunny_pixelarray *pix,
					  t_bunny_position *pos,
					  unsigned int color);
void				tekline_1(t_bunny_pixelarray *pix,
					  t_bunny_position *pos,
					  unsigned int color);
void				tekline(t_bunny_pixelarray *pix,
					t_bunny_position *pos,
					unsigned int color);
void				tekpixel(t_bunny_pixelarray *pix,
					 t_bunny_position *pos,
					 t_color *color);
int				my_is(t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      unsigned int color);
void				my_move(t_bunny_position *pos2,
					t_bunny_position pos1,
					int move);
int				test_pos_plus(t_loop *loop);
int				test_pos_moin(t_loop *loop);
int				test_pos_nuancier(t_loop *loop);
int				test_pos_square(t_loop *loop);
int				test_pos_mouse(t_loop *loop);
int				test_pos_rond(t_loop *loop);
int				test_pos_carre(t_loop *loop);
char				*my_getint(int nb);
int				my_getnbr_const(const char *str);
int				my_getnbr(char *str);
int				size_len(int nb);
int				save_velo(t_bunny_pixelarray *daw, char *name);
void				init_header(t_bunny_pixelarray *daw, char *name,
					    int fd);
void				norm_while(t_loop *data);
char				*read_velo(t_loop *data, char *name);
int				test_pos_save(t_loop *loop);

#endif /* !MY_H_ */
