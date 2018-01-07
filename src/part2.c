/*
** part2.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 20 09:13:34 2016 David Munoz
** Last update Tue Jun 21 12:27:21 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

char	**T_to_U(char **data)
{
  int	y;
  int	x;

  y = 0;
  while (data[y])
    {
      x = 0;
      while (data[y][x])
	{
	  if (data[y][x] == 'T')
	    data[y][x] = 'U';
	  x++;
	}
      y++;
    }
  return (data);
}

int	part_two()
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
  data = T_to_U(data);
  print_result(info, data);
  free_tab(info);
  free_tab(data);
  return (FAS_OK);
}
