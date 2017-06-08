/*
** check_file.c for check_file in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Sat Apr 23 15:25:27 2016 Thomas Bouillon
** Last update Mon Apr 25 17:25:54 2016 Robin Partouche
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "func.h"
#include "get_next_line.h"
#include "mylist.h"
#include "lemin.h"
#include "my.h"

t_list		*get_list_file(char *first_data)
{
  t_list	*list;
  int		check;
  char		*tmp;

  list = NULL;
  check = 0;
  if ((my_put_in_list(&list, first_data)) == 0)
    while (check == 0)
      {
	if ((tmp = get_next_line(0)) == NULL)
	  return (list);
	check = add_elem(&list, tmp);
      }
  if (check == -1)
    return (NULL);
  return (list);
}

int	is_valid(t_list *list)
{
  int	start;
  int	end;
  int	h;

  start = 0;
  end = 0;
  while (list != NULL)
    {
      h = 1;
      if ((h = my_strcmp(list->data, "##start")) == 0)
	start = start + 1;
      if ((h = my_strcmp(list->data, "##end")) == 0)
	end = end + 1;
      list->tst = 0;
      if (h == 0)
	list->tst = 1;
      list = list->next;
    }
  if (end == 1 && start == 1)
    return (0);
  else
    {
      my_putstr("Error: bad file\n");
      return (1);
    }
}

int	is_nbant_valid(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+')
	i++;
      else
	return (-1);
    }
  return (0);
}

int	check_nb_ant(char *str, t_list **list)
{
  int	nb_ants;

  if (str == NULL)
    return (-1);
  if (is_nbant_valid(str) == -1)
    return (-1);
  if ((nb_ants = my_getnbr(str)) == 0)
    return (-1);
  my_put_in_list(list, str);
  return (nb_ants);
}
