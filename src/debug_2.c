/*
** debug_2.c for debug_2 in /home/arakhaa/System_Unix/PSU_2016_tetris
** 
** Made by marianne.levee
** Login   <arakhaa@epitech.net>
** 
** Started on  Mon Mar 13 11:24:45 2017 marianne.levee
** Last update Mon May 22 22:05:07 2017 Antoine Renaud
*/

#include "tetris.h"
#include "move.h"
#include "my_lib.h"

extern t_debug		keys;

void		help(char **av)
{
  my_printf("Usage: %s [options]\n\
Options:\n\t--help\t\t\tDisplay this help\n\
\t-l --level={num}\tStart Tetris at level num (def: 1)\n\
\t-kl --key-left={K}\tMove the tetrimino LEFT using the K key \
(def: left arrow)\n\
\t-kr --key-right={K}\tMove the tetrimino RIGHT using the K key \
(def: right arrow)\n\
\t-kt --key-turn={K}\tTURN the tetrimino clockwise 90d using the \
K key (def: top arrow)\n\
\t-kd --key-drop={K}\tDROP the tetrimino using the K key (def: down arrow)\n\
\t-kq --key-quit={K}\tQUIT the game using the K key (def: 'q' key)\n\
\t-kp --key-pause={K}\tPAUSE/RESTART the game using the K key \
(def: space bar)\n\
\t--map-size={row,col}\tSet the numbers of rows and columns of \
the map (def: 20,10)\n\
\t-w --without-next\tHide next tetrimino (def: false)\n\
\t-d --debug\t\tDebug mode (def: false)\n", av[0]);
}

int		verif_opt(char **opt, char *car)
{
  if (car[0] == '\0')
    return (84);
  *opt = my_strdup(car);
  return (1);
}

int		big_opt(t_debug *opt, int i, char **av)
{
  if (my_strncmp(av[i], "--key-left=", 11) == 0)
    return (verif_opt(&opt->k_left, av[i] + 11));
  else if (my_strncmp(av[i], "--key-right=", 12) == 0)
    return (verif_opt(&opt->k_right, av[i] + 12));
  else if (my_strncmp(av[i], "--key-turn=", 11) == 0)
    return (verif_opt(&opt->k_turn, av[i] + 11));
  else if (my_strncmp(av[i], "--key-drop=", 11) == 0)
    return (verif_opt(&opt->k_drop, av[i] + 11));
  else if (my_strncmp(av[i], "--key-quit=", 11) == 0)
    return (verif_opt(&opt->k_quit, av[i] + 11));
  else if (my_strncmp(av[i], "--key-pause=", 12) == 0)
    return (verif_opt(&opt->k_pause, av[i] + 12));
  else if (my_strncmp(av[i], "--without-next=", 15) == 0)
    return (verif_opt(&opt->next, av[i] + 15));
  else if (my_strncmp(av[i], "--level=", 8) == 0)
    return (verif_opt(&opt->lvl, av[i] + 8));
  else
    return (0);
  return (1);
}
