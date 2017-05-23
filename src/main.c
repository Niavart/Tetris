/*
** main.c for main in /home/arakhaa/System_Unix/PSU_2016_tetris
** 
** Made by marianne.levee
** Login   <arakhaa@epitech.net>
** 
** Started on  Mon Feb 27 10:34:02 2017 marianne.levee
** Last update Tue May 23 04:48:00 2017 Antoine Renaud
*/

#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"
#include "tetris.h"
#include "move.h"

t_debug		keys;

int		nbr_args(int ac, char **av)
{
  int	i;
  int	c;

  i = 1;
  c = 0;
  while (i < ac)
    {
      if (my_strncmp(av[i], "--", 2) == 0)
	c += 2;
      else if (av[i][0] == '-' && i + 1 != ac)
	{
	  c += 2;
	  i++;
	}
      else
	return (1);
      i++;
    }
  return (c % 2);
}

int		whatdidyougaveme(int ac, char **av)
{
  int		res;
  int		i;

  i = 1;
  if (ac < 2)
    return (5);
  while (i < ac - 1)
    {
      if (my_strcmp(av[i + 1], "-d") == 0 && my_strcmp(av[i], "-d") != 0)
	1 ? my_swap(&av[i], &av[i + 1]), i = 1 : i;
      else
	i++;
    }
  i = 1;
  res = 0;
  while (i < ac)
    {
      if (my_strcmp(av[i], "-d") == 0)
	res == 0 ? res = 1 + !(nbr_args(ac - 1, av + 1)) : res;
      else if (my_strcmp(av[i], "--help") == 0)
	res = 4;
      i++;
    }
  return (res);
}

int		display_mnw(t_allpieces *all)
{
   t_all_wins	windows;
   sfMusic	*music;

   music = sfMusic_createFromFile("Tetris.ogg");
   if (!music)
     return (1);
   sfMusic_play(music);
   if ((all = remove_errors(all)) == NULL)
     return (1);
   windows = tab_curses();
   loop(all, windows);
   endwin();
   sfMusic_destroy(music);
   return (0);
}

int		to_debug(int ac, char **av, t_debug *opt, t_allpieces *all)
{
  if (debug(ac, av, opt) == 84)
    {
      write(2, "Error :  Bad parameters\n", 24);
      return (84);
    }
  my_printf("*** DEBUG MODE ***\nKey Left : %s\nKey Right : %s\n\
Key Turn : %s\nKey Drop : %s\nKey Quit : %s\nKey Pause : %s\n\
Next : %s\nLevel : %s\nSize : %s\n", opt->k_left, opt->k_right,
	    opt->k_turn, opt->k_drop, opt->k_quit, opt->k_pause,
	    opt->next, opt->lvl, opt->map);
  parsing(all);
  my_printf("Press any key to start Tetris");
  read(0, 0, 1);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_allpieces	*all;
  t_debug	opt;

  all = get_pieces();
  opt = fill_null(env);
  if ((whatdidyougaveme(ac, av)) == 4 || whatdidyougaveme(ac, av) == 1)
    {
      help(av);
      return (1);
    }
  else if (whatdidyougaveme(ac, av) == 2 && to_debug(ac, av, &opt, all) == 84)
    return (1);
  keys = opt;
  display_mnw(all);
  return (0);
}
