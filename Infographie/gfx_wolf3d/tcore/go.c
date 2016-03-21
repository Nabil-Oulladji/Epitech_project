/*
** go.c for go in /home/oullad_n/rendu/Infographie/gfx_wolf3d/tcore
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Tue Dec 22 17:58:04 2015 nabil oulladji
** Last update Wed Dec 23 11:47:55 2015 nabil oulladji
*/

#include <math.h>
#include "lapin.h"

void	go(t_bunny_position *curpos, double angle,
	   t_bunny_position *newpos, int move)
{
  newpos->x = curpos->x + (move * cos(angle));
  newpos->y = curpos->y + (move * sin(angle));
}
