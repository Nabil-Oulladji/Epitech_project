/*
** wolf3d.h for wold3d in /home/oullad_n/rendu/Infographie/WOLF3D
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sun Dec 20 19:12:25 2015 nabil oulladji
** Last update Sun Dec 27 21:29:42 2015 nabil oulladji
*/

#ifndef	WOLF3D_H_
# define WOLF3D_H_

#include "lapin.h"

# define WIDTH 800
# define HEIGHT 500

typedef struct	s_bunny_star
{
  int		y;
  float		x;
  float		x_speed;
  int		active;
}		t_bunny_star;

typedef struct		s_wolf
{
  int			move;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_bunny_music		*music;
  int			music_next;
  int			i;
  int			a;
  int			max;
  int			*pixel;
  int			tile_size;
  int			width;
  int			height;
  int			**map;
  double		pos_x;
  double		pos_y;
  double		start_position_a;
  double		dir_x;
  double		dir_y;
  double		plane_x;
  double		plane_y;
  double		camera_x;
  double		ray_pos_x;
  double		ray_pos_y;
  double		ray_dir_x;
  double		ray_dir_y;
  int			map_x;
  int			map_y;
  double		side_dist_x;
  double		side_dist_y;
  double		delta_dist_x;
  double		delta_dist_y;
  double		perp_dist;
  int			step_x;
  int			step_y;
  int			hit;
  int			side;
  int			line_height;
  int			draw_start;
  int			draw_end;
  int			c_x;
  double		old_dir_x;
  double		old_plane_x;
  double		old_dir_y;
  double		old_plane_y;
  int			state_up;
  int			state_down;
  int			state_left;
  int			state_right;  
  double		speed_move;
  int			mode;
  int			i_c;
  t_bunny_star		star[200000];
  int			x_colorize;
  int			y_colorize;
  const t_bunny_position        *pos2;
}			t_wolf;

int			main(int, char **);
t_bunny_response	key(t_bunny_event_state, t_bunny_keysym, void *);
void			key_go_up(t_bunny_event_state, t_bunny_keysym ,
				  t_wolf *);
void			key_part_2(t_bunny_keysym, t_wolf *);
t_bunny_response	mainloop(void *);
void			background(t_bunny_pixelarray *, t_wolf *);
void			raycasting(t_wolf *);
void			draw_line(t_wolf *);
void			draw_mode_1(t_bunny_position *, int, t_color *,
				    t_wolf *);
void			draw_mode_2(t_bunny_position *, int, t_color *,
				    t_wolf *);
void			draw_mode_3(t_bunny_position *, int, t_color *,
				    t_wolf *);
void			left(t_wolf *);
void			right(t_wolf *);
void			down(t_wolf *);
void			up(t_wolf *);
void			calcul_height(t_wolf *);
void			side_hit(t_wolf *);
double			abs_f(double);
void			side_dist(t_wolf *);
int			read_file(const char *, t_wolf *);
int			read_start(t_bunny_ini *, const char *, t_wolf *);
void			read_map(t_bunny_ini *, const char *, t_wolf *);
int			bunny_malloc_map(t_wolf *);
void			bunny_free_map(t_wolf *);
int			read_name_tile(t_bunny_ini *, const char *, t_wolf *);
int			my_getnbr(const char *);
int			my_number(const char *, int, int);
void			tekpixel(t_bunny_pixelarray *, t_bunny_position *,
				 unsigned int);
void			loop(t_wolf *);
void			colorize(t_bunny_pixelarray *, t_wolf *, int);
void			move_fonction(t_wolf *, int, int);
void			snow(t_bunny_pixelarray *, t_wolf *);
void			init_all_values(t_wolf *);
void			init_all_value(t_wolf *);
void			init_all_value2(t_wolf *);
int			check_map(t_wolf *);
void			check_wall(t_wolf *);
int			check_start_pos(t_wolf *);
int			check_value_map(t_wolf *);
int			add_music(t_wolf *);
void			stop_music(t_wolf *);

#endif /* !WOLF3D_H_ */
