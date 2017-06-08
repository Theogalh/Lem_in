/*
** get_node.c for get_node in /home/thomas/git/CPE_2015_lemin/src
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Apr 18 21:59:31 2016 thomas
** Last update Mon Apr 18 22:09:33 2016 thomas
*/

#include <stdlib.h>

char	*get_node(char *str, char c, int i)
{
  char	*tmp;
  int	h;

  h = 0;
  if ((tmp = malloc(sizeof(str))) == NULL)
    return (NULL);
  while (str[i] != c)
    {
      tmp[h] = str[i];
      i = i + 1;
      h = h + 1;
    }
  tmp[h] = 0;
  return (tmp);
}
