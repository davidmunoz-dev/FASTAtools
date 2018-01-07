/*
** requirement.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:13:03 2016 David Munoz
** Last update Tue Jun 21 09:58:59 2016 David Munoz
*/

int	separator(char c)
{
  if (c >= 'a' && c <= 'z')
    return (0);
  if (c >= 'A' && c <= 'Z')
    return (0);
  if (c >= '0' && c <= '9')
    return (0);
  return (1);
}

char	*my_strcapitalize_synthesis(char *str)
{
  int	i;

  i = 0;
  if (str[i] >= 'a' && str[i] <= 'z')
    str[i] = str[i] - 32;
  while (str[i] != '\0')
    {
      if (separator(str[i]) == 1 && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
	{
	  i++;
	  str[i] = str[i] - 32;
	}
      else if (separator(str[i]) != 1 && (str[i+1] >= 'A' && str[i+1] <= 'Z'))
	{
	  i++;
	  str[i] = str[i] + 32;
	}
      else
	i++;
    }
  return (str);
}
