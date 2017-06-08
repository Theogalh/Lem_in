/*
** create_maillon.c for create_maillon in /home/theogalh/git/CPE_2015_lemin_bootstrap
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Mon Apr  4 18:43:44 2016 Thomas Bouillon
** Last update Sat Apr 23 14:42:55 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "lemin.h"

t_maillon	*create_maillon(const int id, char *name, const int spec)
{
  t_maillon	*tmp;
  t_nodelist	nodelist;

  if ((tmp = malloc(sizeof(t_maillon))) == NULL)
    return (NULL);
  tmp->name = name;
  tmp->id = id;
  tmp->spec = spec;
  tmp->next = NULL;
  nodelist.first = NULL;
  nodelist.nbnode = 0;
  tmp->node = nodelist;
  return (tmp);
}
