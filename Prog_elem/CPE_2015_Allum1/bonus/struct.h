/*
** struct.h for struct in /home/oullad_n/rendu/System_Unix/PSU_2015_minishell1
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan 20 15:15:25 2016 nabil oulladji
** Last update Thu Feb 11 17:45:00 2016 nabil oulladji
*/

#ifndef MY_STRUCT_
# define MY_STRUCT_

# ifndef REDST
#  define REDST "\033[31m"
# endif /* !REDST */

# ifndef RESET
#  define RESET "\033[0m"
# endif /* !RESET */

# ifndef WHITEST
#  define WHITEST "\033[37m"
# endif /* !WHITEST */

# ifndef GREENST
#  define GREENST "\033[32m"
# endif /* !GREENST */

# ifndef BLUEST
#  define BLUEST "\033[36m"
# endif /* !BLUEST */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_all
{
  char		*s;
  int		line;
  int		allum;
  int		y;
  int		finish;
  int		r;
  int		size_allum;
  int		player;
  int		*tab;
}		t_all;

int		init_value_allum(t_all *);
void		display_next_IA(t_all *);
void		display_next(t_all *);
void		display_tab(t_all *);
void		display_allum(int);
void		display_space(int);
int		display_if_win(t_all *);
int		check_allum_IA(t_all *);
int		check_allum(t_all *);
int		allum1(t_all *);
void		wait_IA_turn(t_all *);
void		wait_IA_turn2(t_all *);
int		wait_turn_line(t_all *);
int		wait_turn_matches(t_all *);
int		main(int, char **);
int		printstr(int, char *, char *);
int		my_getnbr(char *);
void		my_putchar(char);
void		my_put_nbr(int);
char		*get_next_line(const int);

#endif /* !MY_STRUCT_ */
