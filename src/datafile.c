/*
** datafile.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 20 10:04:10 2016 David Munoz
** Last update Tue Jun 21 11:19:15 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

char	**get_data(char *str, int y)
{
  char  **tab;
  int   x;
  int   i;

  i = first_seq(str);
  if ((tab = malloc(sizeof(char*) * (count_word_data(str) + 1))) == NULL)
    return (cerr_msg_exit("Error: Malloc failed", 84));
  while (str[i])
    if (str[i] == '>')
      i = check_carac(str, i);
    else
      {
	x = 0;
	if ((tab[y] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	  return (cerr_msg_exit("Error: Malloc failed", 84));
	while (str[i] != '\0' && str[i] != '>')
	  {
	    if (good_char(str[i]) == FAS_OK)
	      tab[y][x++] = str[i];
	    i++;
	  }
	  tab[y++][x] = 0;
      }
  tab[y] = NULL;
  return (tab);
}

char	**get_info(char *str)
{
  char  **tab;
  int   y;
  int   x;
  int   i;

  i = y = 0;
  if ((tab = malloc(sizeof(char*) * (count_word(str) + 1))) == NULL)
    return (cerr_msg_exit("Error: Malloc failed", 84));
  while (str[i])
    {
      if (str[i] == '>')
        {
          x = 0;
          if ((tab[y] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
            return (cerr_msg_exit("Error: Malloc failed", 84));
          while (str[i] && str[i] != '\n')
            tab[y][x++] = str[i++];
          tab[y][x] = 0;
          x++;
          y++;
        }
      i++;
    }
  tab[y] = NULL;
  return (tab);
}
