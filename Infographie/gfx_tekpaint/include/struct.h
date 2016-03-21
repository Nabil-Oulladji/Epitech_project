/*
** struct.h for tekpaint in /home/pinta_a/rendu/INFOGRAPHIE/TEKPAINT
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Mon Dec 28 12:59:11 2015 arnaud pinta
** Last update Wed Jan 27 19:36:09 2016 nabil oulladji
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct			s_draw
{
  float				r[2];
  float				g[2];
  float				b[2];
  t_bunny_position		pos;
}				t_draw;

typedef struct			s_save
{
  int				x[2];
  int				fd;
  int				i;
  char				*str;
  t_color			color;
}				t_save;

typedef struct			s_pars
{
  int				i;
  int				j;
}				t_pars;

typedef struct			s_bmp
{
  int				width;
  int				height;
  int				buff[1];
  t_color			color;
  t_bunny_pixelarray		*pix;
  int				fd;
  int				i;
  t_bunny_position		pos;
}				t_bmp;

typedef struct			s_pix
{
  t_bunny_pixelarray		*pix;
  t_bunny_position		pos;
}				t_pix;

typedef struct			s_list
{
  struct s_list			*prev;
  struct s_list			*next;
  struct s_pix			pix;
}				t_list;

typedef struct			s_loop
{
  int				l_click;
  int				r_click;
  int				size;
  int				pot;
  int				move;
  int				choice;
  int                           width;
  int                           heigth;
  t_bunny_ini                   *ini;
  t_color			color;
  t_color			nuancier;
  t_bunny_window		*win;
  t_pix				pix2;
  t_bunny_pixelarray		*background;
  t_bunny_pixelarray		*pix;
  t_bunny_pixelarray		*gui;
  t_bunny_position		gui_pos;
  t_bunny_position		cursor;
  char				*save_name;
  const t_bunny_position	*mouse;
  struct s_list			pix_list;
}				t_loop;

#endif /* !STRUCT */
