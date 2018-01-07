/*
** check_args.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sun Jun 19 18:48:49 2016 David Munoz
** Last update Tue Jun 21 11:55:32 2016 David Munoz
*/

#include "utils.h"
#include "fasta.h"

int	print_help()
{
  my_putstr("USAGE\n\t./FASTAtools option\n\n\tDESCRIPTION\n\t");
  my_putstr("option\t1:read FASTA from the standar input, write the DNA");
  my_putstr(" sequences to the standard output\n\t\t2:read FASTA from the ");
  my_putstr("standard input, write on the RNA sequences to the standard");
  my_putstr("output\n\t\t3:read FASTA from the standar input, write the ");
  my_putstr("reverse complement to the standard output\n\t\t4:read FASTA");
  my_putstr(" from the standar input, write the k-mer list to the standard");
  my_putstr("output\n\t\t5:read FASTA from the standar input, write the ");
  my_putstr("coding sequences list to the standar output\n\t\t6:read FASTA");
  my_putstr(" from the standar input, write the amino acids list to the ");
  my_putstr("standard output\n\t\t7:read FASTA from the standard input ");
  my_putstr("containing exactly 2 sequences, aligne them\n\tk\t");
  my_putstr("size of the k-mers for option 4\n");
  return (0);
}

int	check_args(char **av)
{
  if (my_strncmp(av[1], "-h", 2) == FAS_OK && print_help() == FAS_OK);
  else if (my_strncmp(av[1], "1", 2) == FAS_OK && part_one() == FAS_OK);
  else if (my_strncmp(av[1], "2", 2) == FAS_OK && part_two() == FAS_OK);
  else if (my_strncmp(av[1], "3", 2) == FAS_OK && part_three() == FAS_OK);
  else if (my_strncmp(av[1], "5", 2) == FAS_OK && part_five() == FAS_OK);
  else if (my_strncmp(av[1], "6", 2) == FAS_OK && part_six() == FAS_OK);
  else
    return (cerr_exit("Error on usage\nUse the parameter -h for help\n", 84));
  return (FAS_OK);
}
