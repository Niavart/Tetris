/*
** errors.c for errors.c in /home/renaud_e/delivery/wolf3d
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sat Jan  7 15:16:41 2017 Antoine Renaud
** Last update Mon May 22 20:51:50 2017 Antoine Renaud
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"
#include "my_lib.h"

void	error(char *msg)
{
  write(2, msg, my_strlen(msg) - 1);
}

char	*v_malloc1(int size)
{
  char	*str;

  if ((str = malloc(sizeof(char) * size)) == NULL)
    {
      write(2, "Error malloc of char *\n", 23);
      return (NULL);
    }
  return (str);
}

static int	stay_focused(char c)
{
  if (c == '\n' || (c >= '0' && c <= '9'))
    return (1);
  else
    return (0);
}

int	v_file(char *buff, char *file)
{
  int	i;

  i = 0;
  while (buff[i] != '\0' && buff[i] != '\n' && stay_focused(buff[i]))
    i++;
  if (buff[i] == '\0' || i > 13 || !(stay_focused(buff[i])))
    {
      my_printf("Error, %s is not a correct file.\n", file);
      return (0);
    }
  return (1);
}
