/*
** my_strncpy.c for strncpy in /home/renaud_e/delivery/CPE_2016_BSQ
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Fri Dec  9 18:40:05 2016 Antoine Renaud
** Last update Tue Apr  4 18:40:05 2017 Antoine Renaud
*/

char	*my_strncpy(char *dest, const char *src, int n)
{
  int	i;

  i = 0;
  while ((i <= n - 1) && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (src[i] == '\0' && i < n)
    dest[i] = '\0';
  return (dest);
}
