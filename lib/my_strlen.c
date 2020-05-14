#include "header_lib.h"

int my_strlen(char *str)
{
	int rt = 0;
	if (str == NULL) return -1;
	for (; str[rt]; rt++);
	return (rt);
}