/*
** check_data.c for  in /home/benmak_s/CPE/check
**
** Made by Sami Benmakhlouf
** Login   <benmak_s@epitech.net>
**
** Started on  Thu Apr 14 14:50:13 2016 Sami Benmakhlouf
** Last update Sat Apr 23 23:47:00 2016 Sami Benmakhlouf
*/

#include <stdlib.h>
#include "func.h"
#include "my.h"

int	is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      else
	{
	  my_putstr("Error invalid coordinate\n");
	  return (-1);
	}
    }
  return (0);
}

char	*check_data(char *str, t_list **list)
{
  char	**tab;
  int	count;
  int	is_name;

  count = 0;
  is_name = 0;
  tab = str_to_wordtab(str, ' ');
  while (tab[count] != NULL)
    {
      if (count == 0)
	is_name = check_name(tab[count]);
      else
	{
	  if ((is_num(tab[count]) != 0))
	    return (NULL);
	}
      count = count + 1;
    }
  if (name_exist(tab[0], list) == 1)
    return (NULL);
  if ((is_name == 0 && tab[1] != NULL) || (is_name == 1 && tab[1] == NULL))
    return (tab[0]);
  else
    return (NULL);
}
