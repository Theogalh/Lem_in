/*
** ant.c for  in /home/partou_a/rendu/algo_lemin/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Apr  7 16:07:51 2016 Robin Partouche
** Last update Sun Apr 24 23:01:25 2016 Robin Partouche
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int	init_ant(t_path *paths, int ant)
{
  int	ct_ant;

  ct_ant = 1;
  while (paths != NULL && ct_ant != ant + 1)
    {
      paths->i = 1;
      paths->ant = ct_ant;
      ct_ant = ct_ant + 1;
      paths = paths->next;
    }
  return (ct_ant);
}

void		write_ant(t_path *paths, t_lemin *lemin, int *i)
{
  t_maillon	*tab;

  if (*i == 1)
    my_putchar(' ');
  *i = 1;
  tab = lemin->start;
  my_putchar('P');
  my_put_nbr(paths->ant);
  my_putchar('-');
  while (tab != NULL && tab->id != paths->tab[paths->i])
    {
      tab = tab->next;
    }
  my_putstr(tab->name);
}

int		while_ant(t_path *paths, int *ct_ant, int *nb_ant, t_lemin *lemin)
{
  int		i;

  i = 0;
  while (paths != NULL)
    {
      if (paths->ant > 0)
	{
	  write_ant(paths, lemin, &i);
	  if ((new_ant(paths, lemin, nb_ant, ct_ant)) == -1)
	    return (-1);
	  paths->i = paths->i + 1;
	}
      paths = paths->next;
    }
  return (0);
}

int		while_new_ant(t_path *paths, int *ct_ant,
			      int *nb_ant, t_lemin *lemin)
{
  int		i;
  t_path	*tmp;

  i = 1;
  while (paths != NULL)
    {
      if (paths->ant < 0)
	{
	  paths->ant = paths->ant * -1;
	  write_ant(paths, lemin, &i);
	  if (paths->tab[paths->i + 1] == -1 && (tmp = paths))
	    {
	      while (tmp->next != NULL)
		tmp = tmp->next;
	      if ((tmp->next = path_dup(paths, ct_ant, lemin)) == NULL)
		return (-1);
	      paths->ant = 0;
	      paths->i = 0;
	      *nb_ant = *nb_ant + 1;
	    }
	  paths->i = paths->i + 1;
	}
      paths = paths->next;
    }
  return (0);
}

int		ant(t_path *paths, t_lemin *lemin)
{
  t_path	*first;
  int		nb_ant;
  int		ct_ant;

  first = paths;
  nb_ant = 0;
  ct_ant = init_ant(paths, lemin->nbant);
  while (lemin->nbant != nb_ant)
    {
      paths = first;
      if ((while_ant(paths, &ct_ant, &nb_ant, lemin)) == -1)
	return (-1);
      paths = first;
      if ((while_new_ant(paths, &ct_ant, &nb_ant, lemin)) == -1)
	return (-1);
      my_putchar('\n');
    }
  return (0);
}
