#include "stdio.h"

unsigned long frac(int n)
{
	unsigned long result=1;
	int i;
	for(i=1; i<=n; i++)
		result *= i;
	return result;
}

int main()
{
	int n;
	unsigned long f;
	printf("input n:"); scanf("%d", &n);
	f=frac(n);
	printf("%d!=%lu\n", 3, f);
	return 0;
}