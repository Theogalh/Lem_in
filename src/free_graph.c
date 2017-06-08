/*
** free_graph.c for free_graph in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Tue Apr 19 21:10:46 2016 Thomas Bouillon
** Last update Tue Apr 19 21:31:19 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "lemin.h"
#include "mylist.h"

void		free_list(t_lemin *lemin)
{
  t_list	*tmp2;
  t_list	*tmp3;

  tmp2 = lemin->list;
  while (tmp2 != NULL)
    {
      tmp3 = tmp2->next;
      free(tmp2->name);
      free(tmp2->data);
      free(tmp2);
      tmp2 = tmp3;
    }
}

void		free_graph(t_lemin *lemin)
{
  t_maillon	*tmp;
  t_node	*tmp2;
  t_node	*tmp3;
  int		i;

  i = 0;
  while (i != (lemin->lastid + 1))
    {
      tmp = sch_graph_id(lemin->start, i);
      if (tmp->node.nbnode != 0)
	{
	  tmp2 = tmp->node.first;
	  while (tmp2 != NULL)
	    {
	      tmp3 = tmp2->next;
	      free(tmp2);
	      tmp2 = tmp3;
	    }
	}
      i = i + 1;
    }
}
