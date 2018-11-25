#include "stdio.h"

int main (int n, char *arg[])
{
	int a, b;
	a = atoi(arg[1]);
	b = atoi(arg[2]);
	
	printf("%d\n", a+b);
	return 0;
}