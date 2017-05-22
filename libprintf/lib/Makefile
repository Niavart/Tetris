##
## Makefile for makefile in /home/renaud_e/delivery/PSU_2016_my_printf
## 
## Made by Antoine Renaud
## Login   <renaud_e@epitech.net>
## 
## Started on  Fri Nov 18 10:21:18 2016 Antoine Renaud
## Last update Mon May 22 22:42:32 2017 Antoine Renaud
##

SRC	=	my_strncpy.c \
		my_strncat.c \
		my_strcat.c \
		my_strcmp.c \
		my_realloc.c \
		my_epurstr.c \
		my_getnbr.c \
		my_strcpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

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
