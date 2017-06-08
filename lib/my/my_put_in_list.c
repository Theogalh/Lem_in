/*
** my_put_in_list.c for  in /home/partou_a/rendu/Piscine_C_J11/ex_01
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Mon Oct 12 17:14:16 2015 Robin Partouche
** Last update Thu Nov 26 11:26:55 2015 Robin Partouche
*/

#include <stdlib.h>
#include "mylist.h"
#include "my.h"

int		my_put_in_list(struct s_list **list, char *voidata)
{
  struct s_list	*elem;

  elem = malloc(sizeof(*elem) * 100000);
  if (elem == NULL)
    return (1);
  elem->data = voidata;
  elem->next = *list;
  *list = elem;

  return (0);
}
