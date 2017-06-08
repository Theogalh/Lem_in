/*
** list_functions.c for  in /home/benmak_s/CPE/check
**
** Made by Sami Benmakhlouf
** Login   <benmak_s@epitech.net>
**
** Started on  Thu Apr 14 14:52:11 2016 Sami Benmakhlouf
** Last update Mon Apr 25 17:27:16 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "my.h"
#include "func.h"

int		my_put_in_list(t_list **list, char *str)
{
  t_list	*tmp;

  if (str == NULL)
    return (1);
  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (1);
  tmp->data = str;
  tmp->next = *list;
  tmp->name = NULL;
  *list = tmp;
  return (0);
}

int		name_exist(char *name, t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  if (name == NULL)
    return (1);
  while (tmp != NULL)
    {
      if (tmp->name != NULL)
	{
	  if (my_strcmp(name, tmp->name) == 0)
	    {
	      my_putstr("Error same name in file\n");
	      return (1);
	    }
	}
      tmp = tmp->next;
    }
  return (0);
}

int		add_elem(t_list **list, char *data)
{
  t_list	*tmp;
  t_list	*tmp2;
  char		*name;

  tmp2 = *list;
  if (data == NULL)
    return (1);
  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (1);
  if ((name = check_data(data, list)) != NULL && check_name(name) == 0)
    tmp->name = name;
  else if (name == NULL)
    return (-1);
  else
    tmp->name = NULL;
  tmp->data = data;
  tmp->next = NULL;
  while (tmp2->next != NULL)
    {
      tmp2 = tmp2->next;
    }
  tmp2->next = tmp;
  return (0);
}
