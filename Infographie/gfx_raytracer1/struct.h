/*
** struct.h for struct in /home/oullad_n/nabil/rendu/Infographie/gfx_raytracer1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Feb 23 11:11:54 2016 nabil oulladji
** Last update Mon Mar 14 23:52:54 2016 oullad_n
*/

#ifndef STRUCT_H
# define STRUCT_H

# ifndef WIDTH
#  define WIDTH 1000
# endif /* !WIDTH */

# ifndef HEIGHT
#  define HEIGHT 800
# endif /* !HEIGHT */

#include <lapin.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

typedef struct		s_geo
{
  int			x;
  int			y;
  int			z;
  int			rayon;
  int			angle;
  int			hauteur;
  int			intensity;
  int			mirror;
  int			color;
  int			vx;
  int			vy;
  int			vz;
}			t_geo;

typedef struct		s_info
{
  int			nb_sphere;
  int			nb_plan;
  int			nb_cylindre;
  int			nb_cone;
  int			nb_light;
  t_geo			*sphere;
  t_geo			*plan;
  t_geo			*cylindre;
  t_geo			*cone;
  t_geo			*light;
}			t_info;

typedef struct		s_key
{
  int			go;
  int			back;
  int			left;
  int			right;
  int			up;
  int			down;
  int			add_light;
  int			del_light;
  int			up_light;
  int			down_light;
  int			left_light;
  int		        right_light;
  int			go_light;
  int		        back_light;
}			t_key;

typedef struct		s_ray
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_color		color[9];
  t_color		color_ref;
  int			x;
  int			y;
  int			a_x;
  int			a_y;
  int			a_z;
  double		b_x;
  double		b_y;
  double		b_z;
  double		v_x;
  double		v_y;
  double		v_z;
  double		a;
  double		b;
  double		c;
  double		d;
  double		t0;
  double		t1;
  double		p_x;
  double		p_y;
  double		p_z;
  double		n_x;
  double		n_y;
  double		n_z;
  double		l_x;
  double		l_y;
  double		l_z;
  double		r_x;
  double		r_y;
  double		r_z;
  double		angle;
  double		dist1;
  double		dist2;
  double		t;
  double		l;
  double		save_t;
  double		col_x;
  double		col_y;
  double		col_z;
  struct s_key		event;
  struct s_info		info;
}			t_ray;

/*
**	Main
*/

int		main(int ac, char **av);

/*
**	Main_Loop
*/

t_bunny_response	mainloop(void *my_data);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *my_data);
void			background(t_bunny_pixelarray *pix,
				   unsigned int color);

/*
**	Tekpixel
*/

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color);

/*
**	My_getnbr
*/

int		my_number(const char *str, int nb_neg, int i);
int		my_getnbr(const char *str);

/*
**	Init_value
*/

void		init_value(t_ray *st);

/*
**	Read_file
*/

int		read_file(const char *pathname, t_ray *st);
int		read_figure(t_bunny_ini *ini, t_ray *st);
int		read_nb(t_bunny_ini *ini, t_ray *st);
int		malloc_struct(t_ray *st);

/*
**	Read_figure
*/

int		read_sphere(t_bunny_ini *ini, t_ray *st);
int		read_plan(t_bunny_ini *ini, t_ray *st);
int		read_cylindre(t_bunny_ini *ini, t_ray *st);
int		read_cone(t_bunny_ini *ini, t_ray *st);
int		read_light(t_bunny_ini *ini, t_ray *st);
int		read_start(t_bunny_ini *ini, t_ray *st);

/*
**     My_raytracer
*/

void		raytracer(t_ray *st);
void		my_ray(t_ray *st);
void		init_cam(t_ray *st);
void		vector_normalize(double *x,
				 double *y,
				 double *z);

/*
**	Color
*/

void		checker_color(t_ray *st);
int		checker_color_cone_line(t_ray *st);
void		checker_color_plan_line(t_ray *st);
void		checker_color_cone(t_ray *st);
int		color_cone_line(t_ray *st, int i);

/*
**	Mirror_Color
*/

void		mirror_checker_color_cone(t_ray *st);
void		mirror_checker_color_cone_line(t_ray *st);
void		mirror_color_sphere(t_ray *st, int i);
void		mirror_color_cylindre(t_ray *st, int i);
void		mirror_color_cone(t_ray *st, int i);

/*
**	Mirror
*/

void		check_ombre_sphere(t_ray *st, int i);
int		mirror_plan(t_ray *st, int i);
void		check_ombre_plan(t_ray *st, int i);
int		mirror_figure(t_ray *st, int i);
int		mirror_figure_2(t_ray *st);

/*
**	Mirror_figure
*/

int		mirror_calcul_sphere(t_ray *st, int i);
int		mirror_check_sphere(t_ray *st, int i);
int		mirror_calcul_cylindre(t_ray *st, int i);
int		mirror_check_cylindre(t_ray *st, int i);

/*
**	Mirror_figure2
*/

int		mirror_calcul_cone(t_ray *st, int i);
int		mirror_check_cone(t_ray *st, int i);

/*
**	Ombre
*/
void		display_ombre(t_ray *st);
int	        ombre_check_sphere(t_ray *st, int i);
int	        ombre_check_cylindre(t_ray *st, int i);
int	        ombre_check_cone(t_ray *st, int i);
void		ombre_figure(t_ray *st, int i, int figure, int j);


/*
**	Key
*/

void		key_go_up2(t_bunny_keysym key, t_ray *st);
void		key_go_up(t_bunny_event_state state,
			  t_bunny_keysym key, t_ray *st);
void		key_go_down(t_bunny_keysym key, t_ray *st);
void		use_key_2(t_ray *st);
void		use_key(t_ray *st);

/*
**	Plan
*/

int		check_plan(t_ray *st, int i);
void		collision_plan(t_ray *st);
int		mirror_check_plan(t_ray *st, int i);
  
/*
**	Sphere
*/

int		mirror_calcul_sphere(t_ray *st, int i);
int		mirror_check_sphere(t_ray *st, int i);
int		calcul_sphere(t_ray *st, int i);
int		check_sphere(t_ray *st, int i);
void		collision_sphere(t_ray *st);

/*
**      Cylindre
*/

int		check_cylindre(t_ray *st, int i);
int		calcul_cylindre(t_ray *st, int i);
void		collision_cylindre(t_ray *st);
void		check_ombre_cylindre(t_ray *st, int i);

/*
**      Cone
*/

void		collision_cone(t_ray *st);
int		check_cone(t_ray *st, int i);
int		calcul_cone(t_ray *st, int i);
void		check_ombre_cone(t_ray *st, int i);
int		check_solution(t_ray *st);

/*
**	Palette
*/

void		palette_color(t_ray *st);

#endif /* !STRUCT_H */
