/*
** my_nblen.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome/lib/my
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 17:36:38 2016 David Munoz
** Last update Thu Jun 16 17:39:41 2016 David Munoz
*/

int	my_nblen(int nb)
{
  int	i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}
