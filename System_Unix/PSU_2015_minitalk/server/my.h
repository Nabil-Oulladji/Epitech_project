/*
** my.h for my.h in /home/oullad_n/rendu/System_Unix/PSU_2015_sigcheck
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Mon Feb  1 18:24:52 2016 nabil oulladji
** Last update Sat Feb 20 18:34:28 2016 nabil oulladji
*/

#ifndef MY_SIGNAL_
# define MY_SIGNAL_

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct	s_serv
{
  pid_t		pid;
  pid_t		pid_client;
  int		pid_c[32];
  int		c_j;
  int		carac[8];
  int		c_i;
  int		new_client;
}		t_serv;

t_serv		g_st;

int		main();
void		my_signal(int);
void		my_signal_data(int);
int		power_binary(int);
void		converter_decimal_data(int);
void		converter_decimal(int);
void		my_putchar(char);
void		my_put_nbr(int);
int		kill(pid_t, int);
int		usleep(unsigned int);

#endif /* !MY_SIGNAL_ */
