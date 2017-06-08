/*
** sort.c for  in /home/partou_a/rendu/algo_lemin/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Apr 19 17:48:28 2016 Robin Partouche
** Last update Mon Apr 25 16:27:18 2016 Robin Partouche
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		add_to_list(t_path *list, int nbr)
{
  t_path	*elem;
  t_path	*first;

  if (list->length != -1)
    {
      first = list;
      if ((elem = malloc(sizeof(*elem))) == NULL)
	return (-1);
      elem->length = nbr;
      elem->next = NULL;
      while (list->next != NULL)
	list = list->next;
      list->next = elem;
      list = first;
    }
  else
    {
      list->length = nbr;
      list->next = NULL;
    }
  return (0);
}

int		my_put_in_path(t_path *list, t_path *data)
{
  t_path	*elem;
  t_path	*first;

  if (list->tab != NULL)
    {
      first = list;
      if ((elem = malloc(sizeof(*elem))) == NULL)
	return (-1);
      elem->length = data->length;
      elem->tab = data->tab;
      elem->next = NULL;
      while (list->next != NULL)
	list = list->next;
      list->next = elem;
      list = first;
    }
  else
    {
      list->length = data->length;
      list->tab = data->tab;
      list->next = NULL;
    }
  return (0);
}

t_path		*while_sort(t_path *path, t_path *new_path, int min)
{
  t_path	*tmp;
  t_path	*first;

  first = path;
  tmp = NULL;
  while (path != NULL)
    {
      if (min == path->length)
	{
	  if (my_put_in_path(new_path, path) == -1)
	    return (NULL);
	  if (tmp == NULL)
	    first = path->next;
	  else
	    tmp->next = path->next;
	}
      else
	tmp = path;
      path = path->next;
    }
  return (first);
}

int	sort_path(t_lemin *lemin, int min, int ants, t_path *new_path)
{
  t_path	*first;

  first = new_path;
  if (lemin->path->tab[0] == 0 && lemin->path->tab[1] == 1
      && lemin->path->tab[2] == -1)
    return (ant(lemin->path, lemin));
  while (lemin->path != NULL)
    {
      lemin->path = while_sort(lemin->path, new_path, min);
      min = min + 1;
    }
  new_path = first;
  return (best_path(new_path, ants, lemin, 0));
}
