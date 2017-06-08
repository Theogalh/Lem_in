/*
** print_graph.c for print_graph in /home/thomas/git/CPE_2015_lemin/src
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Apr 18 21:41:41 2016 thomas
** Last update Sun Apr 24 22:14:37 2016 Robin Partouche
*/

#include <stdio.h>
#include "lemin.h"
#include "my.h"

void	print_fourmi(t_list *list)
{
  while (list != NULL)
    {
      my_putstr(list->data);
      my_putchar('\n');
      list = list->next;
    }
}
