/*
1;2802;0c** input.c for input in /home/oullad_n/nabil/rendu/System_Unix/PSU_2015_tetris
** 
** Made by oullad_n
** Login   <oullad_n@epitech.eu>
** 
** Started on  Sun Mar 20 19:05:46 2016 oullad_n
** Last update Sun Mar 20 22:08:35 2016 oullad_n
*/

#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void	mode(t_tetris *st, int i)
{
  if (i == 0)
    {
      ioctl(0, TCGETS, &st->old);
      ioctl(0, TCGETS, &st->new);
      st->new.c_lflag &= ~ECHO;
      st->new.c_lflag &= ~ICANON;
      st->new.c_cc[VMIN] = 0;
      st->new.c_cc[VTIME] = 2;
      ioctl(0, TCSETS, &st->new);
    }
  else if (i == 1)
    ioctl(0, TCSETS, &st->new);
}

int	get_maxsequence(t_tetris *st)
{
  int	max;

  max = 0;
  if (my_strlen(st->key.left) > max)
    max = my_strlen(st->key.left);
  if (my_strlen(st->key.right) > max)
    max = my_strlen(st->key.right);
  if (my_strlen(st->key.turn) > max)
    max = my_strlen(st->key.turn);
  if (my_strlen(st->key.drop) > max)
    max = my_strlen(st->key.drop);
  if (my_strlen(st->key.quit) > max)
    max = my_strlen(st->key.quit);
  if (my_strlen(st->key.pause) > max)
    max = my_strlen(st->key.pause);
  return (max);
}

int	get_key(t_tetris *st)
{
  if ((st->readed = read(0, st->buff, get_maxsequence(st))) == -1)
    exit(1);
  st->buff[st->readed] = '\0';
  if (my_strcmp2(st->buff, st->key.left) > 0)
    return (1);
  if (my_strcmp2(st->buff, st->key.right) > 0)
    return (2);
  if (my_strcmp2(st->buff, st->key.turn) > 0)
    return (3);
  if (my_strcmp2(st->buff, st->key.drop) > 0)
    return (4);
  if (my_strcmp2(st->buff, st->key.quit) > 0)
    return (5);
  if (my_strcmp2(st->buff, st->key.pause) > 0)
    return (6);
  return (0);
}
