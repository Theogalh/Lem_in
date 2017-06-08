/*
** keep_path.c for  in /home/partou_a/rendu/algo_lemin/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sat Apr 23 11:41:27 2016 Robin Partouche
** Last update Sun Apr 24 22:55:31 2016 Robin Partouche
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int	keep_path(t_path *path, int nbr, t_lemin *lemin, t_rec *rec)
{
  while (nbr != 0)
    {
      path = path->next;
      nbr = nbr - 1;
    }
  rec->occ = 1;
  rec->tab.length = -1;
  rec->path.tab = NULL;
  add_tab(&rec->tab, path, &rec->path);
  rec_occ(path->next, rec);
  path = &rec->path;
  if ((ant(path, lemin)) == -1)
    return (-1);
  return (0);
}
