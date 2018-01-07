/*
** part1.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sun Jun 19 18:46:22 2016 David Munoz
** Last update Tue Jun 21 12:26:50 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

int	part_one()
{
  char	**info;
  char	**data;
  char  *str;
  int	y;

  y = 0;
  str = read_file();
  info = get_info(str);
  data = get_data(str, y);
  data = get_right_line(data);
  print_result(info, data);
  free_tab(info);
  free_tab(data);
  return (FAS_OK);
}
