/*
** game.c for the whole loop for the game in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Tue Feb 28 17:52:10 2017 Antoine Renaud
** Last update Tue Mar 21 13:40:03 2017 Antoine Renaud
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "tetris.h"
#include "move.h"

t_pieces	random_pi(t_allpieces *all)
{
  t_allpieces	*head;
  int		i;
  int		ra;

  head = all;
  i = 0;
  while (all != NULL)
    1 ? i++, all = all->next : 0;
  all = head;
  ra = rand() % (i);
  i = 0;
  while (i < ra)
    1 ? i++, all = all->next : 0;
  return (all->curr);
}

int		defeat(char ***board, t_pieces pie)
{
  int		x;
  int		y;

  y = 1;
  x = BOARD_W / 2;
  if (stopme_board(board, &pie, y, x))
    return (0);
  return (1);
}

int		loop(t_allpieces *all, t_all_wins windows)
{
  t_pieces	next;
  t_pieces	prems;
  char		***board;

  srand(time(NULL));
  board = create_board();
  prems = random_pi(all);
  init_term(0);
  while (defeat(board, prems))
    {
      wclear(windows.win_pi);
      wborder(windows.win_pi, '|', '|', '-', '-', '/', '\\', '\\', '/');
      display_pi_co(next = random_pi(all), windows.win_pi, 1, 2);
      statsse(0, windows.win_sc, 1);
      scrolling(board, windows, prems);
      prems = next;
    }
  init_term(1);
  end();
  read(0, 0, 1);
  return (0);
}
