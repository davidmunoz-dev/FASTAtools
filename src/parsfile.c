/*
** datafile.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 20 10:02:10 2016 David Munoz
** Last update Tue Jun 21 11:19:24 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

int	good_char(char c)
{
  if (c == 'A' || c == 'a' ||
      c == 'T' || c == 't' ||
      c == 'G' || c == 'g' ||
      c == 'C' || c == 'c' ||
      c == 'N' || c == 'n')
    return (FAS_OK);
  return (FAS_ERR);
}

int	first_seq(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != '>')
    i++;
  return (i);
}

int	check_carac(char *str, int i)
{
  while (str[i] != '\n' && str[i])
    i++;
  return (i);
}

char	**get_right_line(char **tab)
{
  int   y;
  int   x;

  y = 0;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
        {
          if (tab[y][x] >= 'a' && tab[y][x] <= 'z')
            tab[y][x] -= 32;
          x++;
	}
      y++;
    }
  return (tab);
}

void	print_result(char **info, char **data)
{
  int   y;

  y = 0;
  while (info[y] && data[y])
    {
      my_putstr(info[y]);
      my_putchar('\n');
      my_putstr(data[y]);
      my_putchar('\n');
      y++;
    }
}
