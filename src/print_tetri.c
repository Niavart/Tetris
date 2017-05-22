/*
** print_tetri.c for print_tetri in /home/arakhaa/System_Unix/PSU_2016_tetris
** 
** Made by marianne.levee
** Login   <arakhaa@epitech.net>
** 
** Started on  Tue Mar  7 18:12:35 2017 marianne.levee
** Last update Mon May 22 20:46:58 2017 Antoine Renaud
*/

#include <stdlib.h>
#include "tetris.h"
#include "my_lib.h"

int	tetri(t_allpieces *pi)
{
  int	nb_pi;

  nb_pi = 0;
  while (pi != NULL)
    {
      pi = pi->next;
      nb_pi = nb_pi + 1;
    }
  return (nb_pi);
}

char	*remove_exten(char *name)
{
  int	i;

  i = my_strlen(name) - 1;
  while (i >= 0 && name[i] != '.')
    i--;
  return (my_strdup_s(name, i));
}

int	parsing(t_allpieces *pieces)
{
  int	i;

  i = 0;
  my_printf("Tetriminos : %d\n", tetri(pieces));
  while (pieces != NULL)
    {
      my_printf("Tetriminos : Name : %s : ", remove_exten(pieces->curr.name));
      if (pieces->error == NULL)
	my_printf("Size %d*%d : Color %d :\n", pieces->curr.wid,
		  pieces->curr.hei, pieces->curr.color);
      else
	my_printf("Error\n");
      while (pieces->error == NULL && pieces->curr.model[i])
	my_printf("%s\n", pieces->curr.model[i++]);
      pieces = pieces->next;
      i = 0;
    }
  return (0);
}
