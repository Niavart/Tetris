/*
** tetris.h for match in /home/arakhaa/System_Unix/PSU_2016_tetris/include
** 
** Made by Marianne Levee
** Login   <arakhaa@epitech.net>
** 
** Started on  Mon Feb 13 11:24:22 2017 Marianne Levee
** Last update Mon May 22 22:49:50 2017 Antoine Renaud
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#include <curses.h>

#define PAUSED 1
#define BOARD_SIZE 25
#define BOARD_W 17

typedef struct  s_pieces
{
  int           wid;
  int           hei;
  int           color;
  char          **model;
  char		*name;
}               t_pieces;

typedef struct          s_allpieces
{
  t_pieces              curr;
  struct s_allpieces	*error;
  struct s_allpieces    *next;
}                       t_allpieces;

typedef struct          s_all_wins
{
  WINDOW		*win_sc;
  WINDOW		*win_ga;
  WINDOW		*win_pi;
}			t_all_wins;

void		my_printf(const char *, ...);
t_all_wins	tab_curses();
t_allpieces	*get_pieces();
t_allpieces	*remove_errors(t_allpieces *);
char		*delete_zero(char *);
char		*delete_zerominus(char *);
int		a_real_strcmp(char *, char *);
void		my_putstr_error(char *);
int		parsing(t_allpieces *);
int		add_null_piece(t_allpieces *, char *);
int		te_getwid(char *);
int		te_gethei(char *);
int		te_getcol(char *);
int		te_len(char *, int);
char		*my_real_strcat(char *, char *);
int		loop(t_allpieces *, t_all_wins);
int		te_getnbr(char *, int *);
char		***create_board();
char		**fullfilling(char **, int);
void		scrolling(char ***, t_all_wins, t_pieces);
void		display_pi_co(t_pieces, WINDOW *, int, int);
void		display_board_col(char ***, WINDOW *);
t_pieces	turn_piece_r(t_pieces);
int		my_delete_line(char ***);
void		init_term(int);
void		help(char **);
int		no(char *, t_pieces *, int *);
int		verif_nb_var(char *, int *, t_pieces *);
int		statsse(int, WINDOW *, int);
void		end();
void		write_into(WINDOW *, int);
void		r_init_border(t_all_wins);
void		display_timer(int, WINDOW *);
int		whatwassaved();
void		saving(int);
void		my_swap(char **, char **);

#endif /* !TETRIS_H_ */
