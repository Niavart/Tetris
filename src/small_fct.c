/*
** small_fct.c for what do you expect ?  in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Feb 27 18:55:54 2017 Antoine Renaud
** Last update Tue Mar 21 11:52:11 2017 Antoine Renaud
*/

int	te_getwid(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    res = res * 10 + str[i++] - '0';
  return (res);
}

int	te_gethei(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    i++;
  while (str[i] && str[i] == ' ')
    i++;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    res = res * 10 + str[i++] - '0';
  return (res);
}

int	te_getcol(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    i++;
  while (str[i] && str[i] == ' ')
    i++;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    i++;
  while (str[i] && str[i] == ' ')
    i++;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    res = res * 10 + str[i++] - '0';
  return (res);
}

int	te_len(char *str, int loop)
{
  int	i;
  int	max;
  int	c;

  i = 0;
  max = 0;
  c = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  max < c ? max = c : max;
	  if (loop == 1)
	    break ;
	  c = 0;
	}
      else
	c++;
      i++;
    }
  return (max);
}

int	te_getnbr(char *str, int *i)
{
  int	res;

  res = 0;
  while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
    {
      res = res * 10 + str[(*i)] - '0';
      *i = (*i) + 1;
    }
  return (res);
}
