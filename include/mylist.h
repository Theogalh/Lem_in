/*
** mylist.h for  in /home/partou_a/rendu/Piscine_C_J11/include
**
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
**
** Started on  Mon Oct 12 13:40:45 2015 Robin Partouche
** Last update Mon Apr 25 14:28:29 2016 Thomas Bouillon
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct	s_list
{
  struct s_list *next;
  char		*data;
  char		*name;
  int		tst;
}		t_list;

struct d_list	*double_list_new();

typedef struct	s_struct
{
  int		i;
  int		j;
  int		k;
}		t_struct;

#endif /* !MYLIST_H_ */
