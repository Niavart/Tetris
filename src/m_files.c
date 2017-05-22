/*
** m_files.c for files management in /home/renaud_e/delivery/PSU_2016_tetris
** 
** Made by Antoine Renaud
** Login   <renaud_e@epitech.net>
** 
** Started on  Sat Mar 11 14:25:00 2017 Antoine Renaud
** Last update Mon May 22 22:24:35 2017 Antoine Renaud
*/

#include <stdlib.h>
#include "pieces.h"
#include "tetris.h"
#include "my_lib.h"

void		add_files(struct dirent *file, t_files *dir)
{
  while (dir && dir->next != NULL)
    dir = dir->next;
  if ((dir->next = malloc(sizeof(t_files))) == NULL)
    return ;
  dir = dir->next;
  dir->file = file;
  dir->next = NULL;
}

void		sort_my_files(t_files *dir)
{
  struct dirent	*tmp;
  t_files	*head;

  head = dir;
  while (dir->next != NULL)
    {
      if (my_strcmp(dir->file->d_name, dir->next->file->d_name) > 0)
	{
	  tmp = dir->file;
	  dir->file = dir->next->file;
	  dir->next->file = tmp;
	  dir = head;
	}
      dir = dir->next;
    }
}

int		add_null_piece(t_allpieces *ap, char *name)
{
  while (ap->next != NULL)
    ap = ap->next;
  if ((ap->next = malloc(sizeof(t_allpieces))) == NULL)
    return (1);
  ap = ap->next;
  ap->error = ap;
  ap->curr.name = my_strdup_s(name, my_strlen(name));
  ap->next = NULL;
  return (0);
}

t_allpieces	*remove_errors(t_allpieces *ap)
{
  t_allpieces	*head;

  head = ap;
  while (ap && ap->next && ap->error != NULL)
    {
      head = ap->next;
      ap = head;
    }
  while (ap && ap->next != NULL)
    {
      if (ap->next->error != NULL)
	ap->next = ap->next->next;
      else
	ap->next->curr.model = fullfilling(ap->next->curr.model,
					   ap->next->curr.wid);
      ap = ap->next;
    }
  return (head);
}
