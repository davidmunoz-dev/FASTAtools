/*
** palindrome.h for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:11:31 2016 David Munoz
** Last update Tue Jun 21 16:38:42 2016 David Munoz
*/

#ifndef FASTA_H_
# define FASTA_H_

/*
** macro def
*/
# define	TAA	"TAA"
# define	TAG	"TAG"
# define	TGA	"TGA"

# define	FLAG1	"GCT,GCC,GCA,GCG/TGT,TGC/GAT,GAC/GAA,GAG/TTT,TTC/"
# define	FLAG2	"GGT,GGC,GGA,GGG/CAT,CAC/ATT,ATC,ATA/AAA,AAG/"
# define	FLAG3	"TTA,TTG,CTT,CTC,CTA,CTG/ATG/AAT,AAC/"
# define	FLAG4	"CCT,CCC,CCA,CCG/CAA,CAG/AGA,AGG,CGT,CGC,CGA,CGG/"
# define	FLAG5	"TCT,TCC,TCA,TCG,AGT,AGC/ACT,ACC,ACA,ACG/"
# define	FLAG6	"GTT,GTC,GTA,GTG/TGG/N/TAT,TAC"

/*
** prototype func
*/
char    *read_file();
int	cerr_exit(char *log, int status);
void	*cerr_msg_exit(char *log, int status);
int     check_args(char **av);
int	count_word(char *str);
int	count_word_data(char *str);
char	**trie_tab(char **tab);
int	my_strlen_tab(char **str);


/*
** part one
*/
int     good_char(char c);
int     check_carac(char *str, int i);
char    **get_right_line(char **tab);
void    print_result(char **info, char **data);
char    **get_data(char *str, int y);
char    **get_info(char *str);
int     part_one();

/*
** part two
*/
char    **T_to_U(char **data);
int     part_two();

/*
** part three
*/
char    **revers_tab(char **data);
int     part_three();

/*
** part four
*/
int	part_four(int nb);

/*
** part five
*/
int     my_charcmp(char *str, int i, char *cmp);
int     print_to_stop(char **data, int y, int x);
int     check_stop(char **data, int x, int y);
int	part_five();

/*
** part six
*/
int	part_six();
int	first_seq(char *str);

#endif /* FASTA_H_ ! */
