/*
** link_maillon.c for link_maillon in /home/theogalh/git/CPE_2015_lemin_bootstrap
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Mon Apr  4 19:30:10 2016 Thomas Bouillon
** Last update Mon Apr 11 15:38:56 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "lemin.h"

int	link_maillon(t_maillon *maillon1, t_maillon *maillon2)
{
  t_node	*tmp;
  t_node	*tmp2;
  int		i;

  i = 0;
  if ((tmp = malloc(sizeof(t_node))) == NULL)
    return (-1);
  tmp->maillon = maillon2;
  tmp->next = NULL;
  if (maillon1->node.first == NULL)
    maillon1->node.first = tmp;
  else
    {
      tmp2 = maillon1->node.first;
      while (i != (maillon1->node.nbnode - 1))
	{
	  tmp2 = tmp2->next;
	  i = i + 1;
	}
      tmp2->next = tmp;
    }
  maillon1->node.nbnode = maillon1->node.nbnode + 1;
  return (1);
}
