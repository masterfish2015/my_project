#include "stdio.h"
int main(void)
{	
	int n ;
	for(n=100; n<1000; n++){
		int a,b,c;
		a = n / 100;
		b = (n % 100) /10;
		c = n % 10;
		//printf("%d,%d,%d\n",a,b,c);
		if ( n == a*a*a+b*b*b+c*c*c) 
			printf("%d\n", n);
	}
	return 0;
}