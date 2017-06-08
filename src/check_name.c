/*
** check_name.c for  in /home/benmak_s/CPE/check
**
** Made by Sami Benmakhlouf
** Login   <benmak_s@epitech.net>
**
** Started on  Thu Apr 14 14:49:25 2016 Sami Benmakhlouf
** Last update Tue Apr 19 18:05:11 2016 Thomas Bouillon
*/

#include "func.h"

int	check_name(char *str)
{
  int	i;
  int	comment_or_tube;

  i = 0;
  comment_or_tube = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '#' || str[i] == '-')
	comment_or_tube = 1;
      i = i + 1;
    }
  if (comment_or_tube == 0)
    return (0);
  else
    return (1);
}
