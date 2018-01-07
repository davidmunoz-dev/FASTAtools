/*
** my_free_tab.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/lib/my
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sun Jun 19 20:51:29 2016 David Munoz
** Last update Sun Jun 19 20:52:30 2016 David Munoz
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}
