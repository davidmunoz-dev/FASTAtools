/*
** my_power_rec.c for Exercice 4 in /home/munoz_d/rendu/Piscine_C_J05
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Oct  5 22:35:31 2015 munoz david
** Last update Thu Jun 16 23:30:31 2016 David Munoz
*/


int	my_power_rec(int nb, int power)
{
  int a;

  a = nb;
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (power > 0)
    {
      power = power - 1;
      a = a * my_power_rec(nb, power);
      return (a);
    }
  return (0);
}
