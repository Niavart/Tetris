/*
** kek.c for delete_zero in /home/arakhaa/C_Prog_elem/CPE_2016_BSQ/lib
** 
** Made by Marianne Levee 
** Login   <arakhaa@epitech.net>
** 
** Started on  Sun Dec 18 16:08:01 2016 Marianne Levee 
** Last update Mon May 22 22:46:53 2017 Antoine Renaud
*/

#include <stdlib.h>

char	*delete_zero(char *av)
{
  int	i;

  i = 0;
  if (!av)
    return (NULL);
  while (av[i] != '\0' && av[i] == '0')
    i = i + 1;
  return (av + i);
}

char	*delete_zerominus(char *av)
{
  int   i;

  i = 0;
  while (av[i] != '\0' && av[i] == '0')
    i = i + 1;
  if (i > 0)
    return (av + i - 1);
  else
    return (av + i);
}

void	my_swap(char **s1, char **s2)
{
  char	*tmp;

  tmp = *s1;
  *s1 = *s2;
  *s2 = tmp;
}
