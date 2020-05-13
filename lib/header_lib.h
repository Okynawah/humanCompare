#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct pos
{
	int y;
	int x;
} pos_t;

typedef struct fsta
{
	int pif;
	int fprec;
	char *txt;
} fs_t;

char *merge_str(char *princ, char *scd);
char *parser(char *str, char *s);
char *reduce_from(char *str, int from);
int word_counter(char *str);
int next_space(char *, int);
int my_strlen(char *str);
char *st(char c);
void print(char *str);
void printc(char str);
int	my_strcmp(char *s1, char *s2);
int strc_strt(char *source, char *search);
int	my_strcmp_end(char *origin, char *end);
int height_per_i(char *text, int i);
char *conv_int_str(int nbr);
char *my_revstr(char *str);
char *array_to_str(int argc, char **argv);
pos_t *strlen_array(int argc, char **argv);
char *gnw(fs_t *sta);
char *gng(fs_t *sta);
int is_in(char *str, char *source);
char *uptog(char *str);
int strle_nw(fs_t *stat);
fs_t *create_fs(char *text);
fs_t *refrs_fs(fs_t *buffer, int a);
char **str_to_array(fs_t *sta);
char *upton(char *str);
int conv_str_int(char *str);
char    *my_strcpy(char *str);
void printt(char **tab);
pos_t *create_pos(int x, int y);
void printp(pos_t *pos);
void printn(char *str);
int strlnbr (int nbr);
int nbrinv (int nbr);
int nega (int nbr);
void printt (char **tab);
pos_t *create_pos(int x, int y);
pos_t *cpypos(pos_t *pos);
char *cut_from(char *str, int until, fs_t *buff);
int end_by(char *source, char *pattern);
int my_strlen_alphabetic(char *);
int is_calc(char *str);
