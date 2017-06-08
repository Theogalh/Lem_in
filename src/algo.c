/*
** algo.c for algo in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Sat Apr 23 14:15:09 2016 Thomas Bouillon
** Last update Mon Apr 25 16:49:10 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		check_solve(t_lemin *lemin)
{
  t_maillon	*graph;

  graph = lemin->end;
  if (graph->node.nbnode == 0)
    {
      my_putstr("No solution found.\n");
      return (-1);
    }
  if (graph->node.first->maillon->spec == 0)
    {
      my_putstr("No solution found.\n");
      return (-1);
    }
  return (0);
}

int		change_all_spec(t_lemin *lemin)
{
  t_maillon	*curr;
  int		spec;
  int		count;

  count = 1;
  spec = -1;
  change_spec(lemin->start, spec);
  curr = lemin->start;
  while (spec != - (lemin->lastid))
    {
      while (curr != NULL)
	{
	  curr = sch_graph_spec(curr, spec);
	  if (curr != NULL)
	    {
	      change_spec(curr, spec - 1);
	      curr = curr->next;
	      count = count + 1;
	    }
	}
      curr = lemin->start;
      spec = spec - 1;
    }
  return (0);
}

int		algo(t_lemin *lemin, int spec)
{
  t_maillon	*curr;
  t_path	*path;

  if (lemin->spec_max == 1 || lemin->spec_min == 1)
    {
      if ((lemin->path = path1(lemin)) == NULL)
	return (-1);
      return (0);
    }
  path = addpath(lemin);
  spec = lemin->spec_min;
  curr = lemin->end;
  lemin->path = path;
  while (spec != (lemin->spec_max - 1))
    {
      if (pathdid(curr, path, spec, lemin) == -1)
	return (-1);
      while (path->next != NULL)
	path = path->next;
      if ((path->next = pathdup(path, curr->id, lemin)) == NULL)
	return (-1);
      path = path->next;
      spec = spec - 1;
    }
  return (0);
}

int	*reverse_tab(int *tab)
{
  int	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((tmp = malloc(sizeof(tab) * 100)) == NULL)
    return (NULL);
  while (tab[i] != -1)
    i = i + 1;
  i = i - 1;
  while (i != -1)
    {
      tmp[j] = tab[i];
      i = i - 1;
      j = j + 1;
    }
  tmp[j] = -1;
  free(tab);
  return (tmp);
}

int		reverse_all_list(t_path *path)
{
  int		count;
  t_path	*tmp;

  count = 0;
  tmp = path;
  while (tmp != NULL)
    {
      tmp->length = 0;
      if ((tmp->tab = reverse_tab(tmp->tab)) == NULL)
	return (-1);
      while (tmp->tab[tmp->length] != -1)
	tmp->length = tmp->length + 1;
      tmp = tmp->next;
      count = count + 1;
    }
  tmp = path;
  if (tmp->next == NULL)
    return (-1);
  while (tmp->next->length != 1)
    tmp = tmp->next;
  tmp->next = NULL;
  return (0);
}
