/*
** my_strcat.c for strcat in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Wed Nov 16 18:49:34 2016 Antoine Renaud
** Last update Tue Apr  4 18:39:50 2017 Antoine Renaud
*/

char	*my_strcat(char *dest, const char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
      i = i + 1;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
