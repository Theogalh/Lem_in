/*
** my_error.c for my_error in /home/theogalh/git/CPE_2015_lemin/src
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Fri Apr  1 17:19:43 2016 Thomas Bouillon
** Last update Fri Apr  1 17:20:52 2016 Thomas Bouillon
*/

#include <stdlib.h>
#include "my.h"

void	my_error(char *msg)
{
  my_putstr(msg);
  exit(-1);
}
