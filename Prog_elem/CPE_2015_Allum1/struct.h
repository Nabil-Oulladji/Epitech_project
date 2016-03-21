/*
** struct.h for struct in /home/oullad_n/rendu/System_Unix/PSU_2015_minishell1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan 20 15:15:25 2016 nabil oulladji
** Last update Fri Feb 19 20:53:33 2016 nabil oulladji
*/

#ifndef MY_STRUCT_
# define MY_STRUCT_

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_all
{
  char		*s;
  int		tab[4];
  int		line;
  int		allum;
  int		y;
  int		finish;
  int		r;
}		t_all;

void		init_value_allum(t_all *);
void		display_next_IA(t_all *);
void		display_next(t_all *);
void		display_tab(t_all *);
void		display_allum(int);
void		display_space(int);
int		my_dis(int, char *);
int		check_allum_IA(t_all *);
int		check_allum(t_all *);
int		allum1(t_all *);
void		wait_IA_turn(t_all *);
void		wait_IA_turn2(t_all *);
int		wait_turn_line(t_all *);
int		wait_turn_matches(t_all *);
int		main(int, char **);
int		my_getnbr(char *);
void		my_putchar(char);
void		my_put_nbr(int);
int		my_strlen(char *);
char		*get_next_line(const int);

#endif /* !MY_STRUCT_ */
