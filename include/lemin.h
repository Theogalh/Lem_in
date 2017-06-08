/*
** lemin.h for lemin in /home/theogalh/git/CPE_2015_lemin/include
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Mon Apr 11 15:16:09 2016 Thomas Bouillon
** Last update Mon Apr 25 16:46:11 2016 Thomas Bouillon
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include "mylist.h"

typedef struct		s_node
{
  struct s_maillon	*maillon;
  struct s_node		*next;
}			t_node;

typedef struct		s_nodelist
{
  t_node		*first;
  int			nbnode;
}			t_nodelist;

typedef struct		s_maillon
{
  char			*name;
  int			id;
  int			ant;
  int			spec;
  t_nodelist		node;

  struct s_maillon	*next;
}			t_maillon;

typedef struct	s_path
{
  int		*tab;
  int		length;
  int		i;
  int		ant;

  struct s_path	*next;
}		t_path;

typedef struct		s_lemin
{
  int			nbmaillon;
  int			nbant;
  int			lastid;
  int			spec_max;
  int			spec_min;
  t_list		*list;
  t_maillon		*start;
  t_maillon		*end;
  t_path		*path;
}			t_lemin;

typedef struct		s_rec
{
  int			occ;
  t_path		tab;
  t_path		path;
}                       t_rec;

int		sort_path(t_lemin *lemin, int min, int ants, t_path *new_path);
int		my_put_in_path(t_path *list, t_path *data);
int		best_path(t_path *path, int ant, t_lemin *lemin, int i);
t_path		*verif_tab(t_path *tab, t_path *path, t_path *tpath);
void		add_tab(t_path *list, t_path *path, t_path *tpath);
int		add_to_list(t_path *tab, int nbr);
int		keep_path(t_path *path, int nbr, t_lemin *lemin, t_rec *rec);
t_path		*path_dup(t_path *paths, int *ct_ant, t_lemin *lemin);
void		rec_occ(t_path *path, t_rec *rec);
int		ant(t_path *paths, t_lemin *lemin);
int		new_ant(t_path *paths, t_lemin *lemin, int *nb_ant, int *ct_ant);

void		free_graph(t_lemin *lemin);
void		free_list(t_lemin *lemin);
int		reverse_all_list(t_path *path);
t_maillon	*create_maillon(const int id, char *name, const int spec);
int		link_maillon(t_maillon *maillon1, t_maillon *maillon2);
int		addfirst(t_list *list, t_maillon *graph, t_lemin *lemin);
int		addmaillon(char *name, t_maillon *graph, t_lemin *lemin);
int		addnode(char *data, t_maillon *graph);
int		check_list(t_list *list);
t_maillon	*make_graph(t_list *list, t_lemin *lemin);
t_maillon	*sch_graph_name(t_maillon *graph, char *name);
t_maillon	*sch_graph_id(t_maillon *graph, const int id);
char		*get_node(char *str, char c, int i);
void		change_spec(t_maillon *graph, int spec);
void		print_graph(t_maillon *graph);
void		printf_graph(t_maillon *graph);
t_maillon	*sch_graph_spec(t_maillon *graph, const int spec);
int		change_all_spec(t_lemin *lemin);
int		sch_node_name(t_maillon *maillon, char *name);
int		algo(t_lemin *lemin, int spec);
int		pathdid(t_maillon *graph, t_path *path, int spec, t_lemin *lemin);
void		pathaddid(t_path *path, int id);
t_path		*pathdup(t_path *path, const int id, t_lemin *lemin);
t_path		*addpath(t_lemin *lemin);
t_node		*sch_node_spec(t_node *curr, const int spec);
void		print_fourmi(t_list *list);
int		check_solve(t_lemin *lemin);
t_path		*path1(t_lemin *lemin);

/*
For get_node_spec, bol 1 == get min, bol 0 == get max
*/

int		get_node_spec(t_maillon *graph, int bol);

#endif /* !LEMIN_H_ */
