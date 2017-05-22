/*
** save.c for save in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Tue Mar 21 13:35:59 2017 Antoine Renaud
** Last update Mon May 22 22:53:05 2017 Antoine Renaud
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_lib.h"

int	whatwassaved()
{
  int	fd;
  int	ret;
  char	buff[10];

  fd = open("t_save", O_RDONLY);
  ret = read(fd, buff, 10);
  buff[ret] = '\0';
  ret = my_getnbr(buff);
  close(fd);
  return (ret);
}

void	write_nbr(int nbr, int fd)
{
  char	c;

  if (nbr < 0)
    {
      write(fd, "-", 1);
      nbr *= -1;
    }
  if (nbr > 9)
    {
      write_nbr(nbr / 10, fd);
      write_nbr(nbr % 10, fd);
    }
  else
    {
      c = nbr + '0';
      write(fd, &c, 1);
    }
}

void	saving(int score)
{
  int	fd;

  if ((fd = open(".t_save", O_CREAT | O_WRONLY, 0777)) == -1)
    return ;
  write_nbr(score, fd);
  close(fd);
}
