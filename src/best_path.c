/*
** best_path.c for  in /home/partou_a/rendu/algo_lemin/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Fri Apr 22 18:37:26 2016 Robin Partouche
** Last update Sun Apr 24 22:56:34 2016 Robin Partouche
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		calc_path(int ant, int occ, t_path *path)
{
  int		bonus;
  int		hscore;
  int		score;

  bonus = ant % occ;
  score = 0;
  hscore = 0;
  while (path != NULL)
    {
      if (bonus > 0)
	{
	  bonus = bonus - 1;
	  score = (ant / occ) + 1 + path->length - 2;
	}
      else
	score = (ant / occ) + path->length - 2;
      if (score > hscore)
	hscore = score;
      path = path->next;
    }
  return (hscore);
}

void		add_tab(t_path *tab, t_path *path, t_path *tpath)
{
  int		i;

  i = 1;
  while (path->tab[i + 1] != -1 && path->tab[i] != -1)
    {
      add_to_list(tab, path->tab[i]);
      i = i + 1;
    }
  my_put_in_path(tpath, path);
  while (tab != NULL)
    {
      tab = tab->next;
    }
}

t_path		*verif_tab(t_path *tab, t_path *path, t_path *tpath)
{
  t_path	*first;
  t_path	*first_path;
  int		i;

  i = 1;
  first = tab;
  first_path = path;
  while (path->tab[i] != -1 && path->tab[i + 1] != -1)
    {
      while (tab != NULL)
	{
	  if (tab->length == path->tab[i])
	    return (NULL);
	  tab = tab->next;
	}
      tab = first;
      i = i + 1;
    }
  path = first_path;
  add_tab(tab, first_path, tpath);
  return (first);
}

void		rec_occ(t_path *path, t_rec *rec)
{
  t_path	*tmp;

  while (path != NULL)
    {
      if ((tmp = verif_tab(&rec->tab, path, &rec->path)) != NULL)
	{
	  rec->tab = *tmp;
	  rec->occ = rec->occ + 1;
	}
      path = path->next;
    }
}

int		best_path(t_path *path, int ant, t_lemin *lemin, int i)
{
  t_rec		rec;
  t_path	*first;
  int		old_occ;
  int		nbr;

  old_occ = 2000000;
  first = path;
  while (path != NULL)
    {
      rec.occ = 1;
      rec.tab.length = -1;
      rec.path.tab = NULL;
      add_tab(&rec.tab, path, &rec.path);
      rec_occ(path->next, &rec);
      if ((rec.occ = calc_path(ant, rec.occ, &rec.path)) < old_occ)
	{
	  old_occ = rec.occ;
	  nbr = i;
	}
      path = path->next;
      i = i + 1;
    }
  rec.occ = ant;
  return (keep_path(first, nbr, lemin, &rec));
}
