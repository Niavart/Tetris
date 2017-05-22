/*
** pieces.h for pieces headers in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sat Mar 11 14:20:28 2017 Antoine Renaud
** Last update Sat Mar 11 14:51:16 2017 Antoine Renaud
*/

#ifndef PIECE_H_
# define PIECE_H_

#include <dirent.h>

typedef struct		s_files
{
  struct dirent		*file;
  struct s_files	*next;
}			t_files;

void	add_files(struct dirent *, t_files *);
void	sort_my_files(t_files *);

#endif /* !PIECE_H_ */
