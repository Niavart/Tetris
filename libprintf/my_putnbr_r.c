/*
** my_putnbr.c for put nbr in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Nov  7 15:19:03 2016 Antoine Renaud
** Last update Tue May 23 04:39:42 2017 Antoine Renaud
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_lib.h"

char	*my_putnbr_r(va_list vl)
{
  char	*str;
  char	zneed;
  int	a;
  int	i;

  a = 0;
  zneed = 0;
  i = va_arg(vl, int);
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

char		*my_putnbr_hexa_r(va_list vl)
{
  char		*str;
  int		a;
  unsigned int	i;

  a = 0;
  i = va_arg(vl, unsigned int);
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
  if (i == 0)
    return (str = "0");
  while (i)
    {
      str[a] = i % 16 + 48;
      if (str[a] > '9')
	str[a] += 7;
      i = i / 16;
      a++;
    }
  str[a] = '\0';
  return (my_revstr(str));
}

char		*my_putnbr_octa_r(va_list vl)
{
  char		*str;
  int		a;
  unsigned int	i;

  a = 0;
  i = va_arg(vl, unsigned int);
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
  if (i == 0)
    return (str = "0");
  while (i)
    {
      str[a] = i % 8 + 48;
      i = i / 8;
      a++;
    }
  str[a] = '\0';
  return (my_revstr(str));
}

char		*my_putnbr_hexam_r(va_list vl)
{
  char		*str;
  int		a;
  unsigned int	i;

  a = 0;
  i = va_arg(vl, unsigned int);
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
  if (i == 0)
    return (str = "0");
  while (i)
    {
      str[a] = i % 16 + 48;
      if (str[a] > '9')
	str[a] += 39;
      i = i / 16;
      a++;
    }
  str[a] = '\0';
  return (my_revstr(str));
}

char		*my_putnbr_bina_r(va_list vl)
{
  unsigned int	i;
  char		*str;
  int		a;

  a = 0;
  i = va_arg(vl, unsigned int);
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
  if (i == 0)
    return (str = "0");
  while (i)
    {
      str[a] = i % 2 + 48;
      i = i / 2;
      a++;
    }
  str[a] = '\0';
  return (my_revstr(str));
}
