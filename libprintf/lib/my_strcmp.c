/*
** my_strcmp.c for strcmp in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sun Nov 20 22:40:31 2016 Antoine Renaud
** Last update Mon May  8 13:23:51 2017 Antoine Renaud
*/

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return ((s1[i] - s2[i]));
}

int	my_strncmp(const char *s1, const char *s2, int max)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && i < max - 1)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (!(s1[i] == s2[i]));
}
