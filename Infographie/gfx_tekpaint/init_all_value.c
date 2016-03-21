/*
** init_all_value.c for init_all_value in /home/oullad_n/rendu/Infographie/gfx_tekpaint
**
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
**
** Started on  Wed Jan 13 17:04:00 2016 nabil oulladji
** Last update Wed Jan 27 20:11:22 2016 nabil oulladji
*/

#include "include/my.h"

char            *init_all_create(t_loop *loop, char **argv)
{
  int           width;
  int           height;

  if ((width = my_getnbr(argv[3])) > 1524 ||
      (height = my_getnbr(argv[4])) > 1040)
    return ("Error : width or heigth are too big\n");
  loop->win = bunny_start(1920, 1040, false, "TEK_PAINT");
  loop->l_click = 0;
  loop->r_click = 0;
  loop->size = 0;
  loop->pot = 0;
  loop->move = 0;
  loop->choice = 1;
  loop->background = bunny_new_pixelarray(1920, 1040);
  loop->gui = bunny_new_pixelarray(396, 1040);
  loop->size = 1;
  loop->color.full = RED;
  loop->nuancier.full = RED;
  loop->cursor.y = 980;
  noise_color_full(loop->background, 0xFF330000);
  loop->pix = bunny_new_pixelarray(width, height);
  noise_color_full(loop->pix, WHITE);
  loop->save_name = argv[2];
  return (NULL);
}

int            init_all_load(t_loop *loop, char **argv)
{
  char          *str;

  loop->win = bunny_start(1920, 1040, false, "TEK_PAINT");
  loop->l_click = 0;
  loop->r_click = 0;
  loop->size = 0;
  loop->pot = 0;
  loop->move = 0;
  loop->choice = 1;
  loop->background = bunny_new_pixelarray(1920, 1040);
  loop->gui = bunny_new_pixelarray(396, 1040);
  loop->size = 1;
  loop->color.full = RED;
  loop->nuancier.full = RED;
  loop->cursor.y = 980;
  noise_color_full(loop->background, 0xFF330000);
  str = read_velo(loop, argv[2]);
  if (str != NULL)
    {
      my_putstr_err(str);
      return (1);
    }
  loop->save_name = argv[3];
  return (0);
}

int            init_all_bmp(t_loop *loop, char **argv)
{
  loop->win = bunny_start(1920, 1040, false, "TEK_PAINT");
  loop->l_click = 0;
  loop->r_click = 0;
  loop->size = 0;
  loop->pot = 0;
  loop->move = 0;
  loop->choice = 1;
  loop->background = bunny_new_pixelarray(1920, 1040);
  loop->gui = bunny_new_pixelarray(396, 1040);
  loop->size = 1;
  loop->color.full = RED;
  loop->nuancier.full = RED;
  loop->cursor.y = 980;
  noise_color_full(loop->background, 0xFF330000);
  if ((loop->pix = my_load_bitmap(argv[2])) == NULL)
    return (1);
  loop->save_name = argv[3];
  return (0);
}
