/*
** main.c for main in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Sat Apr 23 15:25:51 2016 Thomas Bouillon
** Last update Mon Apr 25 16:49:34 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "my.h"
#include "func.h"
#include "get_next_line.h"
#include "lemin.h"

int		calc_ant_path(t_lemin *lemin)
{
  t_path	new_path;

  if ((lemin->start = make_graph(lemin->list, lemin)) == NULL)
    return (-1);
  change_all_spec(lemin);
  lemin->spec_max = get_node_spec(lemin->end, 1);
  lemin->spec_min = get_node_spec(lemin->end, 0);
  if (algo(lemin, lemin->spec_min) == -1)
    return (-1);
  if (lemin->path->length > 2)
    if ((reverse_all_list(lemin->path)) == -1)
      return (-1);
  new_path.tab = NULL;
  new_path.length = 0;
  new_path.next = NULL;
  if (check_solve(lemin) == -1)
    return (-1);
  print_fourmi(lemin->list);
  if ((sort_path(lemin, (lemin->spec_min * -1)
     + 2, lemin->nbant, &new_path)) == -1)
    return (-1);
  free_list(lemin);
  free_graph(lemin);
  return (0);
}

int	main()
{
  t_lemin	lemin;
  char		*tmp;

  lemin.list = NULL;
  if ((tmp = get_next_line(0)) == NULL)
    {
      my_putstr("Error: Invalid entry.\n");
      return (-2);
    }
  if ((lemin.nbant = check_nb_ant(tmp, &lemin.list)) == -1)
    return (-1);
  if ((lemin.list = get_list_file(lemin.list->data)) == NULL)
    return (-1);
  if ((is_valid(lemin.list)) == 1)
    return (-1);
  if (check_coordinate(lemin.list) == -1)
    return (-1);
  if ((check_salle_exist(lemin.list)) == -1)
    return (-1);
  if ((calc_ant_path(&lemin)) == -1)
    return (-1);
  return (0);
}
