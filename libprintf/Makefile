##
## Makefile for makefile in /home/renaud_e/delivery/PSU_2016_my_printf
## 
## Made by Antoine Renaud
## Login   <renaud_e@epitech.net>
## 
## Started on  Fri Nov 18 10:21:18 2016 Antoine Renaud
## Last update Mon May  8 15:38:35 2017 Antoine Renaud
##

SRC	=	my_putchar.c \
		my_longnbr.c \
		my_putnbr_r.c \
		my_putstr_r.c \
		my_printf.c \
		my_putnbr.c \
		all_back.c \
		fillme.c \
		modifs.c \
		modifs2.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Ilib/

NAME	=	libprintf.a

CFLAGS	+=	-Iinclude -W -Wall -Wextra

all: 	$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
