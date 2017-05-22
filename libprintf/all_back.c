/*
** all_back.c for backslash management in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Tue Nov  8 12:35:48 2016 Antoine Renaud
** Last update Mon May  8 18:21:26 2017 Antoine Renaud
*/

#include "my_printf.h"
#include "my_lib.h"

static char	*(*all_functions(int pos))()
{
  char	*(*tab[11])();

  tab[0] = my_putnbr_r;
  tab[1] = my_putnbr_r;
  tab[2] = my_putstr_r;
  tab[3] = my_putchar_r;
  tab[4] = my_putnbr_octa_r;
  tab[5] = my_putnbr_r;
  tab[6] = my_putnbr_hexa_r;
  tab[7] = my_putnbr_hexam_r;
  tab[8] = my_putssstr;
  tab[9] = my_putnbr_bina_r;
  tab[10] = my_putpointer;
  return (tab[pos]);
}

char	*all_flags(const char *s, int pos, va_list vl)
{
  char	tab[11];
  int	i;

  i = 0;
  tab[0] = 'd';
  tab[1] = 'i';
  tab[2] = 's';
  tab[3] = 'c';
  tab[4] = 'o';
  tab[5] = 'u';
  tab[6] = 'X';
  tab[7] = 'x';
  tab[8] = 'S';
  tab[9] = 'b';
  tab[10] = 'p';
  while (tab[i] && tab[i] != s[pos])
    i++;
  if (tab[i] != s[pos])
    return ("%");
  return (all_functions(i)(vl));
}

int	all_modif(const char *s, int pos, va_list vl)
{
  char	*tab;
  int	i;
  int	start;
  char	*res;

  i = 0;
  start = pos;
  tab = "#lh0+-";
  while (s[pos] == ' ')
    pos++;
  while (tab[i] != '\0' && tab[i] != s[pos])
    i++;
  if (tab[i] == s[pos] && i == 1)
    res = special(s, &pos, i, vl);
  else if (tab[i] == s[pos])
    res = specialcase(s, &pos, i, vl);
  else
    my_putstr(res = all_flags(s, pos + 0, vl));
  if (my_strcmp(res, "%") == 0)
    my_printf("%c%c", pos != start ? ' ' : 0, s[pos]);
  return ((pos - start) + 1);
}

char	*(*the_survivor(int i))(char *, int, char)
{
  char	*(*tam[7])(char *, int, char);

  tam[0] = lediese;
  tam[1] = leelle;
  tam[2] = leache;
  tam[3] = lezero;
  tam[4] = leplus;
  tam[5] = lemoins;
  return (tam[i]);
}

int	getnbr_diff(const char *s, int b)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 48 + b && s[i] <= 57 + b))
    {
      res = res * 10 + (s[i] - 48);
      i++;
    }
  return (res);
}
