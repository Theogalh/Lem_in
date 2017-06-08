/*
** str_to_wordtab.c for  in /home/benmak_s/CPE/check
**
** Made by Sami Benmakhlouf
** Login   <benmak_s@epitech.net>
**
** Started on  Thu Apr 14 14:48:07 2016 Sami Benmakhlouf
** Last update Tue Apr 19 18:25:24 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "my.h"
#include "func.h"

void	init_vars(t_struct *vars)
{
  vars->i = 0;
  vars->j = 0;
  vars->k = 0;
}

char		**str_to_wordtab(char *str, char separator)
{
  t_struct	vars;
  char		**tab;

  init_vars(&vars);
  if ((tab = malloc(sizeof(char *) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[vars.k] != 0)
    {
      vars.j = 0;
      if ((tab[vars.i] = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
	return (NULL);
      while (str[vars.k] == separator)
	vars.k = vars.k + 1;
      while (str[vars.k] != separator && str[vars.k] != 0)
	{
	  tab[vars.i][vars.j] = str[vars.k];
	  vars.j = vars.j + 1;
	  vars.k = vars.k + 1;
	}
      tab[vars.i][vars.j] = 0;
      vars.i = vars.i + 1;
    }
  tab[vars.i] = NULL;
  return (tab);
}
