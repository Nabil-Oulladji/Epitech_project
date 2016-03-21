/*
** my.h for my.h in /home/oullad_n/rendu/System_Unix/PSU_2015_sigcheck
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Mon Feb  1 18:24:52 2016 nabil oulladji
** Last update Sat Feb 20 18:39:19 2016 nabil oulladji
*/

#ifndef MY_SIGNAL_
# define MY_SIGNAL_

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct	s_min
{
  pid_t		pid;
  pid_t		pid_client;
}		t_min;

int		main(int, char **);
int		converter_data(t_min *, char **);
void		converter_pid(t_min *);
void		converter_binary(t_min *, char);
int		my_number(char *, int, int);
int		my_getnbr(char *);
int		kill(pid_t, int);
int		usleep(unsigned int);
void		do_nothing();

#endif /* !MY_SIGNAL_ */
