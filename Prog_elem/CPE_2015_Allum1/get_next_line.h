/*
** get_next_line.h for get_next_line in /home/oullad_n/rendu/Prog_elem/CPE_2015_getnextline
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Wed Jan  6 13:58:45 2016 nabil oulladji
** Last update Wed Jan 20 15:09:59 2016 nabil oulladji
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

typedef struct	s_line
{
  char		*line;
  int		len;
  int		r_read;
  int		size;
  int		n;
  int		j;
  int		m;
  char		*tmp;
  int		k;
  int		l;
  int		a;
}		t_line;

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

char		*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
