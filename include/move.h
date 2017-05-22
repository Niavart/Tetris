/*
** move.h for movement in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Fri Mar 17 17:30:27 2017 Antoine Renaud
** Last update Sat Mar 18 17:52:28 2017 marianne.levee
*/

#ifndef MOVE_H_
# define MOVE_H_

typedef struct	s_coor
{
  int		x;
  int		y;
}		t_coor;

typedef struct          s_debug
{
  char                  *lvl;
  char                  *k_left;
  char                  *k_right;
  char                  *k_turn;
  char                  *k_drop;
  char                  *k_quit;
  char                  *next;
  char                  *k_pause;
  char                  *map;
}                       t_debug;

extern t_debug  keys;

int             debug(int ac, char **av, t_debug *);
t_debug         fill_null(char **);
int		big_opt(t_debug *opt, int i, char **av);
int	        user_input(char ***, t_pieces *, t_coor *);
int		moving_piece(char *, t_coor *, char ***, t_pieces);
int		can_I_go_there(char ***, t_coor *, t_pieces);
int		stopme_board(char ***, t_pieces *, int, int);
void		insert_board(t_pieces *, char ***, int, int);
int		drop_piece(char ***, t_coor *, t_pieces);
int		can_I_turn(t_pieces *, char ***, t_coor);
int		side_movement(char ***, t_coor *, t_pieces, int);

#endif /* !MOVE_H_ */
