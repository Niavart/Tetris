/*
** pause.c for pause.c in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sun Mar 19 23:37:22 2017 Antoine Renaud
** Last update Mon May 22 22:05:38 2017 Antoine Renaud
*/

#include <unistd.h>
#include <time.h>
#include "tetris.h"
#include "move.h"
#include "my_lib.h"

int	pause()
{
  int	ret;
  int	ti_start;
  int	ti_end;
  char	buff[10];

  ti_start = time(NULL);
  while (PAUSED)
    {
      ret = read(0, buff, 10);
      buff[ret] = '\0';
      if (my_strcmp(keys.k_pause, "(space)") == 0)
	{
	  if (my_strcmp(buff, " ") == 0)
	      break ;
	}
      else if (my_strcmp(buff, keys.k_pause) == 0)
	break ;
    }
  ti_end = time(NULL);
  if (ti_start - ti_end < 0)
    display_timer(ti_start - ti_end, stdscr);
  return (0);
}
