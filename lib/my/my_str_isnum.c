/*
** my_str_isnum.c for isnum in /home/munoz_d/rendu/Piscine_C_J07/lib/my
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 11:44:04 2015 munoz david
** Last update Thu Jun 16 12:07:16 2016 David Munoz
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	return (0);
      i = i + 1;
    }
  return (1);
}
