/*
** my_getint.c for tekpaint in /home/pinta_a
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Jan 13 15:28:41 2016 arnaud pinta
** Last update Wed Jan 27 19:49:20 2016 nabil oulladji
*/

#include <stdlib.h>

int	size_len(int nb)
{
  int	i;

  i = 1;
  while (nb >= 10)
    {
      nb = nb / 10;
      i = i + 1;
    }
  return (i);
}

char	*my_getint(int nb)
{
  char	*nbr;
  int	len;

  len = size_len(nb);
  if ((nbr = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  nbr[len] = '\0';
  len = len - 1;
  while (len >= 0)
    {
      nbr[len] = nb % 10 + 48;
      nb = nb / 10;
      len = len - 1;
    }
  return (nbr);
}
