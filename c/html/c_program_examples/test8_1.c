#include "stdio.h"
int my_strlen(char *str)
{
	int len = 0;
	while(*str++!='\0')
		len++;
	return len;
}
int main()
{	char *p = "Hello world!\n";
	printf("len = %d\n", my_strlen(p));
	return 0;
}