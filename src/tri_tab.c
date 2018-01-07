/*
** tri_tab.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 20 21:10:19 2016 David Munoz
** Last update Mon Jun 20 21:11:33 2016 David Munoz
*/

#include "fasta.h"
#include "utils.h"

int	my_strlenghtcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] > s2[i])
        return (1);
      if (s1[i] < s2[i])
        return (-1);
      i++;
    }
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  return (FAS_OK);
}

char	**trie_tab(char **tab)
{
  int   i;
  char  *tmp;

  i = 0;
  while (tab && tab[i] && tab[i + 1])
    {
      if (my_strlenghtcmp(tab[i], tab[i + 1]) == 1)
        {
          while (tab && tab[i] && tab[i + 1])
            {
              tmp = tab[i];
              tab[i] = tab[i + 1];
              tab[i + 1] = tmp;
              i++;
            }
          i = -1;
        }
      i++;
    }
  return (tab);
}
