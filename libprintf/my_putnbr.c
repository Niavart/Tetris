/*
** my_putnbr.c for put nbr in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Nov  7 15:19:03 2016 Antoine Renaud
** Last update Mon May  8 18:20:31 2017 Antoine Renaud
*/

#include <stdlib.h>
#include "my_lib.h"

char	*my_putnbr(int i)
{
  char	*str;
  char	zneed;
  int	a;

  a = 0;
  zneed = 0;
  if ((str = malloc(sizeof(char) * (size_of_int(i) + 1))) == NULL)
    return (NULL);
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
  if (zneed)
    str[a++] = '-';
  str[a] = '\0';
  return (my_revstr(str));
}

char	*my_putnbr_hexa(unsigned int i)
{
  char	*str;
  int	a;

  a = 0;
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
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

char	*my_putnbr_octa(unsigned int i)
{
  char	*str;
  int	a;

  a = 0;
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
  while (i)
    {
      str[a] = i % 8 + 48;
      i = i / 8;
      a++;
    }
  str[a] = '\0';
  return (my_revstr(str));
}

char	*my_putnbr_hexam(unsigned long int i)
{
  char	*str;
  int	a;

  a = 0;
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
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

char	*my_putnbr_bina(unsigned int i)
{
  char	*str;
  int	a;

  a = 0;
  if ((str = malloc(sizeof(i))) == NULL)
    return (NULL);
  while (i)
    {
      str[a] = i % 2 + 48;
      i = i / 2;
      a++;
    }
  str[a] = '\0';
  return (my_revstr(str));
}
