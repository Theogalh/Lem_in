/*
** make_graph.c for make_graph in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Sun Apr 10 14:45:28 2016 Thomas Bouillon
** Last update Mon Apr 25 14:33:00 2016 Thomas Bouillon
*/

#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"
#include "lemin.h"
#include "my.h"

int		addfirst(t_list *list, t_maillon *graph, t_lemin *lemin)
{
  t_list	*tmp;

  tmp = list;
  while (my_strcmp(tmp->data, "##start") != 0)
    tmp = tmp->next;
  tmp = tmp->next;
  if ((graph = create_maillon(0, tmp->name, 1)) == NULL)
    return (-1);
  lemin->start = graph;
  tmp = list;
  while (my_strcmp(tmp->data, "##end") != 0)
    tmp = tmp->next;
  tmp = tmp->next;
  if ((graph->next = create_maillon(1, tmp->name, 2)) == NULL)
    return (-1);
  lemin->nbmaillon = 2;
  lemin->end = graph->next;
  return (0);
}

int		addmaillon(char *name, t_maillon *graph, t_lemin *lemin)
{
  static int	id = 1;
  t_maillon	*new;
  t_maillon	*tmp;
  int		i;

  id = id + 1;
  tmp = graph;
  i = 0;
  if ((new = create_maillon(id, name, 0)) == NULL)
    return (-1);
  while (i != (lemin->nbmaillon - 1))
    {
      tmp = tmp->next;
      i = i + 1;
    }
  tmp->next = new;
  lemin->nbmaillon = lemin->nbmaillon + 1;
  lemin->lastid = id;
  return (0);
}

int		addnode(char *data, t_maillon *graph)
{
  char		*tmp1;
  char		*tmp2;
  int		i;
  int		h;

  i = 0;
  if ((tmp1 = get_node(data, '-', i)) == NULL)
    return (-1);
  while (data[i] != '-')
    i = i + 1;
  i = i + 1;
  if ((tmp2 = get_node(data, 0, i)) == NULL)
    return (-1);
  if (sch_node_name(sch_graph_name(graph, tmp1), tmp2) == -1)
    return (1);
  if (sch_node_name(sch_graph_name(graph, tmp2), tmp2) == -1)
    return (1);
  i = link_maillon(sch_graph_name(graph, tmp1), sch_graph_name(graph, tmp2));
  h = link_maillon(sch_graph_name(graph, tmp2), sch_graph_name(graph, tmp1));
  if ((i + h) != 2)
    return (-1);
  return (1);
}

int		check_list(t_list *list)
{
  int	i;

  i = 0;
  if (list->data[0] == '#')
    return (2);
  while (list->data[i] != 0)
    {
      if (list->data[i] == '-')
	return (1);
      i = i + 1;
    }
  return (0);
}

t_maillon	*make_graph(t_list *list, t_lemin *lemin)
{
  int		h;
  t_list	*tmp;
  t_maillon	*graph;

  tmp = list;
  graph = NULL;
  if ((h = addfirst(tmp, graph, lemin)) == -1)
    return (NULL);
  graph = lemin->start;
  while (tmp->next != NULL)
    {
      if (tmp->tst == 1)
	tmp = tmp->next;
      tmp = tmp->next;
      h = check_list(tmp);
      if (h == 0)
	h = addmaillon(tmp->name, graph, lemin);
      else if (h == 1)
	h = addnode(tmp->data, graph);
      if (h == -1)
	return (NULL);
    }
  return (graph);
}
