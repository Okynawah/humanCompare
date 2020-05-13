#include "header.h"

struct params {
  unsigned short doublel : 1;
  unsigned short nberrortotal;
  unsigned short nberrorfollowing;
  unsigned short spacesensitive : 1;
  unsigned short dashsensitive : 1;
};

unsigned short hcmp_check_space(char c)
{
  return (c == ' ') ? 1 : 0;
}

unsigned short hcmp_check_dash(char c)
{
  return (c == '-') ? 1 : 0;
}

void hcmp_clean(struct params t)
{
  t.doublel = (t.doublel != 1 && t.doublel != 0) ? 0 : t.doublel;
  t.spacesensitive = (t.spacesensitive != 1 && t.spacesensitive != 0) ? 0 : t.spacesensitive;
  t.dashsensitive = (t.dashsensitive != 1 && t.dashsensitive != 0) ? 0 : t.dashsensitive;
}

int hcmp(struct params *t, char *str1, char *str2)
{
  char s1, s2;
  int sl1, sl2;
  unsigned short statut = 0;
  unsigned short proximity = 0;
  unsigned short followingerrors = 0;

  hcmp_clean(*t);
  sl1 = my_strlen(str1);
  sl2 = my_strlen(str2);

  for (unsigned short i = 0, j = 0; i < sl1 || j < sl2; i++, j++) {

    do {
      s1 = str1[i];
      s2 = str2[j];
      statut = 0;

      if (t->spacesensitive == 1) {
        if (hcmp_check_space(s2)) {++j; statut+=1;};
      }
      if (t->dashsensitive == 1) {
        if (hcmp_check_dash(s2)) {++j; statut+=1;};
      }
      if (t->doublel == 1)
      {
        printf("oui");
        if (s1 == str1[i+1] && s1 != str2[j+1]) {++i; statut+=1;};
        if (s2 == str2[j+1] && s2 != str1[i+1]) {++j; statut+=1;};
      }
      proximity += statut;
      printf("boucle %d\n", statut);
    } while(statut != 0);

    if (s1 != s2)
      return (-1);
  }
  if (t->nberrortotal > 0) return (t->nberrortotal < proximity) ? -1 : proximity;

  return proximity;
}


int main()
{
  char *str1 = "hello";//default
  char *str2 = "hello";
  struct params *t = malloc(sizeof(struct params));
  t->dashsensitive = 1;
  t->spacesensitive = 1;
  t->doublel = 1;


  printf("%d\n", hcmp(t, str1, str2));

}
