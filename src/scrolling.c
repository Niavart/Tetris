/*
** scrolling.c for scrolling on main window in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Fri Mar  3 11:10:06 2017 Antoine Renaud
** Last update Mon May 22 22:50:07 2017 Antoine Renaud
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include "tetris.h"
#include "my_lib.h"
#include "move.h"

int		stopme_board(char ***board, t_pieces *piece, int x, int y)
{
  int		i;
  int		j;

  i = y;
  j = x;
  while (x < piece->hei + j)
    {
      y = i;
      while (y < piece->wid + i && y < BOARD_W - 1)
	{
	  if (piece->model[x - j][y - i] != ' ' &&
	      piece->model[x - j][y - i] != '\0')
	    if (board[x][y - 1][0] != ' ')
	      return (1);
	  y++;
	}
      x++;
    }
  return (0);
}

char		***create_board()
{
  int		size;
  int		line;
  char		***board;

  size = 0;
  if ((board = malloc(sizeof(char **) * BOARD_SIZE)) == NULL)
    return (NULL);
  while (size < BOARD_SIZE - 2)
    {
      line = 0;
      board[size] = malloc(sizeof(char *) * BOARD_W);
      while (line < BOARD_W - 2)
	{
	  board[size][line] = malloc(sizeof(char) * 3);
	  board[size][line][0] = ' ';
	  board[size][line][1] = 0;
	  board[size][line][2] = '\0';
	  line++;
	}
      board[size][line] = NULL;
      size++;
    }
  board[size] = NULL;
  return (board);
}

void		insert_board(t_pieces *piece, char ***board, int x, int y)
{
  int		i;
  int		j;
  int		d_y;

  i = 0;
  d_y = y;
  while (piece->model[i])
    {
      j = 0;
      y = d_y;
      while (piece->model[i][j])
	{
	  if (piece->model[i][j] != ' ')
	    {
	      board[x][y - 1][0] = piece->model[i][j];
	      board[x][y - 1][1] = piece->color;
	    }
	  j++;
	  y++;
	}
      i++;
      x++;
    }
}

void    check_size(t_all_wins windows)
{
  int	x;
  int	y;

  x = my_n_getnbr(keys.map);
  y = my_n_getnbr(keys.map + size_of_int(x) + 1);
  refresh();
  if (y + 20 > COLS || x + 20 > LINES)
    {
      clear();
      while (y + 20> COLS || x + 20 > LINES)
	{
	  mvprintw(LINES / 2, COLS / 2, "Resize me please");
	  refresh();
	}
      clear();
      r_init_border(windows);
    }
}

void		scrolling(char ***board, t_all_wins windows, t_pieces piece)
{
  t_coor	c_pie;
  int		ret_val;
  int		timer;

  c_pie.y = 1;
  c_pie.x = BOARD_W / 2;
  display_board_col(board, windows.win_ga);
  display_pi_co(piece, windows.win_ga, c_pie.y, c_pie.x);
  while (1)
    {
      timer = time(NULL);
      check_size(windows);
      display_timer(timer, windows.win_sc);
      if ((ret_val = user_input(board, &piece, &c_pie)) == 1)
	ret_val = can_I_go_there(board, &c_pie, piece);
      display_board_col(board, windows.win_ga);
      display_pi_co(piece, windows.win_ga, c_pie.y, c_pie.x);
      if (ret_val == 3)
	{
	  statsse(my_delete_line(board), windows.win_sc, 1);
	  return ;
	}
      usleep(100000);
    }
}
