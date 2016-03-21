/*
1;2802;0c** get_next_line.h for getnextline in /home/mekkao_y/rendu/cprogelem/CPE_2015_getnextline
**
** Made by Youssef Mekkaoui
** Login   <mekkao_y@epitech.net>
**
** Started on  Mon Jan  4 12:46:46 2016 Youssef Mekkaoui
** Last update Tue Mar  1 17:44:46 2016 Youssef Mekkaoui
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (17)
# endif /* !READ_SIZE */

#include <unistd.h>

typedef struct	s_gnl
{
  char		*str;
  int		size;
  int		next;
  int		str_size;
}		t_gnl;

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_*/
