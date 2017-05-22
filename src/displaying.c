/*
** displaying.c for display all sorts of things in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Fri Mar  3 13:21:46 2017 Antoine Renaud
** Last update Mon May 22 20:46:45 2017 Antoine Renaud
*/

#include <ncurses.h>
#include <time.h>
#include "tetris.h"
#include "my_lib.h"

void	display_board_col(char ***board, WINDOW *game)
{
  int	i;
  int	j;

  i = 0;
  while (board[i])
    {
      j = 0;
      while (board[i][j])
	{
	  wattron(game, COLOR_PAIR(board[i][j][1]));
	  mvwprintw(game, i + 1, j + 1, "%c", board[i][j][0]);
	  wattroff(game, COLOR_PAIR(board[i][j][1]));
	  j++;
	}
      i++;
    }
  wrefresh(game);
}

void    display_pi_co(t_pieces piece, WINDOW *win_pi, int x, int y)
{
  int   i;
  int	j;

  i = 0;
  wattron(win_pi, COLOR_PAIR(piece.color));
  while (piece.model && piece.model[i])
    {
      j = 0;
      while (piece.model[i][j])
	{
	  if (piece.model[i][j] != ' ')
	    mvwprintw(win_pi, i + x, j + y, "%c", piece.model[i][j]);
	  j++;
	}
      i++;
    }
  wattroff(win_pi, COLOR_PAIR(piece.color));
  wrefresh(win_pi);
}

void		display_timer(int t, WINDOW *win_sc)
{
  static int	timer = 0;

  if (timer == 0)
    timer = t;
  else if (t < 0)
    {
      timer += (- 1) * t;
      return ;
    }
  mvwprintw(win_sc, 7, 20, "%2d", t - timer);
  wrefresh(win_sc);
}

int	statsse(int score, WINDOW *win_sc, int where)
{
  static int	nbr = 0;

  nbr = nbr + score * 10;
  if (where)
    {
      mvwprintw(win_sc, 2, 20, "%2d", nbr);
      wrefresh(win_sc);
    }
  else
    {
      mvprintw(20, 20, "SCORE : %d", nbr);
      refresh();
    }
  return (nbr);
}

void	end()
{
  clear();
  refresh();
  mvprintw(BOARD_SIZE / 2, 15, "   _____                         ____       \
          ");
  mvprintw(BOARD_SIZE / 2 + 1, 15, "  / ____|                       / __.\\  \
              ");
  mvprintw(BOARD_SIZE / 2 + 2, 15, "  | |  __  __ _ _ __ ___   ___  | |  \
| __   _____ _ __		");
  mvprintw(BOARD_SIZE / 2 + 3, 15, "  | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  \
| \\ \\ / / _ \\ '__|	");
  mvprintw(BOARD_SIZE / 2 + 4, 15, "  | |__| | (_| | | | | | |  __/ | |__|\
  \\ V /  __/ |   ");
  mvprintw(BOARD_SIZE / 2 + 5, 15, "  \\______|\\__,_|_| |_| |_|\\___| \\____/\
   \\_/ \\___|_|    ");
  if (whatwassaved() < (statsse(0, stdscr, 0)))
      saving(statsse(0, stdscr, 0));
  refresh();
}
