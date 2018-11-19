#include "stdio.h"
void sub(int *x, int y, int z)
{	*x=y-z;
}
int main()
{
	int a, b, c;
	sub(&a, 10, 5);
	sub(&b, a, 7);
	sub(&c, a, b);
	printf("%d,%d,%d\n",a,b,c);
	return 0;
}
