/*
** libmy.h for my own lib in /home/renaud_e/delivery/PSU_2016_42sh/my_printf/lib
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon May  8 13:28:13 2017 Antoine Renaud
** Last update Mon May 22 22:41:55 2017 Antoine Renaud
*/

#ifndef MY_LIB_H_
# define MY_LIB_H_

int	my_strcmp(const char *, const char *);
int	my_strncmp(const char *, const char *, int);
int	my_strlen(const char *);
int	size_of_int(int);
char	*my_strncpy(char *, const char *, int);
char	*my_strncat(char *, const char *, int);
char	*my_strcat(char *, const char *);
char    *my_strdup_s(const char *, int);
char    *my_strdup(const char *);
char    *my_a_realloc(char *, int);
char	*my_strcpy(char *, const char *);
char	*my_revstr(char *);
char	*epur_str(char *);
char	*epur_str_m(char *);
int	count_quote(const char *);
int	my_getnbr(char *);
int	my_n_getnbr(char *);

#endif /* !MY_LIB_H_ */
