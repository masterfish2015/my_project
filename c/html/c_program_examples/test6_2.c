#include "stdio.h"

int main()
{
	int i, a[10];
	for(i=9;i>=0;i--)
		a[i]=10-i;
	printf("%d%d%d",a[2],a[5],a[8]);
	return 0;
}
	