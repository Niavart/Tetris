/*
** my_putchar.c for putchar in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Nov  7 14:51:33 2016 Antoine Renaud
** Last update Mon May  8 11:42:03 2017 Antoine Renaud
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

char	*chartostring(char c)
{
  char  *str;

  if ((str = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  str[0] = c;
  str[1] = '\0';
  return (str);
}

char	*my_putchar_r(va_list vl)
{
  char	c;

  c = va_arg(vl, int);
  return (chartostring(c));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
