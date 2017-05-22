/*
** fillme.c for incertitude.mp4 in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sun Nov 20 17:28:07 2016 Antoine Renaud
** Last update Mon May  8 13:59:55 2017 Antoine Renaud
*/

#include "my_printf.h"
#include "my_lib.h"

char	*specialcase(const char *s, int *pos, int i, va_list vl)
{
  char	*res;
  int	a;

  a = getnbr_diff(s + (*pos) + 1, 0);
  res = all_flags(s, (*pos) + 1 + nbdigit(a), vl);
  my_putstr(the_survivor(i)(res, a, s[(*pos) + 1 + nbdigit(a)]));
  (*pos) = (*pos) + 1 + nbdigit(a);
  return (res);
}

char	*special(const char *s, int *pos, int i, va_list vl)
{
  char	*res;
  int	a;

  a = getnbr_diff(s + (*pos) + 1, 0);
  if (s[(*pos) + 1] == 'd' || s[(*pos) + 1] == 'i')
    {
      res = my_longnbr(vl);
      my_putstr(res);
    }
  else
    {
      res = all_flags(s, (*pos) + 1 + nbdigit(a), vl);
      if (my_strcmp(res, "%") == 0)
	{
	  my_printf("%c%c", '%', s[(*pos) + 1]);
	  res = "";
	}
      my_putstr(the_survivor(i)(res, a, s[(*pos) + 1 + nbdigit(a)]));
    }
  (*pos) = (*pos) + 1 + nbdigit(a);
  return (res);
}
