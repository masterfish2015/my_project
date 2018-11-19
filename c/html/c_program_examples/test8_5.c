#include "stdio.h"
void sum(int*a)
{
	a[0]=a[1];
}
int main()
{
	int aa[10]={1,2,3,4,5,6,7,8,9,10}, i;
	for(i=1;i>0;i--)
		sum(&aa[i]);
	printf("%d\n", aa[0]);
	return 0;
}


