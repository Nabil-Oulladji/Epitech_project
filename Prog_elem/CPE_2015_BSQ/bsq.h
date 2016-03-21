/*
** bsq.h for bsh.h in /home/oullad_n/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Sun Dec 13 12:27:27 2015 nabil oulladji
** Last update Sun Dec 20 19:15:30 2015 nabil oulladji
*/

#ifndef	BSQ_H_
# define BSQ_H_

typedef struct	s_map
{
  char		**map;
  int		nb_ligne;
  int		nb_colone;
  int		**dem;
  int		x_square;
  int		y_square;
  int		r_count;
  int		square;
}		t_map;

void	init_struct(t_map *);
int	my_strlen(char *);
void	my_putchar(char);
int	my_getnbr(char *);
int	read_file(char *, t_map *);
int	malloc_map(t_map *);
int	malloc_dem(t_map *);
void	free_map(t_map *);
void	free_dem(t_map *);
void	stock_map(char *, t_map *);
int	my_nb_colone(char *);
void	init_dem(t_map *);
int	count(t_map *, int, int);
void	algo_bsq(t_map *, int, int);
void	add_x(t_map *);
void	display_x(t_map *);
int	error_nb(t_map *, char *, int);
int	error_caractere(char *, int);
int	check_error(t_map *, char *);
void	nb_1(char *, int);
void	map_o(t_map *);

#endif /* !BSQ_H_ */
