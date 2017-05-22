/*
** my.h for my.h in /home/renaud_e/delivery/PSU_2016_my_printf
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Nov  7 14:54:05 2016 Antoine Renaud
** Last update Mon May  8 18:23:54 2017 Antoine Renaud
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>

int	nbdigit(int);
char	*my_longnbr(va_list);
char	*chartostring(char);
void	my_printf(const char *, ...);
char	*my_putchar_r(va_list);
void	my_putchar(char);
char	*my_putstr_r(va_list);
void	my_putstr(char *);
char	*my_putssstr_r(va_list);
char	*my_putssstr(va_list);
char	*my_putpointer(va_list);
char	*my_putnbr_r(va_list);
char	*my_putnbr(int);
char	*my_putnbr_hexa_r(va_list);
char	*my_putnbr_hexa(unsigned int);
char	*my_putnbr_hexam_r(va_list);
char	*my_putnbr_hexam(unsigned long int);
char	*my_putnbr_deci_r(va_list);
char	*my_putnbr_deci(unsigned int);
char	*my_putnbr_octa_r(va_list);
char	*my_putnbr_octa(unsigned int);
char	*my_putnbr_bina_r(va_list);
char	*my_putnbr_bina(unsigned int);
char	*all_flags(const char *, int, va_list);
char	*(*the_survivor(int))(char *, int, char);
char	*specialcase(const char *, int *, int, va_list);
char	*special(const char *, int *, int, va_list);
int	getnbr_diff(const char *, int);
int	all_modif(const char *, int, va_list);
char	*leplus(char *, int, char);
char	*lemoins(char *, int, char);
char	*lezero(char *, int, char);
char	*lediese(char *, int, char);
char	*leelle(char *, int, char);
char	*leache(char *, int, char);

#endif /* !MY_PRINTF_H_ */
