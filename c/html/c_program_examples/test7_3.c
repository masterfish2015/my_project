#include "stdio.h"
int runc(int a,int b)
{  return(a+b);
}

int main()
{
	int x=2,y=5,z=8,r;
	r=runc(runc(x,y),z);
	printf("%d\n",r);
	return 0;
}


