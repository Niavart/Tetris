/*
** pieces.c for game pieces in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Mon Feb 27 16:21:12 2017 Antoine Renaud
** Last update Mon May 22 20:48:56 2017 Antoine Renaud
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <grp.h>
#include "tetris.h"
#include "my_lib.h"
#include "c_buffto2d.h"
#include "pieces.h"

t_pieces	*v_tmp(char *tmp, char *name)
{
  int		i;
  t_pieces	*pie;

  i = 0;
  if ((pie = malloc(sizeof(t_pieces))) == NULL)
    return (NULL);
  if (verif_nb_var(tmp, &i, pie) == 0)
    return (NULL);
  if (no(tmp, pie, &i) == 0)
    return (NULL);
  while (tmp[i] && (tmp[i] == '*' || tmp[i] == ' ' || tmp[i] == '\n'))
    i++;
  pie->name = my_strdup(name);
  return (tmp[i] == '\0' ? pie : NULL);
}

int		rev_strcmp(char *s1, char *s2)
{
  int		i;
  int		j;

  i = my_strlen(s1);
  j = my_strlen(s2);
  while (i >= 0 && s1[i] == s2[j] && s1[i] != '.' && s2[j] != '.')
    {
      i--;
      j--;
    }
  return (s1[i] == s2[j]);
}

char		**fullfilling(char **model, int width)
{
  int		i;
  int		j;

  i = 0;
  while (model[i])
    {
      j = 0;
      if (my_strlen(model[i]) < width)
	{
	  while (j < width)
	    {
	      if (model[i][j] != '*')
		model[i][j] = ' ';
	      j++;
	    }
	  model[i][j] = '\0';
	}
      i++;
    }
  return (model);
}

int		add_pieces(t_allpieces *ap, char *file)
{
  char		*tmp;
  int		fd;
  t_pieces	*piece;

  tmp = my_strdup_s("tetriminos/", my_strlen(file) + 12);
  file = my_strcat(tmp, file);
  if ((fd = open(file, O_RDONLY)) < 0 ||
      (tmp = malloc(sizeof(char) * 40)) == NULL
      || (fd = read(fd, tmp, 40)) <= 0)
    return (1);
  tmp[fd] = '\0';
  if ((piece = v_tmp(tmp, file + 11)) == NULL)
    return (1);
  while (ap->next != NULL)
    ap = ap->next;
  if ((ap->next = malloc(sizeof(t_allpieces))) == NULL)
    return (1);
  ap = ap->next;
  ap->curr = *piece;
  ap->curr.model = c_buffto2d(tmp + te_len(tmp, 1), 40, 40);
  ap->curr.color = te_getcol(tmp);
  ap->next = NULL;
  ap->error = NULL;
  return (0);
}

t_allpieces	*get_pieces()
{
  DIR		*dir;
  struct dirent *files;
  t_allpieces	*pieces;
  t_files	*list;

  pieces = malloc(sizeof(t_allpieces));
  list = malloc(sizeof(t_files));
  list->next = NULL;
  pieces->next = NULL;
  dir = opendir("tetriminos");
  while ((files = readdir(dir)))
    add_files(files, list);
  list = list->next;
  sort_my_files(list);
  while (list != NULL)
    {
      if (rev_strcmp(list->file->d_name, ".tetrimino"))
	if (add_pieces(pieces, list->file->d_name) == 1)
	  add_null_piece(pieces, list->file->d_name);
      list = list->next;
    }
  pieces = pieces->next;
  return (pieces);
}
