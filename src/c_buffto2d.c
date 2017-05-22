/*
** c_buffto2d.c for buffer to 2d array in /home/renaud_e/delivery/CPE_2016_BSQ
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Fri Dec  9 10:31:30 2016 Antoine Renaud
** Last update Mon May 22 20:54:14 2017 Antoine Renaud
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "c_buffto2d.h"
#include "tetris.h"
#include "my_lib.h"

void	display(char **tab)
{
  int	j;

  j = 0;
  while (tab[j] != NULL)
    my_printf("%s\n", tab[j++]);
}

char	**v_malloc(int size)
{
  char	**tab;

  if ((tab = malloc(sizeof(char *) * size)) == NULL)
    {
      write(2, "Error malloc in c_buffto2d\n", 28);
      return (NULL);
    }
  return (tab);
}

void	multi_zero(int *i, int *k, int *j)
{
  *i = 0;
  *k = 0;
  *j = 0;
}

char	**c_buffto2d(char *buff, int size, int line)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  multi_zero(&i, &k, &j);
  tab = v_malloc(size + 1);
  tab[j] = v_malloc1(line + 1);
  while (buff[i] != '\0')
    {
      if (buff[i] != '\n')
	tab[j][k++] = buff[i];
      else if (k != 0 && buff[i + 1] != '\0')
	{
	  tab[j][k] = '\0';
	  j++;
	  k = 0;
	  tab[j] = v_malloc1(line + 1);
	}
      i++;
    }
  tab[j][k] = '\0';
  tab[j + 1] = NULL;
  return (tab);
}

int	c_size_line(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] && buff[i] != '\n')
    i++;
  return (i);
}
