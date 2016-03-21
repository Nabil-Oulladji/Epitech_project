/*
** client.c for client in /home/oullad_n/rendu/System_Unix/PSU_2015_minitalk
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Mon Feb  1 19:34:40 2016 nabil oulladji
** Last update Sat Feb 20 18:26:23 2016 nabil oulladji
*/

#include "my.h"

void		my_nothing()
{

}

void		converter_binary(t_min *st, char c)
{
  static int	i;
  int		cpt;
  unsigned char	mask;

  cpt = 0;
  mask = 128;
  while (cpt < i)
    {
      c = c << 1;
      cpt = cpt + 1;
    }
  if (c & mask)
    {
      if (kill(st->pid, SIGUSR1) == -1)
	exit(1);
    }
  else
    if (kill(st->pid, SIGUSR2) == -1)
      exit(1);
  i = i + 1;
  if (i == 8)
    i = 0;
}

void		converter_pid(t_min *st)
{
  int		i;
  unsigned int	mask;

  st->pid_client = getpid();
  i = 0;
  mask = 2147483648;
  while (i < 32)
    {
      if (usleep(10000) == -1)
	exit(1);
      if (st->pid_client & mask)
	{
	  if (kill(st->pid, SIGUSR1) == -1)
	    exit(1);
	}
      else
	if (kill(st->pid, SIGUSR2) == -1)
	  exit(1);
      st->pid_client <<= 1;
      i = i + 1;
    }
}

int		converter_data(t_min *st, char **av)
{
  int		i;
  int		cpt;

  i = -1;
  while (av[2][++i] != '\0')
    {
      cpt = 0;
      while (cpt < 8)
	{
	  if (usleep(5000000) == 0)
	    return (2);
	  converter_binary(st, av[2][i]);
	  cpt = cpt + 1;
	}
    }
  cpt = 0;
  while (cpt < 8)
    {
      if (usleep(5000000) == 0)
	return (2);
      converter_binary(st, av[2][i]);
      cpt = cpt + 1;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_min		st;

  if (ac != 3)
    {
      write(2, "Usage: ./client [pid] [string]\n", 31);
      return (1);
    }
  st.pid = (pid_t)my_getnbr(av[1]);
  if (signal(SIGUSR1, my_nothing) == SIG_ERR)
    exit(1);
  converter_pid(&st);
  if (converter_data(&st, av) == 2)
    return (2);
  return (0);
}
