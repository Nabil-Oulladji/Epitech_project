/*
** my_strlen.c for my_strlen in /home/oullad_n/rendu/Piscine_C_J04
** 
** Made by nabil oulladji
** Login   <oullad_n@epitech.net>
** 
** Started on  Fri Oct  2 20:30:46 2015 nabil oulladji
** Last update Tue Oct  6 11:30:16 2015 nabil oulladji
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
