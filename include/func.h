/*
** func.h for  in /home/benmak_s/CPE/check
**
** Made by Sami Benmakhlouf
** Login   <benmak_s@epitech.net>
**
** Started on  Thu Apr 14 14:53:33 2016 Sami Benmakhlouf
** Last update Mon Apr 25 16:04:40 2016 Sami Benmakhlouf
*/

#ifndef _FUNC_H_
# define _FUNC_H_

#include "get_next_line.h"
#include "mylist.h"
#include "lemin.h"

typedef struct		s_mystruct
{
  char			**tab;
  int			first;
  int			second;
}			t_mystruct;

int		is_num(char *str);
char		*check_data(char *str, t_list **list);
t_list		*get_list_file(char *first_data);
void		display_list(t_list *list);
int		check_nb_ant(char *str, t_list **list);
int		is_nbant_valid(char *str);
int		check_name(char *str);
void		init_vars(t_struct *vars);
char		**str_to_wordtab(char *str, char separator);
int		my_put_in_list(t_list **list, char *str);
int		add_elem(t_list **list, char *data);
int		name_exist(char *name, t_list **list);
int		is_valid(t_list *list);
int		check_coordinate(t_list *list);
int		compare_coordinate(t_list *list, char *str);
int		is_different_coordinate(char **tab, char **tab2);
int		check_salle_exist(t_list *list);
int		check_in_tab(char *str, t_list *tmp);
void		free_tab(char **tab);
void		init_mystruct(t_mystruct *vars);
int		name_does_exist(t_mystruct vars);

#endif /*_FUNC_H_*/
