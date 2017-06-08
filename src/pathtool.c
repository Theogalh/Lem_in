/*
** pathtool.c for pathtool in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Sat Apr 23 18:44:04 2016 Thomas Bouillon
** Last update Mon Apr 25 16:20:54 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "lemin.h"

t_path		*addpath(t_lemin *lemin)
{
  t_path	*tmp;

  if ((tmp = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  if ((tmp->tab = malloc(sizeof(int) * -(lemin->spec_max - 3))) == NULL)
    return (NULL);
  tmp->tab[0] = lemin->end->id;
  tmp->tab[1] = -1;
  tmp->length = 1;
  tmp->next = NULL;
  return (tmp);
}

t_path		*pathdup(t_path *path, const int id, t_lemin *lemin)
{
  t_path	*tmp;
  int		i;

  i = 0;
  if ((tmp = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  if ((tmp->tab = malloc(sizeof(int) * -(lemin->spec_max - 2) * 10)) == NULL)
    return (NULL);
  while (path->tab[i] != id)
    {
      tmp->tab[i] = path->tab[i];
      i = i + 1;
    }
  tmp->tab[i] = path->tab[i];
  tmp->tab[i + 1] = -1;
  tmp->length = i;
  tmp->next = NULL;
  return (tmp);
}

void		pathaddid(t_path *path, int id)
{
  int		i;

  i = 0;
  while (path->tab[i] != -1)
    i = i + 1;
  path->tab[i] = id;
  path->tab[i + 1] = -1;
  path->length = path->length + 1;
}

int		pathdid(t_maillon *graph, t_path *tmp2, int spec, t_lemin *lemin)
{
  t_node	*tmp;
  int		h;

  if (spec == 0 || spec == 1)
    spec = 1;
  h = 0;
  tmp = sch_node_spec(graph->node.first, spec);
  while (tmp != NULL)
    {
      if (h == 1)
	{
	  if ((tmp2->next = pathdup(tmp2, graph->id, lemin)) == NULL)
	    return (-1);
	  tmp2 = tmp2->next;
	}
      pathaddid(tmp2, tmp->maillon->id);
      if (spec < 0 && (h = 1))
	if (pathdid(tmp->maillon, tmp2, spec + 1, lemin) == -1)
	  return (-1);
      while (tmp2->next != NULL)
	tmp2 = tmp2->next;
      tmp = tmp->next;
      tmp = sch_node_spec(tmp, spec);
    }
  return (0);
}
