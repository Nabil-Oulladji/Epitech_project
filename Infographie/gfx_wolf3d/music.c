/*
** music.c for music in /home/oullad_n/rendu/Infographie/gfx_wolf3d
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sun Dec 27 03:27:42 2015 nabil oulladji
** Last update Sun Dec 27 19:55:02 2015 nabil oulladji
*/

#include "lapin.h"
#include "wolf3d.h"

void		stop_music(t_wolf *wolf)
{
  if (wolf->music_next == 1)
    bunny_sound_stop(wolf->music);
}

int		add_music(t_wolf *wolf)
{
  stop_music(wolf);
  if (wolf->mode == 1)
    {
      bunny_sound_stop(wolf->music);
      bunny_delete_sound(wolf->music);
      if ((wolf->music = bunny_load_music("ressources/Reine.ogg")) == NULL)
	return (1);
      wolf->music_next = 1;
    }
  if (wolf->mode == 2)
    {
      bunny_sound_stop(wolf->music);
      bunny_delete_sound(wolf->music);
      if ((wolf->music = bunny_load_music("ressources/Daft.ogg")) == NULL)
	return (1);
    }
  if (wolf->mode == 3)
    {
      bunny_sound_stop(wolf->music);
      bunny_delete_sound(wolf->music);
      if ((wolf->music = bunny_load_music("ressources/Bleach.ogg")) == NULL)
	return (1);
    }
  bunny_sound_play(wolf->music);
  return (0);
}
