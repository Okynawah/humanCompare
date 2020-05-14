#include "header_lib.h"

char *lower_case(char *str)
{
	int len = my_strlen(str);
	char *rt = malloc(sizeof(char) * (len + 1));
	int i = 0;

	if (len < 1)
		return NULL;
	for (; i < len; i++)
		rt[i] = (str[i] > 64 && str[i] < 91) ?  str[i] + 32 : str[i];
	rt[i] = '\0'; 
	
	return (rt 	);				
}