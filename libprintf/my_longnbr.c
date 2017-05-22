/*
** my_longnbr.c for long nbr in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sat Nov 19 15:35:09 2016 Antoine Renaud
** Last update Mon May  8 18:18:42 2017 Antoine Renaud
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_lib.h"

char	*my_longnbr(va_list vl)
{
  char		*str;
  char		zneed;
  int		a;
  long int	i;

  a = 0;
  zneed = 0;
  i = va_arg(vl, long int);
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
  if (i == 0)
    return (str = "0");
  if (i < 0)
    {
      zneed = 1;
      i = i * (-1);
    }
  while (i)
    {
      str[a++] = i % 10 + 48;
      i = i / 10;
    }
  zneed ? str[a++] = '-' : zneed;
  str[a] = '\0';
  return (my_revstr(str));
}
