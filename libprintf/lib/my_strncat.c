/*
** my_strncat.c for strncat in /home/renaud_e/delivery/CPool_Day07
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Tue Oct 11 19:16:23 2016 Antoine Renaud
** Last update Mon May  8 13:27:27 2017 Antoine Renaud
*/

int     my_strlen(const char *str)
{
  int   i;

  i = 0;
  while (str && str[i] != '\0')
    i++;
  return (i);
}

char    *my_revstr(char *str)
{
  int   i;
  int   j;
  char  c;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < my_strlen(str) / 2)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i++;
      j--;
    }
  return (str);
}

char	*my_strncat(char *dest, const char *src, int nb)
{
  int	i;
  int	max;

  i = 0;
  max = dest ? my_strlen(dest) : 0;
  while (src[i] != '\0' && i < nb)
    {
      dest[max + i] = src[i];
      i = i + 1;
    }
  if (i == nb)
    dest[max + i] = '\0';
  else
    dest[max + i] = src[i];
  return (dest);
}
