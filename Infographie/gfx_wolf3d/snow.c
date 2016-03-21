/*
** snow.c for snow in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sun Dec 27 08:19:03 2015 nabil oulladji
** Last update Sun Dec 27 20:21:44 2015 nabil oulladji
*/

#include "lapin.h"
#include "wolf3d.h"

void                    loop(t_wolf *wolf)
{
  while (wolf->i_c < 200000 / 2)
    {
      wolf->star[wolf->i_c].active = 0;
      wolf->star[wolf->i_c].x_speed = -rand() % 5;
      wolf->star[wolf->i_c].x = rand() % WIDTH;
      wolf->star[wolf->i_c].y = -1;
      wolf->star[wolf->i_c + 200000 / 2].x_speed = rand() % 5;
      wolf->star[wolf->i_c + 200000 / 2].x =
        rand() % WIDTH;
      wolf->star[wolf->i_c + 200000 / 2].y = -1;
      wolf->i_c++;
    }
  while (wolf->i_c < 200000)
    wolf->star[wolf->i_c++].active = 0;
}

void                    colorize(t_bunny_pixelarray *pix,
                                 t_wolf *wolf, int i)
{
  int                   *colors;

  colors = pix->pixels;
  if (!((wolf->star[i].x < 0) || wolf->star[i].y < 0 || wolf->star[i].x > WIDTH
        || wolf->star[i].y > HEIGHT))
    colors[WIDTH * wolf->star[i].y + (int)wolf->star[i].x] = WHITE;
}

void                    move_function(t_wolf *wolf, int i, int j)
{
  if (wolf->star[i].y < HEIGHT - 2)
    wolf->star[i].y += rand() % j;
  else
    {
      wolf->star[i].y = -1;
      wolf->star[i].active = 0;
    }
}

void			snow_move(t_wolf *wolf)
{
  if (wolf->state_right == 1)
    wolf->move = -10;
  else if (wolf->state_left == 1)
    wolf->move = 10;
  if (wolf->state_right == 0 && wolf->move == -10)
    wolf->move = 0;
  else if (wolf->state_left == 0 && wolf->move == 10)
    wolf->move = 0;

}

void                    snow(t_bunny_pixelarray *pix, t_wolf *wolf)
{
  int                   j;
  int			i;

  i = -1;
  j = 10;
  snow_move(wolf);
  while (++i < 200000)
    {
      if (wolf->star[i].active == 0 && rand() % 100000 == 1)
        wolf->star[i].active = 1;
      colorize(pix, wolf, i);
      if (wolf->star[i].active == 1)
        {
          if (wolf->star[i].x >= 0 && wolf->star[i].x <= WIDTH)
            wolf->star[i].x += wolf->star[i].x_speed + wolf->move;
          else if (wolf->star[i].x < 0)
            wolf->star[i].x = WIDTH - 1;
          else if (wolf->star[i].x > WIDTH)
            wolf->star[i].x = 1;
          move_function(wolf, i, j);
        }
    }
}
