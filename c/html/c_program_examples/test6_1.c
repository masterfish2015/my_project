#include "stdio.h"
int main()
{
	int a[5]={1,2,3,4,5}, b[5]={0,2,1,3,0},i,s=0;
	for(i=0;i<5;i++)
		s+=a[b[i]];
	printf("%d\n", s);
	return 0;
}