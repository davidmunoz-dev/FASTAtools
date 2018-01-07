/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 10:02:16 2016 David Munoz
** Last update Tue Jun 21 11:06:47 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

char	*read_file()
{
  char  buffer[BUFF_SIZE + 1];
  char  *src;
  int   nb;

  if ((src = malloc(sizeof(char *))) == 0)
    return (cerr_msg_exit("Error: Malloc failed", 84));
  src = "\0";
  while ((nb = read(0, buffer, BUFF_SIZE)) > 0)
    {
      buffer[nb] = '\0';
      src = my_realloc(src, nb + 1);
      src = my_strcat(src, buffer);
    }
  return (src);
}

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if (check_args(av) == FAS_OK)
	return (FAS_OK);
    }
  else if (ac == 3)
    if (my_strncmp(av[1], "4", 1) == FAS_OK && part_four(atoi(av[2])) == FAS_OK)
      return (FAS_OK);
  return (cerr_zero(ERROR, ERR_USAGE, 84));
}
