/*
** part2.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 20 09:13:34 2016 David Munoz
** Last update Tue Jun 21 12:27:28 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

char	reverse_complement(char c)
{
  if (c == 'A')
    return (c + 19);
  else if (c == 'T')
    return (c - 19);
  else if (c == 'G')
    return (c - 4);
  else if (c == 'C')
    return (c + 4);
  return (c);
}

char	**revers_tab(char **data)
{
  int	y;
  int	x;

  y = 0;
  while (data[y])
    {
      x = 0;
      while (data[y][x])
	{
	  data[y][x] = reverse_complement(data[y][x]);
	  x++;
	}
      data[y] = my_revstr(data[y]);
      y++;
    }
  return (data);
}

int	part_three()
{
  char	**info;
  char	**data;
  char	*str;
  int	y;

  y = 0;
  str = read_file();
  info = get_info(str);
  data = get_data(str, y);
  data = get_right_line(data);
  data = revers_tab(data);
  print_result(info, data);
  free_tab(info);
  free_tab(data);
  return (FAS_OK);
}
