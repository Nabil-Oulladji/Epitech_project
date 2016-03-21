/*
** sigcheck.c for sigcheck in /home/oullad_n/rendu/System_Unix/PSU_2015_sigcheck
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Mon Feb  1 16:18:32 2016 nabil oulladji
** Last update Wed Mar  2 14:40:31 2016 oullad_n
*/

#include "my.h"

void		my_signal_data(int sign)
{
  if (sign == SIGUSR1)
    g_st.carac[g_st.c_i] = 1;
  if (sign == SIGUSR2)
    g_st.carac[g_st.c_i] = 0;
  g_st.c_i = g_st.c_i + 1;
  if (g_st.c_i == 8)
    {
      converter_decimal_data(7);
      g_st.c_i = 0;
    }
  if (usleep(1) == -1)
    exit(1);
  if (g_st.new_client == 0)
    if (kill(g_st.pid_client, SIGUSR1) == -1)
      exit(1);
}

void		my_signal(int sign)
{
  if (g_st.c_j < 32)
    {
      if (sign == SIGUSR1)
	g_st.pid_c[g_st.c_j] = 1;
      if (sign == SIGUSR2)
	g_st.pid_c[g_st.c_j] = 0;
      g_st.c_j = g_st.c_j + 1;
      if (g_st.c_j == 32)
	{
	  converter_decimal(31);
	  if (kill(g_st.pid_client, SIGUSR1) == -1)
	    exit(1);
	}
    }
  else
    my_signal_data(sign);
}

int		main()
{
  g_st.pid = getpid();
  write(1, "PID : ", 6);
  my_put_nbr(g_st.pid);
  write(1, "\n", 1);
  if (signal(SIGUSR1, my_signal) == SIG_ERR ||
      signal(SIGUSR2, my_signal) == SIG_ERR)
    exit(1);
  while (1)
    {
      if (g_st.new_client == 1)
	{
	  g_st.c_j = 0;
	  g_st.c_i = 0;
	  g_st.new_client = 0;
	}
    }
  return (0);
}
