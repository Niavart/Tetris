/*
** my_epurstr.c for my_epurstr in /home/renaud_e/delivery/PSU_2016_minishell2
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Tue Apr  4 13:41:06 2017 Antoine Renaud
** Last update Mon May  8 13:31:26 2017 Antoine Renaud
*/

#include <stdlib.h>
#include "my_lib.h"

char	*cta(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}

int	is_it_spaces(char i, char ip1)
{

  if (!ip1)
    return (i == ' ' || i == '\t' || i == '\n');
  return ((i == ' ' || i == '\t' || i == '\n') &&
	  (ip1 == ' ' || ip1 == '\t'));
}

char	*epur_str(char *str)
{
  char	*dup;
  int	l;
  int	i;

  l = 0;
  i = 0;
  if ((dup = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
    i++;
  while (str[i])
    {
      if (is_it_spaces(str[i], str[i + 1]))
	i++;
      else
	dup[l++] = str[i++];
    }
  dup[l] = '\0';
  return (dup);
}

int	count_quote(const char *str)
{
  int	i;

  i = (str[0] == '"');
  while (str[i] && str[i] != '"')
    i++;
  return (i + 1);
}

char	*epur_str_m(char *str)
{
  char	*dup;
  int	l;
  int	i;

  l = 0;
  i = 0;
  if (!str || (dup = malloc(sizeof(char) * (my_strlen(cta(str)) + 1))) == NULL)
    return (NULL);
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i])
    {
      if (str[i] == '"')
	{
	  my_strncpy(dup + l, str + i, count_quote(str + i));
	  l += count_quote(str + i);
	  i += count_quote(str + i);
	}
      else if (is_it_spaces(str[i], str[i + 1]))
	i++;
      else
	dup[l++] = str[i++];
    }
  dup[l] = '\0';
  return (dup);
}
