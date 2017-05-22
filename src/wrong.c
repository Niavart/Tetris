/*
** wrong.c for wrong in /home/arakhaa/System_Unix/PSU_2016_tetris
** 
** Made by marianne.levee
** Login   <arakhaa@epitech.net>
** 
** Started on  Thu Mar 16 14:10:56 2017 marianne.levee
** Last update Mon May 22 22:50:27 2017 Antoine Renaud
*/

#include "tetris.h"

int	verif_nb_var(char *tmp, int *i, t_pieces *pie)
{
  int	hmn;

  hmn = 0;
  if ((pie->wid = te_getnbr(tmp, i)) != 0)
    hmn++;
  while (tmp[*i] && tmp[*i] == ' ')
    (*i)++;
  if ((pie->hei = te_getnbr(tmp, i)) != 0)
    hmn++;
  while (tmp[*i] && tmp[*i] == ' ')
    (*i)++;
  if ((pie->color = te_getnbr(tmp, i)) != 0)
    hmn++;
  if (tmp[*i] != '\n' && hmn != 3)
    return (0);
  return (1);
}

int	no(char *tmp, t_pieces *pie, int *i)
{
  if ((pie->color > 7))
    return (0);
  if (tmp[*i] != '*' && tmp[*i] != ' ' && tmp[*i] != '\n')
    return (0);
  return (1);
}

void	r_init_border(t_all_wins windows)
{
  write_into(windows.win_sc, whatwassaved());
  wborder(windows.win_sc, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wborder(windows.win_ga, '|', '|', '-', '-', '+', '+', '+', '+');
  wborder(windows.win_pi, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(windows.win_sc);
  wrefresh(windows.win_ga);
  wrefresh(windows.win_pi);
}

int	lines(char *tmp)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (tmp[i])
    {
      if (tmp[i] == '\n')
	c++;
      i++;
    }
  return (c);
}
