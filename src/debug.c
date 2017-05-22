/*
** parsing.c for parsing in /home/arakhaa/System_Unix/PSU_2016_tetris
** 
** Made by marianne.levee
** Login   <arakhaa@epitech.net>
** 
** Started on  Wed Mar  1 15:14:56 2017 marianne.levee
** Last update Mon May 22 22:50:18 2017 Antoine Renaud
*/

#include <stdio.h>
#include <sys/ioctl.h>
#include <term.h>
#include "tetris.h"
#include "my_lib.h"
#include "move.h"

char		*seek_term(char **env)
{
  int		i;
  int		k;

  i = 0;
  while (env[i] && (k = my_strncmp(env[i], "TERM=", 5)) != 0)
    i++;
  return (env[i]);
}

t_debug		fill_null(char **env)
{
  t_debug	opt;
  int		k;

  setupterm(seek_term(env) + 5, 0, &k);
  opt.k_left = tigetstr("kcub1");
  opt.k_right = tigetstr("kcuf1");
  opt.k_turn = tigetstr("kcuu1");
  opt.k_drop = tigetstr("kcud1");
  opt.k_quit = "q";
  opt.k_pause = "(space)";
  opt.next = "Yes";
  opt.lvl = "1";
  opt.map = "20*10";
  return (opt);
}

static int	key_opt(char **av, int i, t_debug *opt, int *opt_ok)
{
  if (my_strcmp(av[i], "-l") == 0)
    1 ? opt->lvl = my_strdup(av[i + 1]), *opt_ok = 1 : 0;
  else if (my_strcmp(av[i], "-w") == 0)
    1 ? opt->next = my_strdup(av[i + 1]), *opt_ok = 1 : 0;
  else if (my_strncmp(av[i], "--map-size=", 11) == 0)
    opt->map = my_strdup(av[i] + 11);
  else
    return (0);
  return (1);
}

static int	key_pieces(char **av, int i, t_debug *opt, int *opt_ok)
{
  if (my_strcmp(av[i], "-kl") == 0)
    1 ? opt->k_left = my_strdup(av[i + 1]), *opt_ok += 2 : 0;
  else if ((my_strcmp(av[i], "-kr") == 0))
    1 ? opt->k_right = my_strdup(av[i + 1]), *opt_ok += 2 : 0;
  else if (my_strcmp(av[i], "-kt") == 0)
    1 ? opt->k_turn = my_strdup(av[i + 1]), *opt_ok += 2 : 0;
  else if (my_strcmp(av[i], "-kd") == 0)
    1 ? opt->k_drop = my_strdup(av[i + 1]), *opt_ok += 2 : 0;
  else if (my_strcmp(av[i], "-kq") == 0)
    1 ? opt->k_quit = my_strdup(av[i + 1]), *opt_ok += 2 : 0;
  else if (my_strcmp(av[i], "-kp") == 0)
    1 ? opt->k_pause = my_strdup(av[i + 1]), *opt_ok += 2 : 0;
  else
    return (0);
  return (1);
}

int		debug(int ac, char **av, t_debug *opt)
{
  int		i;
  int		opt_ok;

  i = 1;
  opt_ok = 0;
  while (i < ac)
    {
      if (my_strcmp(av[i], "-d") == 0)
	opt_ok += 1;
      else if ((opt_ok += key_pieces(av, i, opt, &opt_ok)) >= 84)
	return (84);
      else if ((opt_ok += key_opt(av, i, opt, &opt_ok)) >= 84)
	return (84);
      else if ((opt_ok += big_opt(opt, i, av)) >= 84)
	return (84);
      else if (opt_ok == 0)
	return (84);
      i = i + 1 + (opt_ok > 2);
      opt_ok = 0;
    }
  return (0);
}
