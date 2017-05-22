/*
** modifs.c for mofids in /home/renaud_e/delivery/PSU_2016_navy/my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Wed Feb  1 12:50:56 2017 Antoine Renaud
** Last update Mon May  8 13:59:38 2017 Antoine Renaud
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my_lib.h"

char	*leplus(char *s, int nb, char c)
{
  char	*tmp;

  (void)nb;
  if (c == 'x' || c == 'X' || c == 's' || c == 'c')
    return (s);
  if ((tmp = malloc(sizeof(s))) == NULL)
    return (NULL);
  tmp[0] = '+';
  if (s && s[0] != '-')
    s = my_strcat(tmp, s);
  return (s);
}

char	*lezero(char *s, int nb, char c)
{
  int	len;
  char	d;

  len = my_strlen(s);
  d = (c == 's' ? ' ' : '0');
  while (nb - len > 0)
    {
      my_putchar(d);
      nb--;
    }
  return (s);
}

char	*lediese(char *s, int nb, char oui)
{
  int	len;

  len = my_strlen(s);
  if (oui == 'x' || oui == 'X')
    nb = nb - 2;
  else if (oui == 'o' && getnbr_diff(s, 17) != 0)
    nb--;
  while (nb - len > 0)
    {
      my_putchar(' ');
      nb--;
    }
  if ((oui == 'x' || oui == 'X') &&
      getnbr_diff(s, oui == 'x' ? 49 : 17) != 0)
    my_printf("0%c", oui);
  else if ((oui == 'o' && getnbr_diff(s, 0) != 0))
    my_putchar('0');
  return (s);
}

int	nbdigit(int nb)
{
  int	i;

  i = 0;
  while (nb > 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}
