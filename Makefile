##
## Makefile for tetris in /home/renaud_e/delivery/PSU_2016_tetris
## 
## Made by Antoine Renaud
## Login   <renaud_e@epitech.net>
## 
## Started on  Mon May 22 20:40:15 2017 Antoine Renaud
## Last update Mon May 22 22:52:38 2017 Antoine Renaud
##

CFLAGS	+=	-Iinclude -Ilib/libprintf/include -Ilibprintf/lib

CPPFLAGS +=	-W -Wall -Wextra

LIBS	=	libprintf/libprintf.a libprintf/lib/libmy.a

SRC	=	src/main.c \
		src/turn_pieces.c \
		src/displaying.c \
		src/print_tetri.c \
		src/errors.c \
		src/scrolling.c \
		src/game.c \
		src/c_buffto2d.c \
		src/pieces.c \
		src/debug.c \
		src/debug_2.c \
		src/small_fct.c \
		src/m_win.c \
		src/wrong.c \
		src/v_movuser.c \
		src/pause.c \
		src/save.c \
		src/delete_zero.c \
		src/m_files.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

RM	=	rm -rf

all:	mklibs $(NAME)

mklibs:
	make -C libprintf/lib
	make -C libprintf/

mklibsre:
	make -C libprintf/lib re
	make -C libprintf/ re

libsclean:
	make -C libprintf/lib clean
	make -C libprintf/ clean

libsfclean:
	make -C libprintf/lib fclean
	make -C libprintf/ fclean

$(NAME):$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) -lncurses -lc_graph_prog

clean:	libsclean
	rm -f $(OBJ)

fclean:	clean libsfclean
	rm -f $(NAME)

re:	fclean mklibs $(NAME)

.PHONY:	clean re all fclean libsfclean libsclean mklibs mklibsre
