/*
** part5.c for  in /rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 20 10:27:49 2016 David Munoz
** Last update Tue Jun 21 16:44:48 2016 David Munoz
*/

#include "fasta.h"
#include "utils.h"

int	my_charcmp(char *str, int i, char *cmp)
{
  int	x;

  x = 0;
  while (cmp[x] == str[i])
    {
      i++;
      x++;
    }
  if (x == my_strlen(cmp))
    return (0);
  return (1);
}

int	print_to_stop(char **data, int y, int x)
{
  my_putstr("ATG");
  while (my_charcmp(data[y], x, TAA) == 1 &&
	 my_charcmp(data[y], x, TAG) == 1 &&
	 my_charcmp(data[y], x, TGA) == 1 &&
	 data[y][x])
    {
      my_putchar(data[y][x]);
      x++;
    }
  my_putchar('\n');
  return (x);
}

int	check_stop(char **data, int x, int y)
{
  while (data[y][x])
    {
      if ((my_charcmp(data[y], x, TAA) == 0 ||
	  my_charcmp(data[y], x, TAG) == 0 ||
	  my_charcmp(data[y], x, TGA) == 0) &&
	  data[y][x])
	return (1);
      x+=3;
    }
  return (0);
}

void	print_part_five(char **data)
{
  int	y;
  int	x;
  int	r;

  y = r = 0;
  while (data[y])
  {
    x = r = 0;
    while (data[y][x])
      {
	if (data[y][x] == 'A'
	    && data[y][x+1] == 'T'
	    && data[y][x+2] == 'G')
	  {
	    x += 3;
	    if ((r = check_stop(data, x, y)) == 1)
	      x = print_to_stop(data, y, x);
	  }
	r == 0 ? (x++) : (x+=3);
      }
    y++;
  }
}

int	part_five()
{
  char  **data;
  char  *str;
  int   y;

  y = 0;
  str = read_file();
  data = get_data(str, y);
  data = get_right_line(data);
  data = trie_tab(data);
  print_part_five(data);
  free_tab(data);
  return (FAS_OK);
}
