/*
** my_printf.c for my_printf in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Nov  7 12:11:16 2016 Antoine Renaud
** Last update Mon May  8 18:22:51 2017 Antoine Renaud
*/

#include <unistd.h>
#include "my_printf.h"

static int	switching(va_list vl, const char *c, int p)
{
  if (c[p])
    {
      if (c[p] != '%')
	return (all_modif(c, p, vl));
      else
	my_putchar('%');
      return (1);
    }
  else
    my_putchar('%');
  return (0);
}

static int	my_backslash(char c)
{
  if (c)
    {
      my_putchar('\\');
      my_putchar(c);
      return (1);
    }
  return (0);
}

void		my_printf(const char *f, ...)
{
  va_list	vl;
  int		i;

  if (!f)
    return ;
  va_start(vl, f);
  i = 0;
  while (f[i] != '\0')
    {
      if (f[i] == '%')
	i += switching(vl, f, i + 1);
      else if (f[i] == '\\')
	i += my_backslash(f[i + 1]);
      else
	write(1, &(f[i]), 1);
      i++;
    }
  va_end(vl);
}
