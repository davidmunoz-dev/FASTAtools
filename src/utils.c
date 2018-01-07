/*
** utils.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sun Jun 19 19:46:59 2016 David Munoz
** Last update Mon Jun 20 22:42:02 2016 David Munoz
*/

#include "fasta.h"
#include "utils.h"

int	my_strlen_tab(char **str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	*cerr_msg_exit(char *log, int status)
{
  write(2, log, my_strlen(log));
  exit(status);
}

int	cerr_exit(char *log, int status)
{
  write(2, log, my_strlen(log));
  exit(status);
}

int	count_word(char *str)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '>')
        {
          while (str[i] != '\n')
            i++;
          j++;
        }
      else
        i++;
    }
  return (j);
}

int	count_word_data(char *str)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '>')
        {
          while (str[i] != '\n')
            i++;
        }
      else
	{
	  i++;
	  if (str[i] == '\n' || str[i] == '\0')
	    j++;
	}
    }
  return (j);
}
