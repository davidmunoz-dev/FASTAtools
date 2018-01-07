/*
** part6.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 21 09:38:04 2016 David Munoz
** Last update Tue Jun 21 13:20:15 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

char	*print_to_stop_six(char **data, int y, int x, char *tab)
{
  int	k;

  if ((tab = malloc(sizeof(char) * (my_strlen(data[y]) + 7))) == NULL)
    return (cerr_msg_exit("Error: Malloc failed", 84));
  tab[0] = 'A';
  tab[1] = 'T';
  tab[2] = 'G';
  k = 3;
  while (my_charcmp(data[y], x, TAA) == 1 &&
         my_charcmp(data[y], x, TAG) == 1 &&
         my_charcmp(data[y], x, TGA) == 1 &&
         data[y][x])
    {
      tab[k] = data[y][x];
      k++;
      x++;
    }
  tab[k] = 0;
  return (tab);
}

char	**print_part_six(char **data, char **tab, int y)
{
  int   x;
  int   r;
  int	k;

  r = k = 0;
  while (data[y])
    {
      x = r = 0;
      while (data[y][x])
	{
	  if (data[y][x] == 'A' && data[y][x+1] == 'T' && data[y][x+2] == 'G')
	    {
	      x += 3;
	      if ((r = check_stop(data, x, y)) == 1)
		{
		  tab[k] = print_to_stop_six(data, y, x, tab[k]);
		  x = x + my_strlen(tab[k]) - 3;
		  k++;
		}
	    }
	  r == 0 ? (x++) : (x+=3);
	}
      y++;
    }
  return (tab);
}


char	**init_tab()
{
  char	**tab_2D;
  char	*tab;

  if ((tab = malloc(250)) == NULL)
    return (cerr_msg_exit("Error: Malloc failed\n", 84));
  my_strcat(tab, FLAG1);
  my_strcat(tab, FLAG2);
  my_strcat(tab, FLAG3);
  my_strcat(tab, FLAG4);
  my_strcat(tab, FLAG5);
  my_strcat(tab, FLAG6);
  tab_2D = my_str_to_wordtab(tab, '/');
  free(tab);
  return (tab_2D);
}

int	print_info(char **info, char **ko)
{
  (void) info;
  (void) ko;
  return (FAS_OK);
}

int	part_six()
{
  char  **data;
  char	**tab;
  char	**ko;
  char	**info;
  char  *str;

  str = read_file();
  data = get_data(str, 0);
  data = get_right_line(data);
  data = trie_tab(data);
  tab = init_tab();
  if ((tab = malloc(sizeof(char*) * 200 + 1)) == NULL)
    return (cerr_exit("Error: Malloc failed", 84));
  ko = print_part_six(data, tab, 0);
  info = init_tab();
  print_info(info, ko);
  free_tab(data);
  print_tab(ko);
  print_tab(info);
  return (FAS_OK);
}
