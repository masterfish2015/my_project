#include "stdio.h"
char *strcpy1(char *dest, char *source)
{	char *p=dest;
	while(*source)
		*p++=*source++;
	return dest;
}
int main()
{
	char s1[100], *s2="apple";
	printf("%s\n", strcpy1(s1, s2));
	printf("%s\n", strcpy1(s1, "banana"));
	return 0;
}





