/*
** v_movuser.c for verif move form user in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Fri Mar 17 18:12:50 2017 Antoine Renaud
** Last update Mon May 22 22:05:23 2017 Antoine Renaud
*/

#include <unistd.h>
#include "tetris.h"
#include "move.h"
#include "my_lib.h"

int	        user_input(char ***board, t_pieces *piece, t_coor *c_pie)
{
  char          buff1[10];
  int           ret;

  ret = read(0, buff1, 10);
  if (ret != 0)
    {
      buff1[ret] = '\0';
      if ((ret = moving_piece(buff1, c_pie, board, *piece)))
	{
	  usleep(100000);
	  return (ret);
	}
      else if (my_strcmp(buff1, keys.k_turn) == 0)
	return (can_I_turn(piece, board, *c_pie));
    }
  usleep(100000);
  c_pie->y++;
  if (can_I_go_there(board, c_pie, *piece))
    {
      insert_board(piece, board, c_pie->y, c_pie->x);
      return (3);
    }
  return (1);
}

int		moving_piece(char *buff1, t_coor *c_pie, char ***board,
			     t_pieces piece)
{
  if (my_strcmp(buff1, keys.k_left) == 0)
    return (side_movement(board, c_pie, piece, -1));
  if (my_strcmp(buff1, keys.k_right) == 0)
    return (side_movement(board, c_pie, piece, 1));
  if (my_strcmp(buff1, keys.k_drop) == 0)
    return (drop_piece(board, c_pie, piece));
  if (my_strcmp(buff1, keys.k_pause) == 0 ||
      (my_strcmp(keys.k_pause, "(space)") == 0 && my_strcmp(buff1, " ") == 0))
    return (pause());
  return (0);
}

int		drop_piece(char ***board, t_coor *c_pie, t_pieces piece)
{
  while (c_pie->y + piece.hei < BOARD_SIZE - 2 &&
	 !stopme_board(board, &piece, c_pie->y + 1, c_pie->x))
    c_pie->y++;
  insert_board(&piece, board, c_pie->y, c_pie->x);
  return (3);
}

int		side_movement(char ***board, t_coor *c_pie, t_pieces piece, int var)
{
  c_pie->x += var;
  if (c_pie->x <= 0)
    c_pie->x = 1;
  else if (c_pie->x + piece.wid >= BOARD_W)
    c_pie->x--;
  if (stopme_board(board, &piece, c_pie->y, c_pie->x))
    {
      c_pie->x -= var;
      return (0);
    }
  return (1);
}

int		can_I_go_there(char ***board, t_coor *c_pie, t_pieces piece)
{

  if (c_pie->y + piece.hei > BOARD_SIZE - 2)
    return (3);
  else if (stopme_board(board, &piece, c_pie->y, c_pie->x))
    {
      c_pie->y--;
      return (3);
    }
  else if (c_pie->y + piece.hei >= BOARD_SIZE - 2)
    return (3);
  return (0);
}
