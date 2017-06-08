/*
** my_strcmp.c for michel in /home/thomas/git/CPE_2015_lemin/lib/my
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Apr 18 16:46:37 2016 thomas
** Last update Mon Apr 18 22:28:31 2016 thomas
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0)
    {
      if (s1[i] == s2[i])
	i = i + 1;
      else
	return (s1[i] - s2[i]);
    }
  if (s2[i] == 0)
    return (0);
  else
    return (-1);
}
