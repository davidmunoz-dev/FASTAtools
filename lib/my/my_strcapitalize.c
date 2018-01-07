/*
** my_strcapitalize.c for capitalize in /home/munoz_d/rendu/Piscine_C_J07/lib/my
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 11:40:37 2015 munoz david
** Last update Sun Jun 19 15:17:09 2016 David Munoz
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] < 'Z')
	str[i] = str[i] + 32;
      i = i + 1;
    }
  i = 0;
  if (str[i] >= 'a' && str[i] <= 'z')
    str[i] = str[i] - 32;
  i = i + 1;
  while (str[i + 1] != '\0')
    {
      while (str[i] != ' ' || (str[i] < 'a' && str[i] > 'z'))
	i = i + 1;
      if (str[i + 1] > 96 && str[i] < 123)
	str[i + 1] = str[i + 1] - 32;
      else
	i = i + 1;
    }
  return (str);
}
