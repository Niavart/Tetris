/*
** turn_pieces.c for turn_pieces in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Mar  6 16:54:08 2017 Antoine Renaud
** Last update Sat Mar 18 16:47:18 2017 Antoine Renaud
*/

#include <stdlib.h>
#include "tetris.h"
#include "move.h"

int		can_I_turn(t_pieces *piece, char ***board, t_coor c_pie)
{
  t_pieces	tmp;

  tmp = turn_piece_r(*piece);
  if (c_pie.x + piece->hei >= BOARD_W ||
      stopme_board(board, &tmp, c_pie.y, c_pie.x))
    return (0);
  *piece = tmp;
  return (1);
}

t_pieces	turn_piece_r(t_pieces piece)
{
  int		tmp;
  int		i;
  int		j;
  char		**n_mod;

  i = 0;
  tmp = piece.wid;
  piece.wid = piece.hei;
  piece.hei = tmp;
  n_mod = malloc(sizeof(char *) * (piece.hei + 1));
  while (i < piece.hei)
    {
      j = 0;
      n_mod[i] = malloc(sizeof(char) * (piece.wid + 1));
      while (j < piece.wid)
	{
	  n_mod[i][j] = piece.model[piece.wid - j - 1][i];
	  j++;
	}
      n_mod[i][j] = '\0';
      i++;
    }
  n_mod[i] = NULL;
  piece.model = n_mod;
  return (piece);
}

char		**new_line()
{
  char		**n_l;
  int		i;

  i = 0;
  n_l = malloc(sizeof(char *) * BOARD_W);
  while (i < BOARD_W - 2)
    {
      n_l[i] = malloc(sizeof(char) * 3);
      n_l[i][0] = ' ';
      n_l[i][1] = 0;
      n_l[i][2] = '\0';
      i++;
    }
  n_l[i] = NULL;
  return (n_l);
}

int		full_line(char **line)
{
  int		i;

  i = 0;
  while (line[i])
    if (line[i++][0] == ' ')
      return (0);
  return (1);
}

int		my_delete_line(char ***board)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (board[i])
    {
      if (full_line(board[i]))
	{
	  while (i > 0)
	    {
	      board[i] = board[i - 1];
	      i--;
	    }
	  board[0] = new_line();
	  count++;
	}
      i++;
    }
  return (count);
}
