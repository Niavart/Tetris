/*
** my_strcpy.c for strcopy in /home/renaud_e/delivery/PSU_2016_my_printf/lib
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Nov  7 12:06:18 2016 Antoine Renaud
** Last update Mon May  8 13:20:17 2017 Antoine Renaud
*/

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
