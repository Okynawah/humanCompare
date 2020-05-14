#include "header.h"
#include <stdio.h>

struct params {
  unsigned short doublel : 1;
  unsigned short nberrortotal;
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

void hcmp_clean(struct params t, int tlen)
{
  t.doublel = (t.doublel != 1 && t.doublel != 0) ? 1 : t.doublel;
  t.spacesensitive = (t.spacesensitive != 1 && t.spacesensitive != 0) ? 1 : t.spacesensitive;
  t.dashsensitive = (t.dashsensitive != 1 && t.dashsensitive != 0) ? 1 : t.dashsensitive;
  t.nberrortotal = (t.nberrortotal < tlen && t.nberrortotal > 0) ? t.nberrortotal : tlen;
}

int hcmp(struct params *t, char *str1, char *str2)
{
  char s1, s2;
  int sl1, sl2;
  unsigned short statut = 0;
  unsigned short proximity = 0;

  sl1 = my_strlen(str1);
  sl2 = my_strlen(str2);
  hcmp_clean(*t, (sl1 > sl2) ? sl1 : sl2);
  str1 = lower_case(str1);
  str2 = lower_case(str2);

  for (unsigned short i = 0, j = 0; i < sl1 || j < sl2; i++, j++) {
    do {
      s1 = str1[i];
      s2 = str2[j];
      statut = 0;

      if (t->spacesensitive == 0) {
        if (hcmp_check_space(s2)) {++j; statut+=1;};
      }
      if (t->dashsensitive == 0) {
        if (hcmp_check_dash(s2)) {++j; statut+=1;};
      }
      if (t->doublel == 0)
      {
        if (s1 == str1[i+1] && s1 != str2[j+1]) {++i; statut+=1;};
        if (s2 == str2[j+1] && s2 != str1[i+1]) {++j; statut+=1;};
      }
      proximity += statut;
    } while(statut != 0);

    if (s1 != s2)
      return (-1);
  }
  if (t->nberrortotal > 0) return (t->nberrortotal < proximity) ? -1 : proximity;

  return proximity;
}

int main()
{
  char *str1 = "hello";
  char *str2 = "heLo";
  struct params *t = malloc(sizeof(struct params));
  
  t->dashsensitive = 0;
  t->spacesensitive = 0;
  t->doublel = 0;

  printf("%d\n", hcmp(t, str1, str2));

}
