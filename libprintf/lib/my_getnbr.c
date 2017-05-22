/*
** my_getnbr.c for tetris in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon May 22 22:07:27 2017 Antoine Renaud
** Last update Mon May 22 22:09:42 2017 Antoine Renaud
*/

int	my_getnbr(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	res = res * 10 + str[i] - 48;
      i++;
    }
  i = 0;
  while (str[i + 1] && (str[i + 1] < '0' || str[i + 1] > '9'))
    i = i + 1;
  if (str[i] == '-')
    res = res * - 1;
  return (res);
}

int	my_n_getnbr(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res);
}
