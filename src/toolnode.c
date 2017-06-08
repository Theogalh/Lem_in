/*
** toolnode.c for toolnode in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Sat Apr 23 16:12:50 2016 Thomas Bouillon
** Last update Mon Apr 25 16:47:00 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int	sch_node_name(t_maillon *maillon, char *name)
{
  t_node	*tmp;

  tmp = maillon->node.first;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->maillon->name, name) == 0)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

int	get_node_spec(t_maillon *graph, int bol)
{
  t_node	*first;
  int		result;

  if (graph->node.first == NULL)
    return (-1);
  first = graph->node.first;
  result = first->maillon->spec;
  while (first != NULL)
    {
      if (first->maillon->spec < result && bol == 1)
	result = first->maillon->spec;
      else if (bol == 0 && first->maillon->spec > result)
	result = first->maillon->spec;
      first = first->next;
    }
  return (result);
}

t_node		*sch_node_spec(t_node *curr, const int spec)
{
  t_node	*tmp;

  tmp = curr;
  while (tmp != NULL)
    {
      if (tmp->maillon->spec == spec)
	return (tmp);
      else
	tmp = tmp->next;
    }
  return (NULL);
}

t_path		*path1(t_lemin *lemin)
{
  t_path	*tmp;

  if ((tmp = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  if ((tmp->tab = malloc(sizeof(int) * 3)) == NULL)
    return (NULL);
  tmp->tab[0] = lemin->start->id;
  tmp->tab[1] = lemin->end->id;
  tmp->tab[2] = -1;
  tmp->length = 2;
  tmp->next = NULL;
  return (tmp);
}
