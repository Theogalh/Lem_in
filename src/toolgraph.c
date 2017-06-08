/*
** toolgraph.c for toolsgraph in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Mon Apr 11 14:52:06 2016 Thomas Bouillon
** Last update Sat Apr 23 21:46:58 2016 thomas
*/

#include <stdio.h>
#include "lemin.h"
#include "my.h"

t_maillon	*sch_graph_name(t_maillon *graph, char *name)
{
  t_maillon	*tmp;

  tmp = graph;
  while (my_strcmp(name, tmp->name) != 0)
    tmp = tmp->next;
  return (tmp);
}

t_maillon	*sch_graph_id(t_maillon *graph, const int id)
{
  t_maillon	*tmp;

  tmp = graph;
  while (id != tmp->id)
    tmp = tmp->next;
  return (tmp);
}

t_maillon	*sch_graph_spec(t_maillon *graph, const int spec)
{
  t_maillon	*tmp;

  tmp = graph;
  while (spec != tmp->spec)
    {
      if (tmp->next != NULL)
	tmp = tmp->next;
      else if (tmp->spec != spec)
	return (NULL);
    }
  return (tmp);
}

void		change_spec(t_maillon *graph, int spec)
{
  int		i;
  t_node	*node;

  i = 0;
  if (graph->node.nbnode != 0)
    {
      node = graph->node.first;
      while (i != graph->node.nbnode)
	{
	  if (node->maillon->spec == 0)
	    node->maillon->spec = spec;
	  if (node->next != NULL)
	    node = node->next;
	  i = i + 1;
	}
    }
}
