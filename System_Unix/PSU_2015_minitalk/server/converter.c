/*
** converter.c for converter in /home/oullad_n/nabil/rendu/System_Unix/PSU_2015_minitalk
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Fri Feb 19 17:03:36 2016 nabil oulladji
** Last update Sat Feb 20 18:32:34 2016 nabil oulladji
*/

#include "my.h"

int		power_binary(int power)
{
  int		nb;
  int		c;

  nb = 0;
  c = 1;
  while (nb < power)
    {
      c = 2 * c;
      nb = nb + 1;
    }
  return (c);
}

void		converter_decimal_data(int value)
{
  int		k;
  int		c;
  int		j;
  char		cha[1];

  k = 0;
  c = 0;
  j = value;
  while (j >= 0)
    {
      if (g_st.carac[j] == 1)
	c = c + power_binary(k);
      j = j - 1;
      k = k + 1;
    }
  cha[0] = c;
  if (c == 0)
    g_st.new_client = 1;
  else
    write(1, cha, 1);
}

void		converter_decimal(int value)
{
  int		k;
  int		c;
  int		j;

  k = 0;
  c = 0;
  j = value;
  while (j >= 0)
    {
      if (g_st.pid_c[j] == 1)
	c = c + power_binary(k);
      j = j - 1;
      k = k + 1;
    }
  g_st.pid_client = c;
}
