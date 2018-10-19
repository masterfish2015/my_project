#include "stdio.h"
int main()
{
	int i,n,fib1=1,fib2=1,fib3;
	puts("input n:"); scanf("%d",&n);
	printf("%4s%10s%10s\n","i","fib[i]","ratio");
	printf("%4d%10d\n",1,fib1);
	printf("%4d%10d%10.7lf\n",
		2, fib2, (double)fib2/fib1);
	for(i=3;i<=n; i++){
		fib3 = fib1+fib2;
		printf("%4d%10d%10.7lf\n", 
			i, fib3, (double)fib3/fib2);
		fib1 = fib2;
		fib2 = fib3;
	}	
	return 0;
}