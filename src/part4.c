/*
** part4.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 20 15:55:12 2016 David Munoz
** Last update Tue Jun 21 12:28:21 2016 David Munoz
*/

#include "fasta.h"
#include "utils.h"

char	**delete_double(char **tab)
{
  char  **new;
  int   i;
  int   k;

  i = k = 0;
  if ((new = malloc((sizeof(new) * my_strlen_tab(tab)) + 1)) == NULL)
    return (cerr_msg_exit("Error: Malloc failed", 84));
  while (tab[i])
    {
      new[k] = my_strdup(tab[i]);
      while (tab[i + 1] && my_strcmp(tab[i], tab[i + 1]) == 0)
        i++;
      k++;
      i++;
    }
  new[k] = 0;
  return (new);
}

int	check_end(char *data, int nb, int j)
{
  int	end;

  end = 0;
  while (data[j] && end < nb)
    {
      j++;
      end++;
    }
  return (end);
}

char	*tab_mers(char *data, int nb, char *mers, int j)
{
  int	y;

  y = 0;
  while (data[j] && y < nb)
    {
      mers[y] = data[j];
      y++;
      j++;
    }
  mers[y] = 0;
  return (mers);
}

char	**mers_create(char **data, int nb)
{
  char	**mers;
  int	i;
  int	j;
  int	l;

  if ((mers = malloc(sizeof(char*) * 500)) == NULL)
    return (cerr_msg_exit("Error: Malloc failed", 84));
  j = i = 0;
  while (data[i])
    {
      l = my_strlen(data[i]);
      while (l-- >= nb)
	{
	  if (check_end(data[i], nb, j) == nb)
	    {
	      if ((mers[j] = malloc(sizeof(char) * 500)) == NULL)
		return (cerr_msg_exit("Error: Malloc failed", 84));
	      mers[j] = tab_mers(data[i], nb, mers[j], j);
	      j++;
	    }
	}
      i++;
    }
  mers[j] = NULL;
  return (mers);
}

int	part_four(int nb)
{
  char  **data;
  char	**mers;
  char  *str;
  int   y;

  if (nb <= 0)
    cerr_msg_exit("Error on usage\nUse the parameter -h for help\n", 84);
  y = 0;
  str = read_file();
  data = get_data(str, y);
  data = get_right_line(data);
  mers = mers_create(data, nb);
  mers = trie_tab(mers);
  mers = delete_double(mers);
  print_tab(mers);
  free_tab(data);
  free_tab(mers);
  return (FAS_OK);
}
