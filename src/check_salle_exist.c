/*
** check_salle_exist.c for  in /home/benmak_s/CPE_2015_lemin/src
** 
** Made by Sami Benmakhlouf
** Login   <benmak_s@epitech.net>
** 
** Started on  Sat Apr 23 13:29:12 2016 Sami Benmakhlouf
** Last update Sat Apr 23 23:32:01 2016 Sami Benmakhlouf
*/

#include <stdlib.h>
#include "my.h"
#include "func.h"
#include "get_next_line.h"
#include "lemin.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}

void	init_mystruct(t_mystruct *vars)
{
  vars->first = 0;
  vars->second = 0;
}

int	name_does_exist(t_mystruct vars)
{
  if (vars.first == 0 || vars.second == 0)
    {
      my_putstr("Error: invalid liaison\n");
      return (-1);
    }
  return (0);
}

int	check_in_tab(char *str, t_list *tmp)
{
  t_list	*tmp2;
  t_mystruct	vars;

  tmp2 = tmp;
  init_mystruct(&vars);
  if (str[0] != '#')
    {
      vars.tab = str_to_wordtab(str, '-');
      while (tmp != NULL)
	{
	  if (tmp->name != NULL)
	    {
	      if ((my_strcmp(tmp->name, vars.tab[0])) == 0)
		vars.first = vars.first + 1;
	      if ((my_strcmp(tmp2->name, vars.tab[1])) == 0)
		vars.second = vars.second + 1;
	    }
	  tmp = tmp->next;
	  tmp2 = tmp2->next;
	}
      free_tab(vars.tab);
      if ((name_does_exist(vars)) == -1)
	return (-1);
    }
  return (0);
}

int	check_salle_exist(t_list *list)
{
  t_list *tmp;

  tmp = list;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (tmp->name == NULL)
	{
	  if ((check_in_tab(tmp->data, list)) == -1)
	    return (-1);
	}
      tmp = tmp->next;
    }
  return (0);
}
