/*
** check_coordinate.c for  in /home/benmak_s/CPE_2015_lemin/src
**
** Made by Sami Benmakhlouf
** Login   <benmak_s@epitech.net>
**
** Started on  Thu Apr 21 21:25:59 2016 Sami Benmakhlouf
** Last update Sat Apr 23 23:43:53 2016 Sami Benmakhlouf
*/

#include <stdlib.h>
#include "my.h"
#include "func.h"
#include "get_next_line.h"
#include "lemin.h"

int	is_different_coordinate(char **tab, char **tab2)
{
  if (((my_strcmp(tab[0], tab2[0])) != 0) &&
      ((my_strcmp(tab[1], tab2[1])) == 0))
    {
      if (my_strcmp(tab[2], tab2[2]) == 0)
	{
	  my_putstr("Error: two same coordinate for different formicary\n");
	  return (-1);
	}
      return (0);
    }
  return (0);
}

int		compare_coordinate(t_list *list, char *str)
{
  char		**tab;
  char		**tab2;
  t_list	*tmp;

  tmp = list;
  tab = str_to_wordtab(str, ' ');
  while (tmp != NULL)
    {
      if (tmp->name != NULL)
	{
	  tab2 = str_to_wordtab(tmp->data, ' ');
	  if (is_different_coordinate(tab, tab2) == -1)
	    {
	      free_tab(tab);
	      free_tab(tab2);
	      return (-1);
	    }
	}
      tmp = tmp->next;
    }
  free_tab(tab);
  free_tab(tab2);
  return (0);
}

int		check_coordinate(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->name != NULL)
	{
	  if ((compare_coordinate(list, tmp->data)) == -1)
	    return (-1);
	}
      tmp = tmp->next;
    }
  return (0);
}
