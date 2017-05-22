/*
** c_buffto2d.h for buffto2d in /home/renaud_e/delivery/wolf3d/include
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sat Jan  7 15:17:43 2017 Antoine Renaud
** Last update Mon May  8 11:48:59 2017 Antoine Renaud
*/

#ifndef MY_BUFF2D_H_
# define MY_BUFF2D_H_

char	**c_buffto2d(char *, int, int);
int	c_size_line(char *);
char	*v_malloc1(int);
char	**v_malloc(int);
void	error(char *);
void	d_tabint(int **);
void	multi_zero(int *, int *, int *);

#endif /* !MY_BUFF2D_H_ */
