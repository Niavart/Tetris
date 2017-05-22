/*
** m_win.c for windows curse in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Feb 27 14:22:08 2017 Antoine Renaud
** Last update Tue Mar 21 14:34:35 2017 Antoine Renaud
*/

#include <sys/ioctl.h>
#include <term.h>
#include <time.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"

void			init_windows()
{
  initscr();
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
}

void			init_colors()
{
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(6, COLOR_CYAN, COLOR_CYAN);
  init_pair(7, COLOR_RED, COLOR_BLACK);
  init_pair(8, COLOR_GREEN, COLOR_BLACK);
  init_pair(9, COLOR_YELLOW, COLOR_BLACK);
  init_pair(10, COLOR_BLUE, COLOR_BLACK);
  init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(12, COLOR_CYAN, COLOR_BLACK);
}

void			write_into(WINDOW *win_sc, int s)
{
  attron(COLOR_PAIR(7));
  mvprintw(0, 0, " _________  ________  _________  _______     _____   __\
____   \n");
  mvprintw(1, 0, "|  _   _  ||_   __  ||  _   _  ||_   __ \\   |_   _|.'\
 ____ \\");
  mvprintw(2, 0, "|_/ | | \\_|  | |_ \\_||_/ | | \\_|  | |__) |    | |  | \
(___ \\_| ");
  mvprintw(3, 0, "    | |      |  _| _     | |      |  __ /     | |   _.___\
_`.  ");
  mvprintw(4, 0, "   _| |_    _| |__/ |   _| |_    _| |  \\ \\_  _| |_ | \\_\
___) |");
  mvprintw(5, 0, "  |_____|  |________|  |_____|  |____| |___||_____| \\_____\
_.' ");
  attroff(COLOR_PAIR(7));
  refresh();
  mvwprintw(win_sc, 1, 2, "High Score");
  mvwprintw(win_sc, 1, 20, "%2d", s);
  mvwprintw(win_sc, 2, 2, "Score");
  mvwprintw(win_sc, 4, 2, "Lines");
  mvwprintw(win_sc, 5, 2, "Level");
  mvwprintw(win_sc, 7, 2, "Timer");
}

t_all_wins		tab_curses()
{
  t_all_wins		windows;

  init_windows();
  cbreak();
  refresh();
  start_color();
  init_colors();
  windows.win_sc = newwin(10, 25, 15, 2);
  windows.win_ga = newwin(BOARD_SIZE, BOARD_W, 8, 35);
  windows.win_pi = newwin(8, 12, 8, 35 + BOARD_W + 2);
  nodelay(stdscr, TRUE);
  write_into(windows.win_sc, whatwassaved());
  wborder(windows.win_sc, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wborder(windows.win_ga, '|', '|', '-', '-', '+', '+', '+', '+');
  wborder(windows.win_pi, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(windows.win_sc);
  wrefresh(windows.win_ga);
  wrefresh(windows.win_pi);
  return (windows);
}

void			init_term(int i)
{
  static struct	termios	oldT;
  static struct	termios newT;

  if (i == 0)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = 1;
      ioctl(0, TCSETS, &newT);
    }
  else
    ioctl(0, TCSETS, &oldT);
}
