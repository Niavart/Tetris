/*
** my_realloc.c for my_realloc in /home/renaud_e/delivery/PSU_2016_minishell1
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Thu Jan 19 14:01:45 2017 Antoine Renaud
** Last update Mon May 22 22:03:48 2017 Antoine Renaud
*/

#include <stdlib.h>
#include "my_lib.h"

char    *my_strdup_s(const char *src, int n)
{
  int   i;
  int   j;
  char	*dest;

  i = 0;
  j = 0;
  if ((dest = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (src[j] != '\0' && (j < n))
    {
      dest[i] = src[j];
      j++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strdup(const char *src)
{
  return (my_strdup_s(src, my_strlen(src)));
}

char    *my_a_realloc(char *s, int len)
{
  char  *res;

  res = my_strdup_s(s, len);
  free(s);
  return (res);
}

int     size_of_int(int i)
{
  int   c;

  c = 0;
  while (i)
    {
      i /= 10;
      c++;
    }
  return (c);
}
