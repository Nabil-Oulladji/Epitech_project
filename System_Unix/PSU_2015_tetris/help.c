/*
** help.c for tetris in /home/mekkao_y/rendu/cprogelem/PSU_2015_tetris
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Wed Feb 24 10:53:32 2016 Youssef Mekkaoui
** Last update Sat Mar 19 00:26:33 2016 Youssef Mekkaoui
*/

#include <stdlib.h>
#include "tetris.h"

int	help(char *name)
{
  my_putstr("Usage: ");
  my_putstr(name);
  my_putstr(" [options]\nOptions:\n");
  my_putstr("  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num\n");
  my_putstr("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("  -kp --key-pause={K}\tPause and restart game when press key K\n");
  my_putstr("  --map-size=[row,col]\tSet game size at row, col\n");
  my_putstr("  -w --without-next\tHide next tetrimino\n");
  my_putstr("  -d --debug\t\tDebug mode\n");
  exit(0);
}
