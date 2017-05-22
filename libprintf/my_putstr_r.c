/*
** my_putstr_r.c for putstr in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Nov  7 14:52:54 2016 Antoine Renaud
** Last update Mon May  8 14:00:29 2017 Antoine Renaud
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my_lib.h"

char	*my_putstr_r(va_list vl)
{
  char	*str;

  str = va_arg(vl, char *);
  if (str == NULL)
    return ("(null)");
  return (str);
}

void	my_putstr(char *str)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return ;
    }
  while (str[i])
    if (str[i++] == 27)
      c = 1;
  i = 0;
  if (c)
    while (str[i])
      {
	if (str[i] == 27)
	  write(1, "^E", 2);
	else
	  write(1, str + i, 1);
	i++;
      }
  else
    write(1, str, my_strlen(str));
}

char	*my_putssstr(va_list vl)
{
  int	i;
  char	*str;
  char	*res;

  i = 0;
  str = va_arg(vl, char *);
  if (str == NULL || (res = malloc(sizeof(str))) == NULL)
    return ("(null)");
  while (str && str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  if (str[i] != 127)
	    res = my_strcat(res, str[i] < 8 ? "\\00" : "\\0");
	  else
	    res = my_strncat(res, "\\", 1);
	  res = my_strcat(res, my_putnbr_octa(str[i]));
	}
      else
	res = my_strncat(res, chartostring(str[i]), 1);
      i++;
    }
  return (res);
}

char			*my_putpointer(va_list vl)
{
  unsigned long int	p;

  p = va_arg(vl, unsigned long int);
  if (!p)
    {
      return ("(nil)");
    }
  my_putstr("0x");
  return (my_putnbr_hexam(p));
}
