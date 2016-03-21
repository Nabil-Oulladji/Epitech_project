/*
** get_nbr.c for getnbr in /home/menett_a/Modules/infographie/test/read_velo
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Jan 27 15:48:31 2016 Nicolas Menettrier
** Last update Wed Jan 27 19:52:16 2016 nabil oulladji
*/

int	my_getnbr_const(const char *str)
{
  int	i;
  int	nb;
  int	m;

  i = 0;
  nb = 0;
  m = 1;
  while (str[i] == '-')
    {
      i = i + 1;
      m = m * -1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - 48);
      i = i + 1;
    }
  nb = nb * m;
  return (nb);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	m;

  i = 0;
  nb = 0;
  m = 1;
  while (str[i] == '-')
    {
      i = i + 1;
      m = m * -1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - 48);
      i = i + 1;
    }
  nb = nb * m;
  if (str[i] != '\0' || nb <= 0)
    nb = 3000;
  return (nb);
}
