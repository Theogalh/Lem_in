/*
** path_dup.c for  in /home/partou_a/rendu/CPE_2015_Lemin/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sun Apr 24 20:45:47 2016 Robin Partouche
** Last update Sun Apr 24 22:59:03 2016 Robin Partouche
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		new_ant(t_path *paths, t_lemin *lemin, int *nb_ant, int *ct_ant)
{
  t_path	*tmp;

  if (paths->tab[paths->i + 1] == -1)
    {
      tmp = paths;
      while (tmp->next != NULL)
	tmp = tmp->next;
      if ((tmp->next = path_dup(paths, ct_ant, lemin)) == NULL)
	return (-1);
      paths->ant = 0;
      paths->i = 0;
      *nb_ant = *nb_ant + 1;
    }
  else if (paths->i == 2)
    {
      tmp = paths;
      while (tmp->next != NULL)
	tmp = tmp->next;
      if ((tmp->next = path_dup(paths, ct_ant, lemin)) == NULL)
	return (-1);
    }
  return (0);
}

t_path		*path_dup(t_path *paths, int *ct_ant, t_lemin *lemin)
{
  t_path	*new_path;

  if ((new_path = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  new_path->tab = paths->tab;
  new_path->length = paths->length;
  new_path->i = 1;
  new_path->ant = paths->ant;
  new_path->next = NULL;
  if (*ct_ant <= lemin->nbant)
    new_path->ant = *ct_ant * -1;
  else
    new_path->ant = 0;
  *ct_ant = *ct_ant + 1;
  return (new_path);
}
